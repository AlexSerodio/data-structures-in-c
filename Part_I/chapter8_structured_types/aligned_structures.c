#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

typedef struct point Point;

struct circle {
    Point p;        /*center*/
    float r;        /*radius*/
};
typedef struct circle Circle;

/*calculates the distance between two points*/
float distance (Point* p, Point* q)
{
    return sqrt((q->x-p->x)*(q->x-p->x)+(q->y-p->y)*(q->y-p->y));
}

/*check if a specific point is inside the circle*/
int inside (Circle* c, Point* p)
{
    float d = distance(&c->p,p);
    return (d<c->r);
}

int main (void)
{
    Point p;
    p.x = 2;
    p.y = 2;
    Circle c;
    c.p.x = 3;
    c.p.y = 3;
    c.r = 5;

    printf("%i",inside(&c,&p));

    return 0;
}