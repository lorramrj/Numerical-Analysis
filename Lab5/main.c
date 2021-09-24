#include <stdio.h>
#include <stdlib.h>
#include "mmq.h"

int main(void)
{
    //erros
    double r1 = 0.0;
    double r2 = 0.0;

	//vetores
	double *b1 = criavet(5);
	double *b2 = criavet(5);
    
   	double *x1_ = criavet(3);
    double *x2_ = criavet(4);

    //Matrizes
    double **A1 = criamat(5, 3);
	double **A2 = criamat(5, 4);

    //preenchendo vetores os b's
	b1[0] = 10;
	b1[1] = 10;
	b1[2] = -5;
	b1[3] = 15;
	b1[4] = 0;        

	b2[0] = 10;
	b2[1] = 0;
	b2[2] = 2;
	b2[3] = 0;
	b2[4] = 5;
	
    //preenchendo as matrizes A's
	A1[0][0] = 3;
	A1[0][1] = -1;
	A1[0][2] = 2;    
	A1[1][0] = 4;
	A1[1][1] = 1;
	A1[1][2] = 0;
	A1[2][0] = -3;
	A1[2][1] = 2;
	A1[2][2] = 1;        
  	A1[3][0] = 1;
	A1[3][1] = 1;
	A1[3][2] = 5;        
	A1[4][0] = -2;
	A1[4][1] = 0;
	A1[4][2] = 3;        

	A2[0][0] = 4;
	A2[0][1] = 2;
	A2[0][2] = 3;    
	A2[0][3] = 0;
    A2[1][0] = -2;
	A2[1][1] = 3;
	A2[1][2] = -1;    
	A2[1][3] = 1;
    A2[2][0] = 1;
	A2[2][1] = 3;
	A2[2][2] = -4;    
	A2[2][3] = 2;
    A2[3][0] = 1;
	A2[3][1] = 0;
	A2[3][2] = 1;    
	A2[3][3] = -1;
    A2[4][0] = 3;
	A2[4][1] = 1;
	A2[4][2] = 3;    
	A2[4][3] = -2;
   
    printf("\n\n===============================================================\n");
    printf("\n");
	printf("\n\nExibindo o vetor b1:\n");
	exibirVetor(b1, 5);

    printf("\n\nExibindo o vetor b2:\n");
    exibirVetor(b2, 5);    

	printf("\n\nExibindo a Matriz A1:\n\n");
	exibirMatriz(5, 3, A1);

	printf("\n\nExibindo a Matriz A2:\n\n");
	exibirMatriz(5, 4, A2);

    printf("\n--------------------------------------\n");
    printf("Resolvendo o sistema inconsistente 1: \n");
    x1_ = mmq(5, 3, A1, b1);
    r1 = mmq_norma2(5, 3, A1, b1, x1_);

    printf("\nA solucao encontrada aplicando mmq foi o vetor x1_:\n");
    exibirVetor(x1_, 3);    
    printf("\nErro associado a x1_ (norma-2): %lf", r1);
    
    printf("\n\n--------------------------------------\n");
    printf("Resolvendo o sistema inconsistente 2: \n");
    x2_ = mmq(5, 4, A2, b2);
    r2 = mmq_norma2(5, 4, A2, b2, x2_);

    printf("\nA solucao encontrada aplicando mmq foi o vetor x2_:\n");
    exibirVetor(x2_, 4);    
    printf("\nErro associado a x1_ (norma-2): %lf", r2);
     
	liberavet(b1);
	liberavet(b2);
    liberavet(x1_);
    liberavet(x2_);

	liberamat(5, A1);
	liberamat(5, A2);

    /*----------------------------------------------------------------------*/
        
   	double *t = criavet(8);
    double *c = criavet(8);

    t[0] = 1;
	t[1] = 2;
	t[2] = 3;
	t[3] = 4;
	t[4] = 5;
	t[5] = 6;
	t[6] = 7;
	t[7] = 8;

    c[0] = 8.0;
	c[1] = 12.3;
	c[2] = 15.5;
	c[3] = 16.8;
	c[4] = 17.1;
	c[5] = 15.8;
	c[6] = 15.2;
	c[7] = 14.0;

    liberavet(c);
    liberavet(t);
    
	return 0;
}
