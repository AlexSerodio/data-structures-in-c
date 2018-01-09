#include <stdlib.h>
#include "circle.h"

#define PI 3.14159

struct circle {
    Point* p;
    float r;
};

Circle* circ_create (float x, float y, float r)
{
    Circle* c = (Circle*)malloc(sizeof(Circle));
    c->p = pt_create(x,y);
    c->r = r;
}

void circ_free (Circle* c)
{
    pt_free(c->p);
    free(c);
}

float circ_area (Circle* c)
{
    return PI*c->r*c->r;
}

int circ_inside (Circle* c, Point* p)
{
    float d = pt_distance(c->p,p);
    return (d<c->r);
}