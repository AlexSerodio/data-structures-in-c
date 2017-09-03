/*some examples using define as definitions and macros*/

#include<stdio.h>

#define PI 3.14159F
float area (float r)
{
  float a = PI * r * r;
  return a;
}

#define MAX(a,b)  ((a) > (b) ? (a) : (b))
float test1 (float v)
{
  float c = MAX(v, 3.0);
  return c;
}

#define DIF(a,b)  ((a) - (b))
void test2 (void)
{
  printf("%d", 4 * DIF(5,3));
}
