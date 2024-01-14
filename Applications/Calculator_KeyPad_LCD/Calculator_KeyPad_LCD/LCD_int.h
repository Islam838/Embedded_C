#ifndef _LCD_INT_H
#define _LCD_INT_H

#define LCD_U8_DIGIT1    0
#define LCD_U8_DIGIT2    1
#define LCD_U8_DIGIT3    2
#define LCD_U8_DIGIT4    3
#define LCD_U8_DIGIT5    4
#define LCD_U8_DIGIT6    5
#define LCD_U8_DIGIT7    6
#define LCD_U8_DIGIT8    7
#define LCD_U8_DIGIT9    8
#define LCD_U8_DIGIT10   9
#define LCD_U8_DIGIT11   10
#define LCD_U8_DIGIT12   11
#define LCD_U8_DIGIT13   12
#define LCD_U8_DIGIT14   13
#define LCD_U8_DIGIT15   14
#define LCD_U8_DIGIT16   15

void LCD_Init(void);
void LCD_SendData(unsigned char);
void LCD_SendCommand(unsigned char);
void LCD_PrintString(char*);

#endif