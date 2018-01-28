/* ADT: N-ary tree*/

/* Exported type */
typedef struct ntree NTree;

/** create function
 *  returns a leaf node (with first and next equal NULL)
**/
NTree* ntree_create (char c);

/** add function
 *  adds a new sub-tree of the specific tree
**/
NTree* ntree_add (NTree* t, NTree* st);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int ntree_empty (NTree* t);

/** print function
 *  prints all the nodes 
**/
void ntree_print (NTree* t);

/** free function 
 *  frees all the trees
**/
NTree* ntree_free (NTree* t);

/** contains function
 *  returns 1 if the element exist in the tree
 *  and 0 if it doesn't 
**/
int ntree_contains (NTree* t, char c);

/** height function
 *  calculates the tree height
**/
int ntree_height (NTree* t);