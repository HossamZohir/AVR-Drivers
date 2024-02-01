
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

/*register manipulation*/
#define SET_REG(Reg)			Reg=0xFF
#define CLR_REG(Reg)			Reg=0x00
#define TOG_REG(Reg)			Reg^=0xFF
#define ASSIGN_REG(Reg,Value)	Reg=Value
#define SET_BITS_REG(Reg,Mask)	Reg|=(Mask)
#define CLR_BITS_REG(Reg,Mask)	Reg=(Reg&(~Mask))

/*bits manipulation*/
#define SET_BIT(Reg,BITNO)		(Reg) |=  (1 << (BITNO))		//uses the bitwise OR assignment operator (|=) to set the specified bit in the variable VAR without affecting the other bits.
#define CLR_BIT(Reg,BITNO)		(Reg) &= ~(1 << (BITNO))		//uses the bitwise AND assignment operator (&=) to clear the specified bit in the variable VAR without affecting the other bits.
#define TOG_BIT(Reg,BITNO)		(Reg) ^=  (1 << (BITNO))		//uses the bitwise XOR assignment operator (^=) to toggle the specified bit in the variable VAR. 
#define GET_BIT(Reg,BITNO)		(((Reg) >> (BITNO)) & 0x01)		//entire expression (((VAR) >> (BITNO)) & 0x01) extracts the value of a specific bit (BITNO) from the variable VAR. The result is either 0 or 1, representing the state of the extracted bit.


#endif