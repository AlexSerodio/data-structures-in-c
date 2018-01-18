#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct list {
    float data;
    struct list* next;
};
typedef struct list List;

struct stack {
    List* first;
};

/* create function: returns an empty stack */
Stack* stack_create (void)
{
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->first = NULL;
    return s;
}

//push function: adds a new element on the top of the stack
void stack_push (Stack* s, float v)
{
    List* l = (List*) malloc(sizeof(List));
    l->data = v;
    l->next = s->first;
    s->first = l;
}

//empty function: returns 1 if empty or 0 if not empty
int stack_empty (Stack* s)
{
    return (s->first == NULL);
}

//pop function: removes and returns the element on the top of the stack
float stack_pop (Stack* s)
{
    List* t;
    float v;
    if(stack_empty(s)) {
        printf("Empty stack exception.\n");
        exit(1);
    }
    t = s->first;
    v = t->data;
    s->first = t->next;
    free(t);
}

//free function: frees all elements from the stack
void stack_free (Stack* s)
{
    List* l = s->first;
    while(l != NULL) {
        List* t = l->next;
        free(l);
        l = t;
    }
    free(s);
}