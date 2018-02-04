#include <stdio.h>
#include "sort.h"

static int compare_floats (void* a, void* b)
{
    float* p1 = (float*) a;
    float* p2 = (float*) b;
    if((*p1) > (*p2))
        return 1;
    return 0; 
}

int main (void)
{
    int a[8] = {25,48,37,12,57,86,33,92};
    bubble_sort_int(8,a);

    int i;
    for(i=0; i<8; i++)
        printf("%d ",a[i]);

    printf("\n");
    
    int b[8] = {25,48,37,12,57,86,33,92};
    bubble_sort(8,b,sizeof(float),compare_floats);

    for(i=0; i<8; i++)
        printf("%d ",b[i]);

    printf("\n");

    int c[8] = {25,48,37,12,57,86,33,92};
    quick_sort_int(8,c);

    for(i=0; i<8; i++)
        printf("%d ",c[i]);

    printf("\n");
    return 0;
}