//	MIT License
//
//	Copyright (c) 2019 Florian von Zabiensky
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//	SOFTWARE.
//

/**
 * @autor: Florian von Zabiensky
 * @version: 1.0
 * @date: 14.03.2019
 *
 * This module is an interfact to the lcd library.
 */
#ifndef __LCD_H_
#define __LCD_H_

/**
 * Includes
 */
#include "stm32f4xx.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"

/**
 * Colors:
 * See ILI9341_STM32_Driver.h for the color definitions.
 */


/**
 * Function prototypes
 */
void lcd_init(void);

void lcd_draw_text_at_line(const char* text, uint8_t line, uint16_t color, uint16_t size, uint16_t background_color);
void lcd_draw_text_at_coord(const char* text, uint16_t x, uint16_t y, uint16_t color, uint16_t size, uint16_t background_color);

void lcd_fill_screen(uint16_t color);

void lcd_draw_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t filled);
void lcd_draw_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color, uint8_t filled);
void lcd_draw_horizontal_line(uint16_t x, uint16_t y, uint16_t width, uint16_t color);
void lcd_draw_vertical_line(uint16_t x, uint16_t y, uint16_t height, uint16_t color);
void lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color);



#endif /* __LCD_H_ */
