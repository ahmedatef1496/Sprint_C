#include <stdio.h>
#include <stdlib.h>
#include"stdtypes.h"
#include "stack.h"
#include "balanced.h"

int8_t isBalancedParanthethes(uint8_t *expression)
{
    int counter=0;
    uint8_t pop_return ;
    int8_t flag=0;
    int exp_flag=0;
    ST_stack_t stackH;
    createEmptyStack(&stackH);
    printStack(&stackH);
    ////////////////////////////CHECK IF THER IS ANY parentheses /////////
    while (expression[counter])
    {
        if(expression[counter] == '{' ||
                expression[counter] == '(' ||
                expression[counter] == '}' ||
                expression[counter] == ')' )
        {
            exp_flag++;
        }

        counter++;
    }
    if (exp_flag==0)
    {
        return -2;
    }
    ////////////////////////////////////////////////////////////////////
    counter=0;
    while (expression[counter])
    { //printf("%c \n",expression[counter]);
        pop_return=0;
        if (expression[counter] == '{' ||expression[counter] == '(' )
        {
            push(&stackH, expression[counter]);
            //printf("here1\n");
        }

        else if (expression[counter] == '}' || expression[counter] == ')' )
        {

            if (isEmpty(&stackH)==STACK_EMPTY)
            {
                flag = -1; //unbalanced
               // printf("here2\n");
            }
            else
            {

                pop(&stackH,&pop_return);
              //  printf("here3\n");


                if (pop_return == '(' && expression[counter] == ')')
                {


                    flag= 0; //balanced
                   // printf("here4\n");
                }
                else if (pop_return == '{' && expression[counter] == '}')
                {
                    flag= 0; //balanced
                }
                else
                {
                    flag=  -1;
                   // printf("here5\n");

                }

            }
        }

        counter++;
    }
    if (flag==0)
    {
        if (isEmpty (&stackH)==-2)
        {
            flag=0;//balanced
        }
        else
        {
            flag=-1;//unbalanced
            //printf("here6\n");
        }
    }
    return flag ;

}
///////////////////////////////////////////////////////////////////////////////////
void expression_scan(char*str,int maxsize)
{
    int i=0;
    fflush(stdin);
    scanf(" %c",&str[i]);
    for(; str[i]!='\n'&&i<maxsize-1;)
    {
        i++;
        scanf("%c",&str[i]);

    }
    str[i]=0;
}
///////////////////////////////////////////////////////////////////////////////////
void expression_print(char*arr)
{
    int i;
    for(i=0; arr[i]; i++)
    {
        printf("%c",arr[i]);
    }

    printf("\n--------------------------------------------\n");
}
int expressionlen (char*str)
{
    int i;
    for(i=0; str[i]; i++);

    return i;
}
///////////////////////////////////////////////////////////////////////////////////
