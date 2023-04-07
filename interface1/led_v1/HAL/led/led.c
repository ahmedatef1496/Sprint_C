/*
 * led.c
 *
 * Created: 4/7/2023 3:38:36 AM
 *  Author: atef
 */ 

#include "led.h"


void LED_init   (DIO_Pin_type pin)
{ 
	DIO_InitPin(pin,OUTPUT);
}
void LED_on     (DIO_Pin_type pin)
{
	DIO_WritePin(pin,HIGH);
}
void LED_off    (DIO_Pin_type pin)
{
    DIO_WritePin(pin,LOW);	
}
void LED_toggel (DIO_Pin_type pin)
{
	
}