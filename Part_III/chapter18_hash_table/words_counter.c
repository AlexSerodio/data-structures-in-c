#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NWORD 64    /* max word size */
#define NTAB 127    /* max hash table size */

struct word {
    char w[NWORD];
    int n;
    struct word* next;
};
typedef struct word Word;

typedef Word* Hash[NTAB];

static int read_word (FILE* fp, char* s)
{
    int i = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c))
            break;
    }

    if (c == EOF)
        return 0;
    else
        s[i++] = c;

    while (i<NWORD-1 && (c = fgetc(fp) != EOF && isalpha(c)))
        s[i++] = c;
    s[i] = '\0';
    
    return 1;
}

static void inicialize (Hash table)
{
    for (int i = 0; i < NTAB; i++)
        table[i] = NULL;
}

static int hash (char* string)
{
    int total = 0;
    for (int i = 0; string[i] != '\0'; i++)
        total += string[i];
    return total % NTAB;
}

static Word* access (Hash table, char* string)
{
    Word* word;
    int h = hash(string);
    for (word=table[h]; word!=NULL; word=word->next){
        if (strcmp(word->w,string))
            return word;
    }
    /* add new word at the beginning of the list */
    word = (Word*) malloc(sizeof(Word));
    strcpy(word->w,string);
    word->n = 0;
    word->next = table[h];
    table[h] = word;
    return word;
}

static int elements_count (Hash table)
{
    int total = 0;
    for (int i = 0; i < NTAB; i++) {
        for(Word* w = table[i]; w != NULL; w = w->next)
            total++;
    }
    return total;
}

static Word** create_array (int n, Hash table)
{
    Word** array = (Word**) malloc(sizeof(Word*));
    int j = 0;
    for (int i = 0; i < NTAB; i++) {
        for (Word* w = table[i]; w != NULL; w = w->next) {
            array[j++] = w;
        }
    }
    return array;
}

static int compare (const void* v1, const void* v2)
{
    Word** w1 = (Word**) v1;
    Word** w2 = (Word**) v2;

    if((*w1)->n > (*w2)->n)
        return -1;
    else if ((*w1)->n < (*w2)->n)
        return 1;
    else
        return strcmp((*w1)->w, (*w2)->w);
}

static void print (Hash table)
{
    int n = elements_count(table);
    Word** array = create_array(n, table);
    qsort(array,n,sizeof(Word*),compare);

    for (int i = 0; i < n; i++)
        printf("%s = %d\n",array[i]->w,array[i]->n);
    
    free(array);
}

int main (int argc, char** argv)
{
    if (argc != 2) {
        printf("Input file not given.");
        return 0;
    }

    FILE* fp = fopen(argv[1], "rt");
    if (fp == NULL) {
        printf("Error trying open the file.");
        return 0;
    }

    Hash table;
    char string[NWORD];
    
    inicialize(table);
    while (read_word(fp, string)) {
        Word* w = access(table, string);
        w->n++;
    }

    print(table);
    return 0;
}