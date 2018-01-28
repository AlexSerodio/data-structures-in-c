/* ADT: Binary tree*/

/* Exported type */
typedef struct tree Tree;

/** create empty function
 *  returns an empty tree
**/
Tree* tree_create_empty (void);

/** create function
 *  returns a tree with its two subtrees
**/
Tree* tree_create (char c, Tree* lt, Tree* rt);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int tree_empty (Tree* t);

/** print function
 *  prints all the trees 
**/
void tree_print (Tree* t);

/** free function 
 *  frees all the trees
**/
Tree* tree_free (Tree* t);

/** contains function
 *  returns 1 if the element exist in the tree
 *  and 0 if it doesn't 
**/
int tree_contains (Tree* t, char c);

/** height function
 *  calculates the tree height
**/
int tree_height (Tree* t);