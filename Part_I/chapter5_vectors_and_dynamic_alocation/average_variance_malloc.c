/*the average and variance calculation of ten numbers using malloc*/

#include <stdio.h>
#include <stdlib.h>

/*average calculation*/
float average(int n, float* v)
{
  int i;
  float s = 0.0;
  for(i = 0; i < n; i++)
    s += v[i];
  return s / n;
}

/*variance calculation*/
float variance (int n, float* v, float a)
{
  int i;
  float s = 0.0;
  for(i = 0; i < n; i++)
    s += (v[i] - a) * (v[i] - a);
  return s / n;
}

int main (void)
{
  int i, n;
  float *v;
  float av, va;

  printf("Type the amount of values:\n");
  /*read the amount of values*/
  scanf("%d", &n);

  /*dynamic alocation*/
  v = (float*) malloc(n*sizeof(float));
  if(v == NULL){
    printf("Not enough memory\n");
    return 1;
  }

  printf("Type the values:\n");
  /*read the inputs*/
  for(i = 0; i < n; i++)
    scanf("%f", &v[i]);
  av = average(n,v);
  va = variance(n,v,av);

  /*show the result*/
  printf("Average = %f Variance = %f \n", av, va);
  /*free the memory used by the array*/
  free(v);
  return 0;
}
