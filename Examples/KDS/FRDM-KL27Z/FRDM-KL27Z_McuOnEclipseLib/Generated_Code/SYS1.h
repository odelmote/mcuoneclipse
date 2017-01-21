/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : SYS1.h
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : SeggerSystemView
**     Version     : Component 01.051, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-01-21, 10:06, # CodeGen: 42
**     Abstract    :
**
**     Settings    :
**          Component name                                 : SYS1
**          Version                                        : V2.40
**          Application Name                               : "Demo Application"
**          Device Name                                    : "KL27Z"
**          RAM Base                                       : 0x1FFFF000
**          ID Base                                        : 0x10000000
**          ID Shift                                       : 2
**          Number of tasks                                : 8
**          Static Buffer                                  : yes
**          Post Mortem                                    : no
**          RTT Channel                                    : 
**            Segger RTT                                   : RTT1
**            Name                                         : "SysView"
**            Channel Index                                : 1
**            Up Buffer size                               : 256
**          SDK                                            : MCUC1
**          Source Folders                                 : 
**            Source Folder                                : ../SEGGER
**            Config Folder                                : 
**     Contents    :
**         OnUserStart    - void SYS1_OnUserStart(unsigned UserId);
**         OnUserStop     - void SYS1_OnUserStop(unsigned UserId);
**         RecordEnterISR - void SYS1_RecordEnterISR(void);
**         RecordExitISR  - void SYS1_RecordExitISR(void);
**         Print          - void SYS1_Print(const char *s);
**         PrintfHost     - void SYS1_PrintfHost(const char *s, ...);
**         PrintfTarget   - void SYS1_PrintfTarget(const char *s, ...);
**         Warn           - void SYS1_Warn(const char *s);
**         WarnfHost      - void SYS1_WarnfHost(const char *s, ...);
**         WarnfTarget    - void SYS1_WarnfTarget(const char *s, ...);
**         Error          - void SYS1_Error(const char *s);
**         ErrorfHost     - void SYS1_ErrorfHost(const char *s, ...);
**         ErrorfTarget   - void SYS1_ErrorfTarget(const char *s, ...);
**         EnableEvents   - void SYS1_EnableEvents(uint32_t EnableMask);
**         DisableEvents  - void SYS1_DisableEvents(uint32_t DisableMask);
**         Init           - void SYS1_Init(void);
**
**     * (c) Copyright Segger, 2016
**      * http      : www.segger.com
**      * See separate Segger licensing terms.
**      *
**      * Processor Expert port: Copyright (c) 2016, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file SYS1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup SYS1_module SYS1 module documentation
**  @{
*/         

#ifndef __SYS1_H
#define __SYS1_H

/* MODULE SYS1. */
#include "MCUC1.h" /* SDK and API used */
#include "SYS1config.h" /* configuration */

/* Include inherited components */
#include "RTT1.h"
#include "MCUC1.h"

#include "SEGGER_SYSVIEW.h"




void SYS1_Init(void);
/*
** ===================================================================
**     Method      :  SYS1_Init (component SeggerSystemView)
**     Description :
**         Driver Initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_OnUserStart(UserId) \
  SEGGER_SYSVIEW_OnUserStart(UserId)

/*
** ===================================================================
**     Method      :  SYS1_OnUserStart (component SeggerSystemView)
**     Description :
**         Send a user event start, such as start of a subroutine for
**         profiling.
**     Parameters  :
**         NAME            - DESCRIPTION
**         UserId          - User defined ID for the event
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_OnUserStop(UserId) \
  SEGGER_SYSVIEW_OnUserStop(UserId)

/*
** ===================================================================
**     Method      :  SYS1_OnUserStop (component SeggerSystemView)
**     Description :
**         Send a user event stop, such as return of a subroutine for
**         profiling.
**     Parameters  :
**         NAME            - DESCRIPTION
**         UserId          - User defined ID for the event
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_RecordEnterISR() \
  SEGGER_SYSVIEW_RecordEnterISR()
/*
** ===================================================================
**     Method      :  SYS1_RecordEnterISR (component SeggerSystemView)
**     Description :
**         Records the enter of an ISR. Place this call at the
**         beginning of the interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_RecordExitISR() \
  SEGGER_SYSVIEW_RecordExitISR()
/*
** ===================================================================
**     Method      :  SYS1_RecordExitISR (component SeggerSystemView)
**     Description :
**         Records the end of the ISR. Call this function at the end of
**         the ISR to be recorded.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_Print(s) \
  SEGGER_SYSVIEW_Print(s)
/*
** ===================================================================
**     Method      :  SYS1_Print (component SeggerSystemView)
**     Description :
**         Prints a string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_Warn(s) \
  SEGGER_SYSVIEW_Warn(s)
/*
** ===================================================================
**     Method      :  SYS1_Warn (component SeggerSystemView)
**     Description :
**         Prints a warning string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_Error(s) \
  SEGGER_SYSVIEW_Error(s)
/*
** ===================================================================
**     Method      :  SYS1_Error (component SeggerSystemView)
**     Description :
**         Prints an error string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_PrintfHost    SEGGER_SYSVIEW_PrintfHost
/*
** ===================================================================
**     Method      :  SYS1_PrintfHost (component SeggerSystemView)
**     Description :
**         Prints a string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_PrintfTarget   SEGGER_SYSVIEW_PrintfTarget
/*
** ===================================================================
**     Method      :  SYS1_PrintfTarget (component SeggerSystemView)
**     Description :
**         Prints a string using printf() to the host which is
**         processed target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_WarnfHost  SEGGER_SYSVIEW_WarnfHost
/*
** ===================================================================
**     Method      :  SYS1_WarnfHost (component SeggerSystemView)
**     Description :
**         Prints a warning string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_WarnfTarget   SEGGER_SYSVIEW_WarnfTarget
/*
** ===================================================================
**     Method      :  SYS1_WarnfTarget (component SeggerSystemView)
**     Description :
**         Prints a warning string using printf() to the host which is
**         processed on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_ErrorfHost   SEGGER_SYSVIEW_ErrorfHost
/*
** ===================================================================
**     Method      :  SYS1_ErrorfHost (component SeggerSystemView)
**     Description :
**         Prints an error string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_ErrorfTarget   SEGGER_SYSVIEW_ErrorfTarget
/*
** ===================================================================
**     Method      :  SYS1_ErrorfTarget (component SeggerSystemView)
**     Description :
**         Prints an error string using printf() to the host which is
**         processed on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_DisableEvents(DisableMask) \
  SEGGER_SYSVIEW_EnableEvents(DisableMask)

/*
** ===================================================================
**     Method      :  SYS1_DisableEvents (component SeggerSystemView)
**     Description :
**         Disable standard SystemView events to not be generated.
**     Parameters  :
**         NAME            - DESCRIPTION
**         DisableMask     - Events to be disabled.
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_EnableEvents(EnableMask) \
  SEGGER_SYSVIEW_EnableEvents(EnableMask)

/*
** ===================================================================
**     Method      :  SYS1_EnableEvents (component SeggerSystemView)
**     Description :
**         Enables standard SystemView events to be generated.
**     Parameters  :
**         NAME            - DESCRIPTION
**         EnableMask      - Events to be enabled
**     Returns     : Nothing
** ===================================================================
*/

/* END SYS1. */

#endif
/* ifndef __SYS1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
