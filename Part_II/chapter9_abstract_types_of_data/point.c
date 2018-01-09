#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

struct point {
    float x;
    float y;
};

Point* pt_create (float x, float y)
{
    Point* p = (Point*) malloc(sizeof(Point));
    if(p == NULL) {
        printf("Not enough memory!\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void pt_free (Point* p)
{
    free(p);
}

void pt_get (Point* p, float* x, float* y)
{
    *x = p->x;
    *y = p->y;
}

void pt_set (Point* p, float x, float y)
{
    p->x = x;
    p->y = y;
}

float pt_distance (Point* p1, Point* p2)
{
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
}