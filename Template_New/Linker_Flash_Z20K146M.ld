/***********************************************************************************************/
/**
 * @file      : Linker_Flash_Z20K146M.ld
 * @brief     : Linker script file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 ***********************************************************************************************/
/*
* Memory:
* 0x00000000    0x000FFFFF  1M    Program Flash
* 0x01000000    0x0101FFFF  128K  Data Flash
* 0x20000000    0x2001FFFF  128K  SRAM
*/

MEMORY
{
    PFLASH_INTERRUPTS(xr)    : ORIGIN = 0x00000000, LENGTH = 0x00000400 /* 1KB */    /* Do not change this section */
    PFLASH_MEM(xr)           : ORIGIN = 0x00000400, LENGTH = 0x000FFC00 /* ~1MB */ 
    SRAM(xrw)                 : ORIGIN = 0x20000000, LENGTH = 0x0001F000 /* 124K */
    SRAM_STACK(xrw)           : ORIGIN = 0x2001F000, LENGTH = 0x00001000 /* 4KB */
    SRAM_END             : ORIGIN = 0x20020000, LENGTH = 0          /* End of SRAM */
}

/* Entry Point */
ENTRY(Reset_Handler)

SECTIONS
{
    .intc_vector :
    {
        . = ALIGN(4096);
        KEEP(*(.intc_vector))               /* Startup code */
    }>PFLASH_INTERRUPTS

    .init_table :
    {
        . = ALIGN(4);
        KEEP(*(.init_table))
    }> PFLASH_MEM
    .zero_table :
    {
        . = ALIGN(4);
        KEEP(*(.zero_table))
    }> PFLASH_MEM

    .ROM.text :
    {
        . = ALIGN(4);
        *(.startup)
        . = ALIGN(4);
        *(.text.startup)
        . = ALIGN(4);
        *(.text)
    }> PFLASH_MEM

    .fls_ac_code_rom :
    {
        . = ALIGN(4);
        *(.fls_ac_code_rom)
    }> PFLASH_MEM

    .ROM.mcal_ramcode :
    {
        . = ALIGN(4);
        *(.mcal_ramcode)
        . = ALIGN(4);
        *(.mcal_code)
    } > PFLASH_MEM

    .ROM.data :
    {
        . = ALIGN(4);
        *(.rodata)
        . = ALIGN(4);
        *(.data)
    } > PFLASH_MEM

        .ROM.mcal_data :
    {
        . = ALIGN(4);
        *(.mcal_data)
        . = ALIGN(4);
        *(.mcal_config_data)
        . = ALIGN(4);
        *(.mcal_const)
    } > PFLASH_MEM

    .intc_vector_ram :
    {
        . = ALIGN(4);
        . = . + SIZEOF(.intc_vector);  /* 确保有足够的空间，即使在对齐后 */
    } > SRAM

    .fls_ac_code_ram :
    {
        . = ALIGN(4);
        . = . + SIZEOF(.fls_ac_code_rom);  /* 确保有足够的空间，即使在对齐后 */
    } > SRAM

    .mcal_ramcode :
    {
        . = ALIGN(4);
        . = . + SIZEOF(.ROM.mcal_ramcode);  /* 确保有足够的空间，即使在对齐后 */
    } > SRAM


    .data :
    {
        . = ALIGN(4);
        . = . + SIZEOF(.ROM.data);  /* 确保有足够的空间，即使在对齐后 */
    } > SRAM

    .mcal_data :
    {
        . = ALIGN(4);
        . = . + SIZEOF(.ROM.mcal_data);  /* 确保有足够的空间，即使在对齐后 */
    } > SRAM

    .bss :
    {
        . = ALIGN(16);
        *(.bss)
        *(COMMON)
    }> SRAM

    .mcal_bss :
    {
        . = ALIGN(16);
        *(.mcal_bss)
    }> SRAM

    /* Stack section */
    .stack (NOLOAD) :
    {
        . = ALIGN(4);
        . = . + LENGTH(SRAM_STACK);  /* 确保有足够的空间，即使在对齐后 */
    } > SRAM_STACK

    __STACK_END         = ORIGIN(SRAM_STACK);
    __STACK_TOP         = ORIGIN(SRAM_STACK) + LENGTH(SRAM_STACK);

    __SRAM_START         = ORIGIN(SRAM);
    __SRAM_END           = ORIGIN(SRAM_END);

    __RAM_RAM_CODE_INIT_START     = ADDR(.mcal_ramcode);
    __RAM_RAM_CODE_INIT_END       = ADDR(.mcal_ramcode) + SIZEOF(.mcal_ramcode);
    __ROM_RAM_CODE_INIT_START     = ADDR(.ROM.mcal_ramcode);
    __ROM_RAM_CODE_INIT_END       = ADDR(.ROM.mcal_ramcode) + SIZEOF(.ROM.mcal_ramcode);


    __RAM_DATA_INIT_START         = ADDR(.data);
    __RAM_DATA_INIT_END           = ADDR(.data) + SIZEOF(.data);
    __ROM_DATA_INIT_START         = ADDR(.ROM.data);
    __ROM_DATA_INIT_END           = ADDR(.ROM.data) + SIZEOF(.ROM.data);

    __RAM_MCAL_DATA_INIT_START    = ADDR(.mcal_data);
    __RAM_MCAL_DATA_INIT_END      = ADDR(.mcal_data) + SIZEOF(.mcal_data);
    __ROM_MCAL_DATA_INIT_START    = ADDR(.ROM.mcal_data);
    __ROM_MCAL_DATA_INIT_END      = ADDR(.ROM.mcal_data) + SIZEOF(.ROM.mcal_data);

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss) + SIZEOF(.mcal_bss)) - ADDR(.bss);
    __BSS_SRAM_END                = ADDR(.mcal_bss) + SIZEOF(.mcal_bss);

    __RAM_INTERRUPT_START         = ADDR(.intc_vector_ram);
    __ROM_INTERRUPT_START         = ADDR(.intc_vector);
    __ROM_INTERRUPT_END           = ADDR(.intc_vector) + SIZEOF(.intc_vector);
                                  
    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __SRAM_INIT_FLAG                    = 1;

    /* Fls module access code support */    
    Fls_Drvw_AcEraseRomStart         = ADDR(.fls_ac_code_rom);
    Fls_Drvw_AcEraseRomEnd           = ADDR(.fls_ac_code_rom) + SIZEOF(.fls_ac_code_rom);
    Fls_Drvw_AcEraseSize             = SIZEOF(.fls_ac_code_rom);

    Fls_Drvw_AcWriteRomStart         = ADDR(.fls_ac_code_rom);
    Fls_Drvw_AcWriteRomEnd           = ADDR(.fls_ac_code_rom) + SIZEOF(.fls_ac_code_rom);
    Fls_Drvw_AcWriteSize             = SIZEOF(.fls_ac_code_rom);

    FLS_AC_ERASE_ADDR        = ADDR(.fls_ac_code_ram);
    FLS_AC_WRITE_ADDR        = ADDR(.fls_ac_code_ram);

}

/*OPTION ("-keep=Flash_Drv_AccessCode")*/
