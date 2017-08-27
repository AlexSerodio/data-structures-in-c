/*Program to convert temperature*/

#include <stdio.h>

/*Auxiliar function*/
float convert (float c)
{
  float f;
  f = 1.8*c + 32;
  return f;
}

/*Main function*/
int main (void)
{
  float t1;
  float t2;

  /*shows a message to the user*/
  printf("Type the temperature in Celsius: ");
  /*Catch the input value typed*/
  scanf("%f", &t1);
  /*Convert Celsius to Fahrenheit*/
  t2 = convert(t1);
  /*Show the result*/
  printf("Temperatura em Fahrenheit: %f\n", t2);
  return 0;
}
