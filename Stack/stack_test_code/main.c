#include <stdio.h>
#include "Stdtyps.h"
#include "stack.h"
ST_stack_t stack;
int main()
{

    uint8_t poppedData = 0;
    uint8_t Stack_Top = 0;

    // 1. Create an empty stack
    createEmptyStack(&stack);

    // 2. Push 5 different characters to the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    // 3. Print all stack data
    printStack(&stack);
    //4. Pop one character from the stack
    pop(&stack, &poppedData);
    //5. Print the stack's top
    getStackTop(&stack,&Stack_Top);
    printf("stack top: %d\n",Stack_Top);
    //6. Print all stack data
    printStack(&stack);
    //7. Push another 7 different characters to the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);
    //8. Print the stack's top
    getStackTop(&stack,&Stack_Top);
    printf("stack top: %d\n",Stack_Top);
    //9. Print all stack data
    printStack(&stack);

    //10. Pop 4 characters from the stack
    pop(&stack, &poppedData);
    pop(&stack, &poppedData);
    pop(&stack, &poppedData);
    pop(&stack, &poppedData);
    //11. Print the stack's top
    getStackTop(&stack,&Stack_Top);
    printf("stack top:%d-> %d\n",spm,Stack_Top);
    //12. Print all stack data
    printStack(&stack);
    //13. Pop 7 more times from the stack
    pop(&stack, &poppedData);
    pop(&stack, &poppedData);
    pop(&stack, &poppedData);
    if ((pop(&stack, &poppedData)==STACK_EMPTY))
{
    printf("stack is empty \n") ;
}
if ((pop(&stack, &poppedData)==STACK_EMPTY))
{
    printf("stack is empty \n") ;
}
if ((pop(&stack, &poppedData)==STACK_EMPTY))
{
    printf("stack is empty \n") ;
}
if ((pop(&stack, &poppedData)==STACK_EMPTY))
{
    printf("stack is empty \n") ;
}
//14. Print the stack's top
getStackTop(&stack,&Stack_Top);
  printf("stack top:%d-> %d\n",spm,Stack_Top);
//15. Print all stack data


return 0;
}
