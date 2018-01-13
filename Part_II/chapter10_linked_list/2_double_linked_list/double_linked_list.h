/* ADT: Double Linked List of integers*/

/* Exported type */
typedef struct dlist DList;

/* Exported functions */

/** create function
 *  returns an empty double linked list
**/
DList* dlst_create (void);

/** free function 
 *  frees all elements from the list 
**/
void dlst_free (DList* l);

/** add function
 *  add in the beginning and returns the updated list 
**/
DList* dlst_add (DList* l, int v);

/** remove function
 *  removes an element from the list 
**/
DList* dlst_remove (DList* l, int v);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int dlst_empty (DList* l);

/** search function 
 *  returns an element from the list 
**/
DList* dlst_search (DList* l, int v);

/** print function 
 *  prints the values ​​of all elements 
**/
void dlst_print (DList* l);