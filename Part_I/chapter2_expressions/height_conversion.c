/*program to convert height*/

#include <stdio.h>

int main (void)
{
  int f;                      /*ft amount*/
  float p;                    /*pol amount*/
  float h;                    /*height in meters*/

  /*shows a message to the user*/
  printf("Type height in meters: ");
  /*catch the input typed*/
  scanf("%f", &h);

  /*convert height in meters to ft and pol*/
  h *= 100;                   /*convert to centimeters*/
  f = (int) (h/30.48);        /*convert to ft*/
  p = (h - f*30.48) / 2.54;   /*convert the rest to pol*/

  /*shows the converted height*/
  printf("Height: %dft, %.1fpol\n", f, p);

  return 0;
}
