#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"

int main(void)
{	
    DIO_VoidInit();
	LCD_Init();
	
	LCD_PrintString("Hello");
	//_delay_ms(10);
	//
	//LCD_SendCommand(0xC0);
	//_delay_ms(10);
	//LCD_SendCommand(0x10);
	//_delay_ms(10);
	//LCD_PrintString("LCD driver");
	
    while (1) 
    {
		
    }
	return 0;
}

