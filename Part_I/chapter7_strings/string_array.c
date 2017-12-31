#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

char* duplicate (char* s)
{
    int n = strlen(s);
    char* d = (char*) malloc ((n+1)*sizeof(char));
    strcpy(d,s);
    return d;
}

char* readline (void)
{
    char line[121];             /*auxiliar variable to read line*/
    printf("Type a name: ");
    scanf(" %120[^\n]",line);
    return duplicate(line);
}

int readnames (char** students)
{
    int i,n;
    do {
        printf("Type the students amount: ");
        scanf("%d",&n);
    } while(n>MAX);

    for(i=0; i<n; i++)
        students[i] = readline();
    return n;
}

void freenames (int n, char** students)
{
    int i;
    for(i=0; i<n; i++)
        free(students[i]);
}

void printnames (int n, char** students)
{
    int i;
    for(i=0; i<n; i++)
        printf("%s\n", students[i]);
}

int main (void)
{
    char* students[MAX];
    int n = readnames(students);
    printnames(n,students);
    freenames(n,students);
    return 0;
}