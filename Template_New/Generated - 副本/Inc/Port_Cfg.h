/**************************************************************************************************/
/**
 * @file      : Port_Cfg.h
 * @brief     : AUTOSAR Port config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Configuration
 *  @brief Port AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_PBcfg.h"



/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_CFG_H_VENDOR_ID                   0x00B3U
#define PORT_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_CFG_H_SW_MAJOR_VERSION            1U
#define PORT_CFG_H_SW_MINOR_VERSION            2U
#define PORT_CFG_H_SW_PATCH_VERSION            1U

/* Check if the vendor id of current file and Port_PBcfg.h are the same  */
#if (PORT_CFG_H_VENDOR_ID != PORT_PBCFG_H_VENDOR_ID)
    #error "Vendor if of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if autodsar version of current file and Port_PBcfg.h are the same */
#if ((PORT_CFG_H_AR_RELEASE_MAJOR_VERSION != PORT_PBCFG_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (PORT_CFG_H_AR_RELEASE_MINOR_VERSION != PORT_PBCFG_H_AR_RELEASE_MINOR_VERSION) ||    \
     (PORT_CFG_H_AR_RELEASE_REVISION_VERSION != PORT_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar version of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the software version of current file and Port_PBcfg.h are the same*/
#if ((PORT_CFG_H_SW_MAJOR_VERSION != PORT_PBCFG_H_SW_MAJOR_VERSION) ||  \
     (PORT_CFG_H_SW_MINOR_VERSION != PORT_PBCFG_H_SW_MINOR_VERSION) ||  \
     (PORT_CFG_H_SW_PATCH_VERSION != PORT_PBCFG_H_SW_PATCH_VERSION)     \
    )
    #error "Software version of Port_Cfg.h and Port_PBcfg.h are different"
#endif


    


#define PORT_PRECOMPILE_SUPPORT     (STD_ON)

#define PORT_DEV_ERROR_DETECT           PORT_DRVW_DEV_ERROR_DETECT

#define PORT_SET_PIN_DIRECTION_API      PORT_DRVW_SET_PIN_DIRECTION_API

#define PORT_SET_PIN_MODE_API           PORT_DRVW_SET_PIN_MODE_API

#define PORT_VERSION_INFO_API           (STD_ON)

#define PORT_NUMBER_OF_PARTITION              (1U)

#define PORT_TOTAL_PIN_NUMBER    ((uint16)144)

#define PORT_NUMBER_OF_CONFIG_PINS      PORT_DRVW_NUMBER_OF_CONFIG_PINS

#define PORT_MAX_PINMUX_NUMBER          PORT_DRVW_MAX_PINMUX_NUMBER


#define PortConf_PortPin_BlueLight  0
#define PortConf_PortPin_RedLight  1
#define PortConf_PortPin_GreenLight  2


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Configuration */

/** @} end of group Port_Module */

#endif /* PORT_CFG_H */

/* End of File */
