/***************************************************************************************************/
/**
 * @file      : CanIf_Types.h
 * @brief     : Autosar Can interface type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/** @addtogroup  CanIf_Module
 *  @{
 */

/** @addtogroup CanIf
 *  @brief CanIf AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CANIF_TYPES_VENDOR_ID                   0x00B3U
#define CANIF_TYPES_AR_RELEASE_MAJOR_VERSION    4U
#define CANIF_TYPES_AR_RELEASE_MINOR_VERSION    6U
#define CANIF_TYPES_AR_RELEASE_REVISION_VERSION 0U
#define CANIF_TYPES_SW_MAJOR_VERSION            1U
#define CANIF_TYPES_SW_MINOR_VERSION            2U
#define CANIF_TYPES_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Can_GeneralTypes.h header file are of the same version */
    #if ((CANIF_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_TYPES_AR_RELEASE_MINOR_VERSION != CAN_GENERAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf_Types.h and Can_GeneralTypes.h are different"
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

/** @} end of group Public_FunctionDeclaration */


#ifdef __cplusplus
}
#endif

/** @} end of group CanIf */

/** @} end of group CanIf_Module */

#endif /* CANIF_TYPES_H */
