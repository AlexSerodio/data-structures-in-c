/* ADT: integer Linked List */

/* Exported type */
typedef struct list List;

/* Exported functions */

/** create function
 *  returns an empty list
**/
List* lst_create (void);

/** free function 
 *  frees all elements from the list 
**/
void lst_free (List* l);

/** add function
 * add in the beginning and returns the updated list 
**/
List* lst_add (List* l, int v);

/** alternative add function
 *  add in the beginning and updates the list value
**/
List* lst_add_2 (List** l, int v);

/** add in ascending order function
 * adds the value in a specific position to keep the list ordered 
**/
List* lst_add_ascending_order (List* l, int v);

/** remove function
 *  removes an element from the list 
**/
List* lst_remove (List* l, int v);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int lst_empty (List* l);

/** search function 
 *  returns an element from the list 
**/
List* lst_search (List* l, int v);

/** print function 
 *  prints the values ​​of all elements 
**/
void lst_print (List* l);