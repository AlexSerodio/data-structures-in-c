/*ten numbers average and variance calculation*/

#include <stdio.h>

int main (void)
{
  float v[10];                                                                    /*declare an array with 10 elements*/
  float average;                                                                /*average variable*/
  float variance;                                                               /*variance variable*/
  int i;                                                                        /*array index*/

  printf("Type 10 numbers:\n");
  /*read the inputs*/
  for(i = 0; i < 10; i++)                                                       /*make the index goes from 0 to 9*/
    scanf("%f", &v[i]);                                                         /*read each element of the array*/

  /*average calculation*/
  average = 0.0;                                                                /*inicialize average with zero*/
  for(i = 0; i < 10; i++)
    average += v[i];                                                            /*sum all the elements*/
  average = average / 10;                                                       /*calculates the average*/

  /*variance calculation*/
  variance = 0.0;                                                               /*inicialize variance with zero*/
  for(i = 0; i < 10; i++)
    variance = variance + (v[i]-average)*(v[i]-average);
  variance = variance / 10;                                                     /*calculates the variance*/

  /*show the result*/
  printf("Average = %f Variance = %f \n", average, variance);
  return 0;
}
