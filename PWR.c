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
    PWR_Instance_t Instance[ PWR_Count ];
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
    PWR_Status_t Status = PWR_Status_Error;
    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );
        for ( PWR_t PWR = PWR_Null; PWR < PWR_Count; ++PWR )
        {
            PWR_Context.Instance[ PWR ].PWR = PWR;
            if ( ( Status = PWR_Instance_Initialize( &PWR_Context.Instance[ PWR ] ) ) != PWR_Status_Success )
            {
                PWR_Warning( "PWR_%d Initialize Failed: Status %d", PWR, Status );
            }
        }
        Status = PWR_Status_Success;
    }
    while ( 0 );
    return Status;
}

static PWR_Status_t PWR_Context_Cycle( void )
{
    PWR_Status_t Status = PWR_Status_Error;
    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );
        for ( PWR_t PWR = PWR_Null; PWR < PWR_Count; ++PWR )
        {
            PWR_Context.Instance[ PWR ].PWR = PWR; // FIXME
            if ( ( Status = PWR_Instance_Cycle( &PWR_Context.Instance[ PWR ] ) ) != PWR_Status_Success )
            {
                PWR_Warning( "PWR_%d Cycle Failed: Status %d", PWR, Status );
            }
        }
        Status = PWR_Status_Success;
    }
    while ( 0 );
    return Status;
}

static PWR_Status_t PWR_Context_DeInitialize( void )
{
    PWR_Status_t Status = PWR_Status_Error;
    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );
        for ( PWR_t PWR = PWR_Null; PWR < PWR_Count; ++PWR )
        {
            PWR_Context.Instance[ PWR ].PWR = PWR; // FIXME
            if ( ( Status = PWR_Instance_DeInitialize( &PWR_Context.Instance[ PWR ] ) ) != PWR_Status_Success )
            {
                PWR_Warning( "PWR_%d DeInitialize Failed: Status %d", PWR, Status );
            }
        }
        Status = PWR_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

PWR_Status_t PWR_Initialize( void )
{
    PWR_Status_t Status = PWR_Status_Error;
    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );
        Status = PWR_Context_Initialize( );
    }
    while ( 0 );
    return Status;
}

PWR_Status_t PWR_Cycle( void )
{
    PWR_Status_t Status = PWR_Status_Error;
    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );
        Status = PWR_Context_Cycle( );
    }
    while ( 0 );
    return Status;
}

PWR_Status_t PWR_DeInitialize( void )
{
    PWR_Status_t Status = PWR_Status_Error;
    do
    {
        PWR_Trace( "%s( void )", __FUNCTION__ );
        Status = PWR_Context_DeInitialize( );
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char PWR_VERSION[] = "0.0.0.v20260117-1036";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
