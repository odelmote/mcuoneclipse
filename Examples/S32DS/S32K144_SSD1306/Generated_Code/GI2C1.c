/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : GI2C1.h
**     Project     : S32K144_SSD1306
**     Processor   : S32K144_100
**     Component   : GenericI2C
**     Version     : Component 01.048, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-12-31, 08:14, # CodeGen: 3
**     Abstract    :
**         This component implements a generic I2C driver wrapper to work both with LDD and non-LDD I2C components.
**     Settings    :
**          Component name                                 : GI2C1
**          Wait                                           : WAIT1
**          Support STOP_NOSTART                           : no
**          Write Buffer Size                              : 32
**          non-LDD I2C                                    : Enabled
**            I2C                                          : I2C1
**          LDD I2C                                        : Disabled
**          RTOS                                           : Disabled
**          Init() on startup                              : yes
**     Contents    :
**         SelectSlave       - uint8_t GI2C1_SelectSlave(uint8_t i2cAddr);
**         UnselectSlave     - uint8_t GI2C1_UnselectSlave(void);
**         RequestBus        - void GI2C1_RequestBus(void);
**         ReleaseBus        - void GI2C1_ReleaseBus(void);
**         WriteBlock        - uint8_t GI2C1_WriteBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags...
**         ReadBlock         - uint8_t GI2C1_ReadBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags...
**         ReadBlockGeneric  - uint8_t GI2C1_ReadBlockGeneric(void* data, uint16_t dataSize,...
**         ReadAddressWait   - uint8_t GI2C1_ReadAddressWait(uint8_t i2cAddr, uint8_t *memAddr, uint8_t...
**         ReadAddress       - uint8_t GI2C1_ReadAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t...
**         WriteAddress      - uint8_t GI2C1_WriteAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t...
**         ReadByte          - uint8_t GI2C1_ReadByte(uint8_t i2cAddr, uint8_t *data);
**         WriteByte         - uint8_t GI2C1_WriteByte(uint8_t i2cAddr, uint8_t data);
**         ReadByteAddress8  - uint8_t GI2C1_ReadByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t *data);
**         WriteByteAddress8 - uint8_t GI2C1_WriteByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t data);
**         ReadWordAddress8  - uint8_t GI2C1_ReadWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t...
**         WriteWordAddress8 - uint8_t GI2C1_WriteWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t...
**         ProbeACK          - uint8_t GI2C1_ProbeACK(void* data, uint16_t dataSize, GI2C1_EnumSendFlags...
**         GetSemaphore      - void* GI2C1_GetSemaphore(void);
**         ScanDevice        - uint8_t GI2C1_ScanDevice(uint8_t i2cAddr);
**         Deinit            - void GI2C1_Deinit(void);
**         Init              - void GI2C1_Init(void);
**
** * Copyright (c) 2013-2019, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file GI2C1.h
** @version 01.00
** @brief
**         This component implements a generic I2C driver wrapper to work both with LDD and non-LDD I2C components.
*/         
/*!
**  @addtogroup GI2C1_module GI2C1 module documentation
**  @{
*/         

/* MODULE GI2C1. */

#include "GI2C1.h"
#include "WAIT1.h"
#include "I2C1.h"

#ifndef NULL
  #define NULL 0L
#endif /* NULL */

#if GI2C1_CONFIG_USE_MUTEX
static SemaphoreHandle_t GI2C1_busSem = NULL; /* Semaphore to protect I2C bus access */
#endif
/*
** ===================================================================
**     Method      :  RequestBus (component GenericI2C)
**
**     Description :
**         Starts a critical section for accessing the bus.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GI2C1_RequestBus(void)
{
  /*lint -save -e522 function lacks side effect  */
#if GI2C1_CONFIG_USE_ON_REQUEST_BUS_EVENT
  GI2C1_CONFIG_ON_REQUEST_BUS_EVENT();
#endif
  /*lint -restore */
#if GI2C1_CONFIG_USE_MUTEX
  (void)xSemaphoreTakeRecursive(GI2C1_busSem, portMAX_DELAY);
#endif
}

/*
** ===================================================================
**     Method      :  ReleaseBus (component GenericI2C)
**
**     Description :
**         Finishes a critical section for accessing the bus.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GI2C1_ReleaseBus(void)
{
#if GI2C1_CONFIG_USE_MUTEX
  (void)xSemaphoreGiveRecursive(GI2C1_busSem);
#endif
  /*lint -save -e522 function lacks side effect  */
#if GI2C1_CONFIG_USE_ON_RELEASE_BUS_EVENT
  GI2C1_CONFIG_ON_RELEASE_BUS_EVENT();
#endif
  /*lint -restore */
}

/*
** ===================================================================
**     Method      :  SelectSlave (component GenericI2C)
**
**     Description :
**         Selects the slave device on the bus. Method might use a
**         semaphore to protect bus access.
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_SelectSlave(uint8_t i2cAddr)
{
  GI2C1_RequestBus();
  if (GI2C1_CONFIG_SELECT_SLAVE(i2cAddr)!=ERR_OK) {
    GI2C1_ReleaseBus();
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UnselectSlave (component GenericI2C)
**
**     Description :
**         Unselects the device. Method will release a used a semaphore.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_UnselectSlave(void)
{
  GI2C1_ReleaseBus();
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  ReadBlockGeneric (component GenericI2C)
**
**     Description :
**         Read from the device a block with using additional control
**         and flags.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Read buffer
**         dataSize        - Size of read buffer
**         flagsSend       - flags for the send transaction
**         flagsStart      - Start flags
**         flagsAck        - Acknowledge flags
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadBlockGeneric(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags, GI2C1_EnumStartFlags flagsStart, GI2C1_EnumAckFlags flagsAck)
{
  uint8_t res = ERR_OK;

#if GI2C1_CONFIG_RECV_BLOCK_CUSTOM_AVAILABLE
  for(;;) { /* breaks */
    uint16_t nof;

    res = GI2C1_CONFIG_RECV_BLOCK_CUSTOM(data, dataSize, &nof, flagsStart, flagsAck);
    if (res!=ERR_OK) {
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    if (flags==GI2C1_SEND_STOP) {
      res = GI2C1_CONFIG_SEND_STOP();
      if (res!=ERR_OK) {
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
    }
    break; /* break for(;;) */
  } /* for(;;) */
#else
  return ERR_FAILED; /* RecvBlockCustom() is not available (e.g. not available in the Hardware I2C component */
#endif
  return res;
}

/*
** ===================================================================
**     Method      :  ReadBlock (component GenericI2C)
**
**     Description :
**         Read from the device a block.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Read buffer
**         dataSize        - Size of read buffer
**         flags           - flags for the transaction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags)
{
  uint8_t res = ERR_OK;
  uint16_t nof;

  for(;;) { /* breaks */
    res = GI2C1_CONFIG_RECV_BLOCK(data, dataSize, &nof);
    if (res!=ERR_OK) {
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    if (flags==GI2C1_SEND_STOP) {
      res = GI2C1_CONFIG_SEND_STOP();
      if (res!=ERR_OK) {
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
    }
    break; /* break for(;;) */
  } /* for(;;) */
  return res;
}

/*
** ===================================================================
**     Method      :  WriteBlock (component GenericI2C)
**
**     Description :
**         Write a block to the device.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Data write buffer
**         dataSize        - 
**         flags           - flags for the transaction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_WriteBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags)
{
  uint16_t nof;
  uint8_t res = ERR_OK;

  for(;;) { /* breaks */
#if GI2C1_CONFIG_SUPPORT_STOP_NO_START
    if (GI2C1_STOP_NOSTART==flags) {
      res = GI2C1_CONFIG_SEND_BLOCK_CONTINUE(data, dataSize, &nof);
    } else {
      res = GI2C1_CONFIG_SEND_BLOCK(data, dataSize, &nof);
    }
#else
    res = GI2C1_CONFIG_SEND_BLOCK(data, dataSize, &nof);
#endif
    if (res!=ERR_OK) {
      (void)GI2C1_CONFIG_SEND_STOP();
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
      break; /* break for(;;) */
    }
    if (flags==GI2C1_SEND_STOP || (flags==GI2C1_STOP_NOSTART)) {
      res = GI2C1_CONFIG_SEND_STOP();
      if (res!=ERR_OK) {
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
    }
    break; /* break for(;;) */
  } /* for(;;) */
  return res;
}

/*
** ===================================================================
**     Method      :  ReadAddressWait (component GenericI2C)
**
**     Description :
**         Same as ReadAddress, but with an optional wait between the
**         address and read. Read from the device. This writes
**         (S+i2cAddr+0), (memAddr), (Sr+i2cAddr+1), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**       * memAddr         - Pointer to device memory address
**         memAddrSize     - number of address bytes
**         waitMs          - Wait time between the address part
**                           and reading the data part. Wait time can be
**                           zero.
**       * data            - Pointer to read buffer
**         dataSize        - Size of read buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadAddressWait(uint8_t i2cAddr, uint8_t *memAddr, uint8_t memAddrSize, uint16_t waitMs, uint8_t *data, uint16_t dataSize)
{
  uint8_t res = ERR_OK;
  uint16_t nof;

  if (GI2C1_SelectSlave(i2cAddr)!=ERR_OK) {
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  for(;;) { /* breaks */
    if(memAddr!=NULL) { /* only if we want to send an address */
      res = GI2C1_CONFIG_SEND_BLOCK((void*)memAddr, memAddrSize, &nof);
      if (res!=ERR_OK) {
        (void)GI2C1_CONFIG_SEND_STOP();
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
    }
    /* optional wait time */
    if (waitMs!=0) {
      WAIT1_WaitOSms(waitMs);
    }
    if (data!=NULL) {
      /* receive data */
      res = GI2C1_CONFIG_RECV_BLOCK(data, dataSize, &nof);
      if (res!=ERR_OK) {
        (void)GI2C1_CONFIG_SEND_STOP();
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
      res = GI2C1_CONFIG_SEND_STOP();
      if (res!=ERR_OK) {
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
    } /* if receive data */
    break; /* break for(;;) */
  } /* for(;;) */
  if (GI2C1_UnselectSlave()!=ERR_OK) {
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  return res;
}

/*
** ===================================================================
**     Method      :  ReadAddress (component GenericI2C)
**
**     Description :
**         Read from the device. This writes (S+i2cAddr+0), (memAddr),
**         (Sr+i2cAddr+1), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**       * memAddr         - Pointer to device memory address
**         memAddrSize     - number of address bytes
**       * data            - Pointer to read buffer
**         dataSize        - Size of read buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t memAddrSize, uint8_t *data, uint16_t dataSize)
{
  return GI2C1_ReadAddressWait(i2cAddr, memAddr, memAddrSize, 0, data, dataSize);
}

/*
** ===================================================================
**     Method      :  WriteAddress (component GenericI2C)
**
**     Description :
**         Write to the device: (S+i2cAddr+0), (memAddr), (data)...
**         (data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**       * memAddr         - Pointer to device memory address
**         memAddrSize     - number of address bytes
**       * data            - Pointer to data write buffer
**         dataSize        - Size of data buffer in bytes
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_WriteAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t memAddrSize, uint8_t *data, uint16_t dataSize)
{
  static uint8_t writeBuf[GI2C1_WRITE_BUFFER_SIZE];
  uint8_t *p;
  uint16_t i;
  uint16_t nof;
  uint8_t res = ERR_OK;

  if (GI2C1_SelectSlave(i2cAddr)!=ERR_OK) {
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  if (memAddrSize+dataSize>GI2C1_WRITE_BUFFER_SIZE) {
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  i = 0; p = memAddr;
  while(i<GI2C1_WRITE_BUFFER_SIZE && memAddrSize>0) {
    writeBuf[i++] = *p++;
    memAddrSize--;
  }
  p = data;
  while(i<GI2C1_WRITE_BUFFER_SIZE && dataSize>0) {
    writeBuf[i++] = *p++;
    dataSize--;
  }
  for(;;) { /* breaks */
    res = GI2C1_CONFIG_SEND_BLOCK((void*)writeBuf, i, &nof);
    if (res!=ERR_OK) {
      (void)GI2C1_CONFIG_SEND_STOP();
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    res = GI2C1_CONFIG_SEND_STOP();
    if (res!=ERR_OK) {
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    break; /* break for(;;) */
  } /* for(;;) */
  if (GI2C1_UnselectSlave()!=ERR_OK) {
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  return res;
}

/*
** ===================================================================
**     Method      :  Init (component GenericI2C)
**
**     Description :
**         Initializes the driver.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GI2C1_Init(void)
{
#if GI2C1_CONFIG_USE_MUTEX
  GI2C1_busSem = xSemaphoreCreateRecursiveMutex();
  if (GI2C1_busSem==NULL) { /* semaphore creation failed */
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    for(;;) {} /* error, not enough memory? */
  }
  vQueueAddToRegistry(GI2C1_busSem, "GI2C1_Mutex");
#endif
}

/*
** ===================================================================
**     Method      :  Deinit (component GenericI2C)
**
**     Description :
**         Deinitializes the driver.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GI2C1_Deinit(void)
{
#if GI2C1_CONFIG_USE_MUTEX
  vQueueUnregisterQueue(GI2C1_busSem);
  vSemaphoreDelete(GI2C1_busSem);
  GI2C1_busSem = NULL;
#endif
}

/*
** ===================================================================
**     Method      :  GetSemaphore (component GenericI2C)
**
**     Description :
**         Returns the currently allocated semaphore.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
void* GI2C1_GetSemaphore(void)
{
#if GI2C1_CONFIG_USE_MUTEX
  return GI2C1_busSem;
#else
  return NULL; /* RTOS and Semaphore enabled in properties */
#endif
}

/*
** ===================================================================
**     Method      :  ReadByteAddress8 (component GenericI2C)
**
**     Description :
**         Read a byte from the device using an 8bit memory address.
**         This writes (S+i2cAddr+0), (memAddr), (Sr+i2cAddr+1), (data)..
**         .(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**         memAddr         - Device memory address
**       * data            - Pointer to read buffer (single byte)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t *data)
{
  return GI2C1_ReadAddress(i2cAddr, &memAddr, sizeof(memAddr), data, 1);
}

/*
** ===================================================================
**     Method      :  WriteByteAddress8 (component GenericI2C)
**
**     Description :
**         Write a byte to the device using an 8bit memory address:
**         (S+i2cAddr+0), (memAddr), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**         memAddr         - Device memory address
**         data            - Data value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_WriteByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t data)
{
  return GI2C1_WriteAddress(i2cAddr, &memAddr, sizeof(memAddr), &data, sizeof(data));
}

/*
** ===================================================================
**     Method      :  ReadWordAddress8 (component GenericI2C)
**
**     Description :
**         Read a word from the device using an 8bit memory address.
**         This writes (S+i2cAddr+0), (memAddr), (Sr+i2cAddr+1), (data)..
**         .(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**         memAddr         - Device memory address
**       * data            - Pointer to read buffer (single byte)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t *data)
{
  return GI2C1_ReadAddress(i2cAddr, &memAddr, sizeof(memAddr), (uint8_t*)data, 2);
}

/*
** ===================================================================
**     Method      :  WriteWordAddress8 (component GenericI2C)
**
**     Description :
**         Write a word to the device using an 8bit memory address:
**         (S+i2cAddr+0), (memAddr), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**         memAddr         - Device memory address
**         data            - Data value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_WriteWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t data)
{
  return GI2C1_WriteAddress(i2cAddr, &memAddr, sizeof(memAddr), (uint8_t*)&data, sizeof(data));
}

/*
** ===================================================================
**     Method      :  ScanDevice (component GenericI2C)
**
**     Description :
**         Checks if a device responds on the bus with an ACK.
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - 7bit I2C device address
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ScanDevice(uint8_t i2cAddr)
{
  uint8_t res = ERR_OK;
  uint16_t nof;
  uint8_t dummy;

  if (GI2C1_SelectSlave(i2cAddr)!=ERR_OK) {
    return ERR_FAILED;
  }
  for(;;) { /* breaks */
    res = GI2C1_CONFIG_RECV_BLOCK((void*)&dummy, 1, &nof);
    if (res!=ERR_OK) {
      (void)GI2C1_CONFIG_SEND_STOP();
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    res = GI2C1_CONFIG_SEND_STOP();
    if (res!=ERR_OK) {
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    break; /* break for(;;) */
  } /* for(;;) */
  if (GI2C1_UnselectSlave()!=ERR_OK) {
  #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
    GI2C1_CONFIG_ON_ERROR_EVENT();
  #endif
    return ERR_FAILED;
  }
  return res;
}

/*
** ===================================================================
**     Method      :  ProbeACK (component GenericI2C)
**
**     Description :
**         Accesses the bus to check if the device responds with an ACK
**         (ACK polling).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Data write buffer
**         dataSize        - 
**         flags           - flags for the transaction
**         WaitTimeUS      - Waiting time in microseconds
**                           to wait for the ACK on the bus.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ProbeACK(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags, uint16_t WaitTimeUS)
{
  uint16_t nof;
  uint8_t res = ERR_OK;

  (void)WaitTimeUS; /* not used */
  for(;;) { /* breaks */
    res = GI2C1_CONFIG_SEND_BLOCK(data, dataSize, &nof);
    if (res!=ERR_OK) {
      (void)GI2C1_CONFIG_SEND_STOP();
    #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
      GI2C1_CONFIG_ON_ERROR_EVENT();
    #endif
      break; /* break for(;;) */
    }
    if (flags==GI2C1_SEND_STOP) {
      res = GI2C1_CONFIG_SEND_STOP();
      if (res!=ERR_OK) {
      #if GI2C1_CONFIG_USE_ON_ERROR_EVENT
        GI2C1_CONFIG_ON_ERROR_EVENT();
      #endif
        break; /* break for(;;) */
      }
    }
    break; /* break for(;;) */
  } /* for(;;) */
  return res;
}

/*
** ===================================================================
**     Method      :  ReadByte (component GenericI2C)
**
**     Description :
**         Read a byte from the device. This writes (S+i2cAddr+0),
**         (Sr+i2cAddr+1),(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**       * data            - Pointer to read buffer (single byte)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_ReadByte(uint8_t i2cAddr, uint8_t *data)
{
  return GI2C1_ReadAddress(i2cAddr, NULL, 0, data, 1);
}

/*
** ===================================================================
**     Method      :  WriteByte (component GenericI2C)
**
**     Description :
**         Write a byte to the device: (S+i2cAddr+0).(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**         data            - Data value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t GI2C1_WriteByte(uint8_t i2cAddr, uint8_t data)
{
  return GI2C1_WriteAddress(i2cAddr, NULL, 0, &data, 1);
}

/* END GI2C1. */

/*!
** @}
*/
