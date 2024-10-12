/**************************************************************************************************/
/**
 * @file      : Dio_Cfg.c
 * @brief     : AUTOSAR Dio configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup DIO_CFG
 *   @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio.h"

#if (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))
    /** @defgroup Private_MacroDefinition
     *  @{
     */

    /**
     *  @brief Published information
     */
    #define DIO_CFG_C_VENDOR_ID                   0x00B3U
    #define DIO_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
    #define DIO_CFG_C_AR_RELEASE_MINOR_VERSION    6U
    #define DIO_CFG_C_AR_RELEASE_REVISION_VERSION 0U
    #define DIO_CFG_C_SW_MAJOR_VERSION            1U
    #define DIO_CFG_C_SW_MINOR_VERSION            2U
    #define DIO_CFG_C_SW_PATCH_VERSION            1U

    /**
     *  @brief Check if current file and Dio_Cfg header file are of the same vendor
     */
    #if ((DIO_CFG_C_VENDOR_ID != DIO_CFG_H_VENDOR_ID))
        #error "VENDOR ID of Dio_Cfg.c and Dio_Cfg.h are different"
    #endif

    /**
     *  @brief Check if current file and Dio_Cfg header file are of the same Autosar version
     */
    #if (((DIO_CFG_C_AR_RELEASE_MAJOR_VERSION != DIO_CFG_H_AR_RELEASE_MAJOR_VERSION) ||            \
          (DIO_CFG_C_AR_RELEASE_MINOR_VERSION != DIO_CFG_H_AR_RELEASE_MINOR_VERSION)) ||           \
         (DIO_CFG_C_AR_RELEASE_REVISION_VERSION != DIO_CFG_H_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR Version of Dio_Cfg.c and Dio_Cfg.h are different"
    #endif
    #if ((DIO_CFG_C_SW_MAJOR_VERSION != DIO_CFG_H_SW_MAJOR_VERSION) ||                             \
         (DIO_CFG_C_SW_MINOR_VERSION != DIO_CFG_H_SW_MINOR_VERSION) ||                             \
         (DIO_CFG_C_SW_PATCH_VERSION != DIO_CFG_H_SW_PATCH_VERSION))
        #error "Software Version of Dio_Cfg.c and Dio_Cfg.h are different"
    #endif

    /** @} end of group Private_MacroDefinition */


/** @defgroup Private_VariableDefinition
 *  @{
 */
#define  DIO_START_SEC_CONFIG_DATA_32
#include "Dio_MemMap.h"
/**
* @brief Array : list of partition for available channel
*/
static const uint32 Dio_ChannelPartitionMap[DIO_CHANNEL_PARTITION_NUM] =
{
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U
};
/**
* @brief Array : list of partition for available port
*/
static const uint32 Dio_PortPartitionMap[DIO_PORT_PARTITION_NUM] =
{
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U,
    (uint32)0x0000000000000001U
};

#define  DIO_STOP_SEC_CONFIG_DATA_32
#include "Dio_MemMap.h"

#define  DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"
/**
* @brief          Array: the available pins in each port.
*
*/
const Dio_PortLevelType Dio_AvailablePinsForWrite[DIO_PORT_NUM] =
{
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0001FBCFUL
};

const Dio_PortLevelType Dio_AvailablePinsForRead[DIO_PORT_NUM] =
{
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0001FBCFUL
};
/**
* @brief         Array: List of Dio channel groups in configuratdion DioConfig.
*/
const Dio_ChannelGroupType Dio_ChannelGroupList[2] =
{
    { DioConf_DioPort_DioPort_0, (uint8)0x04U, (Dio_PortLevelType)0x00000030UL},
    { DioConf_DioPort_DioPort_1, (uint8)0x10U, (Dio_PortLevelType)0x00010000UL}
};
/**
* @brief          Data structure for Dio configuration DioConfig.
*/
static const Dio_ConfigType Dio_Config =
{
    (uint8)0x2U,
    &Dio_ChannelGroupList[0],
    Dio_ChannelPartitionMap,
    Dio_PortPartitionMap
};

#define  DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

#define  DIO_START_SEC_CONFIG_DATA_PTR
#include "Dio_MemMap.h"
/**
* @brief          Dio Configuration data for Dio_PreDefinedConfigPtr.
*
*/
const Dio_ConfigType * const Dio_PreDefinedConfigPtr = &Dio_Config;

/**
* @brief          Array: List of partition for Dio channel groups in configuration DioConfig.
*/
const Dio_ChannelGroupType * const Dio_ChannelGroupsListForEachPartitionPtr[1][2] =
{
    {
    &Dio_ChannelGroupList[0],
    &Dio_ChannelGroupList[1]
    }
};

#define  DIO_STOP_SEC_CONFIG_DATA_PTR
#include "Dio_MemMap.h"
/** @} end of group Private_VariableDefinition */

#endif /* (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))  */

#ifdef __cplusplus
}
#endif

/** @} end of group DIO_CFG */
