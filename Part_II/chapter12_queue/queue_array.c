#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define N 100

struct queue {
    int n;
    int first;
    float array[N];
};

/* create function: returns an empty queue */
Queue* queue_create (void)
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->n = 0;
    q->first = 0;
    return q;
}

/* add function: adds a new element at the end of the queue */
void queue_add (Queue* q, float v)
{
    if(q->n == N) {
        printf("Full queue exception.");
        exit(1);
    }
    int end = (q->first + q->n) % N;
    q->array[end] = v;
    q->n++;
}

/* empty function: returns 1 if empty or 0 if not empty */
int queue_empty (Queue* q)
{
    return (q->n == 0);
}

/* remove function: removes and returns the first element of the queue */
float queue_remove (Queue* q)
{
    if(queue_empty(q)) {
        printf("The queue is empty.");
        exit(1);
    }
    float v = q->array[q->first];
    q->first = (q->first + 1) % N;
    q->n--;
    return v;
}

/* free function: frees all elements from the queue */
void queue_free (Queue* q)
{
    free(q);
}

void queue_print (Queue* q)
{
    int i;
    for(i=0; i<q->n; i++)
        printf("%f\n",q->array[(q->first+i)%N]);
}