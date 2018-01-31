#include <stdio.h>
#include <stdlib.h>
#include "generic_linked_list.h"

struct point {
    float x, y;
};
typedef struct point Point;

static GList* add_point (GList* l, float x, float y)
{
    Point* p = (Point*) malloc (sizeof(Point));
    p->x = x;
    p->y = y;
    return glist_add(l,p);
}

static void print (void* data)
{
    Point* p = (Point*) data;
    printf("%f %f\n", p->x, p->y);
}

struct cg
{
    int n;
    Point p;
};
typedef struct cg Cg;

static void geo_center (void* info, void* data)
{
    Point* p = (Point*) info;
    Cg* cg = (Cg*) data;
    cg->p.x += p->x;
    cg->p.y += p->y;
    cg->n++;
}

int main (void)
{
    GList* l = glist_create();

    l = add_point(l, 1, 2);
    l = add_point(l, 3, 4);
    l = add_point(l, 4, 5);
    l = add_point(l, 2, 6);
    
    glist_run_through(l, print);

    Cg cg = {0,{0.0f,0.0f}};
    glist_run_through2(l, geo_center, &cg);
    cg.p.x /= cg.n;
    cg.p.y /= cg.n;
    printf("%f %f\n", cg.p.x, cg.p.y);

    return 0;
}