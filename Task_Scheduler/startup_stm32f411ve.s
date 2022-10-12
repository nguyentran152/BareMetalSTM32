/*
 * startup_stm32f411ve.s
 *
 *  Created on: Sep 06, 2022
 *      Author: Nguyen Tran
 */
 
 .syntax unified
 .cpu cortex-m4
 .thumb
 
 .word _sdata
 .word _edata
 
 .word _sbss
 .word _ebss
 
 .global vectors    
 
 .section .isr_vector, "a",%progbits
 	.type vectors, %object
 	.size vectors, .-vectors
 	
 vectors:
	.word  _estack
	.word  Reset_Handler
	.word  NMI_Handler
	.word  HardFault_Handler
	.word  MemManage_Handler
	.word  BusFault_Handler
	.word  UsageFault_Handler
	.word  0
	.word  0
	.word  0
	.word  0
	.word  SVC_Handler
	.word  DebugMon_Handler
	.word  0
	.word  PendSV_Handler
	.word  SysTick_Handler

	@ /* External Interrupts */
	@ .word     WWDG_IRQHandler                   /* Window WatchDog              */                                        
	@ .word     PVD_IRQHandler                    /* PVD through EXTI Line detection */                        
	@ .word     TAMP_STAMP_IRQHandler             /* Tamper and TimeStamps through the EXTI line */            
	@ .word     RTC_WKUP_IRQHandler               /* RTC Wakeup through the EXTI line */                      
	@ .word     FLASH_IRQHandler                  /* FLASH                        */                                          
	@ .word     RCC_IRQHandler                    /* RCC                          */                                            
	@ .word     EXTI0_IRQHandler                  /* EXTI Line0                   */                        
	@ .word     EXTI1_IRQHandler                  /* EXTI Line1                   */                          
	@ .word     EXTI2_IRQHandler                  /* EXTI Line2                   */                          
	@ .word     EXTI3_IRQHandler                  /* EXTI Line3                   */                          
	@ .word     EXTI4_IRQHandler                  /* EXTI Line4                   */                          
	@ .word     DMA1_Stream0_IRQHandler           /* DMA1 Stream 0                */                  
	@ .word     DMA1_Stream1_IRQHandler           /* DMA1 Stream 1                */                   
	@ .word     DMA1_Stream2_IRQHandler           /* DMA1 Stream 2                */                   
	@ .word     DMA1_Stream3_IRQHandler           /* DMA1 Stream 3                */                   
	@ .word     DMA1_Stream4_IRQHandler           /* DMA1 Stream 4                */                   
	@ .word     DMA1_Stream5_IRQHandler           /* DMA1 Stream 5                */                   
	@ .word     DMA1_Stream6_IRQHandler           /* DMA1 Stream 6                */                   
	@ .word     ADC_IRQHandler                    /* ADC1, ADC2 and ADC3s         */                   
	@ .word     0               				  	/* Reserved                     */                         
	@ .word     0              					/* Reserved                     */                          
	@ .word     0                                 /* Reserved                     */                          
	@ .word     0                                 /* Reserved                     */                          
	@ .word     EXTI9_5_IRQHandler                /* External Line[9:5]s          */                          
	@ .word     TIM1_BRK_TIM9_IRQHandler          /* TIM1 Break and TIM9          */         
	@ .word     TIM1_UP_TIM10_IRQHandler          /* TIM1 Update and TIM10        */         
	@ .word     TIM1_TRG_COM_TIM11_IRQHandler     /* TIM1 Trigger and Commutation and TIM11 */
	@ .word     TIM1_CC_IRQHandler                /* TIM1 Capture Compare         */                          
	@ .word     TIM2_IRQHandler                   /* TIM2                         */                   
	@ .word     TIM3_IRQHandler                   /* TIM3                         */                   
	@ .word     TIM4_IRQHandler                   /* TIM4                         */                   
	@ .word     I2C1_EV_IRQHandler                /* I2C1 Event                   */                          
	@ .word     I2C1_ER_IRQHandler                /* I2C1 Error                   */                          
	@ .word     I2C2_EV_IRQHandler                /* I2C2 Event                   */                          
	@ .word     I2C2_ER_IRQHandler                /* I2C2 Error                   */                            
	@ .word     SPI1_IRQHandler                   /* SPI1                         */                   
	@ .word     SPI2_IRQHandler                   /* SPI2                         */                   
	@ .word     USART1_IRQHandler                 /* USART1                       */                   
	@ .word     USART2_IRQHandler                 /* USART2                       */                   
	@ .word     0               				 	/* Reserved                     */                   
	@ .word     EXTI15_10_IRQHandler              /* External Line[15:10]s        */                          
	@ .word     RTC_Alarm_IRQHandler              /* RTC Alarm (A and B) through EXTI Line */                 
	@ .word     OTG_FS_WKUP_IRQHandler            /* USB OTG FS Wakeup through EXTI line */                       
	@ .word     0                                 /* Reserved     				*/         
	@ .word     0                                 /* Reserved       			    */         
	@ .word     0                                 /* Reserved 					*/
	@ .word     0                                 /* Reserved                     */                          
	@ .word     DMA1_Stream7_IRQHandler           /* DMA1 Stream7                 */                          
	@ .word     0                                 /* Reserved                     */                   
	@ .word     SDIO_IRQHandler                   /* SDIO                         */                   
	@ .word     TIM5_IRQHandler                   /* TIM5                         */                   
	@ .word     SPI3_IRQHandler                   /* SPI3                         */                   
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */
	@ .word     DMA2_Stream0_IRQHandler           /* DMA2 Stream 0                */                   
	@ .word     DMA2_Stream1_IRQHandler           /* DMA2 Stream 1                */                   
	@ .word     DMA2_Stream2_IRQHandler           /* DMA2 Stream 2                */                   
	@ .word     DMA2_Stream3_IRQHandler           /* DMA2 Stream 3                */                   
	@ .word     DMA2_Stream4_IRQHandler           /* DMA2 Stream 4                */                   
	@ .word     0                    			  	/* Reserved                     */                   
	@ .word     0              					/* Reserved                     */                     
	@ .word     0              					/* Reserved                     */                          
	@ .word     0             					/* Reserved                     */                          
	@ .word     0              					/* Reserved                     */                          
	@ .word     0              					/* Reserved                     */                          
	@ .word     OTG_FS_IRQHandler                 /* USB OTG FS                   */                   
	@ .word     DMA2_Stream5_IRQHandler           /* DMA2 Stream 5                */                   
	@ .word     DMA2_Stream6_IRQHandler           /* DMA2 Stream 6                */                   
	@ .word     DMA2_Stream7_IRQHandler           /* DMA2 Stream 7                */                   
	@ .word     USART6_IRQHandler                 /* USART6                       */                    
	@ .word     I2C3_EV_IRQHandler                /* I2C3 event                   */                          
	@ .word     I2C3_ER_IRQHandler                /* I2C3 error                   */                          
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */                         
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */
	@ .word     FPU_IRQHandler                    /* FPU                          */
	@ .word     0                                 /* Reserved                     */                   
	@ .word     0                                 /* Reserved                     */
	@ .word     SPI4_IRQHandler                   /* SPI4                         */
	@ .word     SPI5_IRQHandler                   /* SPI5                         */  
 	
 .section .text.Reset_Handler
 	.weak Reset_Handler
 	.type Reset_Handler, %function
 

 Reset_Handler:
 	movs r1, #0
 	b loop_copy_data
 	
 copy_data:
 	ldr r3, =_sidata
 	ldr r3, [r3,r1]
 	str r3, [r0,r1]
 	adds r1, r1, #4
 	
 loop_copy_data:
 	ldr r0, =_sdata
 	ldr r3, =_edata
 	adds r2, r0, r1
 	cmp r2, r3
 	bcc copy_data
 	b loop_clear_bss
 
 clear_bss:
 	movs r3, #0
 	str r3, [r2], #4
 	
 loop_clear_bss:
 	ldr r3, =_ebss
 	cmp r2, r3
 	bcc clear_bss
 	
 	bl main
 	
 .size Reset_Handler, .-Reset_Handler
 	
 	
 	
 	
 	
 	
 	
 	
 

