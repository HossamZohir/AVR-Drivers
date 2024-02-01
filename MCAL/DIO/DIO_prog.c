/*
 * DIO_prog.c
 *
 * Created: 12/1/2023 8:48:43 PM
 *  Author: Hossam
 */ 

#include "DIO_int.h"

/***********************************************************************/
void DIO_initialize(void)
{
	u8 Pinnum_inport;
	Port_type Port;
	PinStatus_type Status;
	
	for(u8 i=0; i<TOTAL_PINS; i++)
	{
		Status = PinsStatus[i];               // Get pin status from configuration
		Port = i/8;							 // Calculate port number (integer division)
		Pinnum_inport = i%8;				// Calculate pin number within the port (remainder)	
		
		switch(Status)
		{
			case OUTPUT:
			switch(Port)
			{
				case PA:
				SET_BIT(DDRA,Pinnum_inport);
				break;
				
				case PB:
				SET_BIT(DDRB,Pinnum_inport);
				break;
				
				case PC:
				SET_BIT(DDRC,Pinnum_inport);
				break;
				
				case PD:
				SET_BIT(DDRD,Pinnum_inport);
				break;
			}
			break;
			
			case INPULLUP:
			switch(Port)
			{
				case PA:
				CLR_BIT(DDRA,Pinnum_inport);
				SET_BIT(PORTA,Pinnum_inport);
				break;
				
				case PB:
				CLR_BIT(DDRB,Pinnum_inport);
				SET_BIT(PORTB,Pinnum_inport);
				break;
				
				case PC:
				CLR_BIT(DDRC,Pinnum_inport);
				SET_BIT(PORTC,Pinnum_inport);
				break;
				
				case PD:
				CLR_BIT(DDRD,Pinnum_inport);
				SET_BIT(PORTD,Pinnum_inport);
				break;
			}
			break;
			
			case INFREE:
			switch(Port)
			{
				case PA:
				CLR_BIT(DDRA,Pinnum_inport);
				CLR_BIT(PORTA,Pinnum_inport);
				break;
				
				case PB:
				CLR_BIT(DDRB,Pinnum_inport);
				CLR_BIT(PORTB,Pinnum_inport);
				break;
				
				case PC:
				CLR_BIT(DDRC,Pinnum_inport);
				CLR_BIT(PORTC,Pinnum_inport);
				break;
				
				case PD:
				CLR_BIT(DDRD,Pinnum_inport);
				CLR_BIT(PORTD,Pinnum_inport);
				break;
			}
			break;
		}	
	}
}
/***********************************************************************/
void DIO_WritePort(Port_type Port, u8 Value)
{
	switch(Port)
	{
		case PA:
		ASSIGN_REG(PORTA,Value);
		break;
		
		case PB:
		ASSIGN_REG(PORTB,Value);
		break;
		
		case PC:
		ASSIGN_REG(PORTC,Value);
		break;
		
		case PD:
		ASSIGN_REG(PORTD,Value);
		break;
	}
}
/***********************************************************************/
void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask)
{
	switch(Port)
	{
		case PA:
		CLR_BITS_REG(PORTA,Mask);
		SET_BITS_REG(PORTA,Value);
		break;
		
		case PB:
		CLR_BITS_REG(PORTB,Mask);
		SET_BITS_REG(PORTB,Value);
		break;
		
		case PC:
		CLR_BITS_REG(PORTC,Mask);
		SET_BITS_REG(PORTC,Value);
		break;
		
		case PD:
		CLR_BITS_REG(PORTD,Mask);
		SET_BITS_REG(PORTD,Value);
		break;
	}
}
/***********************************************************************/
 u8 DIO_ReadPort(Port_type Port)
 {
	 switch(Port)
	 {
		 case PA:
		 return PINA;
		 break;
		 
		 case PB:
		 return PINB;
		 break;
		 
		 case PC:
		 return PINC;
		 break;
		 
		 case PD:
		 return PIND;
		 break;
		
		default:
		return 0x00;
		break;
	 }
 }
 /***********************************************************************/
 void DIO_WritePin(PinNum_type Pin,VoltageLevel_type Value)
 {
	 u8 PinNum_InPort = Pin%8;
	 Port_type Port = Pin/8;
	 
	 switch (Port)
	 {
		 case PA:
		 if (HIGH==Value)
		 {
			 SET_BIT(PORTA,PinNum_InPort);
		 }
		 else
		 {
			 CLR_BIT(PORTA,PinNum_InPort);
		 }
		 break;
		 
		 case PB:
		 if (HIGH==Value)
		 {
			 SET_BIT(PORTB,PinNum_InPort);
		 }
		 else
		 {
			 CLR_BIT(PORTB,PinNum_InPort);
		 }
		 break;
		 
		 case PC:
		 if (HIGH==Value)
		 {
			 SET_BIT(PORTC,PinNum_InPort);
		 }
		 else
		 {
			 CLR_BIT(PORTC,PinNum_InPort);
		 }
		 break;
		 
		 case PD:
		 if (HIGH==Value)
		 {
			 SET_BIT(PORTD,PinNum_InPort);
		 }
		 else
		 {
			 CLR_BIT(PORTD,PinNum_InPort);
		 }
		 break;
	 }
 }
 /***********************************************************************/
 void DIO_TogglePin(PinNum_type Pin)
 {
	 u8 PinNum_InPort = Pin%8;
	 Port_type Port = Pin/8;
	 switch (Port)
	 {
		 case PA:
		 TOG_BIT(PORTA,PinNum_InPort);
		 break;
		 case PB:
		 TOG_BIT(PORTB,PinNum_InPort);
		 break;
		 case PC:
		 TOG_BIT(PORTC,PinNum_InPort);
		 break;
		 case PD:
		 TOG_BIT(PORTD,PinNum_InPort);
		 break;
	 }
 }
 /***********************************************************************/
 VoltageLevel_type DIO_ReadPin(PinNum_type Pin)
 {
	 u8 PinNum_InPort = Pin%8;
	 Port_type Port = Pin/8;
	 switch (Port)
	 {
		 case PA:
		 return GET_BIT(PINA,PinNum_InPort);
		 break;
		 case PB:
		 return GET_BIT(PINB,PinNum_InPort);
		 break;
		 case PC:
		 return GET_BIT(PINC,PinNum_InPort);
		 break;
		 case PD:
		 return GET_BIT(PIND,PinNum_InPort);
		 break;
		 default:
		 return 0x00;
		 break;
	 }
 }
 /***********************************************************************/