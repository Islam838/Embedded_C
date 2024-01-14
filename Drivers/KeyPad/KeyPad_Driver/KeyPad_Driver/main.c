#define  F_CPU 16000000Ul
#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "KPad_int.h"
#include "Kpad_priv.h"

/*unsigned char keypad(){
	PORTB = 0b11100000; // first row = 0
	// check every column to find a key -- if column = 0 then it is the pressed key
	// check Port B Pin 4 which is the first column
	if((PINC & (1<<PINC3)) == 0){ // PINC4 is 3 same as (1<<3)
		_delay_ms(10); // de-bounce delay
		return '1';
	}
	else if((PINC & (1<<PINC4)) == 0){
		_delay_ms(10);
		return '2';
	}
	else if((PINC & (1<<PINC5)) == 0){
		_delay_ms(10);
		return '3';
	}
	else if((PINC & (1<<PINC6)) == 0){
		_delay_ms(10);
		return 'A';
	}
	return;
}*/

#define RawPort PORTB
#define ColumnPort PORTC
#define ReadCol PINC
#define ReadColVal 0x78 // columns default value

int main(void)
{
	PORTC = 0x0; // set LEDs = 0
	u8 button;
    DIO_VoidInit();
	KeyPad_Init();
    while (1) 
    {
		RawPort = 0x0;
		ColumnPort |= ReadColVal;
		if(ReadCol != ReadColVal){ // button is pressed but which one
			button = Kpad_RetVal(); // return button asci code
			if (button == '1') {SET_BIT(PORTC, 7); _delay_ms(300);}
			if (button == '2') {CLEAR_BIT(PORTC, 7); _delay_ms(300);}
			if (button == '3') {SET_BIT(PORTC, 2); _delay_ms(300);}
			if (button == 'A') {CLEAR_BIT(PORTC, 2); _delay_ms(300);}			
		}
	}
}

