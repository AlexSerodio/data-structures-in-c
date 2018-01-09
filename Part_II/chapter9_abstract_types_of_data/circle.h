/* ADT: Circle */

/* Module dependence */
#include "ponto.h"

/* Exported type */
typedef struct circle Circle;

/* Exported functions */

/** create function 
 *  Alocates and returns a circle with center (x,y) and radius r
**/
Circle* circ_create (float x, float y, float r);

/** free function 
 *  Free the memory of a circle previously created
**/
void circ_free (Circle* c);

/**
 * area function
 * returns the value of the circle area
**/
float circ_area (Circle* c);

/**
 * inside function
 * check if a specific point is inside the circle
**/
int circ_inside (Circle* c, Point* p);