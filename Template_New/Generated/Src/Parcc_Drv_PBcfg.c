/**************************************************************************************************/
/**
 * @file      : Parcc_Drv_PBcfg.c
 * @brief     : AUTOSAR Mcu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Parcc_Drv_Configuration
 *  @brief PARCC driver configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "Parcc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define PARCC_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define PARCC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PARCC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PARCC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PARCC_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define PARCC_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define PARCC_DRV_PBCFG_C_SW_PATCH_VERSION            1U


/* Check if current file and Parcc_Drv.h file are of the same vendor */
#if (PARCC_DRV_PBCFG_C_VENDOR_ID != PARCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Parcc_Drv_PBcfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Autosar version */
#if ((PARCC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PARCC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PARCC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PARCC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != PARCC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Parcc_Drv_PBcfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Software version */
#if ((PARCC_DRV_PBCFG_C_SW_MAJOR_VERSION != PARCC_DRV_H_SW_MAJOR_VERSION) || \
     (PARCC_DRV_PBCFG_C_SW_MINOR_VERSION != PARCC_DRV_H_SW_MINOR_VERSION) || \
     (PARCC_DRV_PBCFG_C_SW_PATCH_VERSION != PARCC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Parcc_Drv_PBcfg.c and Parcc_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Parcc_Drv_ModuleConfigType Parcc_Drv_PeripheralConfig_0[] = 
{
    /* Start of  PARCC_PORTA*/
    {
        /* Module name id */
        PARCC_DRV_PORTA,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_PORTB*/
    {
        /* Module name id */
        PARCC_DRV_PORTB,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_PORTC*/
    {
        /* Module name id */
        PARCC_DRV_PORTC,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_PORTD*/
    {
        /* Module name id */
        PARCC_DRV_PORTD,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_PORTE*/
    {
        /* Module name id */
        PARCC_DRV_PORTE,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_DMA*/
    {
        /* Module name id */
        PARCC_DRV_DMA,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_CORE,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)0U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_GPIO*/
    {
        /* Module name id */
        PARCC_DRV_GPIO,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_CORE,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)0U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_SPI0*/
    {
        /* Module name id */
        PARCC_DRV_SPI0,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_SPI1*/
    {
        /* Module name id */
        PARCC_DRV_SPI1,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_SPI2*/
    {
        /* Module name id */
        PARCC_DRV_SPI2,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_SPI3*/
    {
        /* Module name id */
        PARCC_DRV_SPI3,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_FOSC,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)15U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
    /* Start of  PARCC_DMAMUX*/
    {
        /* Module name id */
        PARCC_DRV_DMAMUX,
        
        /* Module clock source */
        PARCC_DRV_CLOCK_SRC_CORE,
        
        /* Module clock divider */
        (Parcc_Drv_ClockDividerType)0U,
        
        /* Module enable/disable */
        1U,
        
        /*!< Supervisor access enable/disable */
        0U,
        
        /*!< Write lock enable/disable */
        0U
    },
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

const Parcc_Drv_SystemParccConfigType Parcc_Drv_Config[1U] =
{
    {
        /* Number of Modules */
        12U,
        
        Parcc_Drv_PeripheralConfig_0
    },
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Parcc_Drv_Configuration */

/** @} end of group Mcu_Module */
