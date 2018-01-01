#include <stdio.h>

union example {
    int i;
    char c;
};

enum bool {
    FALSE,
    TRUE
};
typedef enum bool Bool;

int main (void)
{
    union example v;

    v.i = 10;
    //or
    v.c = 'x';

    Bool result;
    result = TRUE;

    printf("%c\n",v.c);
    printf("%i\n",v.i);     /*i was overwritten by c*/
    printf("%i\n",result);

    return 0;
}