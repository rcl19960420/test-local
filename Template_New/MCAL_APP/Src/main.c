/**************************************************************************************************/
/**
 * @file      : main.c
 * @brief     : Dio example source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * 
 * @note      : This example contains sample code for customer evaluation purpose only. It is not
 * part of the production code deliverables. The example code is only tested under defined
 * environment with related context of the whole example project. Therefore, it is not guaranteed
 * that the example always works under user environment due to the diversity of hardware and
 * software environment. Do not use pieces copy of the example code without prior and separate
 * verification and validation in user environment.
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Dio_Example
 *  @brief Dio Example
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Wdg.h"
#include "SchM_Dio.h"


/**
 * @brief definition for blue light
 */
#define EX_DIO_BLUE_LIGHT     0
  
/**
 * @brief definition for red light
 */
#define EX_DIO_RED_LIGHT      1

/**
 * @brief definition for green light
 */
#define EX_DIO_GREEN_LIGHT    2
 
/**
 * @brief definition for blue off
 */
#define EX_DIO_BLUE_OFF     3
  
/**
 * @brief definition for red off
 */
#define EX_DIO_RED_OFF      4

/**
 * @brief definition for green off
 */
#define EX_DIO_GREEN_OFF    5

/**
 * @brief  Use channel to turn the red/blue/green light on.
 *
 */
void Ex_Dio_ChannelLightOn(uint8 LightOn)
{
    Dio_WriteChannel(DioConf_DioChannel_BlueLight, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_RedLight, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_GreenLight, STD_LOW);
    
    switch(LightOn)
    {
        case EX_DIO_BLUE_LIGHT:
            Dio_FlipChannel(DioConf_DioChannel_BlueLight);
            break;
        case EX_DIO_RED_LIGHT:
            Dio_FlipChannel(DioConf_DioChannel_RedLight);
            break;
        case EX_DIO_GREEN_LIGHT:
            Dio_FlipChannel(DioConf_DioChannel_GreenLight);
            break;
        default:
                break;
    }
}

/**
 * @brief  Use port to turn the red/blue/green light on.
 *
 */
void Ex_Dio_PortLightOn(uint8 LightOn)
{
    Dio_WritePort(DioConf_DioPort_DioPort_0,STD_LOW);
    Dio_WritePort(DioConf_DioPort_DioPort_1,STD_LOW);
    
    switch(LightOn)
    {
        case EX_DIO_BLUE_LIGHT:
            Dio_WritePort(DioConf_DioPort_DioPort_0,0x10);
            break;
        case EX_DIO_RED_LIGHT:
            Dio_MaskedWritePort(DioConf_DioPort_DioPort_0,0x20,0x30);
            break;
        case EX_DIO_GREEN_LIGHT:
            Dio_MaskedWritePort(DioConf_DioPort_DioPort_1,0xFFFFFFFF,0x10000);
            break;
        default:
                break;
    }
}

/**
 * @brief  Use channel group to turn the red/blue/green light on.
 *
 */
void Ex_Dio_ChannelGroupLightOn(uint8 LightOn)
{
    Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0,STD_LOW);
    Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_1,STD_LOW);
    
    switch(LightOn)
    {
        case EX_DIO_BLUE_LIGHT:
            Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0,0x1);
            break;
        case EX_DIO_RED_LIGHT:
            Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0,0x2);
            break;
        case EX_DIO_GREEN_LIGHT:
            Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_1,0x1);
            break;
        default:
        	Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0,STD_LOW);
			Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_1,STD_LOW);
                break;
    }
}

int main(void)
{
    volatile uint32 Delay,I=0;
    McalLib_Init();
#if (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
#else
    Mcu_Init(NULL_PTR);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_OFF) */
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
#if (WDG_PRECOMPILE_SUPPORT == STD_OFF)
    Wdg_Init(&Wdg_Config);
#else
    Wdg_Init(NULL_PTR);
#endif /* (WDG_PRECOMPILE_SUPPORT == STD_OFF) */
#if (PORT_PRECOMPILE_SUPPORT == STD_OFF)
    Port_Init(&Port_Config);
#else
    Port_Init(NULL_PTR);
#endif /* (PORT_PRECOMPILE_SUPPORT == STD_OFF) */

    /* 使用通道相关的api来打开蓝/红/绿灯 Use the channel related APIs to turn blue/red/green light on*/
//    Ex_Dio_ChannelLightOn(EX_DIO_BLUE_LIGHT);
//    while(STD_HIGH!=Dio_ReadChannel(DioConf_DioChannel_BlueLight));
//
//    Ex_Dio_ChannelLightOn(EX_DIO_RED_LIGHT);
//    while(STD_HIGH!=Dio_ReadChannel(DioConf_DioChannel_RedLight));
//
//    Ex_Dio_ChannelLightOn(EX_DIO_GREEN_LIGHT);
//    while(STD_HIGH!=Dio_ReadChannel(DioConf_DioChannel_GreenLight));
//
//    /* 使用端口相关的api打开蓝/红/绿指示灯 */
//    Ex_Dio_PortLightOn(EX_DIO_BLUE_LIGHT);
//    while(0x10!=Dio_ReadPort(DioConf_DioPort_DioPort_0));
//
//    Ex_Dio_PortLightOn(EX_DIO_RED_LIGHT);
//    while(0x20!=Dio_ReadPort(DioConf_DioPort_DioPort_0));
//
//    Ex_Dio_PortLightOn(EX_DIO_GREEN_LIGHT);
//    while(0x10000!=Dio_ReadPort(DioConf_DioPort_DioPort_1));
//
//    /* 使用通道组相关的api来打开蓝/红/绿灯  */
//    Ex_Dio_ChannelGroupLightOn(EX_DIO_BLUE_LIGHT);
//    while(0x1!=Dio_ReadChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0));
//
//    Ex_Dio_ChannelGroupLightOn(EX_DIO_RED_LIGHT);
//    while(0x2!=Dio_ReadChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0));
//
//    Ex_Dio_ChannelGroupLightOn(EX_DIO_GREEN_LIGHT);
//    while(0x1!=Dio_ReadChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_1));
//    Dio_WritePort(DioConf_DioPort_DioPort_0,0x30);
//    Dio_MaskedWritePort(DioConf_DioPort_DioPort_1,0xFFFFFFFF,0x10000);
//    while(0x10000!=Dio_ReadPort(DioConf_DioPort_DioPort_1));
//    Dio_WriteChannel(DioConf_DioChannel_BlueLight, STD_HIGH);
//	while(STD_HIGH!=Dio_ReadChannel(DioConf_DioChannel_BlueLight));

    Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0,0x3);
    while(0x3!=Dio_ReadChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_0));
    Dio_WriteChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_1,0x1);
    while(0x1!=Dio_ReadChannelGroup(DioConf_DioChannelGroup_DioChannelGroup_1));
    for (;;)
    {
        Wdg_Service();
        Delay = 0x5fffff;
        while (Delay--)
            ;
//        Dio_FlipChannel(DioConf_DioChannel_BlueLight);

//        Dio_WriteChannel(DioConf_DioChannel_BlueLight, STD_HIGH);
//        Ex_Dio_ChannelGroupLightOn(I++);
//        Delay = 0x5fffff;
//        while (Delay--)
//            ;
//        Ex_Dio_ChannelGroupLightOn(I);
//        if(I>EX_DIO_BLUE_OFF)
//        	I=0;
//        Dio_WriteChannel(DioConf_DioChannel_BlueLight, STD_LOW);
//		while(STD_HIGH!=Dio_ReadChannel(DioConf_DioChannel_BlueLight));
    }
}
#ifdef __cplusplus
}
#endif

/** @} end of group Dio_Example */
