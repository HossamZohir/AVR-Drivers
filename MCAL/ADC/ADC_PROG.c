/*
 * ADC_PROG.c
 *
 * Created: 11/22/2023 7:33:34 PM
 *  Author: Hossam
 */ 

#include "ADC_INT.h"

void ADC_intialize(void)
{
	/********************* selecting voltage refrence ****************************/
			ADMUX &= ADC_voltage_ref_clr_mask;
			ADMUX |= ADC_voltage_ref_selector;
	
	/********************* selecting ADC MODE ****************************/
	#if		ADC_mode_selector == ADC_mode_auto_trigger
			SET_BIT(ADCSRA,ADATE); 
			SFIOR &= ADC_trig_src_clr_mask;
			SFIOR |= ADC_auto_trigger_SRC_selector;
	
	#elif	ADC_mode_selector == ADC_mode_single_conversion
			CLR_BIT(ADCSRA,ADATE); 
	#endif
	
	/********************* selecting position adjustment ****************************/
	#if		ADC_postion_adjust_selector == ADC_left_adjust
			SET_BIT(ADMUX,ADLAR);
			
	#elif	ADC_postion_adjust_selector == ADC_right_adjust
			CLR_BIT(ADMUX,ADLAR);
	#endif
	
	/********************* clearing interrupt flag ****************************/
			SET_BIT(ADCSRA,4);
			
	/********************* ADC enable ****************************/
			SET_BIT(ADCSRA,ADEN);
}


u16 ADC_GetResult(ADC_CHANNEL_TYPES ADC_ch)
{
	
	/****************** select channel ************************/
			ADMUX &= ADC_channel_selector_clr_mask ;
			ADMUX |= ADC_ch;
	
	/******************** start conversion *********************/
			SET_BIT(ADCSRA,ADSC);
			
	/******************** get result **************************/
			while(GET_BIT(ADCSRA,ADSC)==1);
			return ADCL | (ADCH << 8);
}


