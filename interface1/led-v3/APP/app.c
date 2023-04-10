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
u16 blinking_leds_mode=0,blinking_time_mode=1; 

	  		  ST_BLINKING_t blinking_times=
	  		  {.ton=100,
	  		  .toff=900}
	  		  ;


 
void app_start_v1()
  {   
	  int led=0 ,flag =0;
	  DIO_PinVoltage_type data=HIGH;
	  while(1)
	  {
		  led=0;
		  while (!flag)
		  { BUTTON_read(button1,&data);
			  if (!data)
			  {
				  if (led>3)
				  {
					  flag=1;
					  continue;
				  }

				  LED_on(LED1+led);
				  led++;
				  
				 _delay_ms(300) ;  
			  }
		  }
		  led=3;
		  while (flag)
		  { BUTTON_read(button1,&data);
			  if  (!data)
			  {

				  LED_off(LED4-led);
				  led--;
				  if (led<0)
				  {
					  flag=0;
					  continue;
				  }
				  _delay_ms(300) ;  
			  }
		  }
		  _delay_ms(300);


	  }
  }
void app_start2()
  { 
	  int led=0 ,flag =0;
	  while(1)
	  {
		  led=0;
		  while (!flag)
		  {
			  if (!BUTTON_read2(button1))
			  {
				  if (led>3)
				  {
					  flag=1;
					  continue;
				  }

				  LED_on(LED1+led);
				  led++;
				  
				  while (!BUTTON_read2(button1)) ;  //busy wait
			  }
		  }
		  led=3;
		  while (flag)
		  {
			  if  (!BUTTON_read2(button1))
			  {

				  LED_off(LED4-led);
				  led--;
				  if (led<0)
				  {
					  flag=0;
					  continue;
				  }
				  while  (!BUTTON_read2(button1)) ;  //busy wait
			  }
		  }
		  _delay_ms(300);


	  }
  }
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
void set_leds_mode (void)
{   
	 static u16 leds_mode=0;
		   if (leds_mode==7)
		   {  CLR_BIT(blinking_leds_mode,(leds_mode-4));
			   leds_mode=0;
		   }

		    if ( leds_mode<=3)
		   {
			   SET_BIT(blinking_leds_mode,leds_mode);	
		   }
		   else if ( leds_mode>3)
		   {  
			   CLR_BIT(blinking_leds_mode,(leds_mode-4));
		   } 

		   leds_mode++; 

}  
void set_blinking_t_mode (void)
{    
              		switch (blinking_time_mode)
              		{
	              		case 1:	blinking_times.ton =  100;   blinking_times.toff=900;  blinking_time_mode++;
	              		break;
	              		case 2:	blinking_times.ton  = 200;	 blinking_times.toff=800;  blinking_time_mode++;
	              		break;
	              		case 3:	blinking_times.ton  = 300;	 blinking_times.toff=700;  blinking_time_mode++;
	              		break;
	              		case 4:	blinking_times.ton  = 500;	 blinking_times.toff=500;  blinking_time_mode++;
	              		break;
	              		case 5:	blinking_times.ton  = 800;	 blinking_times.toff=200;  blinking_time_mode++;
	              		break;
	              		default:blinking_times.ton =  100;   blinking_times.toff=900; blinking_time_mode=1;
	              		break;
              		}
}
void app_start_v3 (void)
{ 

while(1)
{
	 LEDS_blink(blinking_leds_mode,blinking_times.ton,blinking_times.toff);
	 PORTA=blinking_time_mode;
}

}
void app_init(void)
 {
	 LED_init(LED1);
	 LED_init(LED2);
	 LED_init(LED3);
	 LED_init(LED4);
	 BUTTON_init(button1);
	 BUTTON_init(button2);
	  BUTTON_init(button3);
	  

	  	GLOBALE_ENABLE();
	  	EXI_Enable(EX_INT0);
	  	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	  	EXI_SetCallBack(EX_INT0,set_blinking_t_mode);
		EXI_Enable(EX_INT1);
	  	EXI_TriggerEdge(EX_INT1,RISING_EDGE);
	  	EXI_SetCallBack(EX_INT1,set_leds_mode);
		  

 }