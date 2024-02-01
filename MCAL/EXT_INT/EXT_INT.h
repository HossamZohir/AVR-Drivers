/*
 * EXT_INT.h
 *
 * Created: 12/7/2023 11:38:48 PM
 *  Author: Hossam
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_


#include "../../MYLIB/BIT_MATH.h"
#include "../../MYLIB/Memory_map.h"
#include "../../MYLIB/STD_TYPES.h"
#include "../DIO/DIO_int.h"
#include "../../HAL/LCD/LCD.h"



typedef enum
{
	Ex_int0=0,
	Ex_int1,
	Ex_int2
}EXT_INTER_name;

typedef enum
{
	low_level=0,
	Any_logical_change,
	falling_edge,
	rising_edge
}EXT_INTER_control_mode;

void EXT_INTER_enable (EXT_INTER_name interrupt);
void EXT_INTER_disable (EXT_INTER_name interrupt);
void EXT_INTER_trigger (EXT_INTER_name interrupt, EXT_INTER_control_mode triggering );
void EXT_INTER_setcallback(EXT_INTER_name interrupt, void(*LocalPtr)(void));






#endif /* EXT_INT_H_ */