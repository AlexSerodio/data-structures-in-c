#include <stdio.h>
#include <stdlib.h>

struct student {
    int number;
    char name[81];
    char address[121];
    char tel[21];
};

typedef struct student Student; 


void inicialize (int n, Student** tab)
{
    int i;
    for(i=0; i<n; i++)
        tab[i] = NULL;
}

void fill_tab (int n, Student** tab, int i)
{
    if(i<0 || i >=n) {
        printf("Index out of bounds.\n");
        exit(1);
    }

    if(tab[i]==NULL)
        tab[i] = (Student*) malloc(sizeof(Student));

    printf("Type the student registry number: ");
    scanf("%d", &tab[i]->number);
    printf("Type the student name: ");
    scanf(" %80[^\n]", tab[i]->name);
    printf("Type the student address: ");
    scanf(" %120[^\n]", tab[i]->address);
    printf("Type the student telephone: ");
    scanf(" %20[^\n]", tab[i]->tel);
}

void remove_student (int n, Student** tab, int i)
{
    if(i<0 || i >=n) {
        printf("Index out of bounds.\n");
        exit(1);
    }

    if(tab[i] != NULL) {
        free(tab[i]);
        tab[i] = NULL;
    } 
}

void print (int n, Student** tab, int i)
{
    if(i<0 || i >=n) {
        printf("Index out of bounds.\n");
        exit(1);
    }

    if(tab[i] != NULL) {
        printf("Registry number: %d\n", tab[i]->number);
        printf("Name: %s\n", tab[i]->name);
        printf("Address: %s\n", tab[i]->address);
        printf("Telephone: %s\n", tab[i]->tel);
    }
}

void print_all (int n, Student** tab)
{
    int i;
    for(i=0; i<n; i++)
        print(n, tab, i);
}

#define MAX 10

int main (void)
{
    Student* tab[MAX];
    inicialize (MAX,tab);
    fill_tab(MAX,tab,0);
    fill_tab(MAX,tab,1);
    fill_tab(MAX,tab,2);
    print_all(MAX,tab);
    remove_student(MAX,tab,0);
    remove_student(MAX,tab,1);
    remove_student(MAX,tab,2);
    return 0;
}