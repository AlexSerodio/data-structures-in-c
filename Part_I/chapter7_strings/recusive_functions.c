/*some recursive functions to manipulate strings*/

void show_rec (char* s)
{
  if(s[0] != '\0'){
    printf("%c", s[0]);
    show_rec(&s[1]);
  }
}

void show_inv (char* s)
{
  if(s[0] != '\0'){
    show_inv(s[1]);
    printf("%c", s[0]);
  }
}

int rec_size (char* s)
{
  if(s[0] == '\0')
    retirn 0;
  else
  return 1 + rec_size(&s[1]);
}

void copy_rec (char* dest, char* orig)
{
  des[0] = orig[0];
  if(orig[0] != '\0')
    copy_rec(&dest[1], &orig[1]);
}
