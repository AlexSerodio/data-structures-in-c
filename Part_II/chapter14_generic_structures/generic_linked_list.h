/* ADT: Generic Linked List */

/* Exported type */
typedef struct glist GList;

/** create function
 *  returns an empty list 
**/
GList* glist_create (void);

/** empty function
 *  returns 1 if empty or 0 if not 
**/
int glist_empty (GList* l);

/** add function
 * add in the beginning and returns the updated list 
**/
GList* glist_add (GList* l, void* p);

/** run through function
 *  runs through all the elements of the list applying the callback function to each one 
**/
void glist_run_through (GList* l, void (*cb) (void*));

/** run through function
 *  runs through all the elements of the list applying the callback function to each one 
**/
void glist_run_through2 (GList* l, void (*cb) (void*, void*), void* info);