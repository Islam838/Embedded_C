#include "STD_types.h"
#include "DIO_int.h"
#include "KPad_cfg.h"
#include "KPad_int.h"
#include <avr/io.h>

#define RawPort PORTB
#define ColumnPort PORTC
#define ReadCol PINC

void KeyPad_Init(void){
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN4, DIO_PIN_LOW);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN5, DIO_PIN_LOW);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN6, DIO_PIN_LOW);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN7, DIO_PIN_LOW);
	
	DIO_VoidSetPinValue(ColumnPort, DIO_u8_PIN3, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(ColumnPort, DIO_u8_PIN4, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(ColumnPort, DIO_u8_PIN5, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(ColumnPort, DIO_u8_PIN6, DIO_PIN_HIGH);
}

u8 Kpad_RetVal(void){
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN4, DIO_PIN_LOW);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN5, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN6, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN7, DIO_PIN_HIGH);
	
	if((ReadCol & (1<<3)) == 0) return R1C1;
	else if((ReadCol & (1<<4)) == 0) return R1C2;
	else if((ReadCol & (1<<5)) == 0) return R1C3;
	else if((ReadCol & (1<<6)) == 0) return R1C4;
	
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN4, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN5, DIO_PIN_LOW);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN6, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN7, DIO_PIN_HIGH);
	
	if((ReadCol & (1<<3)) == 0) return R2C1;
	else if((ReadCol & (1<<4)) == 0) return R2C2;
	else if((ReadCol & (1<<5)) == 0) return R2C3;
	else if((ReadCol & (1<<6)) == 0) return R2C4;
	
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN4, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN5, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN6, DIO_PIN_LOW);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN7, DIO_PIN_HIGH);
	
	if((ReadCol & (1<<3)) == 0) return R3C1;
	else if((ReadCol & (1<<4)) == 0) return R3C2;
	else if((ReadCol & (1<<5)) == 0) return R3C3;
	else if((ReadCol & (1<<6)) == 0) return R3C4;
	
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN4, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN5, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN6, DIO_PIN_HIGH);
	DIO_VoidSetPinValue(RawPort, DIO_u8_PIN7, DIO_PIN_LOW);
	
	if((ReadCol & (1<<3)) == 0) return R4C1;
	else if((ReadCol & (1<<4)) == 0) return R4C2;
	else if((ReadCol & (1<<5)) == 0) return R4C3;
	else if((ReadCol & (1<<6)) == 0) return R4C4;
	
	return Kpad_NULL;
	
	
}