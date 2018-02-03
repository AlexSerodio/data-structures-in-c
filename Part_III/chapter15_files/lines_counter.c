#include <stdio.h>

int main (void)
{
    int c;
    int nlines = 0;
    FILE *fp;

    fp = fopen("input.txt","rt");
    if(fp == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }

    while((c = fgetc(fp)) != EOF) {
        if(c == '\n')
            nlines++;
    }

    fclose(fp);

    printf("Number of lines: %d\n",nlines);

    return 0;
}