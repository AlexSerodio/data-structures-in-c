#include <stdio.h>
#include <string.h>

int main (void)
{
    int n = 0;
    int found = 0;
    char input[121];
    char string[121];       
    char line[121];
    FILE* fp;

    printf("Type input file name: ");
    scanf("%120s", input);
    printf("Type string for search: ");
    scanf("%120s", string);

    fp = fopen(input,"rt");
    if(fp == NULL) {
        printf("Not able to open the input file.\n");
        return 1;
    }

    while(fgets(line,121,fp) != NULL) {
        n++;
        if(strstr(line,string) != NULL) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found)
        printf("Found on line: %d.\n",n);
    else
        printf("String not found.\n");

    return 0;
}