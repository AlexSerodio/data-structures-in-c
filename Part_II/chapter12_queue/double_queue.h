/* ADT: Double queue of float*/

/* Exported type */
typedef struct dqueue DQueue;

/** create function
 *  returns an empty queue
**/
DQueue* dqueue_create (void);

/** add function
 *  adds a new element at the beginning of the queue
**/
void dqueue_add_beginning (DQueue* q, float v);

/** add function
 *  adds a new element at the end of the queue
**/
void dqueue_add_end (DQueue* q, float v);

/** remove function
 *  removes and returns the first element of the queue
**/
float dqueue_remove_beginning (DQueue* q);

/** remove function
 *  removes and returns the last element of the queue
**/
float dqueue_remove_end (DQueue* q);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int dqueue_empty (DQueue* q);

/** free function 
 *  frees all elements from the queue 
**/
void dqueue_free (DQueue* q);

/** print function
 *  prints all elements from the queue 
**/
void dqueue_print (DQueue* q);