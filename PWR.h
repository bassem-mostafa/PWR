// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform PWR Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_PWR PWR
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_PWR_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef PWR_H_
    #define PWR_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "PWR_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief PWR Operation Status
     *
     *  @enum PWR_Status_t
     */
    typedef enum PWR_Status
    {
        PWR_Status_Success = 0,     ///< Success
        PWR_Status_ArgumentInvalid, ///< Argument Invalid
        PWR_Status_NotSupported,    ///< Not Supported
        PWR_Status_Error,           ///< General Error
        PWR_Status_Busy,            ///< Busy
        PWR_Status_Timeout,         ///< Timeout
    } PWR_Status_t;

    /**
     *  @brief PWR Callback Context
     */
    typedef void PWR_CallbackContext_t;

    /**
     *  @brief PWR Callback
     */
    typedef PWR_Status_t( PWR_Callback_t )( PWR_t PWRx, PWR_CallbackContext_t * Context );

    /**
     *  @brief PWR On Enter Configuration
     *
     *  @struct PWR_OnEnter_t
     */
    typedef struct PWR_OnEnter
    {
        PWR_Callback_t * Callback;
        PWR_CallbackContext_t * Context;
    } PWR_OnEnter_t;

    /**
     *  @brief PWR On Exit Configuration
     *
     *  @struct PWR_OnExit_t
     */
    typedef struct PWR_OnExit
    {
        PWR_Callback_t * Callback;
        PWR_CallbackContext_t * Context;
    } PWR_OnExit_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize power instance
     *
     *  @note MUST BE called before using any PWR API
     *
     *  @param[in] PWRx Instance
     *
     *  @return PWR_Status_t
     */
    PWR_Status_t PWR_Initialize( PWR_t PWRx );

    /**
     *  @brief Cycle power instance
     *
     *  @param[in] PWRx Instance
     *
     *  @return PWR_Status_t
     */
    PWR_Status_t PWR_Cycle( PWR_t PWRx );

    /**
     *  @brief DeInitialize power instance
     *
     *  @param[in] PWRx Instance
     *
     *  @return PWR_Status_t
     */
    PWR_Status_t PWR_DeInitialize( PWR_t PWRx );

    /**
     *  @brief Set on-enter of power instance
     *
     *  @param[in] PWRx    Instance
     *  @param[in] OnEnter On-Enter configuration
     *
     *  @return PWR_Status_t
     */
    PWR_Status_t PWR_SetOnEnter( PWR_t PWRx, PWR_OnEnter_t OnEnter );

    /**
     *  @brief Set on-exit of power instance
     *
     *  @param[in] PWRx   Instance
     *  @param[in] OnExit On-Exit configuration
     *
     *  @return PWR_Status_t
     */
    PWR_Status_t PWR_SetOnExit( PWR_t PWRx, PWR_OnExit_t OnExit );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char PWR_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* PWR_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
