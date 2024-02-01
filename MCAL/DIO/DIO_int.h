/*
 * DIO_int.h
 *
 * Created: 12/1/2023 8:48:27 PM
 *  Author: Hossam
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "DIO_config.h"
#include "../../MYLIB/STD_TYPES.h"
#include "../../MYLIB/BIT_MATH.h"
#include "../../MYLIB/Memory_map.h"

/*4 ports from 0 to 3*/
typedef enum
{
	PA=0,
	PB,
	PC,
	PD,
}Port_type;

typedef enum
{
	LOW=0,
	HIGH=1,
}VoltageLevel_type;


extern void DIO_initialize(void);
extern void DIO_WritePort(Port_type Port, u8 Value);
extern void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask);
extern u8	DIO_ReadPort(Port_type Port);
extern void DIO_WritePin(PinNum_type Pin,VoltageLevel_type Value);
extern void DIO_TogglePin(PinNum_type Pin);
extern VoltageLevel_type DIO_ReadPin(PinNum_type Pin);

#endif /* DIO_INT_H_ */