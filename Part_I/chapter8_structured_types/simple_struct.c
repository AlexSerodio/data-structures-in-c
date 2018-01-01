/*catch and print the coordenates of a dot*/

#include <stdio.h>

struct point {
    float x;
    float y;
};

void printdot (struct point* pp)
{
    printf("The required dot was: (%.2f,%.2f)\n", pp->x, pp->y);
}

void catchdot (struct point* pp)
{
    printf("Type the coordenates of the point(x, y)");
    scanf("%f %f", &pp->x, &pp->y);
}

int main (void)
{
    struct point p;
    catchdot(&p);
    printdot(&p);
    return 0;
}