#include "gradconj.h"
#include "matriz.h"

int gradconjSemPreCond(int n, double** A, double* b, double* x, double tol)
{
    double alpha=0,beta=0, prod_ecalar_r_corr, k;
    double *d = criavet(n);
    double *r = criavet(n);
    double *v = criavet(n);
    double *Ad = criavet(n);
    double *aux = criavet(n);
    
    multmv(n,n,A,x,v);    
    for(int i=0; i<n; i++)
    {
      d[i] = b[i] - v[i];
      r[i] = d[i];
    }

    for(k=1; k <= n; k++)
    {
      if(norma2(n,r)<tol)
      {
        break;
      }
      
      multmv(n, n, A, d , Ad); //A*dk

      prod_ecalar_r_corr = escalar(n, r, r);
      alpha = prod_ecalar_r_corr / escalar(n, d, Ad);

      multvs(n, d, alpha, aux);
      for(int i=0; i<n; i++)
         x[i] = x[i] + aux[i];

      multvs(n, Ad, alpha, aux);
      for(int i=0; i<n; i++)
         r[i] = r[i] - aux[i];

      beta = escalar(n, r, r) / prod_ecalar_r_corr;

      multvs(n, d, beta, aux);
      for(int i=0; i<n; i++)
         d[i] = r[i] + aux[i];
    }

    liberavet(d);
    liberavet(r);
    liberavet(v);
    liberavet(Ad);
    liberavet(aux);

    return k;
}
int gradconjComPreCond(int n, double** A, double* b, double* x, double tol)
{
    double alpha=0,beta=0, prod_ecalar_rz_corr, k;
    double *d = criavet(n);
    double *r = criavet(n);
    double *z = criavet(n);
    double *v = criavet(n);
    double *Ad = criavet(n);
    double *aux = criavet(n);
    
    multmv(n,n,A,x,v);    
    for(int i=0; i<n; i++)
    {
      r[i] = b[i] - v[i];
    }
    
    for(int i=0; i<n; i++)
    {
      z[i] = A[i][i] * r[i];
      d[i] = z[i];
    }

    for(k=1; k <= n; k++)
    {
      if(norma2(n,r)<tol)
      {
        break;
      }
      
      multmv(n, n, A, d , Ad); //A*dk

      prod_ecalar_rz_corr = escalar(n, r, z);
      alpha = prod_ecalar_rz_corr/escalar(n, d, Ad);

      multvs(n, d, alpha, aux);
      for(int i=0; i<n; i++)
         x[i] = x[i] + aux[i];

      multvs(n, Ad, alpha, aux);
      for(int i=0; i<n; i++)
         r[i] = r[i] - aux[i];

      for(int i=0; i<n; i++)
        z[i] = r[i] / A[i][i];


      beta = escalar(n, r, z) / prod_ecalar_rz_corr;

      multvs(n, d, beta, aux);
      for(int i=0; i<n; i++)
         d[i] = z[i] + aux[i];
    }

    liberavet(d);
    liberavet(r);
    liberavet(z);
    liberavet(v);
    liberavet(Ad);
    liberavet(aux);

    return k;
}

int gradconj (int n, double** A, double* b, double* x, double tol, int precond) {
  if(precond==0)
  {
    return gradconjSemPreCond(n, A, b, x, tol);
  }
  else {
    return gradconjComPreCond(n, A, b, x, tol);
  }

}

