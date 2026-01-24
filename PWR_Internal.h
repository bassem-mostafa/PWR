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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef PWR_INTERNAL_H_
    #define PWR_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "PWR_Port.h"
    #include "driver/STM32L496VGT6P/PWR_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef PWR_TIM
        #define PWR_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef PWR_LOG
        #define PWR_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define PWR_NAME       "PWR"
    #define PWR_LOG_PREFIX UTIL_StringConcatenateConstant( PWR_NAME, "> " )

    #ifdef DEBUG
        #define PWR_Raw( Level, Format, ... ) LOG_Raw( PWR_LOG, Level, Format, ##__VA_ARGS__ )
        #define PWR_Trace( Format, ... )      LOG_Trace( PWR_LOG, UTIL_StringConcatenateConstant( PWR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define PWR_Debug( Format, ... )      LOG_Debug( PWR_LOG, UTIL_StringConcatenateConstant( PWR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define PWR_Info( Format, ... )       LOG_Info( PWR_LOG, UTIL_StringConcatenateConstant( PWR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define PWR_Warning( Format, ... )    LOG_Warning( PWR_LOG, UTIL_StringConcatenateConstant( PWR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define PWR_Error( Format, ... )      LOG_Error( PWR_LOG, UTIL_StringConcatenateConstant( PWR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define PWR_Fatal( Format, ... )      LOG_Fatal( PWR_LOG, UTIL_StringConcatenateConstant( PWR_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define PWR_Raw( Level, Format, ... )
        #define PWR_Trace( Format, ... )
        #define PWR_Debug( Format, ... )
        #define PWR_Info( Format, ... )
        #define PWR_Warning( Format, ... )
        #define PWR_Error( Format, ... )
        #define PWR_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct PWR_Instance_Context_t PWR_Instance_Context_t;

    typedef struct PWR_Instance
    {
        PWR_t PWRx;

        union
        {
            PWR_Instance_Context_t * Context;
            PWR_STM32L496VGT6P_Instance_t * STM32L496VGT6P;
        };
    } PWR_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    PWR_Status_t PWR_IsValid( PWR_t PWRx );

    PWR_Status_t PWR_Instance_Initialize( PWR_Instance_t * Instance );
    PWR_Status_t PWR_Instance_Cycle( PWR_Instance_t * Instance );
    PWR_Status_t PWR_Instance_DeInitialize( PWR_Instance_t * Instance );

    // TODO Add More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* PWR_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
