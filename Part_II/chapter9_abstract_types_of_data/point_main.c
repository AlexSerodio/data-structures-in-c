#include <stdio.h>
#include "point.h"

int main (void)
{
    Point* p = pt_create(2.0,1.0);
    Point* q = pt_create(3.4,2.1);
    float d = pt_distance(p,q);
    printf("Distance between points: %f\n",d);
    pt_free(p);
    pt_free(q);
    return 0;
}