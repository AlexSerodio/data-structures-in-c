#include "sort.h"

void bubble_sort_int (int n, int* array)
{
    int i, j;
    for(i=n-1; i>0; i--) {
        int change = 0;
        for(j=0; j<i; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                change = 1;
            }
        }
        if(change == 0)
            return;
    }
}

void bubble_sort_rec (int n, int* array)
{
    int j;
    int change = 0;
    for(j=0; j<n-1; j++) {
        if(array[j] > array[j+1]) {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            change = 1;
        }
    }
    if(change != 0)
        bubble_sort_rec (n-1, array);
}

static void* access (void* a, int i, int size)
{
    char* t = (char*)a;
    t += size*i;
    return (void*)t;
}

static void change (void* a, void* b, int size)
{
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i;
    for(i=0; i<size; i++) {
        char temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}

void bubble_sort (int n, void* v, int size, int(*cmp)(void*,void*))
{
    int i, j;
    for(i=n-1; i>0; i--) {
        int changed = 0;
        for(j=0; j<i; j++) {
            void* p1 = access(v,j,size);
            void* p2 = access(v,j+1,size);
            if(cmp(p1,p2)) {
                change(p1,p2,size);
                changed = 1;
            }
        }
        if(changed == 0)
            return;
    }
}

void quick_sort_int (int n, int* v)
{
    if(n <= 1)
        return;
    else {
        int x = v[0];
        int a = 1;
        int b = n-1;
        do {
            while (a < n && v[a] <= x)
                a++;
            
            while (v[b] > x)
                b--;
            
            if(a < b ) {
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }
        } while (a <= b);

        v[0] = v[b];
        v[b] = x;

        quick_sort_int(b,v);
        quick_sort_int(n-a,&v[a]);
    }
}