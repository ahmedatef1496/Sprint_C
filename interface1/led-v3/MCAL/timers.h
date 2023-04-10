/*
 * TIMER.h
 *
 * Created: 4/8/2023 3:25:32 AM
 *  Author: atef
 */ 

#ifndef TIMERS_H_
#define TIMERS_H_

#include "Stdtyps.h"
#include "Utils.h"
#include "register.h"
#define  F_CPU   8000000
/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0
////////////////////////////////////////
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;


typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;

typedef enum EN_timerError_t
{
	TIMER_OK,
	TIMER_Error
}EN_timerError_t;
/////////////////////////////////////////////////////////////
void TIMER0_Init_all(Timer0Mode_type mode,Timer0Scaler_type scaler);
void TIMER0_Init(Timer0Mode_type mode);
void timer_InitValue(u8 timerInitValue);
EN_timerError_t timer_start(Timer0Scaler_type scaler);
void timer_reset();
void timer_delay(u16 desiredDelay);
void TIMER0_OC0Mode(OC0Mode_type mode);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OV_SetCallBack(void(*LocalFptr)(void));


#endif /* TIMERS_H_ */