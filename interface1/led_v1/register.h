/*
 * Registers.h
 *
 * Created: 4/3/2023 
 * Author : Ahmed Atef
 * email  : ahmedaatf15@gmail.com
 */ 
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Stdtyps.h"

/************************************************************************/
/*							DIO_REGISTERS								*/
/************************************************************************/

// PORTA registers
#define  PORTA   (*(volatile unsigned char*)0X3B)
#define  DDRA   (*(volatile unsigned char*)0X3A)
#define  PINA   (*(volatile unsigned char*)0X39)
// PORTB registers
#define  PORTB   (*(volatile unsigned char*)0X38)
#define  DDRB  (*(volatile unsigned char*)0X37)
#define  PINB   (*(volatile unsigned char*)0X36)
// PORTC registers
#define  PORTC   (*(volatile unsigned char*)0X35)
#define  DDRC  (*(volatile unsigned char*)0X34)
#define  PINC   (*(volatile unsigned char*)0X33)
// PORTD registers
#define  PORTD   (*(volatile unsigned char*)0X32)
#define  DDRD  (*(volatile unsigned char*)0X31)
#define  PIND   (*(const volatile unsigned char*)0X30)

#endif // !REGISTERS_H_