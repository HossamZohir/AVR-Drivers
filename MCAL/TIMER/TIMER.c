/*
 * TIMER.c
 *
 * Created: 12/10/2023 8:54:32 PM
 *  Author: Hossam
 */ 

#include "TIMER.h"

/*****************************TIMER 0**********************************/
void Timer0_initialize(Timer0_mode_type mode,Timer0_prescaler_type prescaler,OC0_mode_type OC0mode)
{
	switch(mode)
	{
		case Timer0_normal_mode:
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		
		case Timer0_phasecorrect_mode:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		
		case Timer0_ctc_mode:
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		
		case Timer0_fastPWM_mode:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	
	TCCR0 &= 0XF8 ;				// mask to clr first 3 bits
	TCCR0 |= prescaler ;		// as number matches the enum order so there is no need for switch
	
	switch(OC0mode)
	{
		case OCO_disconnected:
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		
		case OCO_toggle:
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		
		case OCO_non_inverting:
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		
		case OCO_inverting:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}

void Timer0_OV_Int_enable(void)
{
	SET_BIT(TIMSK,TOIE0);
}

void Timer0_OV_Int_disable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}

void Timer0_OC_Int_enable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void Timer0_OC_Int_disable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}
