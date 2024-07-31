/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrhman Marzoq
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "Calc.h"


static void myWait(volatile int ms)
{
	for (volatile int i = 0; i < ms; i++)
	{
		for (volatile int j = 0; j < 255; j++);
	}
}


int main(void)
{
	Calc_init();
	uint8_t i = 0;

	while(1)
	{
		uint8_t press = Key_get(&key);
		if (press != ' ' && press != '=')
		{
			if (i < 60) Operation[i++] = press;
			if (!(i%16))
			{
				i = 0;
				LCD_4bit_Set_Cursor(&lcd, 1, 1);
			}
			LCD_4bit_Print_Char(&lcd, press);
		}
		else if (press == '=')
		{
			i = 0;
			Calc(Operation);
		}
	}
}




