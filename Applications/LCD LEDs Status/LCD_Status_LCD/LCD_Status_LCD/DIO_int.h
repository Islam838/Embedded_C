#ifndef _DIO_INT_H
#define _DIO_INT_H
#include "stdbool.h"

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_u8_PIN0		0
#define DIO_u8_PIN1     1
#define DIO_u8_PIN2     2
#define DIO_u8_PIN3     3
#define DIO_u8_PIN4     4
#define DIO_u8_PIN5     5
#define DIO_u8_PIN6     6
#define DIO_u8_PIN7     7

#define DIO_u8_PORTA	5
#define DIO_u8_PORTB	6
#define DIO_u8_PORTC	7
#define DIO_u8_PORTD	8

void DIO_VoidInit(void);
void DIO_VoidSetPinValue(u8 DIO_u8Port , u8 DIO_u8Pin , u8 DIO_u8Val);
bool DIO_u8GetPinValue(u8 DIO_u8Port , u8 DIO_u8Pin);

#endif