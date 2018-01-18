#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define N 50

struct stack {
    int n;
    float array[N];
};

/* create function: returns an empty stack */
Stack* stack_create (void)
{
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->n = 0;
    return s;
}

//push function: adds a new element on the top of the stack
void stack_push (Stack* s, float v)
{
    if(s->n == N) {
        printf("Full stack exception.\n");
        exit(1);
    }
    s->array[s->n] = v;
    s->n++;
}

//empty function: returns 1 if empty or 0 if not empty
int stack_empty (Stack* s)
{
    return (s->n == 0);
}

//pop function: removes and returns the element on the top of the stack
float stack_pop (Stack* s)
{
    if(stack_empty(s)) {
        printf("Empty stack exception.\n");
        exit(1);
    }
    s->n--;
    return s->array[s->n];
}

//free function: frees all elements from the stack
void stack_free (Stack* s)
{
    free(s);
}