/*program to convert temperature*/

#include <stdio.h>

/*auxiliar function*/
float convert (float c)
{
  float f;
  f = 1.8*c + 32;
  return f;
}

void status(float t)
{
  if(t < 10)
    printf("Temperature is too low\n");
  else if(t < 20)
    printf("Temperature is low\n");
  else if(t < 30)
    printf("Temperature is nice\n");
  else
    printf("Temperature is too high\n");
}

/*main function*/
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
  printf("Temperature in Fahrenheit: %f\n", t2);
  status(t1);
  return 0;
}
