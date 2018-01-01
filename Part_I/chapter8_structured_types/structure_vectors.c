#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

typedef struct point Point;

/*calculates the geometric center of a set of points*/
Point geometric_center (int n, Point* v)
{
    int i;
    Point p = {0.0f, 0.0f};
    for(i=0; i<n; i++) {
        p.x += v[i].x;
        p.y += v[i].y;
    }
    p.x /= n;
    p.y /= n;
    return p;
}

float area (int n, Point* p)
{
    int i,j;
    float a = 0;
    for(i=0; i<n; i++) {
        j = (i+1) % n;
        a += (p[j].x-p[i].x)*(p[i].y+p[j].y)/2;
    }
    return fabs(a);
}

int main (void)
{
    Point p[3] = {{1.0,1.0},{5.0,1.0},{4.0,3.0}};
    printf("Area = %f\n",area(3,p));
}