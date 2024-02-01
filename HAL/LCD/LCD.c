

#include "LCD.h"

/************************************* 8 BIT Mode functions********************************************/
#if (LCD_MODE==M_8BIT)

static void LCD_WriteCommand(u8 Command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	
	DIO_WritePort(LCD_PORT,(Command));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}

void LCD_initialize(void)
{
	
	_delay_ms(50);											// said in Data sheet to delay after power on for 1st time
	LCD_WriteCommand(LCD_FuncSet8bit);						//N=1 , F=0
	_delay_ms(1);											//delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(LCD_DisplayOn);						//D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);											//delay 1ms
	LCD_WriteCommand(LCD_DisplayClear);						//clear LCD
	_delay_ms(20);
	LCD_WriteCommand(LCD_EntryMode);
	LCD_WriteCommand(LCD_SetCursor);
}

static void LCD_WriteData(u8 Data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	
	DIO_WritePort(LCD_PORT,(Data));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}

/************************************* 4 BIT Mode functions********************************************/
#elif (LCD_MODE==M_4BIT)

static void LCD_WriteCommand(u8 Command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	//4 upper bits 
	DIO_WritePin(D4,GET_BIT(Command,4));		/*GET_BIT(Command,4): This macro call extracts the value of the fourth bit (index 4) from the Command variable. It shifts the Command variable to the right by 4 positions and applies a bitwise AND operation with 0x01 to isolate and retain the fourth bit. The result is either 0 or 1, representing the value of the fourth bit.*/
	DIO_WritePin(D5,GET_BIT(Command,5));
	DIO_WritePin(D6,GET_BIT(Command,6));
	DIO_WritePin(D7,GET_BIT(Command,7));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
	//4 lower bits
	DIO_WritePin(D4,GET_BIT(Command,0));
	DIO_WritePin(D5,GET_BIT(Command,1));
	DIO_WritePin(D6,GET_BIT(Command,2));
	DIO_WritePin(D7,GET_BIT(Command,3));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}

static void LCD_WriteData(u8 Data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	
	DIO_WritePin(D4,GET_BIT(Data,4));
	DIO_WritePin(D5,GET_BIT(Data,5));
	DIO_WritePin(D6,GET_BIT(Data,6));
	DIO_WritePin(D7,GET_BIT(Data,7));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
	
	DIO_WritePin(D4,GET_BIT(Data,0));
	DIO_WritePin(D5,GET_BIT(Data,1));
	DIO_WritePin(D6,GET_BIT(Data,2));
	DIO_WritePin(D7,GET_BIT(Data,3));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(2);
	DIO_WritePin(EN,LOW);
	_delay_ms(2);
}

void LCD_initialize(void)
{
	_delay_ms(50);								// said in Data sheet to delay after power on for 1st time
	LCD_WriteCommand(LCD_Home);					//4 bit mode only
	_delay_ms(1);
	LCD_WriteCommand(LCD_FuncSet4bit);			//N=1 , F=0
	_delay_ms(1);								//delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(LCD_DisplayOn);			//D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);								//delay 1ms
	LCD_WriteCommand(LCD_DisplayClear);			//clear LCD
	_delay_ms(20);
	LCD_WriteCommand(LCD_EntryMode);
	LCD_WriteCommand(LCD_SetCursor);
}
#endif

/*************************** service functions*****************************************************/
void LCD_WriteChar(u8 character)
{
	LCD_WriteData(character);
}

/*************************************************************************/

void LCD_WriteSentence(u8 *PtrSentance)
{
	for(u8 i=0;PtrSentance[i];i++)				//The loop will continue to iterate as long as the condition PtrSentance[i] is true
	{
		LCD_WriteData(PtrSentance[i]);
	}

}

/*************************************************************************/
void LCD_GoTo(u8 Line, u8 x)
{
	if(Line == 0)
	{
		if ( x <=15)
		{
			LCD_WriteCommand(LCD_SetCursor + x);
		}
	}
	else if (Line == 1)
	{
		if ( x <=15)
		{
			LCD_WriteCommand(LCD_SetCursor2line + x);
		}
	}
}

/*************************************************************************/
void LCD_WriteNumber(u64 Number)
{
	u8 i=0,arr[10],j;
	if(Number==0)
	{
		LCD_WriteData('0');
	}
	else
	{
			while(Number)
			{
				arr[i]=Number%10+'0';        //addressing the last bit of the number and added to '0' to get the corsponding ASCI code
				Number/=10;					 // divide by 10 to remove the last digit
				i++;
			}
			for(j=i;j>0;j--)					//reversed loop to print the numbers from left to right
			{
				LCD_WriteData(arr[j-1]);
			}
	   }
}

/*************************************************************************/
void LCD_WriteNumber2(u16 Number)
{
	LCD_WriteData(Number%10000/1000+'0');			//extracts the thousands digit of the input number by performing a modulo division ()%10000/1000) and then shifts it to the right by three positions ()Number%10000/1000/1000) to isolate the digit. Finally, it adds '0' to get the corresponding ASCII character code
	LCD_WriteData(Number%1000/100+'0');				// hundreds
	LCD_WriteData(Number%100/10+'0');				// tens
	LCD_WriteData(Number%10/1+'0');					// units
}

/*************************************************************************/
void Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8));				//Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]);						//Pass the bytes of pattern on LCD

}

/*************************************************************************/
void LCD_Clear(void)
{

	LCD_WriteCommand(LCD_DisplayClear);

}

	

