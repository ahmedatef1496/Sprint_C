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


void timer_delay(u16 desiredDelay)
{
    double systemClock = F_CPU;
    double oneTickTime = (8 / systemClock) * 1000; // in ms
    double maxDelay = oneTickTime * 256; // in ms
    int overflowsCount = ceil(desiredDelay / maxDelay); 
    u8 timerInitValue;
    if (overflowsCount > 1)
    {
        timerInitValue = (u8)(256 - ((desiredDelay - (maxDelay * (overflowsCount - 1))) / oneTickTime));
    }
    else
    {
        timerInitValue = floor((maxDelay - desiredDelay)/oneTickTime); 
    }
    timer_setTimerValue(timerInitValue);

    timer_start(TIMER0_SCALER_8);

    int currentOverflowNumber = 0;
    do{
        while((READ_BIT(TIFR, 0)) == 0);
        currentOverflowNumber++;
        SET_BIT(TIFR, 0);
    } while (currentOverflowNumber < overflowsCount);
    timer_reset();
}
 void TIMER0_OV_InterruptEnable(void)
 {
	 SET_BIT(TIMSK,TOIE0);
 }
 void TIMER0_OV_InterruptDisable(void)
 {
	 CLR_BIT(TIMSK,TOIE0);
 }
 void TIMER0_OC_InterruptEnable(void)
 {
	 SET_BIT(TIMSK,OCIE0);
 }
 void TIMER0_OC_InterruptDisable(void)
 {
	 CLR_BIT(TIMSK,OCIE0);
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
 
 