#define  F_CPU 16000000Ul
#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"

int main(void)
{
    DIO_VoidInit();
    while (1) 
    {
		DIO_VoidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_PIN_HIGH);
		if(DIO_u8GetPinValue(DIO_u8_PORTC, DIO_u8_PIN2) == true){
			TOGGLE_BIT(PORTC, 7);
			_delay_ms(1000);
		}
    }
}

