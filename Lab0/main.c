#include <stdio.h>
#include "matriz.h"

int main(void)
{
	//vetores
	double *v = criavet(3);
	double *w = criavet(3);
	double *r = criavet(3);
	double *p = criavet(3);

	v[0] = 3;
	v[1] = 4;
	v[2] = 7;

	w[0] = 1;
	w[1] = 2;
	w[2] = 3;

	double resEscalar = prodescalar(3, v, w);
	printf("Produto Escalar => v.w = ");
	exibirVetor(v, 3);
	printf(".");
	exibirVetor(w, 3);
	printf(" = ");
	printf("%0.2f", resEscalar);

	printf("\n\nv = ");
	exibirVetor(v, 3);
	printf(" => Norma de v: %0.2f", norma2(3, v));
	printf("\n\n");

	//escalar
	int s = 5;

	printf("Multiplicacao por um escalar s=%d => v.%d = ", s, s);
	exibirVetor(v, 3);
	printf(" * %d = ", s);
	multvs(3, v, s, r);
	exibirVetor(r, 3);

	//matrizes
	double **A = criamat(3, 2);
	double **B = criamat(2, 2);
	double **C = criamat(3, 2);
	double **T = criamat(2, 3);

	A[0][0] = 1;
	A[0][1] = -3;
	A[1][0] = 2;
	A[1][1] = 5;
	A[2][0] = 0;
	A[2][1] = 6;

	B[0][0] = 1;
	B[0][1] = 0;
	B[1][0] = 0;
	B[1][1] = 1;

	printf("\n\nExibindo a Matriz A:\n");
	exibirMatriz(3, 2, A);

	printf("\n\nExibindo a Matriz B:\n");
	exibirMatriz(2, 2, B);

	printf("\n\nC = AxB =\n");
	multmm(3, 2, 2, A, B, C);
	exibirMatriz(3, 2, C);

	printf("\n\nCt(transposta)= \n");
	transposta(3, 2, C, T);
	exibirMatriz(2, 3, T);

	printf("\n\nMultiplicando T x v = \n");
	exibirMatriz(2, 3, T);
	printf(" x \n");
	exibirVetor(v, 3);
	multmv(2, 3, T, v, p);
	printf("\n = \n");
	exibirVetor(p, 2);
	printf("\n\n");

	//matriz triangular inferior
	printf("Matriz triangular inferior:\n");
	double **TRI = criamattri(3);
	TRI[0][0] = 1;
	TRI[1][0] = 2;
	TRI[1][1] = 3;
	TRI[2][0] = 4;
	TRI[2][1] = 5;
	TRI[2][2] = 6;
	exibirMatrizTri(3, TRI);

	liberavet(v);
	liberavet(w);
	liberavet(r);

	liberamat(3, A);
	liberamat(2, B);
	liberamat(3, C);
	liberamat(2, T);

	printf("\n\nFIM DO PROGRAMA\n");
	return 0;
}