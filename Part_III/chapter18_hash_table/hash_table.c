#include <stdlib.h>
#include <string.h>

struct student {
    int code;
    char name[81];
    char class;
    char email[41];
    struct student* next;
};
typedef struct student Student;

#define N 217
typedef Student* Hash[N];

static int hash (int code)
{
    return code % N;
}

Student* hash_search (Hash tab, int code)
{
    int h = hash(code);
    Student* s = tab[h];
    while (s != NULL) {
        if (s->code == code)
            return s;
        s = s->next;
    }
    return NULL;
}

Student* hash_add (Hash tab, int code, char* name, char* email, char class)
{
    int h = hash(code);
    Student* s = tab[h];
    while (s != NULL) {
        if (s->code == code)
            break;
        s = s->next;
    }
    if (s == NULL) {    /* didn't find the element */
        /* add new element at the beginning of the list */
        s = (Student*) malloc(sizeof(Student));
        s->code = code;
        s->next = tab[h];
        tab[h] = s;
    }
    strcpy(s->name, name);
    strcpy(s->email, email);
    s->class = class;
    return s;
}