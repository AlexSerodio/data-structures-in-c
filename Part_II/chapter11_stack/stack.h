/* ADT: Stack of float*/

/* Exported type */
typedef struct stack Stack;

/** create function
 *  returns an empty stack
**/
Stack* stack_create (void);

/** push function
 *  adds a new element on the top of the stack
**/
void stack_push (Stack* s, float v);

/** pop function
 *  removes and returns the element on the top of the stack
**/
float stack_pop (Stack* s);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int stack_empty (Stack* s);

/** free function 
 *  frees all elements from the stack 
**/
void stack_free (Stack* s);