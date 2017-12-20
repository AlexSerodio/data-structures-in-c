/*shows how to deal with symmetric arrays to minimize the memory usage*/

float* create_simple (int n)
{
  int s = n*(n+1)/2;
  float* mat = (float*) malloc(s*sizeof(float));
  return mat;
}

float access_simple (int n, float* mat, int i, int j)
{
  int k;                                                                        /*element index*/

  if(i<0 || i>n || j<0 || j>=n){
    printf("Invalid access.\n", );
    exit(1);
  }
  if(i>=j)
    k = i*(i+1)/2 + j;                                                          /*access represented element*/
  else
    k = j*(j+1)/2 + i;                                                          /*access symmetric element*/

  return mat[k];
}

/*the same functions using pointers*/

float** create_with_pointers (int n)
{
  int i;
  float** mat = (float**) malloc(n*sizeof(float*));
  for(i=0; i<n; i++)
    mat[i] = (float*) malloc((i+1)*sizeof(float));
  return mat;
}

float access_with_pointers (int n, float** mat, int i, int j)
{
  if(i<0 || i>n || j<0 || j>=n){
    printf("Acesso inválido.\n", );
    exit(1);
  }
  if(i>=j)
    return mat[i][j];                                                           /*access represented element*/
  else
    return mat[j][i];                                                           /*access symmetric element*/
}
