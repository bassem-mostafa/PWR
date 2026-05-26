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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "PWR.h"
#include "PWR_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct PWR_Context
{
} PWR_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static PWR_Status_t PWR_Context_Initialize( void );
static PWR_Status_t PWR_Context_Cycle( void );
static PWR_Status_t PWR_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static PWR_Context_t PWR_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static PWR_Status_t PWR_Context_Initialize( void )
{
    PWR_Status_t Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( PWR_Context );
    }
    while ( 0 );

    return Status;
}

static PWR_Status_t PWR_Context_Cycle( void )
{
    PWR_Status_t Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( PWR_Context );
    }
    while ( 0 );

    return Status;
}

static PWR_Status_t PWR_Context_DeInitialize( void )
{
    PWR_Status_t Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( PWR_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

PWR_Status_t PWR_Initialize( PWR_t PWRx )
{
    PWR_Status_t Status = PWR_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( PWRx=%d )", __FUNCTION__, PWRx );

        if ( ( Status = PWR_Context_Initialize( ) ) != PWR_Status_Success )
        {
            break;
        }

        PWR_t PWR_start = ( PWRx == PWR_All ? PWR_Null : PWRx );
        PWR_t PWR_end = ( PWRx == PWR_All ? PWR_Count : PWRx + 1 );
        for ( PWR_t PWR_x = PWR_start; PWR_x < PWR_end; ++PWR_x )
        {
            if ( ( PWR_Status = PWR_Port_Initialize( PWR_x ) ) != PWR_Status_Success )
            {
                Status = PWR_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

PWR_Status_t PWR_Cycle( PWR_t PWRx )
{
    PWR_Status_t Status = PWR_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( PWRx=%d )", __FUNCTION__, PWRx );

        if ( ( Status = PWR_Context_Cycle( ) ) != PWR_Status_Success )
        {
            break;
        }

        PWR_t PWR_start = ( PWRx == PWR_All ? PWR_Null : PWRx );
        PWR_t PWR_end = ( PWRx == PWR_All ? PWR_Count : PWRx + 1 );
        for ( PWR_t PWR_x = PWR_start; PWR_x < PWR_end; ++PWR_x )
        {
            if ( ( PWR_Status = PWR_Port_Cycle( PWR_x ) ) != PWR_Status_Success )
            {
                Status = PWR_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

PWR_Status_t PWR_DeInitialize( PWR_t PWRx )
{
    PWR_Status_t Status = PWR_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( PWRx=%d )", __FUNCTION__, PWRx );

        PWR_t PWR_start = ( PWRx == PWR_All ? PWR_Null : PWRx );
        PWR_t PWR_end = ( PWRx == PWR_All ? PWR_Count : PWRx + 1 );
        for ( PWR_t PWR_x = PWR_start; PWR_x < PWR_end; ++PWR_x )
        {
            if ( ( PWR_Status = PWR_Port_DeInitialize( PWR_x ) ) != PWR_Status_Success )
            {
                Status = PWR_Status;
            }
        }

        if ( ( Status = PWR_Context_DeInitialize( ) ) != PWR_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

PWR_Status_t PWR_SetOnEnter( PWR_t PWRx, PWR_OnEnter_t OnEnter )
{
    PWR_Status_t Status = PWR_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( PWRx=%d, Callback=%p, Context=%p )", __FUNCTION__, PWRx, OnEnter.Callback, OnEnter.Context );

        PWR_t PWR_start = ( PWRx == PWR_All ? PWR_Null : PWRx );
        PWR_t PWR_end = ( PWRx == PWR_All ? PWR_Count : PWRx + 1 );
        for ( PWR_t PWR_x = PWR_start; PWR_x < PWR_end; ++PWR_x )
        {
            if ( ( PWR_Status = PWR_Port_SetOnEnter( PWR_x, &OnEnter ) ) != PWR_Status_Success )
            {
                Status = PWR_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

PWR_Status_t PWR_SetOnExit( PWR_t PWRx, PWR_OnExit_t OnExit )
{
    PWR_Status_t Status = PWR_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;

    do
    {
        PWR_Trace( "%s( PWRx=%d, Callback=%p, Context=%p )", __FUNCTION__, PWRx, OnExit.Callback, OnExit.Context );

        PWR_t PWR_start = ( PWRx == PWR_All ? PWR_Null : PWRx );
        PWR_t PWR_end = ( PWRx == PWR_All ? PWR_Count : PWRx + 1 );
        for ( PWR_t PWR_x = PWR_start; PWR_x < PWR_end; ++PWR_x )
        {
            if ( ( PWR_Status = PWR_Port_SetOnExit( PWR_x, &OnExit ) ) != PWR_Status_Success )
            {
                Status = PWR_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char PWR_VERSION[] = "0.0.0.v20260526-1834";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
