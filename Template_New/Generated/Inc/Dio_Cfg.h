
/*************************************************************************************/
/**
 * @file      : Dio_Cfg.h
 * @brief     : AUTOSAR Dio configuration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

/** @addtogroup DIO_CFG
*   @{
*/
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif



/** @defgroup Public_MacroDefinition
*  @{
*/
#define DIO_CFG_H_VENDOR_ID                   0x00B3U
#define DIO_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_CFG_H_SW_MAJOR_VERSION            1U
#define DIO_CFG_H_SW_MINOR_VERSION            2U
#define DIO_CFG_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((DIO_CFG_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||   \
         (DIO_CFG_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Dio_Cfg.h and Std_Types.h are different"
    #endif
#endif

/**
* @brief          Enable or Disable Development Error Detection.
*/
#define DIO_DEV_ERROR_DETECT     (STD_ON)

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/**
* @brief     Switch for checking Dio Channel Groups configuration.
*
*/
#define DIO_CHANNEL_GROUPS_AVAILABLE 
#endif 
/**
* @brief          Enable or Disable Dio module verion acquisition.
*/
#define DIO_VERSION_INFO_API   (STD_ON)

/**
* @brief          Enable or Disable function for flipping channel.
*
*/
#define DIO_FLIP_CHANNEL_API    (STD_ON)

/**
* @brief          Enable or Disable function for mask channel.
*
*/
#define DIO_MASKED_WRITE_PORT_API  (STD_ON)





/**
* @brief          Number of implemented ports.
*
*/
#define DIO_PORT_NUM            ((uint16)0x5U)      

/**
* @brief          The number of partition on the port
*/
#define DIO_PORT_PARTITION_NUM   ((uint16)5U)
 
/**
* @brief          Number of channels available on the implemented ports.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
#define DIO_CHANNEL_NUM           ((uint32)159U)
#endif

/**
* @brief The number of partition on the channel.
*/
#define DIO_CHANNEL_PARTITION_NUM   ((uint16)160U)

/**
* @brief          Mask representing no available channels on a port.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NO_AVAILABLE_CHANNEL_NUM   ((Dio_PortLevelType)0x0U)
#endif


/**
* @brief          Mask representing the maximum valid offset for a channel group.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_VALID_OFFSET_MAX         ((uint8)0x1FU)
#endif


/**
* @brief          Dio driver Pre-Compile configuration switch.
*/
#define DIO_PRECOMPILE_SUPPORT





/* ========== DioConfig ========== */

/* ---------- DioPort_0 ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_0.
*
*/
#define DioConf_DioPort_DioPort_0  ((uint8)0x01U)



/**
* @brief          Symbolic name for the channel BlueLight.
*
*/
#define  DioConf_DioChannel_BlueLight  ((uint16)0x0024U)


/**
* @brief          Symbolic name for the channel RedLight.
*
*/
#define  DioConf_DioChannel_RedLight  ((uint16)0x0025U)

/**
* @brief        Symbolic name for the channel group DioChannelGroup_3.
*
*/

#define DioConf_DioChannelGroup_DioChannelGroup_0   (&Dio_ChannelGroupList[0])
/* ---------- DioPort_1 ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_1.
*
*/
#define DioConf_DioPort_DioPort_1  ((uint8)0x03U)



/**
* @brief          Symbolic name for the channel GreenLight.
*
*/
#define  DioConf_DioChannel_GreenLight  ((uint16)0x0070U)

/**
* @brief        Symbolic name for the channel group DioChannelGroup_1.
*
*/

#define DioConf_DioChannelGroup_DioChannelGroup_1   (&Dio_ChannelGroupList[1])
/** @} end of group Public_MacroDefinition */



/** @defgroup Global_VariableDefinition
 *  @{
 */

/**
* @brief Array: the available pins in each port.
*/
#define DIO_CONFIG_AVAILABLE_PIN \
extern const Dio_PortLevelType Dio_AvailablePinsForWrite[DIO_PORT_NUM];\
extern const Dio_PortLevelType Dio_AvailablePinsForRead[DIO_PORT_NUM];


/**
* @brief          Array: List of Dio channel groups in configuration DioConfig.
*/
#define DIO_CONFIG_GROUP_LIST \
extern const Dio_ChannelGroupType Dio_ChannelGroupList[2];


/**
* @brief           Array: List of partition for Dio channel groups in configuration DioConfig.
*/
#define DIO_CONFIG_GROUP_PARTITION \
extern const Dio_ChannelGroupType * const Dio_ChannelGroupsListForEachPartitionPtr[1][2];

/** @} end of group Global_VariableDefinition */



#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} end of group DIO_CFG */

