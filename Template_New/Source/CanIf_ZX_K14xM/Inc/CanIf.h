/***************************************************************************************************/
/**
 * @file      : CanIf.h
 * @brief     : CanIf AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CANIF_H
#define CANIF_H

/** @addtogroup  Can_Module
 *  @{
 */

/** @addtogroup Can
 *  @brief Can AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "CanIf_Types.h"
#include "EcuM.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CANIF_VENDOR_ID                   0x00B3U
#define CANIF_AR_RELEASE_MAJOR_VERSION    4U
#define CANIF_AR_RELEASE_MINOR_VERSION    6U
#define CANIF_AR_RELEASE_REVISION_VERSION 0U
#define CANIF_SW_MAJOR_VERSION            1U
#define CANIF_SW_MINOR_VERSION            2U
#define CANIF_SW_PATCH_VERSION            1U

/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf.h and CanIf_Types.h are different"
#endif

/* Check if current file and EcuM.h header file are of the same version */
#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((CANIF_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf.h and EcuM.h are different"
    #endif
#endif

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

Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType * PduInfoPtr);
Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Can */

/** @} end of group Can_Module */

#endif /* CANIF_H */

