/**************************************************************************************************/
/**
 * @file      : NvM.h
 * @brief     : NvM AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef NVM_H
#define NVM_H

/** @addtogroup NvM_Module
 *  @{
 */

/** @addtogroup NvM
 *  @brief NvM AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Rte_NvM_Type.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define NVM_VENDOR_ID                   0x00B3U
#define NVM_MODULE_ID                   114U
#define NVM_AR_RELEASE_MAJOR_VERSION    4U
#define NVM_AR_RELEASE_MINOR_VERSION    6U
#define NVM_AR_RELEASE_REVISION_VERSION 0U
#define NVM_SW_MAJOR_VERSION            1U
#define NVM_SW_MINOR_VERSION            2U
#define NVM_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Rte_NvM_Type.h are the same Autosar version */
    #if ((NVM_AR_RELEASE_MAJOR_VERSION != RTE_NVM_TYPE_H_AR_RELEASE_MAJOR_VERSION) || \
         (NVM_AR_RELEASE_MINOR_VERSION != RTE_NVM_TYPE_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of NvM.h and Rte_NvM_Type.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
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

/**
 * @brief      Service to copy the data of the NV block to its corresponding RAM block.
 *
 * @param[in]  BlockId: The block identifier uniquely identifies one NVRAM block descriptor. A NVRAM
 *             block descriptor contains all needed information about a single NVRAM block.
 * @param[out] NvM_DstPtr: Pointer to the RAM data block.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * 
 */
Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void* NvM_DstPtr);

/**
 * @brief      Service to copy the data of the RAM block to its corresponding NV block.
 *
 * @param[in]  BlockId: The block identifier uniquely identifies one NVRAM block descriptor. A NVRAM
 *             block descriptor contains all needed information about a single NVRAM block.
 * @param[out] NvM_SrcPtr: Pointer to the RAM data block.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * 
 */
Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, void* NvM_SrcPtr);

/**
 * @brief      Service for setting the RAM block status of a permanent RAM block or the status of 
 *             the explicit synchronization of a NVRAM block.
 *
 * @param[in]  BlockId: The block identifier uniquely identifies one NVRAM block descriptor. A NVRAM
 *             block descriptor contains all needed information about a single NVRAM block.
 * @param[out] NvM_SrcPtr: 
 *             TRUE: Validate the permanent RAM block or the explicit synchronization and mark block
 *             as changed. 
 *             FALSE: Invalidate the permanent RAM block or the explicit synchronization and mark block 
 *             block as unchanged.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * 
 */
Std_ReturnType NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group NvM */

/** @} end of group NvM_Module */

#endif /* NVM_H */

