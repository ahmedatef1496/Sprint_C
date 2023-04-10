/*
 * timers.c
 *
 * Created: 4/9/2023 7:36:42 PM
 *  Author: atef
 */ 
#include "timers.h"

/*************************Pointer to functions to be assigned to ISR*********************************/
static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;
/******************************************************************************************/


void TIMER0_Init_all(Timer0Mode_type mode,Timer0Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	TCCR0&=0XF8;//0b11111000
	TCCR0|=scaler;
}


void TIMER0_Init(Timer0Mode_type mode)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
} 

 EN_timerError_t timer_start(Timer0Scaler_type scaler)
 {
	 switch (scaler) {
		 case TIMER0_STOP:
		 case TIMER0_SCALER_1:
		 case TIMER0_SCALER_8:
		 case TIMER0_SCALER_64:
		 case TIMER0_SCALER_256:
		 case TIMER0_SCALER_1024:
		 case EXTERNALl_FALLING:
		 case EXTERNAL_RISING:
		 TCCR0&=0XF8;//0b11111000
		 TCCR0|=scaler;
		 return TIMER_OK;
		 default:
		 return TIMER_Error;
	 }
 } 
 
 void timer_reset()
 {
	 TCCR0 &= 0x00; 
	 CLR_BIT(TIFR, 0); 
	 TCNT0 = 0; 
 }

 void timer_InitValue(u8 timerInitValue)
 {
	 TCNT0 = timerInitValue;
 }  
 void TIMER0_OC0Mode(OC0Mode_type mode)
 {
	 switch (mode)
	 {
		 case OC0_DISCONNECTED:
		 CLR_BIT(TCCR0,COM00);
		 CLR_BIT(TCCR0,COM01);
		 break;
		 case OC0_TOGGLE:
		 SET_BIT(TCCR0,COM00);
		 CLR_BIT(TCCR0,COM01);
		 break;
		 case OC0_NON_INVERTING:
		 CLR_BIT(TCCR0,COM00);
		 SET_BIT(TCCR0,COM01);
		 break;
		 case OC0_INVERTING:
		 SET_BIT(TCCR0,COM00);
		 SET_BIT(TCCR0,COM01);
		 break;
	 }
 }
 void timer_setTimerValue(u8 timerInitValue)
{
    TCNT0 = timerInitValue;
}



 ////////////////////////////////////////////Timer 0 Call Back functions///////////////////////////////////////
 void TIMER0_OV_SetCallBack(void(*LocalFptr)(void))
 {
	 Timer0_OVF_Fptr=LocalFptr;
 }
 ////////////////////////////////////////////Timer 0 ISR functions////////////////////////////////////////////
 ISR(TIMER0_OVF_vect)
 {
	 if(Timer0_OVF_Fptr!=NULLPTR)
	 {
		 Timer0_OVF_Fptr();
	 }
 }
 //////////////////////////////////////////// 
 
 
