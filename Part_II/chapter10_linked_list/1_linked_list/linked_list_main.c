#include <stdio.h>
#include "linked_list.h"

int main (void)
{
    List* l1;
    l1 = lst_create();
    l1 = lst_add(l1, 23);
    l1 = lst_add(l1, 45);
    l1 = lst_add(l1, 56);
    //or
    lst_add_2(&l1, 78);
    lst_print(l1);
    l1 = lst_remove(l1, 78);
    lst_print(l1);
    l1 = lst_remove(l1, 45);
    lst_print(l1);
    lst_free(l1);

    List* l2;
    l2 = lst_create();
    l2 = lst_add(l2, 23);
    l2 = lst_add(l2, 45);
    l2 = lst_add(l2, 56);
    lst_print_rec(l2);
    printf("+-----------+\n");
    l2 = lst_remove_rec(l2, 78);
    lst_print_rec(l2);
    printf("+-----------+\n");
    l2 = lst_remove_rec(l2, 45);
    lst_print_rec(l2);
    lst_free_rec(l2);
    
    return 0;
}