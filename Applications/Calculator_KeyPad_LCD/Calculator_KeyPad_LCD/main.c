#define  F_CPU 16000000Ul
#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KPad_int.h"


#define RawPort PORTB
#define ColumnPort PORTC
#define ReadCol PINC
#define ReadColVal 0x78 // columns default value 0b01111000
#define ReadRawVal 0x0F // columns default value 0b00001111;	

#define f(x, op, y) x op y

int main(void)
{
	u8 button, op1, op2;
	u16 result;
	DIO_VoidInit();
	LCD_Init();
	KeyPad_Init();
	while (1)
	{
		RawPort &= ReadRawVal;
		ColumnPort |= ReadColVal;
		if(ReadCol != ReadColVal){ // button is pressed but which one
			button = Kpad_RetVal(); // return button asci code
			switch (button){
			case'1':	LCD_PrintString("1"); _delay_ms(300); op1 = 1;break;
			case'2':	LCD_PrintString("2"); _delay_ms(300); op1 = 2;break;
			case'3':	LCD_PrintString("3"); _delay_ms(300); op1 = 3;break;
			case'4':	LCD_PrintString("4"); _delay_ms(300); op1 = 4;break;
			case'5':	LCD_PrintString("5"); _delay_ms(300); op1 = 5;break;
			}
		}
	}
}

