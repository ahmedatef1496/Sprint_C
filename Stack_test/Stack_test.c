#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  10
#define sp       stack->top

typedef unsigned char uint8_t ;
typedef char int8_t ;


typedef struct stack
{
    uint8_t elements[STACK_SIZE];
    int8_t top
} ST_stack_t; // Type

typedef enum
{

    STACK_EMPTY=-2,
    STACK_FULL=-1,
    STACK_OK=0
} stack_status;

/////////////////////////////////////////headers//////////////////////////////////////
void createEmptyStack(ST_stack_t *stack);
int8_t push(ST_stack_t *stack, uint8_t data);
int8_t pop(ST_stack_t *stack, uint8_t *data);
int8_t printStack(ST_stack_t *stack);
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
int8_t isEmpty(ST_stack_t *stack);
int8_t isFull(ST_stack_t *stack);
int8_t isBalancedParanthethes(uint8_t *expression);

//////////////////////////////////////////////////////////////////////////////////////
int main()
{
    uint8_t exp[] = {"{(2+3)/(<3+3>*(15-10))}"};
    int8_t rdata;

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

    return 0;
}






//////////////////////////////////functions body///////////////////////////////////
void createEmptyStack(ST_stack_t *stack)
{
    sp=-1;
}
int8_t push(ST_stack_t *stack, uint8_t data)
{
    stack_status status;
    if ( sp == STACK_SIZE)
    {
        //status =-1;
        status=STACK_FULL;
    }
    else
    {
        sp++;
        stack->elements[sp]=data;
        //status =0;
        status=STACK_OK;
    }
    return status ;
}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    stack_status status;

    if (sp==-1)
    {
        // status=-2;
        status=STACK_EMPTY;
    }

    else
    {
        *data =stack->elements[sp];
        sp--;
        // status =0;
        status=STACK_OK;
    }



    return status;
}
int8_t printStack(ST_stack_t *stack)
{
    stack_status  status;
    if (sp==-1)
    {
        //status =-2;
        status=STACK_EMPTY;
    }
    else if ( sp == STACK_SIZE)
    {
        //status =-1;
        status=STACK_FULL;
    }
    else
    {
        status=STACK_OK;
        // status =0;
        while(sp>-1)
        {
            printf("%d->| %c\n",sp,(stack->elements[sp]));
            sp--;

        }
    }


    return status;
}
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    stack_status status;

    if (sp==-1)
    {
        // status=-2;
        status=STACK_EMPTY;
    }

    else
    {
        *topData =stack->elements[sp];
        // status =0;
        status=STACK_OK;
    }



    return status;
}
int8_t isEmpty(ST_stack_t *stack)
{
    stack_status status;

    if (sp==-1)
    {
        // status=-2;
        status=STACK_EMPTY;
    }
    return status;
}
int8_t isFull(ST_stack_t *stack)
{
    stack_status status;

    if (sp==STACK_SIZE)
    {
        // status=-2;
        status=STACK_FULL;
    }
    return status;

}
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
    {
        pop_return=0;
        if (expression[counter] == '{' ||expression[counter] == '(' )
        {
            push(&stackH, expression[counter]);
        }

        else if (expression[counter] == '}' || expression[counter] == ')' )
        {

            if (isEmpty(&stackH)==STACK_EMPTY)
            {
                flag = -1; //unbalanced
            }
            else
            {

                pop(&stackH,&pop_return);


                if (pop_return == '(' && expression[counter] == ')')
                {


                    flag= 0; //balanced
                }
                else if (pop_return == '{' && expression[counter] == '}')
                {
                    flag= 0; //balanced
                }
                else
                {
                    flag=  -1;

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
        }
    }
    return flag ;

}


