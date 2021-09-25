#include <stdlib.h>
#include <stdio.h>
#include "mmq.h"

double* mmq (int m, int n, double** A, double* b)
{
    double** At = criamat(n, m);    
    double** At_x_A = criamat(n, n);
    
    double* At_x_b = criavet(n);
    double* x_ = criavet(n);

    //transposta de A
	transposta(m, n, A, At);

    //multiplicacao de A por At
   	multmm(n, m, n, At, A, At_x_A);

    //mutiplicacao de At pelo vetor b
    multmv(n, m, At, b, At_x_b);

    gauss(n, At_x_A, At_x_b, x_);

	liberamat(n, At);
	liberamat(n, At_x_A);
    liberavet(At_x_b);	

    return x_;
}

double mmq_norma2 (int m, int n, double** A, double* b, double* x)
{
	double* r = criavet(m);
	double* A_xx_ = criavet(m);
	double erro = 0.0;    
    int i;
	
	multmv(m, n, A, x, A_xx_);

	for (i = 0; i < m; i++)
    {
		r[i] = b[i] - A_xx_[i];
    }

	erro = norma2(m, r);

	liberavet(A_xx_);
	liberavet(r);

	return erro;
}

void ajuste (int n, double* t, double* c, double* a, double* b)
{
	double** A = criamat(n, 2);
    double *y = criavet(n);    

    double *x = criavet(2);    
    double k = 0.0;

    for(int i = 0; i < n; i++)
	{
		A[i][0] = 1;
		A[i][1] = t[i];

        y[i] = log(c[i]/t[i]);
	}

    printf("\n");
    printf("Matriz A formada: \n");
    exibirMatriz(n, 2, A);
    printf("\n");
    printf("Vetor Y formado: \n");
    exibirVetor(y, n);

    x = mmq(n, 2, A, y);

    k = x[0];

    *a = exp(k);
    *b = x[1];


    printf("\n\nErro associado (norma-2)= %lf", mmq_norma2(n, 2, A, y, x));

    liberavet(x);
    liberavet(y);
    liberamat(n, A);
}