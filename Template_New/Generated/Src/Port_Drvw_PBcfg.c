/**************************************************************************************************/
/**
 * @file      : Port_Drvw_PBcfg.c
 * @brief     : AUTOSAR Port low level driver config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Drvw_Configuration
 *  @brief Port drvw level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Port_Drvw.h"
#include "Port_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define PORT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define PORT_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define PORT_DRVW_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if the vendor id of current file and Port_Drvw.h are the same*/
#if (PORT_DRVW_PBCFG_C_VENDOR_ID != PORT_DRVW_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw_PBcfg.c and Port_Drvw.h are diffrent"
#endif
/* Check if Autosar version of Port_Drvw_PBcfg.c and Port_Drvw.h are the same */
#if ((PORT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PORT_DRVW_H_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PORT_DRVW_H_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_DRVW_H_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar version of Port_Drvw_PBcfg.c and Port_Drvw.h are different"
#endif
/* Check if software version of Port_Drvw_PBcfg.c and Port_Drvw.h are the same */
#if ((PORT_DRVW_PBCFG_C_SW_MAJOR_VERSION != PORT_DRVW_H_SW_MAJOR_VERSION) || \
     (PORT_DRVW_PBCFG_C_SW_MINOR_VERSION != PORT_DRVW_H_SW_MINOR_VERSION) || \
     (PORT_DRVW_PBCFG_C_SW_PATCH_VERSION != PORT_DRVW_H_SW_PATCH_VERSION)    \
    )
    #error "Software version of Port_Drvw_PBcfg.c and Port_Drvw.h are different"
#endif

/* Check if the vendor id of current file and Port_Drv.h are the same*/
#if (PORT_DRVW_PBCFG_C_VENDOR_ID != PORT_DRV_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw_PBcfg.c and Port_Drvw.h are diffrent"
#endif
/* Check if Autosar version of Port_Drvw_PBcfg.c and Port_Drv.h are the same */
#if ((PORT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PORT_DRV_H_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PORT_DRV_H_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_DRV_H_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar version of Port_Drvw_PBcfg.c and Port_Drv.h are different"
#endif
/* Check if software version of Port_Drvw_PBcfg.c and Port_Drv.h are the same */
#if ((PORT_DRVW_PBCFG_C_SW_MAJOR_VERSION != PORT_DRV_H_SW_MAJOR_VERSION) || \
     (PORT_DRVW_PBCFG_C_SW_MINOR_VERSION != PORT_DRV_H_SW_MINOR_VERSION) || \
     (PORT_DRVW_PBCFG_C_SW_PATCH_VERSION != PORT_DRV_H_SW_PATCH_VERSION)    \
    )
    #error "Software version of Port_Drvw_PBcfg.c and Port_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"


/**
* @brief Port attributes of the un-configured pins
*/
static const Port_Drvw_UnconfigPinAttrType Port_DrvwUnconfigPinAttr =
{
    PORT_DRVW_PIN_IN, (uint8)PORT_DRVW_LEVEL_LOW, PORT_DRVW_SLOW_RATE, PORT_DRVW_PULL_DISABLED
};

/**
* @brief Port attributes of the configured pins
*/
static const Port_Drvw_ConfigPinAttrType Port_DrvwConfigPinAttr[PORT_DRVW_NUMBER_OF_CONFIG_PINS]=
{
    /* Pin Id, Output Level, Direction, IsGpio, Direction Changeable, Mode Changeable */
    {(uint16)36, (uint8)PORT_DRVW_LEVEL_LOW, PORT_DRVW_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    /* Pin Id, Output Level, Direction, IsGpio, Direction Changeable, Mode Changeable */
    {(uint16)37, (uint8)PORT_DRVW_LEVEL_LOW, PORT_DRVW_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    /* Pin Id, Output Level, Direction, IsGpio, Direction Changeable, Mode Changeable */
    {(uint16)112, (uint8)PORT_DRVW_LEVEL_LOW, PORT_DRVW_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE}
};

#if (0UL != PORT_DRVW_NUMBER_OF_UNCONFIG_PINS)
/**
* @brief Information of the Un-config pins
*/
static const uint16 Port_DrvwUnconfigPinList[PORT_DRVW_NUMBER_OF_UNCONFIG_PINS]=
{
    (uint16)0,
    (uint16)1,
    (uint16)2,
    (uint16)3,
    (uint16)4,
    (uint16)5,
    (uint16)6,
    (uint16)7,
    (uint16)8,
    (uint16)9,
    (uint16)10,
    (uint16)11,
    (uint16)12,
    (uint16)13,
    (uint16)14,
    (uint16)15,
    (uint16)16,
    (uint16)17,
    (uint16)32,
    (uint16)33,
    (uint16)34,
    (uint16)35,
    (uint16)38,
    (uint16)39,
    (uint16)40,
    (uint16)41,
    (uint16)42,
    (uint16)43,
    (uint16)44,
    (uint16)45,
    (uint16)46,
    (uint16)47,
    (uint16)48,
    (uint16)49,
    (uint16)64,
    (uint16)65,
    (uint16)66,
    (uint16)67,
    (uint16)68,
    (uint16)69,
    (uint16)70,
    (uint16)71,
    (uint16)72,
    (uint16)73,
    (uint16)74,
    (uint16)75,
    (uint16)76,
    (uint16)77,
    (uint16)78,
    (uint16)79,
    (uint16)80,
    (uint16)81,
    (uint16)96,
    (uint16)97,
    (uint16)98,
    (uint16)99,
    (uint16)100,
    (uint16)101,
    (uint16)102,
    (uint16)103,
    (uint16)104,
    (uint16)105,
    (uint16)106,
    (uint16)107,
    (uint16)108,
    (uint16)109,
    (uint16)110,
    (uint16)111,
    (uint16)113,
    (uint16)128,
    (uint16)129,
    (uint16)130,
    (uint16)131,
    (uint16)134,
    (uint16)135,
    (uint16)136,
    (uint16)137,
    (uint16)139,
    (uint16)140,
    (uint16)141,
    (uint16)142,
    (uint16)143,
    (uint16)144
};
#endif

/**
* @brief Port drvw attribtes struct
*/
const Port_Drvw_ConfigType Port_DrvwConfig =
{
    PORT_DRVW_NUMBER_OF_CONFIG_PINS,
    PORT_DRVW_NUMBER_OF_UNCONFIG_PINS,
#if (0UL != PORT_DRVW_NUMBER_OF_UNCONFIG_PINS)
    Port_DrvwUnconfigPinList,
#else
    NULL_PTR,
#endif
    &Port_DrvwUnconfigPinAttr,
    Port_DrvwConfigPinAttr,
    Port_DrvConfig,
};


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Drvw_Configuration */

/** @} end of group Port_Module */
