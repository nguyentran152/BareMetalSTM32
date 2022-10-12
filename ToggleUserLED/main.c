/*
 * @file           : main.c
 * @author         : Nguyen Tran
 * @Description    : The program used for toggle user led on STM32F411 Discovery Kit 
 */


#include"main.h"




int main(void)
{
	RCC_AHB1ENR_t	volatile *const pClockControl = (RCC_AHB1ENR_t*) 0x40023830; //base_addes + 0x30
	GPIOx_MODE_t	volatile *const pPortDModeReg = (GPIOx_MODE_t*)	0x40020C00;	//base_addes + 0x00
	GPIOx_ODR_t		volatile *const pPortDOutReg  = (GPIOx_ODR_t*) 0x40020C14; //base_addes + 0x14

	//1 enable the clock for GPIO peripheral in the AHB1ENR(3rd bit position)
	pClockControl ->GPIOD_EN = 1;

	//2 configure the mode of the IO pin
	pPortDModeReg ->PIN_12 = 1;
	pPortDModeReg ->PIN_13 = 1;
	pPortDModeReg ->PIN_14 = 1;
	pPortDModeReg ->PIN_15 = 1;

	while(1)
	{
		//set 12th bit High
		pPortDOutReg -> PIN_12 = 1;
		pPortDOutReg -> PIN_13 = 1;
		pPortDOutReg -> PIN_14 = 1;
		pPortDOutReg -> PIN_15 = 1;
		for(uint32_t i = 0; i <300000; i++);
		//set 12th bit Low
		pPortDOutReg -> PIN_12 = 0;
		pPortDOutReg -> PIN_13 = 0;
		pPortDOutReg -> PIN_14 = 0;
		pPortDOutReg -> PIN_15 = 0;
		for(uint32_t i = 0; i <300000; i++);
	}
}
