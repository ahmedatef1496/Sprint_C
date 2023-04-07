#define  F_CPU  8000000
#include <util/delay.h>
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_Interface.h"


int main(void)
{
	DIO_Init();
   int led=0 ,flag =0;
	 
while(1)
{
    led=0;
    while (!flag)
    {
        if (! DIO_ReadPin(PIND7))
        {
            if (led>3)
            {
                flag=1;
                continue;
            }

            DIO_WritePin(PINB0+led,HIGH);
            led++;

            while (! DIO_ReadPin(PIND7))  ;  //busy wait
        }
    }
    led=3;
    while (flag)
    {
        if (! DIO_ReadPin(PIND7))
        {

            DIO_WritePin(PINB3-led,LOW);
            led--;
            if (led<0)
            {
                flag=0;
                continue;
            }
            while (! DIO_ReadPin(PIND7))  ;  //busy wait
        }
    }
    _delay_ms(300);


}


}
