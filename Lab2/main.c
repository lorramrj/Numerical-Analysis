#include <stdlib.h>
#include <conio.h>
#include "raiz.h"

//f(x) = x^2 - x - 2
double func_Q1(double x) {
	return (x*x - x - 2.0);
}

//f(x) = x^3 + x - 7
double funcQ2A(double x) {
     return (x*x*x + x - 7);
}

//f(x) = x^4 + x - 1
double funcQ2B(double x) {
     return x*x*x*x + x + 1;
}

//f(x) = 35 - ((9.8 * m)/15) * (1 - exp(-(15/m)*9))
double funcVelPQD(double m) {
     return 35 - ((9.8 * m)/15) * (1 - exp(-(15/m)*9));
}

int main(void)
{
     int passosSec = 0, passosIQI;
     double *rSec = (double*) malloc(sizeof(double));
     double* raizIQI = (double*) malloc(sizeof(double));
     double x0, x1, x2;

     if (rSec == NULL || raizIQI == NULL)
	{
		perror("Não foi possível alocar memória para executar os testes");
		return 0;
	}

     //Questão 1
     printf("\n-------------------------------------------------\n\n");
     printf("\nFuncao inicial de teste: f(x) = x^2 - x - 2\n");

     //Metodo da secante (1a)
     printf("\n=>(1a) Metodo da Secante:");
     printf("\nEntre com valor de x0: ");
     scanf("%lf", &x0);
     printf("Entre com valor de x1: ");
     scanf("%lf", &x1);

     printf("\n");
     passosSec = secante(x0, x1, &func_Q1, rSec);

     if(passosSec>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *rSec);
		printf("Numero de passos = %d\n", passosSec);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     //Método da Interpolação Quadrática Inversa (1b)
     printf("\n=>(1b) Metodo da Interpolacao Quadratica Inversa:");
     printf("\nEntre com valor de x0: ");
     scanf("%lf", &x0);
     printf("Entre com valor de x1: ");
     scanf("%lf", &x1);
     printf("Entre com valor de x2: ");
     scanf("%lf", &x2);

     printf("\n");
     passosIQI= IQI(x0, x1, x2, &func_Q1, raizIQI);

     if(passosIQI>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *raizIQI);
		printf("Numero de passos = %d\n", passosIQI);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     printf("\n-------------------------------------------------\n\n");

     printf("\nPressione qualquer tecla para iniciar os testes da questao (2a)...");
     getch();

     /*Questao 2A*/
     printf("\n-------------------------------------------------\n\n");

     printf("\nQ2) Funcao inicial de teste: f(x) = x^3 + x - 72\n");
     
     //Metodo da secante
     printf("\n=>(2a) Metodo da Secante:");
     printf("\nx0 = -5 | x1 = 10");
     passosSec = secante(-5, 10, &funcQ2A, rSec);
     printf("\n");

     if(passosSec>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *rSec);
		printf("Numero de passos = %d\n", passosSec);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }
     
     printf("\n\n(2a) x0 = 0 | x1 = 20");
     passosSec = secante(0, 20, &funcQ2A, rSec);
     printf("\n");

     if(passosSec>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *rSec);
		printf("Numero de passos = %d\n", passosSec);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     printf("\n\n(2a) x0 = 90 | x1 = 300");
     passosSec = secante(90, 300, &funcQ2A, rSec);
     printf("\n");

     if(passosSec>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *rSec);
		printf("Numero de passos = %d\n", passosSec);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     //Metodo IQI
     printf("\n=> (2a) Metodo IQI:");
     printf("\nx0 = -5 | x1 = 10 | x2 = 20");

     passosIQI= IQI(-5, 10, 20, &funcQ2A, raizIQI);

     if(passosIQI>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *raizIQI);
		printf("Numero de passos = %d\n", passosIQI);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     printf("\n(2a) x0 = 0 | x1 = 20 | x2 = 50");

     passosIQI= IQI(0, 20, 50, &funcQ2A, raizIQI);

     if(passosIQI>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *raizIQI);
		printf("Numero de passos = %d\n", passosIQI);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     printf("\n(2a) x0 = 90 | x1 = 300 | x2 = 500");

     passosIQI= IQI(90, 300, 500, &funcQ2A, raizIQI);

     if(passosIQI>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *raizIQI);
		printf("Numero de passos = %d\n", passosIQI);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     printf("\nAnalisando os valores testados na questao 2A a proximacao IQI encontrou uma aproximacao para a raiz da funcao em um numero de passos sutilmente menor do que o metodo da secante!\n");
     printf("\n-------------------------------------------------\n\n");

     /*Questao 2B*/

     printf("\n-------------------------------------------------\n\n");

     printf("\n(2b) Funcao inicial de teste de nao convergencia: f(x) = x^4 + x - 1\n");
     
     //Metodo da secante
     printf("\n=> (2b) Metodo da Secante:");
     printf("\nEntre com valor de x0: ");
     scanf("%lf", &x0);
     printf("Entre com valor de x1: ");
     scanf("%lf", &x1);

     printf("\n");
     passosSec = secante(x0, x1, &funcQ2B, rSec);

     if(passosSec>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *rSec);
		printf("Numero de passos = %d\n", passosSec);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     //Metodo da IQI
     printf("\n=> (2b) Metodo da Interpolacao Quadratica Inversa:");
     printf("\nEntre com valor de x0: ");
     scanf("%lf", &x0);
     printf("Entre com valor de x1: ");
     scanf("%lf", &x1);
     printf("Entre com valor de x2: ");
     scanf("%lf", &x2);

     printf("\n");
     passosIQI= IQI(x0, x1, x2, &funcQ2B, raizIQI);

     if(passosIQI>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor de r = %lf\n", *raizIQI);
		printf("Numero de passos = %d\n", passosIQI);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }
     
     printf("\nTestando varios valores os metodos nao convergiram para a funcao dada no item 2B como esperado, ja que nao tem raizes reais!\n");
     printf("\n-------------------------------------------------\n");

     /*Questao 2C*/
     printf("\n-------------------------------------------------\n");
     printf("\n (2c) Funcao inicial de teste: f(x) = 35 - ((9.8 * m)/15) * (1 - exp(-(15/m)*9))\n");
     
     //Metodo da secante
     printf("\n=>(2c) Metodo da Secante para determinar a massa 'm':");
     printf("\nEntre com valor de x0: ");
     scanf("%lf", &x0);
     printf("Entre com valor de x1: ");
     scanf("%lf", &x1);

     printf("\n");
     passosSec = secante(x0, x1, &funcVelPQD, rSec);

     if(passosSec>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor da massa = %lf\n", *rSec);
		printf("Numero de passos = %d\n", passosSec);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }


     //Método da Interpolação Quadrática Inversa
     printf("\n=>(2c) Metodo da Interpolacao Quadratica Inversa para determinar a massa 'm':");
     printf("\nEntre com valor de x0: ");
     scanf("%lf", &x0);
     printf("Entre com valor de x1: ");
     scanf("%lf", &x1);
     printf("Entre com valor de x2: ");
     scanf("%lf", &x2);

     printf("\n");
     passosIQI= IQI(x0, x1, x2, &funcVelPQD, raizIQI);

     if(passosIQI>0)
     {
          printf("\nConvergiu!\n");
		printf("Valor da massa = %lf\n", *raizIQI);
		printf("Numero de passos = %d\n", passosIQI);
     }
     else 
     {
          printf("\nNao convergiu!\n\n");
     }

     printf("Nos testes feitos com varios valores diferentes os dois metodos se mostraram bem parecidos nos numeros de passos para achar o valor aproximado da massa 'm'\n");
     printf("\n-------------------------------------------------\n\n");


     free(rSec);
     free(raizIQI);

     return 0;
}