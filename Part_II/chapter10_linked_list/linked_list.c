#include <stdlib.h>
#include <stdio.h>

struct list {
    int data;
    struct list* next;
};

typedef struct list List;

/* create function: returns an empty list */
List* lst_create (void)
{
    return NULL;
}

/* add in the beginning: returns the updated list */
List* lst_add (List* l, int v)
{
    List* new = (List*) malloc(sizeof(List));
    new->data = v;
    new->next = l;
    return new;
}

/* add in the beginning: updates the list value */
List* lst_add_2 (List** l, int v)
{
    List* new = (List*) malloc(sizeof(List));
    new->data = v;
    new->next = *l;
    *l = new;
}

/*adds the value in a specific position to keep the list ordered:  returns the updated list*/
List* lst_add_ascending_order (List* l, int v)
{
    List* pre = NULL;
    List* p = l;

    //search the right position
    while(p != NULL && p->data < v) {
        pre = p;
        p = p->next;
    }

    List* new = (List*) malloc(sizeof(List));
    new->data = v;

    if(pre == NULL) {
        new->next = l;
        l = new;
    } else {
        new->next = pre->next;
        pre->next = new;
    }

    return l;
}

/* print function: prints the values ​​of all elements */
void lst_print (List* l)
{
    List* p;
    for(p = l; p != NULL; p = p->next)
        printf("data = %d\n", p->data);
}

/* empty function: returns 1 if empty or 0 if not empty */
int lst_empty (List* l)
{
    return (l == NULL);
}

/* search function: returns an element from the list */
List* lst_search (List* l, int v)
{
    List* p;
    for(p = l; p != NULL; p = p->next) {
        if(p->data == v)
            return p;
    }
    return NULL;
}

/* remove function: removes an element from the list */
List* lst_remove (List* l, int v)
{
    List* pre = NULL;
    List* p = l;

    //search the element to be removed
    while(p != NULL && p->data != v) {
        pre = p;
        p = p->next;
    }

    //element not found
    if(p == NULL)
        return l;

    //it is the first element in the list
    if(pre == NULL)
        l = p->next;
    else
        pre->next = p->next;
    
    free(p);
    return l;
}

/* free function: frees all elements from the list */
void lst_free (List* l)
{
    List* p;
    while(p != NULL) {
        List* t = p->next;
        free(p);
        p = t;
    }
}