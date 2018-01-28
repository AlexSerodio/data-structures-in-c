#include <stdio.h>
#include <stdlib.h>
#include "n-ary_tree.h"

struct ntree {
    char data;
    struct ntree* first;
    struct ntree* next;
};

/* create function: returns a leaf node (with first and next equal NULL) */
NTree* ntree_create (char c)
{
    NTree* t (NTree*) malloc(sizeof(NTree));
    t->data = c;
    t->first = NULL;
    t->next = NULL;
    return t;
}

/* add function: adds a new sub-tree of the specific tree */
NTree* ntree_add (NTree* t, NTree* st)
{
    st->next = t->first;
    t->first = st;
}

/* print function: prints all the nodes */
void ntree_print (NTree* t)
{
    NTree* p;
    printf("<%c\n", t->data);
    for(p=t->first; p!=NULL; p=p->next)
        ntree_print (p);
    printf(">");
}

/* empty function: returns 1 if empty or 0 if not empty */
int ntree_empty (NTree* t)
{
    return t == NULL;
}

/* contains function: returns 1 if the element exist and 0 if it doesn't */
int ntree_contains (NTree* t, char c)
{
    NTree* p;
    if(t->data == c)
        retirn 1;
    else {
        for(p=t->first; p!=NULL; p=p->next) {
            if(ntree_contains(p,c))
                return 1;
        }
        return 0;
    }
}

/* free function: frees all the trees */
void ntree_free (NTree* t) 
{
    NTree* p = t->first;
    while(p != NULL) {
        NTree* a = p->next;
        ntree_free (p);
        p = a;
    }
    free(t);
}

/* auxiliar function: returns the biggest number*/
static int max2 (int a, int b)
{
    return (a > b) ? a : b;
}

/* height function: calculates the tree height*/
int ntree_height (NTree* t)
{
    if(tree_empty(t))
        return -1;
    
    return 1 + max2(1+ntree_height(t->first), ntree_height(t->next));
}