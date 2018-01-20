/* ADT: Queue of float*/

/* Exported type */
typedef struct queue Queue;

/** create function
 *  returns an empty queue
**/
Queue* queue_create (void);

/** add function
 *  adds a new element at the end of the queue
**/
void queue_add (Queue* q, float v);

/** remove function
 *  removes and returns the first element of the queue
**/
float queue_remove (Queue* q);

/** empty function
 *  returns 1 if empty or 0 if not empty 
**/
int queue_empty (Queue* q);

/** free function 
 *  frees all elements from the queue 
**/
void queue_free (Queue* q);

/** print function
 *  prints all elements from the queue 
**/
void queue_print (Queue* q);