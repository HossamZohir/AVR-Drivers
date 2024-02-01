/*
 * KEYPAD_PROG.c
 *
 * Created: 11/18/2023 9:43:16 PM
 *  Author: Hossam
 */ 

#include "KEYPAD_INT.h"

u8 keypadarr[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'on','0','=','+'}
};

u8 KeyPad_PressedButton(void)
{ 
	// make o/p 1 and pull up the i/p
	PORTB |= 0xF0;
	
	u8 result;
	/*Loop through the o/p (col) of the keypad*/
	for(u8 colcount=colstart ;colcount<colfinish; colcount++)
	{
		/*Set the current col pin to LOW (activate)*/
		keypadport &= ~(1 << colcount);
		
		/*Loop through i/p (row) of the keypad*/
		for(u8 rowcount=rowstart; rowcount<rowfinish; rowcount++)
		{
			/*Check if the current row pin is LOW (button pressed)*/
			if(!(keypadpin & (1 << rowcount)))
			{
				/*Get the corresponding value from the keypad array regarding the starting and finishing (tricky)*/
				result = keypadarr[rowcount-rowstart][colcount-colstart];
				
				/*Wait until the button is released*/
				while(!(keypadpin & (1 << rowcount)));
				
				/*Delay for debouncing*/
				_delay_ms(20);
			}
		}
		
		/*Set the current col pin back to HIGH*/
		keypadport |= (1 << colcount);
	}
	return result;
}

