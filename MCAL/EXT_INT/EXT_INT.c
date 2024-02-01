/*
 * EXT_INT.c
 *
 * Created: 12/7/2023 11:39:25 PM
 *  Author: Hossam
 */ 


#include "EXT_INT.h"



/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;
/********************************************************************************************************/
void EXT_INTER_setcallback(EXT_INTER_name interrupt, void(*LocalPtr)(void))
{
	switch(interrupt)
	{
		case Ex_int0:
		INT0_Fptr=LocalPtr;
		break;
		
		case Ex_int1:
		INT1_Fptr=LocalPtr;
		break;
		
		case Ex_int2:
		INT2_Fptr=LocalPtr;
		break;
	}
}
/***************************************************************************************************/

void EXT_INTER_enable (EXT_INTER_name interrupt)
{
	switch(interrupt)
	{
		case Ex_int0:
		SET_BIT(GICR_Reg,INTG0);
		break;
		
		case Ex_int1:
		SET_BIT(GICR_Reg,INTG1);
		break;
		
		case Ex_int2:
		SET_BIT(GICR_Reg,INTG2);
		break;
	}
}

void EXT_INTER_disable (EXT_INTER_name interrupt)
{
	switch(interrupt)
	{
		case Ex_int0:
		CLR_BIT(GICR_Reg,INTG0);
		break;
		
		case Ex_int1:
		CLR_BIT(GICR_Reg,INTG1);
		break;
		
		case Ex_int2:
		CLR_BIT(GICR_Reg,INTG2);
		break;
	}
}

void EXT_INTER_trigger (EXT_INTER_name interrupt, EXT_INTER_control_mode triggering )
{
	switch(interrupt)
	{
		case Ex_int0:
		switch(triggering)
		{
			case low_level:
			CLR_BIT(MCUCR_Reg,ISC00);
			CLR_BIT(MCUCR_Reg,ISC01);
			break;
			
			case Any_logical_change:
			SET_BIT(MCUCR_Reg,ISC00);
			CLR_BIT(MCUCR_Reg,ISC01);
			break;
			
			case falling_edge:
			CLR_BIT(MCUCR_Reg,ISC00);
			SET_BIT(MCUCR_Reg,ISC01);
			break;
			
			case rising_edge:
			SET_BIT(MCUCR_Reg,ISC00);
			SET_BIT(MCUCR_Reg,ISC01);
			break;
		}
		case Ex_int1:
		switch(triggering)
		{
			case low_level:
			CLR_BIT(MCUCR_Reg,ISC10);
			CLR_BIT(MCUCR_Reg,ISC11);
			break;
			
			case Any_logical_change:
			SET_BIT(MCUCR_Reg,ISC10);
			CLR_BIT(MCUCR_Reg,ISC11);
			break;
			
			case falling_edge:
			CLR_BIT(MCUCR_Reg,ISC10);
			SET_BIT(MCUCR_Reg,ISC11);
			break;
			
			case rising_edge:
			SET_BIT(MCUCR_Reg,ISC10);
			SET_BIT(MCUCR_Reg,ISC11);
			break;
		}
		case Ex_int2:
		switch(triggering)
		{
			case falling_edge:
			CLR_BIT(MCUCSR_Reg,ISC2);
			break;
			
			case rising_edge:
			SET_BIT(MCUCSR_Reg,ISC2);
			break;
			
			default:
			CLR_BIT(MCUCSR_Reg,ISC2);
		}
		break;
	}
}

/****************************************************************************************************/
ISR(INT0_vect)
{
	if (INT0_Fptr != NULLPTR)				// guard
	{
		INT0_Fptr();
	}
}

ISR(INT1_vect)
{
	if (INT1_Fptr != NULLPTR)
	{
		INT1_Fptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_Fptr != NULLPTR)
	{
		INT2_Fptr();
	}
}