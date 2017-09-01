/*calculates the factorial of a number*/

#include <stdio.h>

int fac(int n);
int recfac(int n);

int main (void)
{
  int r;
  int n;

  /*wait for an input greater than zero*/
  do {
    printf("Type an integer value greater than zero: ");
    scanf("%d", &n);
  } while(n < 0);

  r = recfac(n);
  printf("Factorial = %d\n", r);
  return 0;
}

/*function that calculates the factorial*/
int fac(int n)
{
  int i;
  int f = 1;
  for(i = 1; i <= n; i++)
    f *= i;
  return f;
}

/*recursive function that calculates the factorial*/
int recfac(int n)
{
  if(n == 0)
    return 1;
  else
  return n*fac(n-1);
}
