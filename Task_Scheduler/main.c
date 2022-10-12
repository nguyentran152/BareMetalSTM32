/*
 * @file           : main.c
 * @author         : Nguyen Tran
 * @Description    : The program used for task_scheduling user led on STM32F411 Discovery Kit 
 */

#include"main.h"

uint32_t tick_count = 0;
TaskControlBlock_t UserThreads[MAX_TASKS];
int CurrentTask = 0;



uint32_t GetPSPValue(void)
{
    return UserThreads[CurrentTask].TCB_PSPValue;
}

void SavePSPValue(uint32_t stack_addr)
{
    UserThreads[CurrentTask].TCB_PSPValue = stack_addr;
}

void NextTaskHandler(void)
{
    int i;
    for(i = 0; i < MAX_TASKS; i++)
    {
        CurrentTask++;
        CurrentTask %= MAX_TASKS;
        if(UserThreads[CurrentTask].TCB_CurrentState == TASK_READY_STATE)
        {
            break;
        }
    }
}

void InitTaskControlBlock(void)
{
    for(int i =0; i < MAX_TASKS; i++)
    {
        UserThreads[i].TCB_CurrentState = TASK_INVALID_STATE;
    }
}

uint32_t CreateThread(void (*TCB_TaskHandler)(void))
{
    uint32_t *pPSP;
    for(int i = 0; i < MAX_TASKS; i++)
    {
        if(UserThreads[i].TCB_CurrentState == TASK_INVALID_STATE)
        {
            UserThreads[i].TCB_TaskHandler = TCB_TaskHandler;
            UserThreads[i].TCB_CurrentState = TASK_READY_STATE;
            UserThreads[i].TCB_PSPValue = SRAM_END - (i+1)*TASK_STACK_SIZE;
            pPSP = (uint32_t*)UserThreads[i].TCB_PSPValue;
            pPSP--; //XPSP
            *pPSP = (uint32_t)0x01000000;
            pPSP--; //PC
            *pPSP = (uint32_t)UserThreads[i].TCB_TaskHandler;
            pPSP--; //LR
            *pPSP = (uint32_t)0xFFFFFFFD;
            for(int j = 0; j < 13; j++)
            {
                pPSP--;
                *pPSP = 0;
            }
            UserThreads[i].TCB_PSPValue = (uint32_t)pPSP;
            return i;
        }
    }
    return -1;
}

void DeleteThread(void)
{
    UserThreads[CurrentTask].TCB_CurrentState = TASK_INVALID_STATE;
    //trigger pendsv exception
    *SCB_ICSR |= (1 << 28);
}


void Enable_Processor_Faults(void)
{
    *SCB_SHCSR |= 0x7 << 16; //usage, bus, memory fault system exceptions
    //Lowest priority of PenSV (pr15)
    *SCB_SHPR3 |= 0xF << 20;
}


void InitSystick(uint32_t tick_hz)
{
    uint32_t count = ((SYSTICK_TIMER_CLOCK/tick_hz) - 1);

    *STK_LOAD = count;
    //update SCSR to trigger systick interrupt
    *STK_SCSR |= 0x3 << 0;
}

void SysTick_Handler(void)
{
    tick_count++;

    //trigger pendsv exception
    *SCB_ICSR |= (1 << 28);
}

//context sw
__attribute__((naked)) void PendSV_Handler(void)
{
    //disable interrupt
    __asm volatile("CPSID I");
    //save context of current task
    //get current task PSP
    __asm volatile("MRS R0,PSP");
    //using psp value store (R4-R11)
    __asm volatile("STMDB R0!,{R4-R11}");
    //save current value of psp
    __asm volatile("PUSH {LR}");
    __asm volatile("BL SavePSPValue");

    //retrieve context of next task 
    //decide next task to run
    __asm volatile("BL NextTaskHandler");
    //get next task PSP value 
    __asm volatile("BL GetPSPValue");
    __asm volatile("POP {LR}");
    //using PSP value restrieve R4 -R11
    __asm volatile("LDMIA R0!,{R4-R11}");
    //upgrade psp and exit
    __asm volatile("MSR PSP,R0");
    //enable interrups
    __asm volatile("CPSIE I");
    __asm volatile("BX LR");
}

__attribute__((naked)) void SwitchSPtoPSP(void)
{
    //init PSP to task
    __asm volatile("PUSH {LR}");
    __asm volatile("BL GetPSPValue");
    __asm volatile("POP {LR}");
    __asm volatile("MSR PSP,R0");


    //change SP to PSP using Control register
    __asm volatile("MOV R0,#0X02");
    __asm volatile("MSR CONTROL,R0");
    __asm volatile("BX LR");
}




//Fault Handlers
void NMI_Handler(void)
{
    while (1);    
}

void HardFault_Handler(void)
{
    while (1);  
}

void MemManage_Handler(void)
{
    while (1);
}

void BusFault_Handler(void)
{
    while(1);
}

void UsageFault_Handler(void)
{
    while(1);
}

void SVC_Handler(void)
{
    while(1);
}

void DebugMon_Handler(void)
{
    while(1);
}





void task1(void)
{
    while(1)
    {
        for(uint32_t i = 0; i <250000; i++);
        *GPIOD_ODR &= ~(1 << 14);
        for(uint32_t i = 0; i <250000; i++);
        *GPIOD_ODR |= (1 << 14);   
    }
}

void task2(void)
{
    while(1)
    {
        for(uint32_t i = 0; i <170000; i++);
        *GPIOD_ODR &= ~(1 << 13);
        for(uint32_t i = 0; i <170000; i++);
        *GPIOD_ODR |= (1 << 13);   
    }
}

void idle_task(void)
{  
    while(1)
    {
        for(uint32_t i = 0; i <300000; i++);
        *GPIOD_ODR &= ~(1 << 12);
        for(uint32_t i = 0; i <300000; i++);
        *GPIOD_ODR |= (1 << 12);   
    }
}

int main(void)
{
    //enable GPIOD
    *RCC_AHB1ENR |= (1 << 3);
    //reset GPIOD
    *RCC_AHB1RSTR |= (1 << 3);
    *RCC_AHB1RSTR &= ~(1 << 3);
    //set PD12 mode output
    *GPIOD_MODER |= (1 << 24);
    //set PD13 mode output
    *GPIOD_MODER |= (1 << 26);
    //set PD14 mode output
    *GPIOD_MODER |= (1 << 28);
    //set PD12 high
    *GPIOD_ODR |= (1 << 12);
    //set PD13 high
    *GPIOD_ODR |= (1 << 13);
    //set PD13 high
    *GPIOD_ODR |= (1 << 14);
    

    Enable_Processor_Faults();
    CreateThread(idle_task);
    CreateThread(task1);
    CreateThread(task2);
    InitSystick(TICK_HZ);
    SwitchSPtoPSP();

    idle_task(); 

	while(1);
    return 0;
}


