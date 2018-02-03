#include <stdio.h>
#include <ctype.h>

int main (void)
{
    int c;
    char input[121];        //input file name
    char output[121];       //output file name
    FILE* i;
    FILE* o;

    printf("Type input file name: ");
    scanf("%120s", input);
    printf("Type output file name: ");
    scanf("%120s", output);

    i = fopen(input,"rt");
    if(i == NULL) {
        printf("Not able to open the input file.\n");
        return 1;
    }

    o = fopen(output,"wt");
    if(o == NULL) {
        printf("Not able to open the output file.\n");
        fclose(i);
        return 1;
    }

    while((c = fgetc(i)) != EOF)
        fputc(toupper(c),o);

    fclose(i);
    fclose(o);
    
    return 0;
}