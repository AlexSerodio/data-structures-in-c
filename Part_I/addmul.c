/*add and multiply two numbers*/

#include<stdio.h>

void addmul (int a, int b, int *p, int *q)
{
  *p = a + b;
  *q = a * b;
}

int main (void)
{
  int s, p;

  addmul(3, 5, &s, &p);
  printf("Addition = %d Multiplication = %d\n", s, p);

  return 0;
}
