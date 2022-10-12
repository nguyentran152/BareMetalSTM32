#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdint.h>

#define RCC_AHB1ENR	    ((uint32_t*) 0x40023830U)
#define	RCC_AHB1RSTR	((uint32_t*) 0x40023810U)

#define	GPIOD_MODER		((uint32_t*) 0x40020C00U)
#define GPIOD_ODR       ((uint32_t*) 0x40020C14U)


#define SCB_SHCSR       ((uint32_t*) 0xE000ED24U)
#define SCB_SHPR3       ((uint32_t*) 0xE000ED20U)
#define SCB_ICSR        ((uint32_t*) 0xE000ED04U)

#define STK_SCSR        ((uint32_t*) 0xE000E010U)
#define STK_LOAD        ((uint32_t*) 0xE000E014U)

#define TICK_HZ             1000U
#define SYSTICK_TIMER_CLOCK 16000000U




typedef struct{
    uint32_t TCB_PSPValue;
    uint32_t TCB_CurrentState;
    void (*TCB_TaskHandler)(void);
}TaskControlBlock_t;

#define TASK_INVALID_STATE  0
#define TASK_READY_STATE    1

#define MAX_TASKS           10
#define TASK_STACK_SIZE     4096U

#define SRAM_START          0x20000000U
#define SRAM_SIZE           112*1024
#define SRAM_END            (SRAM_START + SRAM_SIZE)




#endif 