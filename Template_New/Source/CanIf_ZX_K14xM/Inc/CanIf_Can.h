/***************************************************************************************************/
/**
 * @file      : CanIf_Can.h
 * @brief     : Autosar Can interface level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CANIF_CAN_H
#define CANIF_CAN_H

/** @addtogroup  CanIf_Module
 *  @{
 */

/** @addtogroup CanIf
 *  @brief CanIf AUTOSAR level
 *  @{
 */

#ifdef  __cplusplus
extern "C" {
#endif

#include "CanIf_Types.h"
#include "CanIf.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CANIF_CAN_VENDOR_ID                   0x00B3U
#define CANIF_CAN_AR_RELEASE_MAJOR_VERSION    4U
#define CANIF_CAN_AR_RELEASE_MINOR_VERSION    6U
#define CANIF_CAN_AR_RELEASE_REVISION_VERSION 0U
#define CANIF_CAN_SW_MAJOR_VERSION            1U
#define CANIF_CAN_SW_MINOR_VERSION            2U
#define CANIF_CAN_SW_PATCH_VERSION            1U

/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_CAN_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf_Can.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_CAN_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_CAN_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_CAN_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf_Can.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_CAN_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_CAN_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_CAN_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf_Can.h and CanIf_Types.h are different"
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

extern void CanIf_ErrorNotification (uint8 ControllerId,Can_ErrorType CanErrorType);
extern void CanIf_ControllerErrorStatePassive (uint8 ControllerId,uint16 RxErrorCounter,uint16 TxErrorCounter);
extern void CanIf_TxConfirmation(PduIdType CanTxPduId);
extern void CanIf_RxIndication( const Can_HwType * Mailbox, const PduInfoType * PduInfoPtr );
extern void CanIf_ControllerBusOff(uint8 ControllerId);
extern void CanIf_ControllerModeIndication( uint8 ControllerId, Can_ControllerStateType ControllerMode );
extern void CanIf_CurrentIcomConfiguration( uint8 ControllerId, IcomConfigIdType  ConfigurationId, IcomSwitch_ErrorType Error);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group CanIf */

/** @} end of group CanIf_Module */

#endif /* CANIF_CAN_H */


