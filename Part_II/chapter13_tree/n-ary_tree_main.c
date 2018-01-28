#include <stdio.h>
#include "n-ary_tree.h"

int main (void)
{
    NTree* a = ntree_create('a');
    NTree* a = ntree_create('b');
    NTree* a = ntree_create('c');
    NTree* a = ntree_create('d');
    NTree* a = ntree_create('e');
    NTree* a = ntree_create('f');
    NTree* a = ntree_create('g');
    NTree* a = ntree_create('h');
    NTree* a = ntree_create('i');
    NTree* a = ntree_create('j');
    ntree_add(c,d);
    ntree_add(b,e);
    ntree_add(b,c);
    ntree_add(i,j);
    ntree_add(g,i);
    ntree_add(g,h);
    ntree_add(a,g);
    ntree_add(a,f);
    ntree_add(a,b);

    return 0;
}