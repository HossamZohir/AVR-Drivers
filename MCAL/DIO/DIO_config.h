/*
 * DIO_config.h
 *
 * Created: 12/1/2023 8:48:02 PM
 *  Author: Hossam
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/* pin status */
typedef enum
{
	OUTPUT=0,
	INPULLUP,
	INFREE,
}PinStatus_type;

/* pin numbers 4*8=32 */
typedef enum
{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}PinNum_type;

/*array of 32 element from type (PinNum_type) would be defined in separated (DIO_config.c) file 
  WHY?? 
  you need to be careful to avoid multiple definitions when including the header in multiple source files. 
  To do this, you can use the extern keyword in the header file and define the array in a single source file.*/

extern const PinStatus_type PinsStatus[TOTAL_PINS];



#endif /* DIO_CONFIG_H_ */