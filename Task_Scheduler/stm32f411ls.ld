/*
 * stm32f411ls.ld
 *
 *  Created on: Sep 06, 2022
 *      Author: Nguyen Tran
 */



/* Entry Point */
ENTRY(Reset_Handler)

/* Memories definition */
MEMORY
{
    FLASH(rx) :ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(wx) :ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

/* Sections definition */
SECTIONS
{
    .isr_vector :
    {
      . = ALIGN(4);
      KEEP(*(.isr_vector))
      . = ALIGN(4);
    } >FLASH
    
    .text :
    {
      . = ALIGN(4);
      *(.text)
      *(.text*)      
    } >FLASH
    
    _sidata = LOADADDR(.data);
    
    .data :
    {
      . = ALIGN(4);
      _sdata = .;
      *(.data)
      *(.data*)
      . = ALIGN(4);
      _edata = .;   	 
    } >SRAM AT> FLASH
    
    .bss :
    {
      _sbss = .;
      __bss_start__ = _sbss;
      *(.bss)
      *(.bss*)
      *(COMMON)

      _ebss = .;
      __bss_end__ = _ebss;
    } >SRAM    
}



