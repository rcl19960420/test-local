/**************************************************************************************************/
/**
 * @file      : MemIf.h
 * @brief     : AUTOSAR memory interface driver header file. It is a stub file. It shall be 
 *                   replaced by integrators.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MEMIF_H
#define MEMIF_H

/** @addtogroup MemIf_Module
 *  @{
 */

/** @defgroup MemIf
 *  @brief MemIf
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define MEMIF_VENDOR_ID                   0x00B3U
#define MEMIF_MODULE_ID                   22U
#define MEMIF_AR_RELEASE_MAJOR_VERSION    4U
#define MEMIF_AR_RELEASE_MINOR_VERSION    6U
#define MEMIF_AR_RELEASE_REVISION_VERSION 0U
#define MEMIF_SW_MAJOR_VERSION            1U
#define MEMIF_SW_MINOR_VERSION            2U
#define MEMIF_SW_PATCH_VERSION            1U
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
typedef enum
{
    MEMIF_UNINIT = 0U,          /*!< The underlying abstraction module or device driver has not been initialized (yet). */
    MEMIF_IDLE,                 /*!< The underlying abstraction module or device driver is currently idle. */
    MEMIF_BUSY,                 /*!< The underlying abstraction module or device driver is currently busy. */
    MEMIF_BUSY_INTERNAL         /*!< The underlying abstraction module is busy with internal management operations.
                                     The underlying device driver can be busy or idle. */
}MemIf_StatusType;

typedef enum
{
    MEMIF_JOB_OK = 0U,           /*!< The job has been finished successfully */ 
    MEMIF_JOB_FAILED,            /*!< The job has not been finished successfully */   
    MEMIF_JOB_PENDING,           /*!< The job has not yet been finished. */   
    MEMIF_JOB_CANCELED,          /*!< The job has been canceled. */    
    MEMIF_BLOCK_INCONSISTENT,    /*!< 1. The requested block is inconsistent, it may contain corrupted data. 2. Block is NOT found. */      
    MEMIF_BLOCK_INVALID          /*!< The requested block has been marked as invalid, the requested operation can not be performed */   
}MemIf_JobResultType;

typedef enum
{
    MEMIF_MODE_SLOW = 0U,        /*!< The underlying memory abstraction modules and drivers are working in slow mode. */
    MEMIF_MODE_FAST              /*!< The underlying memory abstraction modules and drivers are working in fast mode */
}MemIf_ModeType;
/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group MemIf */

/** @} end of group MemIf_Module */

#endif /* MEMIF_H */

