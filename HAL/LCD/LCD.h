#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_config.h"
#include <util/delay.h>

/* fun from data sheet*/
#define LCD_FuncSet8bit			0x38            // 2 lines 5*7 font
#define LCD_FuncSet4bit			0x28		   // 2 lines 5*7 font
#define LCD_DisplayOn			0x0C		  // cursor off no blink
#define LCD_DisplayOff			0x08		  // cursor off no blink
#define LCD_DisplayClear		0x01
#define LCD_EntryMode			0x06          // cursor move from left to right
#define LCD_FuncReset			0x30          // reset the LCD
#define LCD_Home				0x02          // return cursor to first position on first line
#define LCD_SetCursor			0x80          // set cursor position
#define LCD_SetCursor2line		0xC0          // set cursor position

/**********************************     LCD Modes   **************************************************/
#define M_4BIT			 0
#define M_8BIT           1


/********************************* define control pins     *******************************************/
#define RS  PINA0
#define RW  PINA1
#define EN  PINA2

/*********************************   define LCD Mode       *******************************************/
#define LCD_MODE  M_4BIT

/*******************for 8 bit mode and 4 bit_sameport mode define the LCD port **********************/
#define LCD_PORT  PA

/*******************for 4 bit same port mode define pins mask in port *******************************/
#define M_4BIT_MASK 0X78

/*******************    for 4 bit separated pins  mode define pins    *******************************/
#define D4 PINA3
#define D5 PINA4
#define D6 PINA5
#define D7 PINA6

/******************************************************************************************************/


extern void LCD_initialize(void);
extern void LCD_WriteChar(u8 Character);
extern void LCD_WriteSentence(u8 *PtrSentance);
extern void LCD_GoTo(u8 Line, u8 x);
extern void LCD_WriteNumber(u64 Number);
extern void LCD_WriteNumber2(u16 Number);
extern void LCD_Create_Character(u8 *Pattern,u8 Location);
extern void LCD_Clear(void);






#endif
