#define STACK_SIZE  10                                    // u can configure stack size
#define sp       stack->top
#define spm       stack.top
///////////////////////////////////////////////////////////////////////////////////////

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

/*  createEmptyStack
    Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t *stack);
///////////////////////////////////////////////////////////////////////////////////////
/*  push
    Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t *stack, uint8_t data);
///////////////////////////////////////////////////////////////////////////////////////
/*  pop
    Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t *stack, uint8_t *data);
///////////////////////////////////////////////////////////////////////////////////////
/*  printStack
    Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t *stack);
///////////////////////////////////////////////////////////////////////////////////////
/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
///////////////////////////////////////////////////////////////////////////////////////
/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack);
///////////////////////////////////////////////////////////////////////////////////////
/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t *stack);
///////////////////////////////////////////////////////////////////////////////////////

