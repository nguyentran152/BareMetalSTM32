#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdint.h>

typedef struct
{
	 uint32_t GPIOA_EN		:1;
	 uint32_t GPIOB_EN		:1;
	 uint32_t GPIOC_EN		:1;
	 uint32_t GPIOD_EN		:1;
	 uint32_t GPIOE_EN		:1;
	 uint32_t GPIOF_EN		:1;
	 uint32_t GPIOG_EN		:1;
	 uint32_t GPIOH_EN		:1;
	 uint32_t GPIOI_EN		:1;
	 uint32_t Reserved1		:3;
	 uint32_t CRC_EN		:1;
	 uint32_t Reserved2		:3;
	 uint32_t Reserved3		:2;
	 uint32_t BKPSRAM_EN	:1;
	 uint32_t Reserved4		:1;
	 uint32_t CCMDAT_EN		:1;
	 uint32_t DMA1_EN		:1;
	 uint32_t DMA2_EN		:1;
	 uint32_t Reserved5		:2;
	 uint32_t ETHMAC_EN		:1;
	 uint32_t ETHMACTX_EN	:1;
	 uint32_t ETHMACRX_EN	:1;
	 uint32_t ETHMACPTP_EN	:1;
	 uint32_t OTGHS_EN		:1;
	 uint32_t OTGHSULPI_EN	:1;
}RCC_AHB1ENR_t;

typedef struct
{
	uint32_t PIN_0 		:1;
	uint32_t PIN_1 		:1;
	uint32_t PIN_2 		:1;
	uint32_t PIN_3 		:1;
	uint32_t PIN_4 		:1;
	uint32_t PIN_5 		:1;
	uint32_t PIN_6 		:1;
	uint32_t PIN_7 		:1;
	uint32_t PIN_8 		:1;
	uint32_t PIN_9 		:1;
	uint32_t PIN_10 	:1;
	uint32_t PIN_11 	:1;
	uint32_t PIN_12 	:1;
	uint32_t PIN_13 	:1;
	uint32_t PIN_14 	:1;
	uint32_t PIN_15 	:1;
	uint32_t Reserved 	:16;
}GPIOx_ODR_t;

typedef struct
{
	uint32_t PIN_0 		:2;
	uint32_t PIN_1 		:2;
	uint32_t PIN_2 		:2;
	uint32_t PIN_3 		:2;
	uint32_t PIN_4 		:2;
	uint32_t PIN_5 		:2;
	uint32_t PIN_6 		:2;
	uint32_t PIN_7 		:2;
	uint32_t PIN_8 		:2;
	uint32_t PIN_9 		:2;
	uint32_t PIN_10 	:2;
	uint32_t PIN_11 	:2;
	uint32_t PIN_12 	:2;
	uint32_t PIN_13 	:2;
	uint32_t PIN_14 	:2;
	uint32_t PIN_15 	:2;
	uint32_t Reserved 	:2;
}GPIOx_MODE_t;



#endif

