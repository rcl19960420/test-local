/**************************************************************************************************/
/**
 * @file      : Mcu_PBcfg.c
 * @brief     : AUTOSAR Mcu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Mcu_Module
 *  @{
 */

/** @addtogroup Mcu_Configuration
 *  @brief Mcu high level driver configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif


#include "Mcu.h"
#include "Mcu_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define MCU_PBCFG_C_VENDOR_ID                   0x00B3U
#define MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MCU_PBCFG_C_SW_MAJOR_VERSION            1U
#define MCU_PBCFG_C_SW_MINOR_VERSION            2U
#define MCU_PBCFG_C_SW_PATCH_VERSION            1U


/* Check if current file and Mcu header file are of the same vendor */
#if (MCU_PBCFG_C_VENDOR_ID != MCU_VENDOR_ID)
    #error "Vender ID of Mcu_PBcfg.c and Mcu.h are different "
#endif

/* Check if current file and Mcu header file are of the same Autosar version */
#if ((MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION    != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_PBcfg.c and Mcu.h are different"
#endif

/* Check if current file and Mcu header file are of the same Software version */
#if ((MCU_PBCFG_C_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_C_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION) || \
     (MCU_PBCFG_C_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION))
    #error "Software Version of Mcu_PBcfg.c and Mcu.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same vendor */
#if (MCU_PBCFG_C_VENDOR_ID != MCU_DRVW_H_VENDOR_ID)
    #error "Vender ID of Mcu_PBcfg.c and Mcu_Drvw.h are different "
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Autosar version */
#if ((MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != MCU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION    != MCU_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION != MCU_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_PBcfg.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Software version */
#if ((MCU_PBCFG_C_SW_MAJOR_VERSION != MCU_DRVW_H_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_C_SW_MINOR_VERSION != MCU_DRVW_H_SW_MINOR_VERSION) || \
     (MCU_PBCFG_C_SW_PATCH_VERSION != MCU_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_PBcfg.c and Mcu_Drvw.h are different"
#endif


/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/**
* @brief   Initialization mode data.
* @details Static configuration realized by calling Mcu_SetMode() API.
*
*/
static const Mcu_ModeConfigType Mcu_ModeConfig[2U] =
{
    /* Start of Mcu_ModeConfig[0] */
    {
        /* Mode Configuration ID. */
        (Mcu_ModeType)0U,

        /* The Power Mode name (code). */
        MCU_POWERMODE_RUN,
    }, /* End of Mcu_ModeConfig0] */
    /* Start of Mcu_ModeConfig[1] */
    {
        /* Mode Configuration ID. */
        (Mcu_ModeType)1U,

        /* The Power Mode name (code). */
        MCU_POWERMODE_STANDBY,
    } /* End of Mcu_ModeConfig1] */
};

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief Initialization Clock data.
*
*/
static const Mcu_ClockConfigType Mcu_ClockConfig[1U] =
{
    /* Start of Mcu_ClockConfig[0] */
    {
        /* The ID for Clock configuration. */
        (Mcu_ClockType)0U,

        &Mcu_Drvw_ClockConfig[0U]
    } /* End of  Mcu_ClockConfig[0] */
};
#endif

#ifndef MCU_MAX_NORAMCONFIGS
/**
* @brief   Definition of a RAM section within the configuration structure:
* @details Blocks of memory are initialized with a default data.
*          Configuration set by calling Mcu_InitRamSection() API.
*/
static const Mcu_RamConfigType Mcu_RamConfig[3U] = 
{
    {
        /* The ID for Ram Sector configuration. */
        (Mcu_RamSectionType)0U,

        /* RAM section base address. */
        0x20000000U,

        /* RAM section size. */
        (uint32)0x00000400U,

        /* RAM default value for initialization. */
        (uint64) (((uint64)0x00U << 0U) | ((uint64)0x00U << 8U) | ((uint64)0x00U << 16U) | ((uint64)0x00U << 24U) | ((uint64)0x00U << 32U) | ((uint64)0x00U << 40U) | ((uint64)0x00U << 48U) | ((uint64)0x00U << 56U)),

        /* RAM section write size. */
        (Ram_Drv_WriteSizeType)8U
    }, /* End of Mcu_RamConfig[0]. */
    {
        /* The ID for Ram Sector configuration. */
        (Mcu_RamSectionType)1U,

        /* RAM section base address. */
        0x20000000U,

        /* RAM section size. */
        (uint32)0x00000400U,

        /* RAM default value for initialization. */
        (uint64) (((uint64)0x00U << 0U) | ((uint64)0x00U << 8U) | ((uint64)0x00U << 16U) | ((uint64)0x00U << 24U) | ((uint64)0x00U << 32U) | ((uint64)0x00U << 40U) | ((uint64)0x00U << 48U) | ((uint64)0x00U << 56U)),

        /* RAM section write size. */
        (Ram_Drv_WriteSizeType)8U
    }, /* End of Mcu_RamConfig[1]. */
    {
        /* The ID for Ram Sector configuration. */
        (Mcu_RamSectionType)2U,

        /* RAM section base address. */
        0x20000000U,

        /* RAM section size. */
        (uint32)0x00000400U,

        /* RAM default value for initialization. */
        (uint64) (((uint64)0x00U << 0U) | ((uint64)0x00U << 8U) | ((uint64)0x00U << 16U) | ((uint64)0x00U << 24U) | ((uint64)0x00U << 32U) | ((uint64)0x00U << 40U) | ((uint64)0x00U << 48U) | ((uint64)0x00U << 56U)),

        /* RAM section write size. */
        (Ram_Drv_WriteSizeType)8U
    } /* End of Mcu_RamConfig[2]. */
};
#endif /* ifndef MCU_MAX_NORAMCONFIGS */


/**
* @brief   Initialization data for the MCU driver.
* @details A pointer to such a structure is provided to the MCU initialization routines for configuration.
*
*/
static const Mcu_ConfigType Mcu_Config =
{
    /* Total number of RAM sections. */
    (Mcu_RamSectionType)3U,
    /* Total number of  MCU modes. */
    (Mcu_ModeType)2U,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Total number of MCU clock configurations. */
    (Mcu_ClockType)1U,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
    /* Pointer to RAM Section configurations. */
    &Mcu_RamConfig,
#endif

    /* Pointer to Power Modes data configuration. */
    &Mcu_ModeConfig,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Pointer to Clock configuration. */
    &Mcu_ClockConfig,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    &Mcu_Drvw_HwConfig
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA_PTR
#include "Mcu_MemMap.h"

/**
* @brief Mcu configuration data for Mcu_PreDefinedConfigPtr.
*
*/
const Mcu_ConfigType * const Mcu_PreDefinedConfigPtr = &Mcu_Config;

#define MCU_STOP_SEC_CONFIG_DATA_PTR
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

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


/** @} end of group Mcu_Configuration */

/** @} end of group Mcu_Module */
