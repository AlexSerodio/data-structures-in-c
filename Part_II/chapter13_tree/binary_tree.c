#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct tree {
    char data;
    struct tree* left;
    struct tree* right;
};

/* create empty function: returns an empty tree */
Tree* tree_create_empty (void)
{
    return NULL;
}

/* create function: returns a tree with its two subtrees */
Tree* tree_create (char c, Tree* lt, Tree* rt)
{
    Tree* p = (Tree*) malloc(sizeof(Tree));
    p->data = c;
    p->left = lt;
    p->right = rt;
    return p;
}

/* empty function: returns 1 if empty or 0 if not empty */
int tree_empty (Tree* t)
{
    return t == NULL;
}

/* print function: prints all the trees */
void tree_print (Tree* t)
{
    printf("<");
    if(!tree_empty(t)) {
        printf("%c ", t->data);
        tree_print(t->left);
        tree_print(t->right);
    }
    printf(">");
}

/* free function: frees all the trees */
Tree* tree_free (Tree* t)
{
    if(!tree_empty(t)) {
        tree_free(t->left);
        tree_free(t->right);
        free(t);
    }
    return NULL;
}

/* contains function: returns 1 if the element exist and 0 if it doesn't */
int tree_contains (Tree* t, char c)
{
    if(tree_empty(t))
        return 0;
    
    return t->data==c || 
        tree_contains(t->left,c) || 
        tree_contains(t->right,c);
}

/* auxiliar function: returns the biggest number*/
static int max2 (int a, int b)
{
    return (a > b) ? a : b;
}

/* height function: calculates the tree height*/
int tree_height (Tree* t)
{
    if(tree_empty(t))
        return -1;
    
    return 1 + max2(tree_height(t->left), tree_height(t->right));
}