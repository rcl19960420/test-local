/**************************************************************************************************/
/**
 * @file      : Pmu_Drv_PBcfg.h
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

/** @addtogroup Pmu_Drv_Configuration
 *  @brief PMU driver configuration
 *  @{
 */
#ifndef PMU_DRV_PBCFG_H
#define PMU_DRV_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PMU_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define PMU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PMU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PMU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PMU_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define PMU_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define PMU_DRV_PBCFG_H_SW_PATCH_VERSION            1U


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define PMU_DRV_CONFIG_PB \
    extern const Pmu_Drv_ConfigType Pmu_Drv_Config;


/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */



/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /* PMU_DRV_PBCFG_H  */

/** @} end of group Pmu_Drv_Configuration */

/** @} end of group Mcu_Module */

