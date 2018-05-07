#include <stdio.h>
#include "n-ary_tree.h"

int main (void)
{
    NTree* a = ntree_create('a');
    NTree* b = ntree_create('b');
    NTree* c = ntree_create('c');
    NTree* d = ntree_create('d');
    NTree* e = ntree_create('e');
    NTree* f = ntree_create('f');
    NTree* g = ntree_create('g');
    NTree* h = ntree_create('h');
    NTree* i = ntree_create('i');
    NTree* j = ntree_create('j');
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
