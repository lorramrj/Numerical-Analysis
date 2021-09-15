#include "interp.h"
#include <stdlib.h>
#include <stdio.h>

double funcDistribuicaoNormal(double x)
{
	double factor = (-0.5)*((x/0.5)*(x/0.5));
	return (1 / (0.5*sqrt(2*PI))) * exp(factor);
}

double exibirVetor(int n, double *v)
{
	int i=0;
	printf("\n[");
	for(i; i < n-1; i++)
	{
		printf("%e, ", v[i]);
	}
	printf("%e]", v[i]);
}

int main(void)
{
	double a = -2;
	double b = 2;

	double yres1, yres2, yreal;

	double *x1, *x2, *y1, *y2;

	int n[5]= {3, 5, 8, 10, 15};
	double aval[8] = {-2, -1.5, -1.2, 0, 0.5, 1.2, 1.5, 2};

	for(int i=0; i<5; i++)
	{		
			printf("-----------------------------------\n");
			printf("Avaliando a funcao para n=%d\n\n", n[i]);

			x1 = (double *) malloc(n[i] * sizeof(double));
			x2 = (double *) malloc(n[i] * sizeof(double));

			y1 = (double *) malloc(n[i] * sizeof(double));
			y2 = (double *) malloc(n[i] * sizeof(double));

			if(x1 == NULL || x2 == NULL || y1 == NULL || y2 == NULL)
			{
				printf("Erro na alocacao de memoria!\n");
				exit(1);
			}
   
    		regular(n[i], a, b, funcDistribuicaoNormal, x1, y1);			
			printf("> Distribuicao regular, vetores x e y:\n");
			exibirVetor(n[i], x1);
			exibirVetor(n[i], y1);

			chebyshev(n[i], a, b, funcDistribuicaoNormal, x2, y2);
			printf("\n\n> Distribuicao chebyshev, vetores x e y:\n");
			exibirVetor(n[i], x2);
			exibirVetor(n[i], y2);

			printf("\n");
			for(int j=0; j < 8; j++)
			{
				printf("\n*Avaliando o polinomio de lagrange para as distribuicoes no ponto x0=%lf\n", aval[j]);
	    		yres1 = lagrange(n[i], x1, y1, aval[j]);
				yres2 = lagrange(n[i], x2, y2, aval[j]);

				yreal = funcDistribuicaoNormal(aval[j]);

				printf("\nf(%lf)= %e  (distribuicao regular) | ERRO= %e\n", aval[j], yres1, fabs(yreal - yres1));
				printf("f(%lf)= %e  (distribuicao chebyshev) | ERRO= %e\n", aval[j], yres2, fabs(yreal - yres2));
				printf("f(%lf)= %e  (funcao original)\n", aval[j], yreal);
			}

			x1 = NULL;
			x2 = NULL;
			y1 = NULL;
			y2 = NULL;
	}		

			printf("\n\nAnalisando diversos tamanho de amostras e em pontos no intervalo [-2,2], percebe-se que a amostragem de Chebyshev perde para a amostragem regular em diversos momentos comparados a erro absoluto, mas o erro absoluto maximo encontrado foi da amostragem regular > f(-1.200000)= 5.107419e-01  (distribuicao regular) | ERRO= 4.659529e-01.\nPortanto, a amostragem de Chebyshev para esses casos analisados diminuiu o erro maximo!\n\n");

			free(x1);
			free(x2);
			free(y1);
			free(y2);

	return 0;
}
