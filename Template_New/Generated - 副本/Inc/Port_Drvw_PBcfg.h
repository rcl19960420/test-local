/**************************************************************************************************/
/**
 * @file      : Port_Drvw_PBcfg.h
 * @brief     : AUTOSAR Port driver PB config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PORT_DRVW_PBCFG_H
#define PORT_DRVW_PBCFG_H

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


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PORT_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define PORT_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define PORT_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define PORT_DRVW_PBCFG_H_SW_PATCH_VERSION            1U

/**
 * @brief User configuration structure 
 */
#define PORT_DRVW_CONFIG_PB \
extern const Port_Drvw_ConfigType Port_DrvwConfig;

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

/** @} end of group Port_Drvw_Configuration */

/** @} end of group Port_Module */

#endif /* PORT_DRVW_PBCFG_H */
