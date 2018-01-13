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

/* empty function: returns 1 if empty or 0 if not empty */
int lst_empty (List* l)
{
    return (l == NULL);
}

/* print function: prints the values ​​of all elements */
void lst_print (List* l)
{
    List* p;
    for(p = l; p != NULL; p = p->next)
        printf("data = %d\n", p->data);

    printf("+---------------+");
}

/* recursive print function: prints the values ​​of all elements */
void lst_print_rec (List* l)
{
    if(!lst_empty(l)) {
        printf("data: %d\n",l->data);
        lst_print_rec(l->next);
    }
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

/* recursive remove function: removes an element from the list */
List* lst_remove_rec (List* l, int v)
{
    if(!lst_empty(l)) {
        if(l->data == v) {
            List* t = l;
            l = l->next;
            free(t);
        } else {
            l->next = lst_remove_rec(l->next, v);
        }
    }
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

/* recursive free function: frees all elements from the list */
void lst_free_rec (List* l)
{
    if(!lst_empty(l)) {
        lst_free_rec(l->next);
        free(l);
    }
}

/* equals function: check the equality between two lists */
int lst_equals (List* l1, List* l2)
{
    List* p1;
    List* p2;

    for(p1=l1,p2=l2; p1!=NULL && p2!=NULL; p1=p1->next,p2=p2->next) {
        if(p1->data != p2->data)
            return 0;
    }
    return p1==p2;
}

/* recursive equals function: check the equality between two lists */
int lst_equals_rec (List* l1, List* l2)
{
    if(l1==NULL && l2==NULL)
        return 1;
    else if(l1==NULL || l2==NULL)
        return 0;
    else
        return l1->data==l2->data && lst_equals_rec(l1->next,l2->next); 
}