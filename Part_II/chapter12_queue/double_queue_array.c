#include <stdio.h>
#include <stdlib.h>
#include "double_queue.h"

#define N 100

struct dqueue {
    int n;
    int first;
    float array[N];
};

/* create function: returns an empty queue */
DQueue* dqueue_create (void)
{
    DQueue* q = (DQueue*) malloc(sizeof(DQueue));
    q->n = 0;
    q->first = 0;
    return q;
}

/* add function: adds a new element at the beginning of the queue */
void dqueue_add_beginning (DQueue* q, float v)
{
    if(q->n == N) {
        printf("Full queue exception.");
        exit(1);
    }       
    int prec = (q->first - 1 + N) % N;
    q->array[prec] = v;
    q->first = prec;
    q->n++;
}

/* add function: adds a new element at the end of the queue */
void dqueue_add_end (DQueue* q, float v)
{
    int end;
    if(q->n == N) {
        printf("Full queue exception.");
        exit(1);
    }

    end = (q->first + q->n) % N;
    q->array[end] = v;
    q->n++;
}

/* empty function: returns 1 if empty or 0 if not empty */
int dqueue_empty (DQueue* q)
{
    return (q->n == 0);
}

/* remove function: removes and returns the first element of the queue */
float dqueue_remove_beginning (DQueue* q)
{
    float v;
    if(dqueue_empty(q)) {
        printf("The queue is empty.");
        exit(1);
    }
    v = q->array[q->first];
    q->first = (q->first + 1) % N;
    q->n--;
    return v;
}

/* remove function: removes and returns the last element of the queue */
float dqueue_remove_end (DQueue* q)
{
    if(dqueue_empty(q)) {
        printf("The queue is empty.");
        exit(1);
    }
    int las = (q->first + q->n - 1) % N;
    float v = q->array[las];
    q->n--;
    return v;
}

/* free function: frees all elements from the queue */
void dqueue_free (DQueue* q)
{
    free(q);
}

void dqueue_print (DQueue* q)
{
    int i;
    for(i=0; i<q->n; i++)
        printf("%f\n",q->array[(q->first+i)%N]);
}