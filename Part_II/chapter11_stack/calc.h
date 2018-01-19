/* ADT: float calculator */

/* Exported type */
typedef struct calc Calc;

/** create function
 *  returns an empty calculator
**/
Calc* calc_create (char* f);

/** operand function
 *  adds the value on the stack and print it
**/
void calc_operand (Calc* c, float v);

/** operator function
 *  removes two values from the stack, apply the specified operation on them,
 *  adds the result on the stack and print it
**/
void calc_operator (Calc* c, char op);

/** free function 
 *  frees all elements from the stack and them free the calculator 
**/
void calc_free (Calc* c);