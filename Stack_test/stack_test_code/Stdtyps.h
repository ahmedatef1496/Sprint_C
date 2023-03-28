#define STACK_SIZE  10
#define sp       stack->top
#define spm       stack.top

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


