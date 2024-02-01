/*
 * KEYPAD_INT.h
 *
 * Created: 11/18/2023 9:27:47 PM
 *  Author: Hossam
 */ 


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define F_CPU 8000000
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_config.h"
#include <util/delay.h>

#define keypadport PORTB
#define keypadpin  PINB

#define colstart	0
#define colfinish	4

#define rowstart	4
#define rowfinish	8

u8 KeyPad_PressedButton(void);

#endif /* KEYPAD_INT_H_ */