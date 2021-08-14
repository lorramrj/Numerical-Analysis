#include <stdio.h>
#include "Lab01/matriz.h"


int main(void)
{
	//vetores
	double* v = criavet(3);
	double* w = criavet(3);

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
	double* r = criavet(3);

	printf("Multiplicacao por um escalar s=%d => v.%d = ", s, s);
	exibirVetor(v, 3);
	printf(" * %d = ", s);
	multvs(3, v, s, r);
	exibirVetor(r, 3);
	
	//matrizes
	double** A = criamat(3, 2);
	double** B = criamat(3, 2);
	double** D = criamat(3, 3);

	A[0][0] = 1;
	A[1][1] = -3;
	A[2][0] = 2;
	A[0][1] = 5;
	A[1][0] = 0;
	A[2][1] = 6;

	exibirMatriz(3, 2, A);

	//matriz triângular inferior
	double** T = criamattri(3);


	//produto escalar entre v e w


	printf("\n\nFIM DO PROGRAMA\n");
	return 0;
}