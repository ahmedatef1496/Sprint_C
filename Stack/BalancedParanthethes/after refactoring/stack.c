#include <stdio.h>
#include <stdlib.h>
#include"stdtypes.h"
#include "stack.h"
//////////////////////////////////functions body///////////////////////////////////
void createEmptyStack(ST_stack_t *stack)
{
    sp=-1;
}
///////////////////////////////////////////////////////////////////////////////////
int8_t push(ST_stack_t *stack, uint8_t data)
{
    stack_status status;
    if ( sp == STACK_SIZE-1)
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
///////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////
int8_t printStack(ST_stack_t *stack)
{
    int8_t sp_holder=sp;
    stack_status  status;
    if (sp_holder==-1)
    {
        //status =-2;
        status=STACK_EMPTY;

    }
    else if ( sp_holder == STACK_SIZE-1)
    {
        //status =-1;
        status=STACK_FULL;
    }
    else
    {
        status=STACK_OK;
        // status =0;

    }
    if (status==STACK_OK||status==STACK_FULL)
    {
        while(sp_holder>-1)
        {
            printf("%d->| %d\n",sp_holder,(stack->elements[sp_holder]));
            sp_holder--;

        }
    }

    return status;
}
///////////////////////////////////////////////////////////////////////////////////
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
        // printf("Peek value: %d\n", stack->elements[stack->top]);
        // status =0;
        status=STACK_OK;
    }



    return status;
}
///////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////
int8_t isFull(ST_stack_t *stack)
{
    stack_status status;

    if (sp==STACK_SIZE-1)
    {
        // status=-2;
        status=STACK_FULL;
    }
    return status;

}
///////////////////////////////////////////////////////////////////////////////////
