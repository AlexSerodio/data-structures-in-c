/*ten numbers average and variance calculation*/

#include <stdio.h>

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
  float v[10];                                                                  /*declare an array with 10 elements*/
  float av;                                                                     /*average variable*/
  float va;                                                                     /*variance variable*/
  int i;                                                                        /*array index*/

  printf("Type 10 numbers:\n");
  /*read the inputs*/
  for(i = 0; i < 10; i++)                                                       /*make the index goes from 0 to 9*/
    scanf("%f", &v[i]);                                                         /*read each element of the array*/

  av = average(10, v);
  va = variance(10, v, av);

  /*show the result*/
  printf("Average = %f Variance = %f \n", av, va);
  return 0;
}
