int search (int n, int* vec, int elem)
{
    int i;
    for(i=0; i<n; i++) {
        if(elem == vec[i])
            return i;
    }
    return -1;
}

int orderly_search (int n, int* vec, int elem)
{
    int i;
    for(i=0; i<n; i++) {
        if(elem == vec[i])
            return i;
        else if(elem < vec[i])
            return -1;
    }
    return -1;
}

int binary_search(int n, int* vec, int elem)
{
    int start = 0;
    int end = n-1;
    int half;

    while(start <= end) {
        half = (start + end) /2;
        if(elem < vec[half])
            end = half - 1;
        else if(elem > vec[half])
            start = half + 1;
        else
            return half;
    }
    return -1;
}

int binary_search_rec(int n, int* vec, int elem)
{
    if(n <= 0)
        return -1;
    else {
        int half = n /2;
        if(elem < vec[half]) {
            return binary_search_rec(half, vec, elem);
        } else if(elem > vec[half]) {
            int r = binary_search_rec(n-1-half, vec, elem);
            if (r < 0)
                return -1;
            else 
                return half+1+r;
        } else {
            return half;
        }
    }
}

#include <stdio.h>

int main (void)
{
    int a[8] = {2, 4, 5, 8, 9, 11, 12, 14};

    printf("%i\n",binary_search(8, a, 8));
    return 0;
}