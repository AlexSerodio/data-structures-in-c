#include <stdio.h>

//1.1
int inside_rec (int x0, int y0, int x1, int y1, int x, int y)
{
    if(x>x0 && x<x1 && y>y0 && y<y1)
        return 1;

    return 0;
}

//1.2
int prime (int n)
{
    int i, x = 0;
    for(i=n; i>0; i--) {
        if(n%i==0)
            x++;
    }
    if(x==2)
        return 1;
    
    return 0;
}

//1.3
int fibonacci (int n)
{
    int i, x=1, y=0, c;
    for(i=0; i<n; i++) {
        if(i==0) {
            c = 1;
        }else {
            c = x+y;
            y=x;
            x=c;
        }
        printf("%i, ",c);
    }
    printf("\n");
    return c;
}

//1.4
int sum_odds (int n)
{
    int i, x=0;
    for(i=n; i>0; i--) {
        if(i%2==1)
            x+=i;
    }
    return x;
}

//1.5
double pi (int n) 
{
    int i;
    double s=0;
    for(i=0; i<=n; i++) { 
        s+= -1/(double)(2*i+1);
        s*=-1;
    }      
    return s*4;
}

int main (void)
{

    //1.1
    /*
    printf("%i\n",inside_rec(0, 0, 7, 3, 2, 2));
    printf("%i\n",inside_rec(0, 0, 7, 3, 3, 2));
    printf("%i\n",inside_rec(0, 0, 7, 3, 3, 3));
    printf("%i\n",inside_rec(0, 0, 7, 3, 8, 3));
    */

    //1.2
    /*
    printf("1: %i\n",prime(1));
    printf("2: %i\n",prime(2));
    printf("3: %i\n",prime(3));
    printf("4: %i\n",prime(4));
    printf("5: %i\n",prime(5));
    printf("6: %i\n",prime(6));
    printf("7: %i\n",prime(7));
    printf("8: %i\n",prime(8));
    printf("9: %i\n",prime(9));
    */

    //1.3
    //printf("%i",fibonacci(8));

    //1.4
    //printf("%i",sum_odds(10));

    //1.5
    //printf("%0.6f\n",pi(1000));

    return 0;
}