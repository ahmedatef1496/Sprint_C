//////////////////////////////////////////////////////////////////////////////////////
/*  isBalancedParanthethes
    Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression);
//////////////////////////////////////////////////////////////////////////////////////
/*  expression_scan
    Description:
    This function takes an expression from user and store it
 */
void expression_scan(char*str,int maxsize);
//////////////////////////////////////////////////////////////////////////////////////
/*  expression_scan
    Description:
    This function takes an expression and print it
 */
void expression_print(char*arr);
//////////////////////////////////////////////////////////////////////////////////////
int  expressionlen (char*str);
/*  expression_scan
    Description:
    This function takes an expression and return length of it
 */
//////////////////////////////////////////////////////////////////////////////////////
