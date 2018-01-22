#include <stdio.h>
#include <stdlib.h>
#include "double_queue.h"

struct dlist {
    float data;
    struct dlist* pre;
    struct dlist* next;
};
typedef struct dlist DList;

struct dqueue {
    DList* first;
    DList* end;
};

/* auxiliar function: adds at the beginning */
static DList* add_beginning (DList* first, float v)
{
    DList* p = (DList*) malloc(sizeof(DList));
    p->data = v;
    p->next = first;
    p->pre = NULL;
    if(first != NULL)
        first->pre = p;
    return p;
}

/* auxiliar function: adds at the end */
static DList* add_end (DList* end, float v)
{
    DList* p = (DList*) malloc(sizeof(DList));
    p->data = v;
    p->next = NULL;
    p->pre = end;
    if(end != NULL)
        end->next = p;
    return p;
}

/* auxiliar function: removes at the beginning */
static DList* remove_beginning (DList* first)
{
    DList* p = first->next;
    if(p != NULL)
        p->pre = NULL;
    free(first);
    return p;
}

/* auxiliar function: removes at the end */
static DList* remove_end (DList* end)
{
    DList* p = end->pre;
    if(p != NULL)
        p->next = NULL;
    free(end);
    return p;
}

/* create function: returns an empty queue */
DQueue* dqueue_create (void)
{
    DQueue* q = (DQueue*) malloc(sizeof(DQueue));
    q->first = q->end = NULL;
    return q;
}

/* add function: adds a new element at the beginning of the queue */
void dqueue_add_beginning (DQueue* q, float v)
{
    q->first = add_beginning(q->first, v);
    if(q->end == NULL)
        q->end = q->first;
}

/* add function: adds a new element at the end of the queue */
void dqueue_add_end (DQueue* q, float v)
{
    q->end = add_end(q->end, v);
    if(q->first == NULL)
        q->first = q->end;
}

/* empty function: returns 1 if empty or 0 if not empty */
int dqueue_empty (DQueue* q)
{
    return (q->first == NULL);
}

/* remove function: removes and returns the first element of the queue */
float dqueue_remove_beginning (DQueue* q)
{
    if(dqueue_empty(q)) {
        printf("Empty queue.");
        exit(1);
    }
    float v = q->first->data;
    q->first = remove_beginning(q->first);
    if(q->first == NULL)
        q->end = NULL;
    return v;    
}

/* remove function: removes and returns the last element of the queue */
float dqueue_remove_end (DQueue* q)
{
    if(dqueue_empty(q)) {
        printf("Empty queue.");
        exit(1);
    }
    float v = q->end->data;
    q->end = remove_end(q->end);
    if(q->end == NULL)
        q->first = NULL;
    return v;
}

/* free function: frees all elements from the queue */
void dqueue_free (DQueue* q)
{
    DList* l = q->first;
    while(l != NULL) {
        DList* t = l->next;
        free(l);
        l = t;
    }
    free(q);
}

/* print function: prints all elements from the queue */
void dqueue_print (DQueue* q)
{
    DList* l;
    for(l=q->first; l!=NULL; l=l->next)
        printf("%f\n",l->data);
}