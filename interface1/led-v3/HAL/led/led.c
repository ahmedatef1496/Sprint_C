/*
 * led.c
 *
 * Created: 4/7/2023 3:38:36 AM
 *  Author: atef
 */ 

#include "led.h"
#include "Stdtyps.h" 

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


void LED_blink( DIO_Pin_type led , u16 on_t, u16 off_t)
{
	LED_on(led);
	timer_delay(on_t);
	LED_off(led);
	timer_delay(off_t);
} 
void LEDS_blink( u16 ledS_PINS , u16 on_t, u16 off_t)
{
	PORTB=ledS_PINS;
	timer_delay(on_t);
	PORTB=0;
	timer_delay(off_t);
}

/*
typedef enum{
	M1,
	M2,
	M3,
	M4,
	M5
}MOTOR_type;


void MOTOR_Init(void);

void MOTOR_Stop(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);
//  speed from 0 to 100  %///
void MOTOR_Speed(MOTOR_type motor,u8 speed);*/