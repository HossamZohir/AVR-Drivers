/*
 * TIMER.h
 *
 * Created: 12/10/2023 8:54:19 PM
 *  Author: Hossam
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../MYLIB/BIT_MATH.h"
#include "../../MYLIB/Memory_map.h"
#include "../../MYLIB/STD_TYPES.h"
#include "../DIO/DIO_int.h"

/***************************timer0**********************************************************/
typedef enum						//from table 38
{
	Timer0_normal_mode=0,
	Timer0_ctc_mode,
	Timer0_phasecorrect_mode,
	Timer0_fastPWM_mode
}Timer0_mode_type;

typedef enum						// table 42
{
	Timer0_stop=0,
	Timer0_prescaler_1,
	Timer0_prescaler_8,
	Timer0_prescaler_64,
	Timer0_prescaler_256,
	Timer0_prescaler_1024,
	Timer0_external_falling,
	Timer0_external_rising
}Timer0_prescaler_type;

typedef enum						  // merge tables 39,40,41
{
	OCO_disconnected=0,
	OCO_toggle,
	OCO_non_inverting,					// fast PWM 
	OCO_inverting						// fast PWM

}OC0_mode_type;

void Timer0_initialize(Timer0_mode_type mode,Timer0_prescaler_type prescaler,OC0_mode_type OC0mode);
void Timer0_OV_Int_enable(void);
void Timer0_OV_Int_disable(void);
void Timer0_OC_Int_enable(void);
void Timer0_OC_Int_disable(void);

#endif /* TIMER_H_ */