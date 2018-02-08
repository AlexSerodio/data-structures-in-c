#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};
typedef struct tree Tree;

Tree* bstree_create (void)
{
    return NULL;
}

void bstree_print (Tree* t)
{
    if(t != NULL) {
        bstree_print(t->left);
        printf("%d\n",t->data);
        bstree_print(t->right);
    }
}

Tree* bstree_add (Tree* t, int v)
{
    if(t == NULL) {
        t = (Tree*) malloc(sizeof(Tree));
        t->data = v;
        t->left = t->right = NULL;
    } else if(v < t->data)
        t->left = bstree_add(t->left,v);
    else
        t->right = bstree_add(t->right,v);
    return t;
}

Tree* bstree_remove (Tree* r, int v)
{
    if(r == NULL)
        return NULL;
    else if(r->data > v)
        r->left = bstree_remove(r->left,v);
    else if(r->data < v)
        r->right = bstree_remove(r->right,v);
    else {
        if(r->left == NULL && r->right == NULL) {
            free(r);
            r = NULL;
        } else if(r->left == NULL) {
            Tree* t = r;
            r = r->right;
            free(t);
        } else if(r->right == NULL) {
            Tree* t = r;
            r = r->left;
            free(t);
        } else {
            Tree* f = r->left;
            while(f->right != NULL)
                f = f->right;
            r->data = f->data;
            f->data = v;
            r->left = bstree_remove(r->left,v);
        }
    }
    return r;
}