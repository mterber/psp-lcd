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

#include <lcd.h>
#include "stm32f4xx.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"

/**
 * Initializes the LCD
 */
void lcd_init(void)
{
	/* Initialization of the LCD */
	ILI9341_Init();

	/* Clear screen with white color */
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_VERTICAL_2);
}


/**
 * Draws a text at a given line.
 * @param	text	The text to draw
 * @param 	line	The line on the screen
 * @param	color	The text color
 * @param	size	The text size
 * @param	background_color	The background color
 */
void lcd_draw_text_at_line(const char* text, uint8_t line, uint16_t color, uint16_t size, uint16_t background_color)
{
	uint16_t y = line * (8*size)+10;

	ILI9341_Draw_Text(text, 10, y, color, size, background_color);
}

/**
 * Draws a text at a given position.
 * @param	text	The text to draw
 * @param 	x		The x coordinate on the screen
 * @param 	y		The y coordinate on the screen
 * @param	color	The text color
 * @param	size	The text size
 * @param	background_color	The background color
 */
void lcd_draw_text_at_coord(const char* text, uint16_t x, uint16_t y, uint16_t color, uint16_t size, uint16_t background_color)
{
	ILI9341_Draw_Text(text, x, y, color, size, background_color);
}

/**
 * Fills the screen with a color.
 * @param color	The color to fill the screen
 */
void lcd_fill_screen(uint16_t color)
{
	ILI9341_Fill_Screen(color);
}

/**
 * Draws a rectangle to the screen.
 * @param x0		The x coordinate of the first corner
 * @param y0		The y coordinate of the first corner
 * @param x1		The x coordinate of the second corner
 * @param y1		The y coordinate of the second corner
 * @param color		The color of the rectangle
 * @param filled	0 if the rectangle should not be filled, otherwise != 0
 */
void lcd_draw_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t filled)
{
	if(filled)
	{
		ILI9341_Draw_Filled_Rectangle_Coord(x0, y0, x1, y1, color);
	}
	else
	{
		ILI9341_Draw_Hollow_Rectangle_Coord(x0, y0, x1, y1, color);
	}
}

/**
 * Draws a circle to the screen.
 * @param x			The x coordinate of the center
 * @param y			The y coordinate of the center
 * @param r			The radius of the circle
 * @param color		The color of the circle
 * @param filled	0 if the circle should not be filled, otherwise != 0
 */
void lcd_draw_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color, uint8_t filled)
{
	if(filled)
	{
		ILI9341_Draw_Filled_Circle(x, y, r, color);
	}
	else
	{
		ILI9341_Draw_Hollow_Circle(x, y, r, color);
	}
}

/**
 * Draws a horizontal line to the screen
 * @param x			The x coordinate of the left point
 * @param y			The y coordinate of the left point
 * @param width		The width(length) of the line
 * @param color		The color of the line
 */
void lcd_draw_horizontal_line(uint16_t x, uint16_t y, uint16_t width, uint16_t color)
{
	ILI9341_Draw_Horizontal_Line(x, y, width, color);
}

/**
 * Draws a vertical line to the screen.
 * @param x			The x coordinate of the topmost point
 * @param y			The y coordinate of the topmost point
 * @param height	The height(length) of the line
 * @param color		The color of the line
 */
void lcd_draw_vertical_line(uint16_t x, uint16_t y, uint16_t height, uint16_t color)
{
	ILI9341_Draw_Vertical_Line(x, y, height, color);
}

/**
 * Draws a pixel to the screen.
 * @param x		The x coordinate of the pixel
 * @param y		The y coordinate of the pixel
 * @param color	The color of the pixel
 */
void lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
	ILI9341_Draw_Pixel(x, y, color);
}

