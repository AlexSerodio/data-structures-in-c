#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "stack.h"

struct calc {
    char f[21];
    Stack* s;
};

/* create function: returns an empty calculator */
Calc* calc_create (char* f)
{
    Calc* c = (Calc*) malloc(sizeof(Calc));
    strcpy(c->f, f);
    c->s = stack_create();
    return c;
}

/* operand function: adds the value on the stack and print it */
void calc_operand (Calc* c, float v)
{
    stack_push(c->s, v);
    printf(c->f,v);
}

/* operator function: removes two values from the stack, apply the specified operation 
    on them, adds the result on the stack and print it */
void calc_operator (Calc* c, char op)
{
    float v1, v2, v;

    if(stack_empty(c->s))
        v2 = 0.0;
    else
        v2 = stack_pop(c->s);
    
    if(stack_empty(c->s))
        v1 = 0.0;
    else
        v1 = stack_pop(c->s);

    switch(op) {
        case '+': v = v1+v2; break;
        case '-': v = v1-v2; break;
        case '*': v = v1*v2; break;
        case '/': v = v1/v2; break;
    }

    stack_push(c->s, v);

    printf(c->f, v);
}

/* free function: frees all elements from the stack and them free the calculator */
void calc_free (Calc* c)
{
    stack_free(c->s);
    free(c);
}