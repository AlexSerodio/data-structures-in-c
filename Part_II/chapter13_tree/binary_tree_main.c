#include <stdio.h>
#include "binary_tree.h"

int main (void)
{
    Tree* t = tree_create('a', 
        tree_create('b', 
            tree_create_empty(),
            tree_create('d', tree_create_empty(), tree_create_empty())
        ),
        tree_create('c', 
            tree_create('e', tree_create_empty(), tree_create_empty()),
            tree_create('f', tree_create_empty(), tree_create_empty())
        )
    );
    printf("\n");
    tree_print(t);
    printf("\n");

    printf("%i\n", tree_contains(t,'c'));
    printf("%i\n", tree_contains(t,'j'));

    printf("%i\n", tree_height(t));

    tree_free(t);
    return 0;
}