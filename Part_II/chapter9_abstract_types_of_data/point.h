/* ADT: Point(x,y) */

/* Exported type */
typedef struct point Point;

/* Exported functions */

/** create function 
 *  Alocates and returns a point with coordinates (x,y)
**/
Point* pt_create (float x, float y);

/** free function 
 *  Free the memory of a point previously created
**/
void pt_free (Point* p);

/**
 * get function
 * get the coordinates values of a point
**/
void pt_get (Point* p, float* x, float* y);

/**
 * set function
 * set new coordinates values of a point
**/
void pt_set (Point* p, float x, float y);

/**
 * distance function
 * return the distance between two points
**/
float pt_distance (Point* p1, Point* p2);