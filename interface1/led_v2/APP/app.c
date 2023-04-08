/*
 * app.h
 *
 * Created: 4/7/2023 3:44:35 AM
 *  Author: atef
 */ 
#define  F_CPU  8000000
#include <util/delay.h>
#include "app.h"

u16 led_counter=0;
 
void app_start_v2 (void)
{ 
		   if (led_counter>7)
		   {
			   led_counter=0;
		   }
		   
		   if ( led_counter<=3)
		   {  
			    LED_on(LED1+led_counter);  
		   }
		   else if ( led_counter>3)
		   {  
			    LED_off(LED1+(led_counter-4)); 
		   }
		   led_counter++;
} 


 void app_init(void)
 {
	 LED_init(LED1);
	 LED_init(LED2);
	 LED_init(LED3);
	 LED_init(LED4);
	 BUTTON_init(button1);
	 BUTTON_init(button2);
	  
	  
	  	GLOBALE_ENABLE();
	  	EXI_Enable(EX_INT0);
	  	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	  	EXI_SetCallBack(EX_INT0,app_start_v2);
 }