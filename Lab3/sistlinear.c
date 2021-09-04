#include "sistlinear.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void fatoracao(int n, double** A, int* p)
{
  int i, j, k, m, t;
  double fat, temp;

  //inicializando o vetor p de permutacao
  for (i=0; i<n; ++i) p[i] = i;

  //encontrar pivô
  for (j=0; j<n-1; ++j) {
    m = j;
    for (i=j+1; i<n; ++i)
      if (fabs(A[i][j]) > fabs(A[m][j]))
        m = i;

   // troca de linhas: (j <=> m)
   for (k=0; k<n; ++k) {
      temp = A[j][k];
      A[j][k] = A[m][k];
      A[m][k] = temp;
    }
    
    //registro da permutacao    
    t = p[j];
    p[j] = p[m];
    p[m] = t;
    
    // eliminacao de gaus    
    for (i=j+1; i<n; ++i) {
      fat = A[i][j]/A[j][j];
      for (k=j+1; k<n; ++k)
        A[i][k] -= fat*A[j][k];
      A[i][j] = fat;
    }
  }
}


void fatoracao2(int n, double** A, int* p)
{
  int i, j, k, m, t;
  double fat, temp;

  //inicializando o vetor p de permutacao
  for (i=0; i<n; ++i) p[i] = i;

  for(j = 0; j < n-2; j++)
  {
    //encontra pivo
     m = j;
     for (k = j + 1; k < n-1; k++)
        if(fabs(A[k][j]) > fabs(A[m][j]))
            m = k;

     //trocar linhas
     for(k = j; k < n-1; k++)
        A[j][k] = A[m][k];

     //registrar permutacao
     t = p[j];
     p[j] = p[m];
     p[m] = t;

     //fazer eliminacao da forma A=LU
     for(i = j + 1; i < n - 1; i++) {
         fat = A[i][j]/A[j][j];
         for(k = j; k < n - 1; k++)
            A[i][k] = A[i][k] - A[j][k]*fat;
         A[i][j] = fat;
     }
   }
 }

void substituicao(int n, double** A, int* p, double* b, double* x)
{
  int i, j;
  double s;

  // substituicao progressiva
  for (i=0; i<n; ++i) {
    s = 0;
    for (j=0; j<i; ++j) 
      s += A[i][j]*x[j];
    x[i] = b[p[i]] - s;
  }

  //retrosubstituicao
  for (i=n-1; i>=0; --i) {
    s = 0;
    for (j=i+1; j<n-1; ++j) 
      s = s + A[i][j]*x[j];
    x[i] = (x[i] - s) / A[i][i];
  }
}

void gauss(int n, double** A, double* b, double* x)
{
    int* p = (int *) malloc(sizeof(int) * n);
    if(p == NULL)
    {
        printf("Erro ao alocar o vetor de permutacao p em memoria\n!");
        exit(1);
    }

    fatoracao2(n, A, p);
    substituicao(n, A, p, b, x);

    free(p);
}