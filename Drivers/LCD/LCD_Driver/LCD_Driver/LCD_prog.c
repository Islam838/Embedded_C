#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"
	
void LCD_SendCommand(unsigned char comm){
	// defining the next inputs as commands (Execute) not data (Data)
	CLEAR_BIT(PORTB, LCD_U8_RS);
	// to write only commands
	CLEAR_BIT(PORTB, LCD_U8_RW);
	
	// since we deal with 4 bits, we will send commands like (81)
	// on two parts upper nibble (80)(0101) & (1)(0001)
	// send upper nibble
	PORTA = comm & 0xF0;
	//send 1ms pulse to enable LCD to send the first 4 bits
	SET_BIT(PORTB, LCD_U8_EN);

	_delay_ms(1);
	CLEAR_BIT(PORTB, LCD_U8_EN);
	
	// send lower nibble (1)
	PORTA = comm << 4;
	SET_BIT(PORTB, LCD_U8_EN);
	_delay_ms(1);
	CLEAR_BIT(PORTB, LCD_U8_EN);
}

void LCD_SendData(unsigned char data){
	// defining the next inputs as data (Data) not commands (Execute)
	SET_BIT(PORTB, LCD_U8_RS);
	// to write only commands
	CLEAR_BIT(PORTB, LCD_U8_RW);
	
	// character a is 41 in asci, it is 8 bit data, so we need to divide by 2
	// send upper nibble
	PORTA = data & 0xF0;
	//send 1ms pulse to enable LCD to send the first 4 bits
	SET_BIT(PORTB, LCD_U8_EN);
	_delay_ms(1);
	CLEAR_BIT(PORTB, LCD_U8_EN);
	
	// send lower nibble (1)
	PORTA = data << 4;
	SET_BIT(PORTB, LCD_U8_EN);
	_delay_ms(1);
	CLEAR_BIT(PORTB, LCD_U8_EN);
}

	
void LCD_Init(void)
{
	// make sure enable is initialized by zero to be able to send one pulse in the commands or data
	CLEAR_BIT(PORTB, LCD_U8_EN);
	// next 3 commands will do the 4 bit mode starting
	LCD_SendCommand(33);	
	LCD_SendCommand(32);
	LCD_SendCommand(28);	// configurations, check the readme
	LCD_SendCommand(0x0e);	// display on.cursor on
	LCD_SendCommand(0x01);	// Clear LCD
	_delay_ms(2);
}

void LCD_PrintString(char* Str_Print){
	unsigned char i = 0;
	while(Str_Print[i] != 0){ //null character
		LCD_SendData(Str_Print[i]);
		i++;
	}
}
