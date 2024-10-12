/**************************************************************************************************/
/**
 * @file      : CanIf.c
 * @brief     : AUTOSAR Can If driver source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup CanIf_Module
 *  @{
 */

/** @addtogroup CanIf
 *  @brief AUTOSAR Can If driver source file. It is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "CanIf_Can.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */

#define CANIF_C_VENDOR_ID                   0x00B3U
#define CANIF_C_AR_RELEASE_MAJOR_VERSION    4U
#define CANIF_C_AR_RELEASE_MINOR_VERSION    6U
#define CANIF_C_AR_RELEASE_REVISION_VERSION 0U
#define CANIF_C_SW_MAJOR_VERSION            1U
#define CANIF_C_SW_MINOR_VERSION            2U
#define CANIF_C_SW_PATCH_VERSION            1U

/* Check if current file and CanIf header file are of the same vendor */
#if (CANIF_C_VENDOR_ID != CANIF_VENDOR_ID)
    #error "CanIf.c and CanIf.h have different vendor ids"
#endif

/* Check if current file and CanIf header file are of the same Autosar version */
#if ((CANIF_C_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_C_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_C_AR_RELEASE_REVISION_VERSION != CANIF_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf.c and CanIf.h are different"
#endif

/* Check if current file and CanIf header file are of the same Software version */
#if ((CANIF_C_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION) || \
     (CANIF_C_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION) || \
     (CANIF_C_SW_PATCH_VERSION != CANIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of CanIf.c and CanIf.h are different"
#endif

/** @} end of Private_MacroDefinition */

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

Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
    return E_OK;
}

void CanIf_ErrorNotification (uint8 ControllerId,Can_ErrorType CanErrorType)
{
    (void)ControllerId;
    (void)CanErrorType;
}

void CanIf_ControllerErrorStatePassive (uint8 ControllerId,uint16 RxErrorCounter,uint16 TxErrorCounter)
{
    (void)ControllerId;
    (void)RxErrorCounter;
    (void)TxErrorCounter;
}

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    (void)CanTxPduId;
}

void CanIf_RxIndication( const Can_HwType * Mailbox, const PduInfoType * PduInfoPtr )
{
    (void)Mailbox;
    (void)PduInfoPtr;
}

void CanIf_ControllerBusOff(uint8 ControllerId)
{
    (void)ControllerId;
}

void CanIf_ControllerModeIndication( uint8 ControllerId, Can_ControllerStateType ControllerMode )
{
    (void)ControllerId;
    (void)ControllerMode;
}

void CanIf_CurrentIcomConfiguration( uint8 ControllerId, IcomConfigIdType  ConfigurationId, IcomSwitch_ErrorType Error)
{
    (void)ControllerId;
    (void)ConfigurationId;
    (void)Error;
}

Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType * PduInfoPtr)
{
    (void)TxPduId;
    (void)PduInfoPtr;
    return E_OK;
}

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group CanIf */

/** @} end of group CanIf_Module */
