#include <stdio.h>
#include "calc.h"

int main (void)
{
    char c;
    float v;
    Calc* calc;

    calc = calc_create("%.2f\n");
    
    do {
        scanf(" %c", &c);
        if(c=='+' || c=='-' || c=='*' || c=='/') {
            calc_operator (calc, c);
        } else {
            ungetc(c,stdin);
            if(scanf("%f",&v) == 1)
                calc_operand(calc, v);
        }
    } while(c!='q');
    
    calc_free(calc);
    return 0;
}