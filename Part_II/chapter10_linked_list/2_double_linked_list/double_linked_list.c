#include <stdlib.h>
#include <stdio.h>
#include "double_linked_list.h"

struct dlist {
    int data;
	struct dlist* pre;
    struct dlist* next;
};

/* create function: returns an empty double linked list */
DList* dlst_create (void)
{
    return NULL;
}

/* add in the beginning: returns the updated list */
DList* dlst_add (DList* l, int v)
{
	DList* new = (DList*) malloc(sizeof(DList));
	new->data = v;
	new->next = l;
	new->pre = NULL;
	if(l != NULL)
		l->pre = new;
	return new;
}

/* search function: returns an element from the list */
DList* dlst_search (DList* l, int v)
{
	DList* p;
	for(p=l; p!=NULL; p=p->next)
		if(p->data == v)
			return p;
	return NULL;
}

/* remove function: removes an element from the list */
DList* dlst_remove (DList* l, int v)
{
	DList* p = dlst_search(l,v);
	if(p == NULL)
		return l;
	
	if(l == p)
		l = p->next;
	else
		p->pre->next = p->next;
	
	if(p->next != NULL)
		p->next->pre = p->pre;
	
	free(p);
	return l;
}

/* empty function: returns 1 if empty or 0 if not empty */
int dlst_empty (DList* l)
{
    return (l == NULL);
}

/* print function: prints the values ​​of all elements */
void dlst_print (DList* l)
{
    DList* p;
    for(p = l; p != NULL; p = p->next)
        printf("data = %d\n", p->data);

    printf("+---------------+");
}

/* free function: frees all elements from the list */
void dlst_free (DList* l)
{
    DList* p;
    while(p != NULL) {
        DList* t = p->next;
        free(p);
        p = t;
    }
}