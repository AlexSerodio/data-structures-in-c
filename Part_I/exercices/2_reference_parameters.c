#include <stdio.h>
#include <math.h>

//2.1
int squares (float a, float b, float c, float* x1, float* x2)
{
    float d = sqrt(b*b-4*a*c);

    if(d>=0) {
        *x1=(-b+d)/(2*a);
        *x2=(-b-d)/(2*a);
        return 2;
    }else {
        return 0;
    }
}

//2.2
void calc_sphere (float r, float* area, float* volume)
{
    *area = 4*r*r;
    *volume = (4*r*r*r)/3;
}

int main (void) 
{
    //2.1
    float x1, x2;
    squares(8, 12, -6, &x1, &x2);
    printf("x1=%f, x2=%f\n",x1,x2);

    //2.2
    float a, v;
    calc_sphere(4, &a, &v);
    printf("area=%f, volume=%f\n",a,v);

    return 0;
}