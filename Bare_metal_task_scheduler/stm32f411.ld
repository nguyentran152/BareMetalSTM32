/* Entry Point */
ENTRY(Reset_Handler)

/* Memories definition */
MEMORY
{
    FLASH(rx) :ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx) :ORIGIN = 0x20000000, LENGTH = 128K
}


/* Sections definition */
SECTIONS
{
    .text :
    {
        /* .text all the input file */
        *(.isr_vector)
        *(.text)
        *(.text.*) /* merger of stdlib */
        *(.init)
	    *(.fini)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
        _etext = .;
    }>FLASH

    _loadaddr_data = LOADADDR(.data);
    .data :
    {
        /* .data all the input file */
        _sdata = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .;
    }>SRAM AT> FLASH

    .bss :
    {
        /* .bss all the input file */
        _sbss = .;
        __bss_start__ = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = .;
        . = ALIGN(4);
        end = .;
        __end__ = .;
    }>SRAM
}