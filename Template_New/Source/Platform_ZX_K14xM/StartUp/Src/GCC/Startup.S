/*****************************************************************************************/
/* @file      : startup.s                                                                */
/* @brief     : Startup Source File.                                                     */
/*              - Platform: Z20K14xM                                                     */
/*              - Autosar Version: 4.6.0                                                 */
/* @version   : 1.2.1                                                                    */
/* @author    : Zhixin Semiconductor                                                     */
/* @note                                                                                 */
/*                                                                                       */
/* @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.   */
/*****************************************************************************************/
    .syntax unified
    .arch armv7-m

/* 定义全局符号和初始化表格 */
	.section .init_table, "a"
	.align 2
	.long 4
	.long __RAM_RAM_CODE_INIT_START
	.long __ROM_RAM_CODE_INIT_START
	.long __ROM_RAM_CODE_INIT_END
	.long __RAM_DATA_INIT_START
	.long __ROM_DATA_INIT_START
	.long __ROM_DATA_INIT_END
	.long __RAM_MCAL_DATA_INIT_START
	.long __ROM_MCAL_DATA_INIT_START
	.long __ROM_MCAL_DATA_INIT_END
	.long __RAM_INTERRUPT_START
	.long __ROM_INTERRUPT_START
	.long __ROM_INTERRUPT_END

	.section .zero_table, "a"
	.long 1
	.long __BSS_SRAM_START
	.long __BSS_SRAM_END
	.globl __VECTOR_TABLE

	.section .startup,"ax"

	.thumb
	.globl Reset_Handler
//	.globl _start
	.align 2
	.set VTOR_REG, 0xE000ED08
	.set CPACR_REG, 0xE000ED88
	.set CPACR_VAL, 0x00F00000

    .text
    .thumb


Reset_Handler:
//_start:
/*****************************************************/
/* Mask interrupts and initialize the registers */
/*****************************************************/
    cpsid i
    mov   r0, #0
    mov   r1, #0
    mov   r2, #0
    mov   r3, #0
    mov   r4, #0
    mov   r5, #0
    mov   r6, #0
    mov   r7, #0

/**************************************************/
/* relocate vector table to RAM. */
/**************************************************/
SetVTOR:
    ldr  r0, =VTOR_REG
    ldr  r1, =__RAM_INTERRUPT_START
    str  r1,[r0]

/**************************************************/
/* set up stack; r13 SP. */
/**************************************************/
SetStack:
    ldr  r0, =__STACK_TOP
    msr  MSP, r0
    b    EnableFPU

/**************************************************/
/* Enable FPU. */
/**************************************************/
EnableFPU:
    ldr  r0, =CPACR_REG   //将CPACR_REG寄存器地址加载到r0中
    ldr  r1, [r0]		//从r0指向的地址读取寄存器值，并存入r1中
    ldr  r2, =CPACR_VAL		//将预先设定好的数据加载到r2中
    orr  r1, r2, r1			//将r1和让按位取或运算，并存入到r1中
    str  r1, [r0]			//将r1中的新值写回到由r0指向的内存位置
    dsb						//数据同步指令
    isb						//指令同步指令
    b    InitSram

/**************************************************/
/* Initialize SRAM. 置0 */
/**************************************************/
InitSram:
    ldr  r0, =__SRAM_INIT_FLAG
    cmp  r0, #0        /* Check if __SRAM_INIT_FLAG is not set */
    beq .INIT_SRAM_LOOP_END		//如果标志被设置，此时不会跳转
    ldr r1, =__SRAM_START
    ldr r2, =__SRAM_END
    subs    r2, r1			//r2=r2-r1
    subs    r2, #1			//r2=r2-1
    ble .INIT_SRAM_LOOP_END	//如果r2的值变成0或者负数，则跳转，否则为下面循环做准备
    movs    r0, 0
    movs    r3, #4

.INIT_SRAM_LOOP:
	str r0,[r1]		//将r0的值写入r1指向的地址
	add r1,r1,r3	//更新r1的值，使r1 = r1+r3,指向下一个待初始化的内存位置
	subs r2, 4		//r2减4,此时已经初始化了4个字节，所以需要减去
	bge .INIT_SRAM_LOOP     //如果r2的值大于或等于0，跳回到.INIT_SRAM_LOOP标签处

.INIT_SRAM_LOOP_END:
    b    CopyRomToRam

/**************************************************/
/* Copy the vector table from ROM to RAM. */
/* Copy initialized data from ROM to RAM. */
/* Copy code that should reside in RAM from ROM. */
/**************************************************/
CopyRomToRam:
	ldr r5, =__RAM_RAM_CODE_INIT_START
    ldr  r0, =__SRAM_INIT_FLAG
    cmp  r0, 0
    beq .COPY_ROM_TO_RAM_END
    ldr r0, =__INIT_TABLE
    ldm r0!, {r1}      /* r1: major loop count 从r0指向的地址内存中加载一个字到r1中，r0自动递增4地址，指向下一个字地址 */
.COPY_ROM_TO_RAM_START:
    subs r1, #1
    blt .COPY_ROM_TO_RAM_END		//如果r1小于0，则跳转，跳出循环
    ldm r0!, {r3, r4, r5}
    subs r2, r5, r4      /* r2: copy size r2 = r5-r4 */
    beq .COPY_ROM_TO_RAM_START //若r2为0 即跳转COPY_ROM_TO_RAM_START
.COPY_ROM_TO_RAM_LOOP:
    ldm r4!, {r6}			//从 r4 指向的内存地址读取一个字的数据，并将该数据存储到 r6 寄存器中；r4 指向的下一个字的内存地址
    stm r3!, {r6}			//将r6的内容，存到r3指向的地址的内存中，然后r3再指向下一个字的地址
    subs r2, #4				//r2 = r2-4，并设置条件标志。
    bgt .COPY_ROM_TO_RAM_LOOP //当r2大于0时，跳转
    b .COPY_ROM_TO_RAM_START	//循环结束后返回到复制过程的起始点
.COPY_ROM_TO_RAM_END:
    b    InitBss

/*********************************************/
/* Clear the zero-initialized data section. */
/********************************************/
InitBss:
    ldr r0, =__ZERO_TABLE
    ldm r0!, {r1}      /* r1: major loop count 从r0指向的地址内存中加载一个字到r1中，r0自动递增4地址，指向下一个字地址 */
INIT_BSS_DATA_START:
    subs r1, #1
    blt INIT_BSS_DATA_END	//如果r1小于0，则跳转，跳出循环
    ldm r0!, {r3, r4}
    subs r2, r4, r3      /* r2: copy size */
    beq INIT_BSS_DATA_START
    movs r5, #0
INIT_BSS_DATA_LOOP:
    stm r3!, {r5}		//将r5的内容，存到r3指向的地址的内存中，然后r3再指向下一个字的地址
    subs r2, #4
    bgt INIT_BSS_DATA_LOOP	//当r2大于0时，跳转
    b INIT_BSS_DATA_START	//循环结束后返回到复制过程的起始点
INIT_BSS_DATA_END:

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
_MAIN:
    cpsie i
    bl main

.align 4
.ltorg
