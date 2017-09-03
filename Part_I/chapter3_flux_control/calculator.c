/*calculator of four operations*/

#include<stdio.h>

int main(void)
{
  float num1, num2;
  char op;

  printf("Type: number operator number\n");
  scanf("%f %c %f", &num1, &op, &num2);
  switch(op) {
    case '+':
      printf(" = %f\n", num1 + num2);
      break;
    case '-':
      printf(" = %f\n", num1 - num2);
      break;
    case '*':
      printf(" = %f\n", num1 * num2);
      break;
    case '/':
      printf(" = %f\n", num1 / num2);
      break;
    default:
      printf("Invalid operator!\n");
      break;
  }
  return 0;
}
