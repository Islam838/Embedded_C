#include <avr/io.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"
#include "stdbool.h"


void DIO_VoidInit(void){
	DDRA = DIO_u8_PORTA_DIR;
	DDRB = DIO_u8_PORTB_DIR;
	DDRC = DIO_u8_PORTC_DIR;
	DDRD = DIO_u8_PORTD_DIR;
}

void DIO_VoidSetPinValue(u8 DIO_u8Port , u8 DIO_u8Pin , u8 DIO_u8Val){
	switch(DIO_u8Port)
	{
		case DIO_u8_PORTA:
			if(DIO_u8Val == DIO_PIN_HIGH)
				SET_BIT(PORTA, DIO_u8Pin);
			else if(DIO_u8Val == DIO_PIN_LOW)
				CLEAR_BIT(PORTA, DIO_u8Pin);
			break;
		case DIO_u8_PORTB:
			if(DIO_u8Val == DIO_PIN_HIGH)
				SET_BIT(PORTB, DIO_u8Pin);
			else if(DIO_u8Val == DIO_PIN_LOW)
				CLEAR_BIT(PORTB, DIO_u8Pin);
			break;
		case DIO_u8_PORTC:
			if(DIO_u8Val == DIO_PIN_HIGH)
				SET_BIT(PORTC, DIO_u8Pin);
			else if(DIO_u8Val == DIO_PIN_LOW)
				CLEAR_BIT(PORTC, DIO_u8Pin);
			break;
		case DIO_u8_PORTD:
			if(DIO_u8Val == DIO_PIN_HIGH)
				SET_BIT(PORTD, DIO_u8Pin);
			else if(DIO_u8Val == DIO_PIN_LOW)
				CLEAR_BIT(PORTD, DIO_u8Pin);
			break;
		default:
			return;	
	}
}

bool DIO_u8GetPinValue(u8 DIO_u8Port , u8 DIO_u8Pin){
	switch(DIO_u8Port)
	{
		case DIO_u8_PORTA:
			return GET_BIT(PINA, DIO_u8Pin);
			break;
		case DIO_u8_PORTB:
			return GET_BIT(PINB, DIO_u8Pin);
			break;
		case DIO_u8_PORTC:
			return GET_BIT(PINC, DIO_u8Pin);
			break;
		case DIO_u8_PORTD:
			return GET_BIT(PIND, DIO_u8Pin);
			break;
		default:
			return 0;
	}
}
