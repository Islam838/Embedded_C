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
	
    while (1) 
    {
		DIO_VoidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_PIN_HIGH);
		if(DIO_u8GetPinValue(DIO_u8_PORTC, DIO_u8_PIN2) == true){
			LCD_SendCommand(0x01);
			_delay_ms(5);
			if(DIO_u8GetPinValue(DIO_u8_PORTC, DIO_u8_PIN7) == true){
				LCD_PrintString("LED off ");
				CLEAR_BIT(PORTC, 7);
				_delay_ms(3000);
			}
			else if(DIO_u8GetPinValue(DIO_u8_PORTC, DIO_u8_PIN7) == false){
				LCD_PrintString("LED on");
				SET_BIT(PORTC, 7);
				_delay_ms(3000);
			}
			
		}
    }
	return 0;
}

