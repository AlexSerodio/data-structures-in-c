#include <stdio.h>
#include "linked_list.h"

int main (void)
{
    List* l;
    l = lst_create();
    l = lst_add(l, 23);
    l = lst_add(l, 45);
    l = lst_add(l, 56);
    //or
    lst_add_2(&l, 78);
    lst_print(l);
    printf("+-----------+\n");
    l = lst_remove(l, 78);
    lst_print(l);
    printf("+-----------+\n");
    l = lst_remove(l, 45);
    lst_print(l);
    lst_free(l);

    return 0;
}