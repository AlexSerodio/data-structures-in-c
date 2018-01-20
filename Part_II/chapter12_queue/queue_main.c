#include <stdio.h>
#include "queue.h"

int main (void)
{
    Queue* q = queue_create();

    queue_add(q,20.0);
    queue_add(q,20.8);
    queue_add(q,21.2);
    queue_add(q,24.3);
    
    printf("First element: %f\n", queue_remove(q));
    printf("Second element: %f\n", queue_remove(q));

    queue_print(q);
    queue_free(q);
    return 0;
}