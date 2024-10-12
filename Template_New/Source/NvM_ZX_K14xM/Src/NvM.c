/**************************************************************************************************/
/**
 * @file      : NvM.c
 * @brief     : NvM AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup NvM_Module
 *  @{
 */

/** @addtogroup NvM
 *  @brief Nvm AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "NvM.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define NVM_C_VENDOR_ID                   0x00B3U
#define NVM_C_AR_RELEASE_MAJOR_VERSION    4U
#define NVM_C_AR_RELEASE_MINOR_VERSION    6U
#define NVM_C_AR_RELEASE_REVISION_VERSION 0U
#define NVM_C_SW_MAJOR_VERSION            1U
#define NVM_C_SW_MINOR_VERSION            2U
#define NVM_C_SW_PATCH_VERSION            1U
/** @} end of Private_MacroDefinition */

/* Check if current file and NvM.h are the same vendor */
#if (NVM_C_VENDOR_ID != NVM_VENDOR_ID)
    #error "Vendor ID of NvM.c and NvM.h are different"
#endif
/* Check if current file and NvM.h are the same Autosar version */
#if ((NVM_C_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
     (NVM_C_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION) || \
     (NVM_C_AR_RELEASE_REVISION_VERSION != NVM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of NvM.c and NvM.h are different"
#endif
/* Check if current file and NvM.h are the same Software version */
#if ((NVM_C_SW_MAJOR_VERSION != NVM_SW_MAJOR_VERSION) || \
     (NVM_C_SW_MINOR_VERSION != NVM_SW_MINOR_VERSION) || \
     (NVM_C_SW_PATCH_VERSION != NVM_SW_PATCH_VERSION))
    #error "Software Version of NvM.c and NvM.h are different"
#endif

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

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
Std_ReturnType NvM_ReadBlock(NvM_BlockIdType BlockId, void* NvM_DstPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    (void)BlockId;
    (void)NvM_DstPtr;

    return Ret;
}

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
Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, void* NvM_SrcPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    (void)BlockId;
    (void)NvM_SrcPtr;

    return Ret;
}

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
Std_ReturnType NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    (void)BlockId;
    (void)BlockChanged;

    return Ret;
}
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group NvM */

/** @} end of group NvM_Module */

