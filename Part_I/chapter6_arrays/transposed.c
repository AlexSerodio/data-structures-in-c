float* transposed_simple (int m, int n, float* mat)
{
  int i, j;
  float* trp;

  /*allocate the transposed matrx*/
  trp = (float*) malloc(n*m*sizeof(float));

  /*populate the matrix*/
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      trp[j*m+i] = mat[i*n+j];

  return trp;
}

float** transposed_with_pointers (int m, int n, float** mat)
{
  int i, j;
  float** trp;

  /*allocate the transposed matrx: n lines and m rows*/
  trp = (float**) malloc(n*sizeof(float*));
  for(i = 0; i < n; i++)
    trp[i] = (float*) malloc(m*sizeof(float));

  /*populate the matrix*/
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      trp[j][i] = mat[i][j];

  return trp;
}
