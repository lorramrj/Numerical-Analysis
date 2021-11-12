#include "metiter.h"
#include "matriz.h"

double diff_norma2 (int n, double* v, double* u){
	int i;
  double soma = 0;
	for (i=0; i<n; i++)
		soma += (v[i] - u[i]) * (v[i] - u[i]);
	return sqrt(soma);
}

int diagonal_dominante(int n, double** A) {

  double d, sumRow;
  for(int i=0; i < n; i++){
    d=0.0;
    sumRow=0.0;
    for(int j=0; j < n; j++) {
      if (i==j) {
        d=fabs(A[i][j]);
      }
      else {
        sumRow += fabs(A[i][j]);
      }
    }      
    if(sumRow >= d) 
    {
      return 0;
    }
  }
  return 1;
}

int gauss_seidel (int n, double** A, double* b, double* x, double tol) {

  if(!diagonal_dominante(n, A))
    return 0;
  
  int i, j, k, n_iter;
  double Uxk, Lxk1, dist = 1;
  double* x_ult = criavet(n);

  for(n_iter=1; dist > tol; n_iter++)
  {
    for(k=0; k<n; k++)
        x_ult[k] = x[k];

    for(i=0; i<n; i++)
    {
      Uxk = 0;
      Lxk1 = 0;
      for(j=0; j<n; j++)
      {
        if(i < j)
          Uxk += A[i][j]*x[i];

        if(i > j)
           Lxk1 += A[i][j]*x[j];
      }          
      x[i] = (b[i] - Uxk - Lxk1) / A[i][i];
    }

    dist = diff_norma2(n, x, x_ult);
  }
  
  liberavet(x_ult);
  return n_iter;
}


int SOR (int n, double** A, double* b, double* x, double tol, double w) {
  
  if(!diagonal_dominante(n, A))
    return 0;
  
  int i, j, k, n_iter;
  double Uxk, Lxk1, dist = 1;
  double* x_ult = criavet(n);

  for(n_iter=1; dist > tol; n_iter++)
  {
    for(k=0; k<n; k++)
        x_ult[k] = x[k];

    for(i=0; i<n; i++)
    {
      Uxk = 0;
      Lxk1 = 0;
      for(j=0; j<n; j++)
      {
        if(i < j)
          Uxk += A[i][j]*x[i];

        if(i > j)
           Lxk1 += A[i][j]*x[j];
      }          
      x[i] = (b[i] - Uxk - Lxk1) / A[i][i];
      x[i] = (1-w)*x_ult[i] + w*x[i];
    }

    dist = diff_norma2(n, x, x_ult);
  }
  
  liberavet(x_ult);
  return n_iter;
} 