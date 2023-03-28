#include <stdio.h>
#include <stdlib.h>
#include"stdtypes.h"
#include "stack.h"
#include "balanced.h"
#include "main.h"





int main()
{
    uint8_t exp[SCAN_SIZE] ;
    int8_t rdata;
    int Explen=0;
    while(1)
    {
        printf("**Enter exp**\n");
        expression_scan(&exp,SCAN_SIZE );
        Explen=expressionlen(exp);
        if(Explen>EXPRESSIOS_MAX_SIZE)
        {
            printf("\nwrong entry your expression more than %d character,try another\n\n",EXPRESSIOS_MAX_SIZE);
            continue;
        }




        rdata= isBalancedParanthethes(&exp) ;

        if (rdata==-1)
        {
            printf("not balanced\n",rdata);
        }
        else if (rdata==0)
        {
            printf("balanced\n",rdata);
        }
        else
        {
            printf("neither of parentheses is used\n",rdata);
        }


    }
    return 0;
}




