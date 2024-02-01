/*
 * ADC_CONFIG.h
 *
 * Created: 11/22/2023 7:34:27 PM
 *  Author: Hossam
 */ 
/*
*****************This file is used by user to config all the driver option ***************/
/****************** all ranges is written choose and paste it below ***************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*configure voltage reference
	ADC_voltage_ref_AREF
	ADC_voltage_ref_AVCC
	ADC_voltage_ref_2_56v
 */
#define ADC_voltage_ref_selector		ADC_voltage_ref_AVCC
/*#define ADC_voltage_ref_mv				5000
#define ADC_max_step_number					1024*/
/**************************************************************/

/*select the position 
	ADC_right_adjust
	ADC_left_adjust
*/
#define ADC_postion_adjust_selector		ADC_right_adjust
/**************************************************************/

/*select the mode
	ADC_mode_auto_trigger
	ADC_mode_single_conversion
*/
#define ADC_mode_selector				ADC_mode_auto_trigger
/***************************************************************/

/*select prescaler
	ADC_prescaler_2_
	ADC_prescaler_4_
	ADC_prescaler_8_
	ADC_prescaler_16_
	ADC_prescaler_32_
	ADC_prescaler_64_
	ADC_prescaler_128_
*/
#define ADC_prescaler_selector			ADC_prescaler_64_
/***************************************************************/

/*select auto trigger source
	ADC_trig_src_free_runing
	ADC_trig_src_analog_comp
	ADC_trig_src_extr_interrupt
	ADC_trig_timer0_comp
	ADC_trig_timer0_over
	ADC_trig_timer1_comp
	ADC_trig_timer1_over
	ADC_trig_timer1_capt
*/
#define ADC_auto_trigger_SRC_selector		ADC_trig_src_free_runing
/****************************************************************/


#endif /* ADC_CONFIG_H_ */