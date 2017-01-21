/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TmDt1.h
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : GenericTimeDate
**     Version     : Component 01.059, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-01-21, 09:50, # CodeGen: 37
**     Abstract    :
**         Software date/time module.
**     Settings    :
**          Component name                                 : TmDt1
**          Software RTC                                   : Enabled
**            Tick Time (ms)                               : 10
**            RTOS                                         : Enabled
**              RTOS                                       : FRTOS1
**          Hardware RTC                                   : Disabled
**          Set Time and Date                              : 
**            Software RTC                                 : yes
**            Internal RTC                                 : no
**            External RTC                                 : no
**          Get Time and Date                              : Software RTC
**          Init()                                         : 
**            Defaults                                     : 
**              Time                                       : 17:51:31
**              Date                                       : 2017-01-21
**            Call Init() in startup                       : yes
**            Software RTC Initialization                  : Init from Defaults
**          System                                         : 
**            Critical Section                             : CS1
**            Utility                                      : UTIL1
**            SDK                                          : MCUC1
**            Shell                                        : Enabled
**              Shell                                      : CLS1
**     Contents    :
**         AddTick                     - void TmDt1_AddTick(void);
**         AddTicks                    - void TmDt1_AddTicks(uint16_t nofTicks);
**         TicksToTime                 - uint8_t TmDt1_TicksToTime(uint32_t ticks, TIMEREC *time);
**         TimeToTicks                 - uint8_t TmDt1_TimeToTicks(TIMEREC *time, uint32_t *ticks);
**         CalculateDayOfWeek          - uint8_t TmDt1_CalculateDayOfWeek(uint16_t Year, uint8_t Month, uint8_t Day);
**         SetTime                     - uint8_t TmDt1_SetTime(uint8_t Hour, uint8_t Min, uint8_t Sec, uint8_t Sec100);
**         GetTime                     - uint8_t TmDt1_GetTime(TIMEREC *time);
**         SetDate                     - uint8_t TmDt1_SetDate(uint16_t Year, uint8_t Month, uint8_t Day);
**         GetDate                     - uint8_t TmDt1_GetDate(DATEREC *date);
**         SetTimeDate                 - uint8_t TmDt1_SetTimeDate(TIMEREC *time, DATEREC *date);
**         GetTimeDate                 - uint8_t TmDt1_GetTimeDate(TIMEREC *time, DATEREC *date);
**         SetSWTimeDate               - uint8_t TmDt1_SetSWTimeDate(TIMEREC *time, DATEREC *date);
**         GetSWTimeDate               - uint8_t TmDt1_GetSWTimeDate(TIMEREC *time, DATEREC *date);
**         SetInternalRTCTimeDate      - uint8_t TmDt1_SetInternalRTCTimeDate(TIMEREC *time, DATEREC *date);
**         GetInternalRTCTimeDate      - uint8_t TmDt1_GetInternalRTCTimeDate(TIMEREC *time, DATEREC *date);
**         SyncWithInternalRTC         - uint8_t TmDt1_SyncWithInternalRTC(void);
**         SetExternalRTCTimeDate      - uint8_t TmDt1_SetExternalRTCTimeDate(TIMEREC *time, DATEREC *date);
**         GetExternalRTCTimeDate      - uint8_t TmDt1_GetExternalRTCTimeDate(TIMEREC *time, DATEREC *date);
**         SyncWithExternalRTC         - uint8_t TmDt1_SyncWithExternalRTC(void);
**         UnixSecondsToTimeDateCustom - void TmDt1_UnixSecondsToTimeDateCustom(int32_t seconds, int8_t offset_hours,...
**         UnixSecondsToTimeDate       - void TmDt1_UnixSecondsToTimeDate(int32_t seconds, int8_t offset_hours,...
**         TimeDateToUnixSecondsCustom - int32_t TmDt1_TimeDateToUnixSecondsCustom(TIMEREC *time, DATEREC *date,...
**         TimeDateToUnixSeconds       - int32_t TmDt1_TimeDateToUnixSeconds(TIMEREC *time, DATEREC *date, int8_t...
**         AddDateString               - uint8_t TmDt1_AddDateString(uint8_t *buf, size_t bufSize, DATEREC *date,...
**         AddTimeString               - uint8_t TmDt1_AddTimeString(uint8_t *buf, size_t bufSize, TIMEREC *time,...
**         ParseCommand                - uint8_t TmDt1_ParseCommand(const unsigned char *cmd, bool *handled, const...
**         DeInit                      - void TmDt1_DeInit(void);
**         Init                        - uint8_t TmDt1_Init(void);
**
**     * Copyright (c) 2011-2016, Erich Styger
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
** @file TmDt1.h
** @version 01.00
** @brief
**         Software date/time module.
*/         
/*!
**  @addtogroup TmDt1_module TmDt1 module documentation
**  @{
*/         

#ifndef __TmDt1_H
#define __TmDt1_H

/* MODULE TmDt1. */
#include "MCUC1.h" /* SDK and API used */
#include "TmDt1config.h" /* configuration */

/* Include inherited components */
#include "FRTOS1.h"
#include "CS1.h"
#include "UTIL1.h"
#include "MCUC1.h"
#include "CLS1.h"


/* if command line parser is enabled */
#define TmDt1_PARSE_COMMAND_ENABLED  1  /* set to 1 if method ParseCommand() is present, 0 otherwise */

/* if Init() is called durint startup */
#define TmDt1_INIT_IN_STARTUP                               1 /* 1: call Init() during startup, 0: application needs to call Init() */

/* RTC Initialization options during Init() */
#define TmDt1_INIT_SOFTWARE_RTC_FROM_DEFAULTS               1  /* init software RTC from default values */
#define TmDt1_INIT_SOFTWARE_RTC_FROM_INTERNAL_RTC           1  /* init software RTC from internal RTC values */
#define TmDt1_INIT_SOFTWARE_RTC_FROM_EXTERNAL_RTC           1  /* init software RTC from external RTC values */

/* settings for software RTC */
#define TmDt1_USE_SOFTWARE_RTC                              1  /* set to 1 if using software RTC, 0 otherwise */
#define TmDt1_INIT_SOFTWARE_RTC_METHOD                      TmDt1_INIT_SOFTWARE_RTC_FROM_DEFAULTS /* which method to use during Init() */

/* settings for internal hardware RTC */
#define TmDt1_USE_INTERNAL_HW_RTC                           0  /* set to 1 if using internal HW RTC, 0 otherwise */
#define TmDt1_USE_INTERNAL_HW_RTC_BEAN                      0  /* set to 1 if using HW RTC using normal bean driver, 0 otherwise */
#define TmDt1_USE_INTERNAL_HW_RTC_LDD                       0  /* set to 1 if using HW RTC using LDD driver, 0 otherwise */

#define TmDt1_USE_EXTERNAL_HW_RTC                           0  /* set to 1 if using external HW RTC driver, 0 otherwise */

#if TmDt1_USE_INTERNAL_HW_RTC_BEAN
  #define TmDt1_HAS_SEC100_IN_TIMEREC                       0 /* Bean version have no Sec100!  */
#else
  #define TmDt1_HAS_SEC100_IN_TIMEREC                       1 /* non-Bean version have Sec100  */
#endif

/* SetTime() and SetDate() configuration */
#define TmDt1_SET_TIME_DATE_METHOD_USES_SOFTWARE_RTC        1 /* 1: Enable setting software RTC time/date */
#define TmDt1_SET_TIME_DATE_METHOD_USES_INTERNAL_RTC        0 /* 1: Enable setting internal RTC time/date */
#define TmDt1_SET_TIME_DATE_METHOD_USES_EXTERNAL_RTC        0 /* 1: Enable setting external RTC time/date */

/* GetTime() and GetDate() configuration */
#define TmDt1_GET_TIME_DATE_METHOD_SOFTWARE_RTC             1 /* use software RTC */
#define TmDt1_GET_TIME_DATE_METHOD_INTERNAL_RTC             2 /* use internal RTC */
#define TmDt1_GET_TIME_DATE_METHOD_EXTERNAL_RTC             3 /* use external RTC */
#define TmDt1_USE_GET_TIME_DATE_METHOD                      TmDt1_GET_TIME_DATE_METHOD_SOFTWARE_RTC /* specifies method to get time and date */

/* default time and date format strings */
#define TmDt1_DEFAULT_TIME_FORMAT_STR  "hh:mm:ss,cc"
#define TmDt1_DEFAULT_DATE_FORMAT_STR  "dd.mm.yyyy"

/* user events */
#define TmDt1_ON_DATE_GET_EVENT                             0 /* 1: enabled user event */
#define TmDt1_ON_DATE_GET_EVENT_NAME                        TmDt1_OnDateGet /* name of user event*/
#define TmDt1_ON_TIME_GET_EVENT                             0 /* 1: enabled user event */
#define TmDt1_ON_TIME_GET_EVENT_NAME                        TmDt1_OnTimeGet /* name of user event*/
#define TmDt1_ON_DATE_SET_EVENT                             0 /* 1: enabled user event */
#define TmDt1_ON_DATE_SET_EVENT_NAME                        TmDt1_OnDateSet /* name of user event*/
#define TmDt1_ON_TIME_SET_EVENT                             0 /* 1: enabled user event */
#define TmDt1_ON_TIME_SET_EVENT_NAME                        TmDt1_OnTimeSet /* name of user event*/


#ifndef __BWUserType_TIMEREC
#define __BWUserType_TIMEREC
  typedef struct {                     /* It contains actual number of hours, minutes, seconds and hundreth of seconds. */
    uint8_t Hour;                      /* hours (0 - 23) */
    uint8_t Min;                       /* minutes (0 - 59) */
    uint8_t Sec;                       /* seconds (0 - 59) */
  #if TmDt1_HAS_SEC100_IN_TIMEREC /* does not exist for Bean version */
    uint8_t Sec100;                    /* hundredth of seconds (0 - 99) */
  #endif
  } TIMEREC;
#endif
#ifndef __BWUserType_DATEREC
#define __BWUserType_DATEREC
  typedef struct {                     /* It contains actual year, month, and day description. */
    uint16_t Year;                     /* years (1998 - 2099) */
    uint8_t Month;                     /* months (1 - 12) */
    uint8_t Day;                       /* days (1 - 31) */
  } DATEREC;
#endif

/* default time/date values */
static const TIMEREC TmDt1_DefaultTime = {
  17, /* hour */
  51,  /* minute */
  31,  /* second */
#if TmDt1_HAS_SEC100_IN_TIMEREC
  0 /* h-second */
#endif
};
static const DATEREC TmDt1_DefaultDate = {
  2017, /* year */
  1,  /* month */
  21 /* day */
};

#define TmDt1_TICK_TIME_MS \
  (1000/100)                            /* Period in milliseconds as defined in RTOS component properties, at which TmDt1_AddTick() is called */





uint8_t TmDt1_SetTime(uint8_t Hour, uint8_t Min, uint8_t Sec, uint8_t Sec100);
/*
** ===================================================================
**     Method      :  TmDt1_SetTime (component GenericTimeDate)
**     Description :
**         This method sets a new actual time of the software RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Hour            - Hours (0 - 23)
**         Min             - Minutes (0 - 59)
**         Sec             - Seconds (0 - 59)
**         Sec100          - Hundredth of seconds (0 - 99)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void TmDt1_AddTick(void);
/*
** ===================================================================
**     Method      :  TmDt1_AddTick (component GenericTimeDate)
**     Description :
**         Increments the tick counter of the software RTC. Needs to be
**         called periodically by the application to increase the time
**         tick count.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t TmDt1_GetTime(TIMEREC *time);
/*
** ===================================================================
**     Method      :  TmDt1_GetTime (component GenericTimeDate)
**     Description :
**         This method returns current time from the software RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to the structure TIMEREC. It
**                           contains actual number of hours, minutes,
**                           seconds and hundredth of seconds.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SetDate(uint16_t Year, uint8_t Month, uint8_t Day);
/*
** ===================================================================
**     Method      :  TmDt1_SetDate (component GenericTimeDate)
**     Description :
**         This method sets a new actual date of the software RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Year            - Years (16-bit unsigned integer)
**         Month           - Months (8-bit unsigned integer)
**         Day             - Days (8-bit unsigned integer)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_GetDate(DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_GetDate (component GenericTimeDate)
**     Description :
**         This method returns current date from the software RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * date            - Pointer to DATEREC
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_Init(void);
/*
** ===================================================================
**     Method      :  TmDt1_Init (component GenericTimeDate)
**     Description :
**         Initialization method
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
/*
** ===================================================================
**     Method      :  TmDt1_ParseCommand (component GenericTimeDate)
**     Description :
**         Shell Command Line parser
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command line
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**       * io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void TmDt1_DeInit(void);
/*
** ===================================================================
**     Method      :  TmDt1_DeInit (component GenericTimeDate)
**     Description :
**         Deinitializes the driver.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TmDt1_AddTicks(uint16_t nofTicks);
/*
** ===================================================================
**     Method      :  TmDt1_AddTicks (component GenericTimeDate)
**     Description :
**         Same as AddTick(), but multiple ticks can be added in one
**         step.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nofTicks        - Number of ticks to be added
**     Returns     : Nothing
** ===================================================================
*/

uint8_t TmDt1_TicksToTime(uint32_t ticks, TIMEREC *time);
/*
** ===================================================================
**     Method      :  TmDt1_TicksToTime (component GenericTimeDate)
**     Description :
**         Transforms ticks into time information
**     Parameters  :
**         NAME            - DESCRIPTION
**         ticks           - 
**       * time            - Pointer where to store the time
**                           information
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_TimeToTicks(TIMEREC *time, uint32_t *ticks);
/*
** ===================================================================
**     Method      :  TmDt1_TimeToTicks (component GenericTimeDate)
**     Description :
**         Transforms time information into ticks
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer where to time information
**       * ticks           - Pointer to where to store the ticks
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SetInternalRTCTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_SetInternalRTCTimeDate (component GenericTimeDate)
**     Description :
**         This method sets a new actual time and date of the internal
**         hardware RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to struct which contains the
**                           time to be set. Can be NULL if time shall
**                           not be set.
**       * date            - Pointer to struct which contains the
**                           date information to be set. Can be NULL if
**                           date shall not be set.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_GetInternalRTCTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_GetInternalRTCTimeDate (component GenericTimeDate)
**     Description :
**         This method returns current time and date from the hardware
**         RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to the structure to return the
**                           time. Can be NULL.
**       * date            - Pointer to structure which returns the
**                           date information. Can be NULL
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_CalculateDayOfWeek(uint16_t Year, uint8_t Month, uint8_t Day);
/*
** ===================================================================
**     Method      :  TmDt1_CalculateDayOfWeek (component GenericTimeDate)
**     Description :
**         Returns the day of the week, Sunday starting as zero. Monday
**         is 1, ...
**     Parameters  :
**         NAME            - DESCRIPTION
**         Year            - Years (16-bit unsigned integer)
**         Month           - Months (8-bit unsigned integer)
**         Day             - Days (8-bit unsigned integer)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SetSWTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_SetSWTimeDate (component GenericTimeDate)
**     Description :
**         This method sets a new actual time and date of the software
**         RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to struct which contains the
**                           time to be set. Can be NULL if time shall
**                           not be set.
**       * date            - Pointer to struct which contains the
**                           date information to be set. Can be NULL if
**                           date shall not be set.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_GetSWTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_GetSWTimeDate (component GenericTimeDate)
**     Description :
**         This method returns current time and date from the software
**         RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to the structure to return the
**                           time. Can be NULL.
**       * date            - Pointer to structure which returns the
**                           date information. Can be NULL
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SyncWithInternalRTC(void);
/*
** ===================================================================
**     Method      :  TmDt1_SyncWithInternalRTC (component GenericTimeDate)
**     Description :
**         Synchronizes the software RTC with date and time from the
**         internal hardware RTC
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SyncWithExternalRTC(void);
/*
** ===================================================================
**     Method      :  TmDt1_SyncWithExternalRTC (component GenericTimeDate)
**     Description :
**         Synchronizes the software RTC with date and time from the
**         hardware RTC. Note that if that RTC interface requires
**         interrupts, this function should be called only when
**         interrupts are enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SetExternalRTCTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_SetExternalRTCTimeDate (component GenericTimeDate)
**     Description :
**         This method sets a new actual time and date of the external
**         hardware RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to struct which contains the
**                           time to be set. Can be NULL if time shall
**                           not be set.
**       * date            - Pointer to struct which contains the
**                           date information to be set. Can be NULL if
**                           date shall not be set.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_GetExternalRTCTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_GetExternalRTCTimeDate (component GenericTimeDate)
**     Description :
**         This method returns current time and date from the external
**         hardware RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to the structure to return the
**                           time. Can be NULL.
**       * date            - Pointer to structure which returns the
**                           date information. Can be NULL
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_SetTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_SetTimeDate (component GenericTimeDate)
**     Description :
**         This method sets a new actual time and date of the RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to struct which contains the
**                           time to be set. Can be NULL if time shall
**                           not be set.
**       * date            - Pointer to struct which contains the
**                           date information to be set. Can be NULL if
**                           date shall not be set.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t TmDt1_GetTimeDate(TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_GetTimeDate (component GenericTimeDate)
**     Description :
**         This method returns current time and date from the RTC.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to the structure to return the
**                           time. Can be NULL.
**       * date            - Pointer to structure which returns the
**                           date information. Can be NULL
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void TmDt1_UnixSecondsToTimeDateCustom(int32_t seconds, int8_t offset_hours, TIMEREC *time, DATEREC *date, uint16_t baseYear);
/*
** ===================================================================
**     Method      :  TmDt1_UnixSecondsToTimeDateCustom (component GenericTimeDate)
**     Description :
**         Transforms a given time/date into the Unix time stamp, with
**         the number of seconds from a starting date
**     Parameters  :
**         NAME            - DESCRIPTION
**         seconds         - Unix time stamp in seconds after
**                           the given base year and base month
**         offset_hours    - Optional time zone
**                           offset, use 0 for no offset
**       * time            - Pointer to TIMEREC struct where the
**                           result is stored. Can be NULL.
**       * date            - Pointer to DATEREC struct where the
**                           result is stored. Can be NULL.
**         baseYear        - Base year from which is used as
**                           base to count the seconds, in YYYY format.
**     Returns     : Nothing
** ===================================================================
*/

int32_t TmDt1_TimeDateToUnixSecondsCustom(TIMEREC *time, DATEREC *date, int8_t offset_hours, uint16_t baseYear);
/*
** ===================================================================
**     Method      :  TmDt1_TimeDateToUnixSecondsCustom (component GenericTimeDate)
**     Description :
**         Returns for a given time/date the corresponding UNIX time
**         stamp with a custom base date.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to TIMEREC which holds the time
**                           to convert
**       * date            - Pointer to DATEREC with the date to
**                           convert
**         offset_hours    - Optional number of
**                           offset hours to adjust for the time zone.
**                           Use 0 for no adjustment.
**         baseYear        - Base year from which is used as
**                           base to count the seconds, in YYYY format
**     Returns     :
**         ---             - number of seconds after given base
**                           month/year
** ===================================================================
*/

void TmDt1_UnixSecondsToTimeDate(int32_t seconds, int8_t offset_hours, TIMEREC *time, DATEREC *date);
/*
** ===================================================================
**     Method      :  TmDt1_UnixSecondsToTimeDate (component GenericTimeDate)
**     Description :
**         Transforms a given time/date into the Unix time stamp, with
**         the number of seconds after 1-Jan-1970
**     Parameters  :
**         NAME            - DESCRIPTION
**         seconds         - Unix time stamp in seconds after
**                           the given base year and base month
**         offset_hours    - Optional time zone
**                           offset, use 0 for no offset
**       * time            - Pointer to TIMEREC struct where the
**                           result is stored. Can be NULL.
**       * date            - Pointer to DATEREC struct where the
**                           result is stored. Can be NULL.
**     Returns     : Nothing
** ===================================================================
*/

int32_t TmDt1_TimeDateToUnixSeconds(TIMEREC *time, DATEREC *date, int8_t offset_hours);
/*
** ===================================================================
**     Method      :  TmDt1_TimeDateToUnixSeconds (component GenericTimeDate)
**     Description :
**         Returns for a given time/date the corresponding UNIX time
**         stamp, starting at 1-Jan-1970.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * time            - Pointer to TIMEREC which holds the time
**                           to convert
**       * date            - Pointer to DATEREC with the date to
**                           convert
**         offset_hours    - Optional number of
**                           offset hours to adjust for the time zone.
**                           Use 0 for no adjustment.
**     Returns     :
**         ---             - number of seconds after given base
**                           month/year
** ===================================================================
*/

uint8_t TmDt1_AddDateString(uint8_t *buf, size_t bufSize, DATEREC *date, uint8_t *format);
/*
** ===================================================================
**     Method      :  TmDt1_AddDateString (component GenericTimeDate)
**     Description :
**         Adds a formatted date string to a buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buf             - Pointer to zero terminated buffer where to
**                           append the string
**         bufSize         - Size of the buffer in bytes
**       * date            - Pointer to date information
**       * format          - Pointer to the format string.
**                           Supported formats: "dd.mm.yyyy"
**     Returns     :
**         ---             - Error code, ERR_OK for no error
** ===================================================================
*/

uint8_t TmDt1_AddTimeString(uint8_t *buf, size_t bufSize, TIMEREC *time, uint8_t *format);
/*
** ===================================================================
**     Method      :  TmDt1_AddTimeString (component GenericTimeDate)
**     Description :
**         Adds a formatted time string to a buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buf             - Pointer to zero terminated buffer where to
**                           append the string
**         bufSize         - Size of the buffer in bytes
**       * time            - Pointer to time information
**       * format          - Pointer to the format string.
**                           Supported formats: "hh:mm.ss,cc"
**     Returns     :
**         ---             - Error code, ERR_OK for no error
** ===================================================================
*/

/* END TmDt1. */

#endif
/* ifndef __TmDt1_H */
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
