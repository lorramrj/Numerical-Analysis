#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matriz.h"

double* criavet(int n)
{
	double* v = (double*) malloc(n * sizeof(double));
	return v;
}

void exibirVetor(double* v, int n)
{
	printf("(");
	for (int i = 0; i < n; i++)
	{
		printf("%0.2f ", v[i]);
	}
	printf(")");
}

void liberavet(double* v)
{
	free(v);
}

double escalar(int n, double* v,  double* w)
{
	double soma = 0;
	for (int i = 0; i < n; i++)
	{

		soma += v[i] * w[i];
	}

	return soma;
}

double norma2(int n, double* v)
{
	double soma = 0;
	for (int i = 0; i < n; i++)
	{
		soma += pow(v[i], 2);
	}

	double norma = sqrt(soma);
	return norma;
}

void multvs(int n, double* v, double s, double* w)
{
	for (int i = 0; i < n; i++)
	{
		w[i] = s * v[i];
	}
}

double** criamat(int m, int n)
{
	double** M = (double**) malloc(m * sizeof(double*));

	for (int i = 0; i < m; i++)
	{
		M[i] = criavet(n);
	}

	return M;
}

double** criamattri(int n)
{
	double** M = (double**)malloc(n * sizeof(double*));

	for (int i=0; i < n; i++)
	{
		M[i] = criavet(i+1);
	}
	return M;
}

void exibirMatriz(int m, int n, double** M)
{
	for (int i = 0; i < m; i++)
	{
		printf("[");
		for (int j = 0; j < n; j++)
		{
			printf(" %0.2f ", M[i][j]);
		}
		printf("]\n");
	}
}

void exibirMatrizTri(int n, double **M)
{
	for (int i = 0; i < n; i++)
	{
		printf("[");
		for (int j = 0; j < n; j++)
		{
			if(j <= i)
			{
			 printf(" %0.2f ", M[i][j]);
			}
			else 
			{
			 printf(" %d ",0);
			}
		}
		printf("]\n");
	}
}


void liberamat(int m, double** A)
{
	for (int i = 0; i < m; i++)
		liberavet(A[i]);

	free(A);
}

void transposta(int m, int n, double** A, double** T)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			T[j][i] = A[i][j];
		}
	}
}

void multmv(int m, int n, double** A, double* v, double* w)
{
	for(int i = 0; i < m; i++)
	{
		w[i] = escalar(n, A[i], v);
	}
}

void multmm(int m, int n, int q, double** A, double** B, double** C)
{
	double produto = 0.0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < q; j++)
		{
			for(int k = 0; k < n; k++) 
			{
				produto += A[i][k] * B[k][j];
			}

			C[i][j] = produto;
			produto = 0.0;
		}
	}
}