/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LCD1.h
**     Project     : S32K144_SSD1306
**     Processor   : S32K144_100
**     Component   : SSD1306
**     Version     : Component 01.044, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-12-31, 08:14, # CodeGen: 3
**     Abstract    :
**         Display driver for the SSD1306 OLED module
**     Settings    :
**          Component name                                 : LCD1
**          Type                                           : 128x64
**          Driver                                         : SH1106
**          Orientation                                    : landscape
**          Width                                          : 128
**          Height                                         : 64
**          Bytes in rows                                  : no
**          Bytes in x direction                           : yes
**          MSB first                                      : no
**          Bits per pixel                                 : 1
**          Window capability                              : no
**          Display Memory Write                           : no
**          Display Memory Read                            : no
**          Use RAM Buffer                                 : yes
**          Clear display in init                          : no
**          Initialize on Init                             : yes
**          Init Delay (ms)                                : 5
**          HW                                             : 
**            I2C Device Address                           : 0x3C
**            I2C Transaction Delay (us)                   : 100
**            Bock Transfer                                : yes
**            I2C                                          : GI2C1
**            Reset                                        : Disabled
**          System                                         : 
**            Wait                                         : WAIT1
**            SDK                                          : MCUC1
**     Contents    :
**         GetWidth        - LCD1_PixelDim LCD1_GetWidth(void);
**         GetHeight       - LCD1_PixelDim LCD1_GetHeight(void);
**         GetLongerSide   - LCD1_PixelDim LCD1_GetLongerSide(void);
**         GetShorterSide  - LCD1_PixelDim LCD1_GetShorterSide(void);
**         PutPixel        - void LCD1_PutPixel(LCD1_PixelDim x, LCD1_PixelDim y, LCD1_PixelColor color);
**         Clear           - void LCD1_Clear(void);
**         UpdateFull      - void LCD1_UpdateFull(void);
**         UpdateRegion    - void LCD1_UpdateRegion(LCD1_PixelDim x, LCD1_PixelDim y, LCD1_PixelDim w,...
**         InitCommChannel - void LCD1_InitCommChannel(void);
**         SetContrast     - uint8_t LCD1_SetContrast(uint8_t contrast);
**         DisplayOn       - uint8_t LCD1_DisplayOn(bool on);
**         DisplayInvert   - uint8_t LCD1_DisplayInvert(bool invert);
**         GetLCD          - void LCD1_GetLCD(void);
**         GiveLCD         - void LCD1_GiveLCD(void);
**         SetRowCol       - uint8_t LCD1_SetRowCol(uint8_t row, uint8_t col);
**         PrintString     - void LCD1_PrintString(uint8_t line, uint8_t col, uint8_t *str);
**         ClearLine       - void LCD1_ClearLine(uint8_t line);
**         Deinit          - void LCD1_Deinit(void);
**         Init            - void LCD1_Init(void);
**
** * Copyright (c) 2017-2019, Erich Styger
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
** @file LCD1.h
** @version 01.00
** @brief
**         Display driver for the SSD1306 OLED module
*/         
/*!
**  @addtogroup LCD1_module LCD1 module documentation
**  @{
*/         

#ifndef __LCD1_H
#define __LCD1_H

/* MODULE LCD1. */
#include "MCUC1.h" /* SDK and API used */
#include "LCD1config.h" /* configuration */
#include <stddef.h> /* for size_t */


#if LCD1_CONFIG_SSD1306_SIZE_TYPE==12864
  #define LCD1_DISPLAY_HW_NOF_COLUMNS  128u /* number of columns in hardware */
  #define LCD1_DISPLAY_HW_NOF_ROWS      64u /* number of rows in hardware */
  #define LCD1_DISPLAY_HW_NOF_PAGES      8u /* number of pages in hardware */
#elif LCD1_CONFIG_SSD1306_SIZE_TYPE==12832
  #define LCD1_DISPLAY_HW_NOF_COLUMNS  128u /* number of columns in hardware */
  #define LCD1_DISPLAY_HW_NOF_ROWS      32u /* number of rows in hardware */
  #define LCD1_DISPLAY_HW_NOF_PAGES      4u /* number of pages in hardware */
#else
  #error "unknown display type, must be 128x64 or 128x32"
#endif

typedef bool LCD1_PixelColor;          /* type to hold color information */
typedef uint8_t LCD1_PixelDim;         /* one byte is enough to describe the x/y position */
typedef uint16_t LCD1_PixelCount;      /* needed type to hold the number of pixels on the display. */

extern uint8_t LCD1_DisplayBuf[((LCD1_DISPLAY_HW_NOF_ROWS-1)/8)+1][LCD1_DISPLAY_HW_NOF_COLUMNS]; /* buffer for the display */

#define LCD1_PIXEL_BLACK  0 /* 0 is a black pixel */
#define LCD1_PIXEL_WHITE  1 /* 1 is a color/white pixel */
#define LCD1_COLOR_PIXEL_SET      LCD1_PIXEL_WHITE /* color for a pixel set */
#define LCD1_COLOR_PIXEL_CLR      LCD1_PIXEL_BLACK /* color for a pixel cleared */

#define LCD1_COLOR_BLACK          LCD1_PIXEL_BLACK
#define LCD1_COLOR_WHITE          LCD1_PIXEL_WHITE
#define LCD1_COLOR_RED            LCD1_PIXEL_WHITE
#define LCD1_COLOR_BRIGHT_RED     LCD1_COLOR_WHITE
#define LCD1_COLOR_DARK_RED       LCD1_PIXEL_WHITE
#define LCD1_COLOR_GREEN          LCD1_PIXEL_WHITE
#define LCD1_COLOR_BRIGHT_GREEN   LCD1_PIXEL_WHITE
#define LCD1_COLOR_DARK_GREEN     LCD1_PIXEL_WHITE
#define LCD1_COLOR_BLUE           LCD1_PIXEL_WHITE
#define LCD1_COLOR_BRIGHT_BLUE    LCD1_PIXEL_WHITE
#define LCD1_COLOR_DARK_BLUE      LCD1_PIXEL_WHITE
#define LCD1_COLOR_YELLOW         LCD1_PIXEL_WHITE
#define LCD1_COLOR_BRIGHT_YELLOW  LCD1_PIXEL_WHITE
#define LCD1_COLOR_ORANGE         LCD1_PIXEL_WHITE
#define LCD1_COLOR_GREY           LCD1_PIXEL_WHITE
#define LCD1_COLOR_BRIGHT_GREY    LCD1_PIXEL_WHITE

#define LCD1_PIXEL_ON  LCD1_COLOR_WHITE /* value of a pixel if it is 'on' */
#define LCD1_PIXEL_OFF LCD1_COLOR_BLACK /* value of a pixel if it is 'off' */

#define LCD1_HW_LONGER_SIDE  LCD1_DISPLAY_HW_NOF_COLUMNS                        /* Hardware display longer side in pixels */
#define LCD1_HW_SHORTER_SIDE LCD1_DISPLAY_HW_NOF_ROWS                           /* Hardware display shorter side in pixels */

typedef enum {
  LCD1_ORIENTATION_PORTRAIT    = 0,
  LCD1_ORIENTATION_PORTRAIT180 = 1,
  LCD1_ORIENTATION_LANDSCAPE   = 2,
  LCD1_ORIENTATION_LANDSCAPE180= 3
} LCD1_DisplayOrientation;

#define LCD1_WritePixel(data)  \
  LCD1_WriteDataWord(data)

#define LCD1_ReadPixel(data)  \
  0 /* with the I2C interface it is NOT possible to read from display memory */



void LCD1_Clear(void);
/*
** ===================================================================
**     Method      :  Clear (component SSD1306)
**
**     Description :
**         Clears the whole display memory.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_Init(void);
/*
** ===================================================================
**     Method      :  Init (component SSD1306)
**
**     Description :
**         Display driver initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_UpdateFull(void);
/*
** ===================================================================
**     Method      :  UpdateFull (component SSD1306)
**
**     Description :
**         Updates the whole display from the microcontroller RAM
**         display buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_UpdateRegion(LCD1_PixelDim x, LCD1_PixelDim y, LCD1_PixelDim w, LCD1_PixelDim h);
/*
** ===================================================================
**     Method      :  UpdateRegion (component SSD1306)
**
**     Description :
**         Updates a region of the display. This is only a stub for
**         this display as we are using windowing.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - x coordinate
**         y               - y coordinate
**         w               - width of the region
**         h               - Height of the region
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_OpenWindow(LCD1_PixelDim x0, LCD1_PixelDim y0, LCD1_PixelDim x1, LCD1_PixelDim y1);
/*
** ===================================================================
**     Method      :  LCD1_OpenWindow (component SSD1306)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void LCD1_CloseWindow(void);

/*
** ===================================================================
**     Method      :  LCD1_CloseWindow (component SSD1306)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void LCD1_WriteData(uint8_t data);
/*
** ===================================================================
**     Method      :  LCD1_WriteData (component SSD1306)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#if LCD1_CONFIG_DYNAMIC_DISPLAY_ORIENTATION
  LCD1_PixelDim LCD1_GetWidth(void);
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_PORTRAIT
  #define LCD1_GetWidth()    LCD1_HW_SHORTER_SIDE
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_PORTRAIT180
  #define LCD1_GetWidth()    LCD1_HW_SHORTER_SIDE
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_LANDSCAPE
  #define LCD1_GetWidth()    LCD1_HW_LONGER_SIDE
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_LANDSCAPE180
  #define LCD1_GetWidth()    LCD1_HW_LONGER_SIDE
#endif
/*
** ===================================================================
**     Method      :  GetWidth (component SSD1306)
**
**     Description :
**         Returns the width of the display in pixels (in x direction)
**     Parameters  : None
**     Returns     :
**         ---             - Width of display
** ===================================================================
*/

#if LCD1_CONFIG_DYNAMIC_DISPLAY_ORIENTATION
  LCD1_PixelDim LCD1_GetHeight(void);
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_PORTRAIT
  #define LCD1_GetHeight()    LCD1_HW_LONGER_SIDE
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_PORTRAIT180
  #define LCD1_GetHeight()    LCD1_HW_LONGER_SIDE
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_LANDSCAPE
  #define LCD1_GetHeight()    LCD1_HW_SHORTER_SIDE
#elif LCD1_CONFIG_FIXED_DISPLAY_ORIENTATION==LCD1_CONFIG_ORIENTATION_LANDSCAPE180
  #define LCD1_GetHeight()    LCD1_HW_SHORTER_SIDE
#endif
/*
** ===================================================================
**     Method      :  GetHeight (component SSD1306)
**
**     Description :
**         Returns the height of the display in pixels (in y direction)
**     Parameters  : None
**     Returns     :
**         ---             - Height of display
** ===================================================================
*/

#define LCD1_GetLongerSide() \
  LCD1_HW_LONGER_SIDE
/*
** ===================================================================
**     Method      :  GetLongerSide (component SSD1306)
**
**     Description :
**         Returns the size of the longer side of the display
**     Parameters  : None
**     Returns     :
**         ---             - number of pixels
** ===================================================================
*/

#define LCD1_GetShorterSide() \
  LCD1_HW_SHORTER_SIDE
/*
** ===================================================================
**     Method      :  GetShorterSide (component SSD1306)
**
**     Description :
**         Returns the size of the shorter side of the display
**     Parameters  : None
**     Returns     :
**         ---             - number of pixels
** ===================================================================
*/

uint16_t LCD1_ReadDataWord(void);
/*
** ===================================================================
**     Method      :  LCD1_ReadDataWord (component SSD1306)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void LCD1_GetLCD(void);
/*
** ===================================================================
**     Method      :  GetLCD (component SSD1306)
**
**     Description :
**         Method to be called for mutual exclusive access to the LCD
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_GiveLCD(void);
/*
** ===================================================================
**     Method      :  GiveLCD (component SSD1306)
**
**     Description :
**         Method to be called for mutual exclusive access to the LCD
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_InitCommChannel(void);
/*
** ===================================================================
**     Method      :  InitCommChannel (component SSD1306)
**
**     Description :
**         Method to initialize communication to the LCD. Needed if the
**         bus to the LCD is shared with other components and settings
**         are different.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t LCD1_SetContrast(uint8_t contrast);
/*
** ===================================================================
**     Method      :  SetContrast (component SSD1306)
**
**     Description :
**         Sets the display contrast level (default:0x7F)
**     Parameters  :
**         NAME            - DESCRIPTION
**         contrast        - Contrast level (default 0x7F).
**                           Contrast increases as the value increases.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t LCD1_DisplayOn(bool on);
/*
** ===================================================================
**     Method      :  DisplayOn (component SSD1306)
**
**     Description :
**         Turns the display on or off (sleep)
**     Parameters  :
**         NAME            - DESCRIPTION
**         on              - turns the display on or off
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t LCD1_DisplayInvert(bool invert);
/*
** ===================================================================
**     Method      :  DisplayInvert (component SSD1306)
**
**     Description :
**         Used to inverse the display. In normal mode, 1 one in the
**         display RAM is a pixel set and a 0 means pixel clear.
**     Parameters  :
**         NAME            - DESCRIPTION
**         invert          - if TRUE, a 1 is pixel clear and a 0
**                           is a pixel set.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void LCD1_PrintString(uint8_t line, uint8_t col, uint8_t *str);
/*
** ===================================================================
**     Method      :  PrintString (component SSD1306)
**
**     Description :
**         Simple low level method printing text to the display.
**         Newline is supported.
**     Parameters  :
**         NAME            - DESCRIPTION
**         line            - line number, starting with 0
**         col             - column number, starting with 0
**       * str             - Pointer to string to be printed on display
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_PutPixel(LCD1_PixelDim x, LCD1_PixelDim y, LCD1_PixelColor color);
/*
** ===================================================================
**     Method      :  PutPixel (component SSD1306)
**
**     Description :
**         Draws a pixel into the display buffer (not on the display).
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - x position of the pixel
**         y               - y position of the pixel
**         color           - color value of the pixel
**     Returns     : Nothing
** ===================================================================
*/

void LCD1_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component SSD1306)
**
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t LCD1_SetRowCol(uint8_t row, uint8_t col);
/*
** ===================================================================
**     Method      :  SetRowCol (component SSD1306)
**
**     Description :
**         Sets the column and row position, useful for start writing
**         text with PrintString()
**     Parameters  :
**         NAME            - DESCRIPTION
**         row             - row (or line) number, starting with 0
**         col             - column number, starting with 0
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void LCD1_ClearLine(uint8_t line);
/*
** ===================================================================
**     Method      :  ClearLine (component SSD1306)
**
**     Description :
**         Clear a text line on the display
**     Parameters  :
**         NAME            - DESCRIPTION
**         line            - Line number, starting with zero
**     Returns     : Nothing
** ===================================================================
*/

/* END LCD1. */

#endif
/* ifndef __LCD1_H */
/*!
** @}
*/
