#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "sistlinear.h"

int main(void)
{
	//vetores
	double *b1 = criavet(3);
	double *b2 = criavet(6);
    
    double *x1 = criavet(3);
    double *x2 = criavet(6);    

	b1[0] = 3;
	b1[1] = 3;
	b1[2] = -6;

	b2[0] = 2.5;
	b2[1] = 1.5;
	b2[2] = 1.0;
	b2[3] = 1.0;
	b2[4] = 1.5;
	b2[5] = 2.0;            

	printf("\n\nExibindo o vetor b1:\n");
	exibirVetor(b1, 3);

    printf("\n\nExibindo o vetor b2:\n");
    exibirVetor(b2, 6);    

    //Matrizes
    double **A1 = criamat(3, 3);
	double **A2 = criamat(6, 6);

	A1[0][0] = 1;
	A1[0][1] = 2;
	A1[0][2] = -1;    
	A1[1][0] = 2;
	A1[1][1] = 1;
	A1[1][2] = -2;
	A1[2][0] = -3;
	A1[2][1] = 1;
	A1[2][2] = 1;        

	A2[0][0] = 3;
	A2[0][1] = -1;
	A2[0][2] = 0;    
	A2[0][3] = 0;
	A2[0][4] = 0;
	A2[0][5] = 0.5;
	A2[1][0] = -1;
	A2[1][1] = 3;
	A2[1][2] = -1;        
	A2[1][3] = 0;
	A2[1][4] = 0.5;
	A2[1][5] = -0;    
	A2[2][0] = 0;
	A2[2][1] = -1;
	A2[2][2] = 3;
	A2[2][3] = -1;
	A2[2][4] = 0;
	A2[2][5] = 0;        
	A2[3][0] = 0;
	A2[3][1] = 0;
	A2[3][2] = -1;    
	A2[3][3] = 3;
	A2[3][4] = -1;
	A2[3][5] = 0;
	A2[4][0] = 0;
	A2[4][1] = 0.5;
	A2[4][2] = 0;        
	A2[4][3] = -1;        
	A2[4][4] = 3;        
	A2[4][5] = -1;                    
	A2[5][0] = 0.5;
	A2[5][1] = 0;
	A2[5][2] = 0;        
	A2[5][3] = 0;        
	A2[5][4] = -1;        
	A2[5][5] = 3;                    

	printf("\n\nExibindo a Matriz A1:\n");
	exibirMatriz(3, 3, A1);

	printf("\n\nExibindo a Matriz A2:\n");
	exibirMatriz(6, 6, A2);

    //int *p = (int *) malloc(sizeof(int)*3);
    //fatoracao2(3, A1, p);
    //printf("\n\n");
    //exibirMatriz(3,3, A1);


    printf("\n--------------------------------------\n");
    printf("Resolvendo o sistema linear 1: \n");
    gauss(3, A1, b1, x1);
    printf("\nA solucao encontrada aplicando gauus foi o vetor x:\n");
    exibirVetor(x1, 3);    

    printf("\n--------------------------------------\n");
    printf("Resolvendo o sistema linear 2: \n");
    //gauss(6, A2, b2, x2);
    //printf("\nA solucao encontrada aplicando gauus foi o vetor x:\n");
    //exibirVetor(x2, 6);    

	liberavet(b1);
	liberavet(b2);
    liberavet(x1);
    liberavet(x2);

	liberamat(3, A1);
	liberamat(6, A2);

	printf("\n\nFIM DO PROGRAMA\n");
	return 0;
}