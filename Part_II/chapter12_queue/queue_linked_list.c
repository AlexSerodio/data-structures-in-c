#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct list {
    float data;
    struct list* next;
};
typedef struct list List;

struct queue {
    List* first;
    List* end;
};

/* create function: returns an empty queue */
Queue* queue_create (void)
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->first = q->end = NULL;
    return q;
}

/* add function: adds a new element at the end of the queue */
void queue_add (Queue* q, float v)
{
    List* l = (List*) malloc(sizeof(List));
    l->data = v;
    l->next = NULL;
    if(q->end != NULL)
        q->end->next = l;
    else
        q->first = l;
    q->end = l;
}

/* empty function: returns 1 if empty or 0 if not empty */
int queue_empty (Queue* q)
{
    return (q->first == NULL);
}

/* remove function: removes and returns the first element of the queue */
float queue_remove (Queue* q)
{
    List* t;
    float v;
    if(queue_empty(q)) {
        printf("Empty queue.");
        exit(1);
    }
    t = q->first;
    v = t->data;
    q->first = t->next;
    if(q->first == NULL)
        q->end = NULL;
    
    free(t);
    return v;
}

/* free function: frees all elements from the queue */
void queue_free (Queue* q)
{
    List* l = q->first;
    while(l != NULL) {
        List* t = l->next;
        free(l);
        l = t;
    }
    free(q);
}

/* print function: prints all elements from the queue */
void queue_print (Queue* q)
{
    List* l;
    for(l=q->first; l!=NULL; l=l->next)
        printf("%f\n",l->data);
}