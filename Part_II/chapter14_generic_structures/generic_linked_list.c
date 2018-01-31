#include <stdlib.h>
#include "generic_linked_list.h"

struct glist {
    void* data;
    struct glist* next;
};

/* create function: returns an empty list */
GList* glist_create (void)
{
    return NULL;
}

/* empty function: returns 1 if empty or 0 if not */
int glist_empty (GList* l)
{
    return (l == NULL);
}

GList* glist_add (GList* l, void* p)
{
    GList* n = (GList*) malloc(sizeof(GList));
    n->data = p;
    n->next = l;
    return n;
}

void glist_run_through (GList* l, void (*cb) (void*))
{
    GList* p;
    for(p=l; p!=NULL; p=p->next) {
        cb(p->data);
    }
}

void glist_run_through2 (GList* l, void (*cb) (void*, void*), void* info)
{
    GList* p;
    for(p=l; p!=NULL; p=p->next)
        cb(p->data, info);
}