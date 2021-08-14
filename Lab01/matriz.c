
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

double prodescalar(int n, const double* v, const double* w)
{
	double soma = 0;
	for (int i = 0; i < n; i++)
	{

		soma += v[i] * w[i];
	}

	return soma;
}

double norma2(int n, const double* v)
{
	double soma = 0;
	for (int i = 0; i < n; i++)
	{
		soma += pow(v[i], 2);
	}

	double norma = sqrt(soma);
	return norma;
}

void multvs(int n, const double* v, double s, double* w)
{
	for (int i = 0; i < n; i++)
	{
		w[i] = s * v[i];
	}
}

double** criamat(int m, int n)
{
	double** M = (double**) malloc(m * sizeof(double*));
	if (M == NULL) return NULL;

	for (int i = 0; i < m; i++)
	{
		M[i] = (double *) malloc(n * sizeof(double));
		if (M[i] == NULL) return NULL;
	}
}

double** criamattri(int n)
{
	double** M = (double**)malloc(n * sizeof(double*));
	if (M == NULL) return NULL;

	for (int i = 1; i <= n; i++)
	{
		M[i-1] = (double*)malloc(i * sizeof(double));
		if (M[i-1] == NULL) return NULL;
	}
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

void liberamat(int m, double** A)
{
	for (int i = 0; i <= m; i++)
		liberavet(A[i]);

	liberavet(A);
}

void transposta(int m, int n, const double** A, double** T)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			T[j][i] = A[i][j];
		}
	}
}

void multmv(int m, int n, const double** A, const double* v, double* w)
{
	for (int i = 0; i < m; i++)
	{
		w[i] = 0;
		for (int j = 0; j < n; j++)
		{
			w[i] += A[i][j] * v[j];
		}
	}
}

void multmm(int m, int n, int q, const double** A, const double** B, double** C)
{
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < q; k++)
		{
			for (int j = 0; j < n; j++)
			{
				C[i][k] = A[i][j] * B[j][k];
			}
		}		
	}
}