/*
 * app.h
 *
 * Created: 4/7/2023 3:44:46 AM
 *  Author: atef
 */ 


#ifndef APP_H_
#define APP_H_

#include "button.h"
#include "led.h"
#include "EX_Interrupt.h"

typedef struct ST_BLINKING_t {
	u16 ton;
	u16 toff;
}ST_BLINKING_t;

 void app_init(void);
 void app_start_v3 (void);


#endif /* APP_H_ */
