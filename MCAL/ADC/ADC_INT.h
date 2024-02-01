/*
 * ADC_INT.h
 *
 * Created: 11/22/2023 7:48:05 PM
 *  Author: Hossam
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "ADC_CONFIG.h"
#include "../../MYLIB/BIT_MATH.h"
#include "../../MYLIB/Memory_map.h"
#include "../../MYLIB/STD_TYPES.h"

/* ADC voltage select*/
#define ADC_voltage_ref_clr_mask		0X3F    //make the working bits with 0 (mask)
#define ADC_voltage_ref_AREF			0X00
#define ADC_voltage_ref_AVCC			0X40
#define ADC_voltage_ref_2_56v			0XC0

/* ADC position adjust */
#define ADC_right_adjust				0
#define ADC_left_adjust					1

/* ADC mode select*/
#define ADC_mode_auto_trigger			1
#define ADC_mode_single_conversion		0

/* ADC prescaler select bits*/
#define ADC_prescaler_clr_mask		0xF8
#define ADC_prescaler_2_			0x01
#define ADC_prescaler_4_			0x02
#define ADC_prescaler_8_			0x03
#define ADC_prescaler_16_			0x04
#define ADC_prescaler_32_			0x05
#define ADC_prescaler_64_			0x06
#define ADC_prescaler_128_			0x07


/* ADC auto trigger source*/
#define ADC_trig_src_clr_mask           0x1F
#define ADC_trig_src_free_runing        0x00
#define ADC_trig_src_analog_comp        0x20
#define ADC_trig_src_extr_interrupt     0x40
#define ADC_trig_timer0_comp            0xC0
#define ADC_trig_timer0_over            0x80
#define ADC_trig_timer1_comp            0xA0
#define ADC_trig_timer1_over            0xC0
#define ADC_trig_timer1_capt            0xE0


/*mask for clear channel*/
#define ADC_channel_selector_clr_mask	0xE0


/********** ADC CHANNELS ***********/
/*Those channels can be put in enum as the working bits is from 0 so it gives
the same value as i make them with reference or mask (check data sheet)*/
typedef enum
{
	ADC_CH0,		/* --> 0b00000000 */
	ADC_CH1,		/* --> 0b00000001 */
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7			/* --> 0b00000111 */
	
}ADC_CHANNEL_TYPES;

/********** FUNC PROTOTYPES ***********/

void ADC_intialize(void);

u16 ADC_GetResult(ADC_CHANNEL_TYPES ADC_ch);







#endif /* ADC_INT_H_ */