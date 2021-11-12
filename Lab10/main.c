
#include <stdio.h>
#include <stdlib.h>
#include "metiter.h"
#include "matriz.h"

#define TOL pow(10, -7.0)
#define REL 1.1

int main(void)
{
     int do1, do2;
     double **A1 = criamat(2,2);
     double **A2 = criamat(6,6);
     double *b1 = criavet(2);
     double *b2 = criavet(6);
     double *x1 = criavet(2);
     double *x2 = criavet(6);

     A1[0][0] = 3;
     A1[0][1] = 1;
     A1[1][0] = 1;
     A1[1][1] = 2;

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
     A2[1][5] = 0;
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

     b1[0] = 5;
     b1[1] = 5;

     b2[0] = 2.5;
     b2[1] = 1.5;
     b2[2] = 1;
     b2[3] = 1;
     b2[4] = 1.5;
     b2[5] = 2.5;

     printf("\n");
     printf("A1=\n");
     exibirMatriz(2,2,A1);
     printf("\n");
     printf("A2=\n");
     exibirMatriz(6,6,A2);
     printf("\n");
     printf("b1= ");
     exibirVetor(b1,2);
     printf("\n");
     printf("b2= ");
     exibirVetor(b2,6);
     printf("\n\n");

     do1 = gauss_seidel(2,A1,b1,x1,TOL);
     do2 = gauss_seidel(6,A2,b2,x2,TOL);
     
     printf("\n------------------------------------------\n");
     printf("Sistema 1:\n");
     if(!do1)
     {
          printf("A1 nao e estritamente diagonal dominante!\n");
     } 
     else {
          printf("\nSolucao com %d iteracoes, utilizando o metodo Gauus seidel: ", do1);
          printf("\n\nx1 = ");
          exibirVetor(x1, 2);
     }

     printf("\n\n------------------------------------------\n");
     printf("Sistema 2:\n");
     if(!do2)
     {
          printf("A2 nao e estritamente diagonal dominante!\n");
     } 
     else {
          printf("\nSolucao com %d iteracoes, utilizando o metodo Gauus seidel: ", do2);
          printf("\n\nx2 = ");
          exibirVetor(x2, 6);
     }

     printf("\n");

     do1 = SOR(2,A1,b1,x1,TOL,REL);
     do2 = SOR(6,A2,b2,x2,TOL,REL);
     
     printf("\n------------------------------------------\n");
     printf("Sistema 1:\n");
     if(!do1)
     {
          printf("A1 nao e estritamente diagonal dominante!\n");
     } 
     else {
          printf("\nSolucao com %d iteracoes, utilizando o metodo Gauus seidel c/ relaxacao sucessiva de rel=1.1: ", do1);
          printf("\n\nx1 = ");
          exibirVetor(x1, 2);
     }

     printf("\n\n------------------------------------------\n");
     printf("Sistema 2:\n");
     if(!do2)
     {
          printf("A2 nao e estritamente diagonal dominante!\n");
     } 
     else {
          printf("\nSolucao com %d iteracoes, utilizando o metodo Gauus seidel c/ relaxacao sucessiva de rel=1.1: ", do2);
          printf("\n\nx2 = ");
          exibirVetor(x2, 6);
     }

     printf("\n\n");
     printf("Podemos ver que usando o metodo do Gauus Seidel com relaxacao sucessiva com sobre-relaxao houve uma convergencia muito mais rapida para solucao dos sistemas!");
     printf("\n\n");
     liberamat(2, A1);
     liberamat(6, A2);
     liberavet(b1);
     liberavet(b2);
     liberavet(x1);
     liberavet(x2);
     return 0;
}