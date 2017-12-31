/*some functions to manipulate strings*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenght(char* s);

int main (void)
{
  int size;
  char city[80];
  printf("Type a city name: \n");
  scanf(" %80[^\n]", city);                         /*read max 80 characters*/
  size = lenght(city);
  printf("The string \"%s\" has %d characters.\n", city, size);
  return 0;
}

char upper_case(char c)
{
  /*check if is uppercase*/
  if(c>='a' && c<='z')
    c = c-'a'+'A';                                  /*convert to uppercase*/
  return c;
}

/*read the input until the user press Enter*/
void read_a_line (void)
{
  char city[81];
  scanf(" %[^\n]", city);
}

/*read a limited string*/
void read_limited_characters (char* s)
{
  char city[80];
  scanf(" %80[^\n]", city);                         /*read max 80 characters*/
}

/*calculates the word lenght*/
/*strlen function*/
int lenght (char* s)
{
  int i;
  int n = 0;
  for(i = 0; s[i] != '\0'; i++)
    n++;
  return n;
}

/*copy a string to another*/
/*strcpy function*/
void copy (char* dest, char* orig)
{
  int i;
  for (i=0; orig[i] != '\0'; i++)
    dest[i] = orig[i];
  dest[i] = '\0';
}

/*concatenates two strings*/
/*strcat function*/
void cat (char* dest, char* orig)
{
  int i = 0;                                        /*index used in the dest string*/
  int j;                                            /*index used in the orig string*/
  /*find the end of the dest string*/
  i = 0;
  while(dest[i] != '\0')
    i++;
  /*copy the orig elements to the end of dest string*/
  for(j=0; j != '\0'; j++){
    dest[i] = orig[j];
    i++;
  }
  dest[i] = '\0';
}

/*conpare two strings*/
/*strcmp function*/
void compare (char* s1, char s2)
{
  int i;
  /*compare char to char*/
  for(i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
    if(s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  if(s1[i]==s2[i])
    return 0;                                       /*the strings are equals*/
  else if (s2[i] != '\0')
    return -1;                                      /*s1 has less characters*/
  else
    return 1;                                       /*s2 has less characters*/
}

/*duplicate a string using some functions from the lib string.h*/
char* duplicate (char* s)
{
  int n = strlen(s);
  char* d = (char*) malloc((n+1)*sizeof(char));
  strcpy(d, s);
  return d;
}
