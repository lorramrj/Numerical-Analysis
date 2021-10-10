
#include <stdlib.h>
#include "trapezio.h"
#include "math.h"

double f1(double x) {
     return x / (sqrt(x*x + 9.0));
}

double f2(double x) {
     return (2/sqrt(PI)) * exp(-x*x);
}

double f3(double x) {
     return log(cos(x) + sin(x));
}

int main(void)
{
     double TOL[10] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.0000000001};
     double S[3] = {1.0, 2.0, 3.0};

     printf("\nQ1) -----------------------------------------------\n\n");
     //funcao 1 

     double realRes1 = 0.1622776601683793;
     printf("Valor da integral da f1 calculado no site: %0.16lf\n\n", realRes1);

     printf("Calculando valores de f1 com a funcao adaptativa para diferentes valores de tolerancia:\n");
     for(int i=0; i < 10; i++)
     {
          double res1 = adaptiva(0, 1, f1, TOL[i]);
          printf("Tol=%e | res=%0.10lf | error=%e\n", TOL[i], res1, fabs(res1-realRes1));
     };
     printf("\n\n");

     //funcao 2

     double realRes2 = 0.9999779095030014;
     printf("Valor da integral da f2 calculado no site: %0.16lf\n\n", realRes2);

     printf("Calculando valores de f2 com a funcao adaptativa para diferentes valores de tolerancia:\n");
     for(int i=0; i < 10; i++)
     {
          double res2 = adaptiva(0, 3, f2, TOL[i]);
          printf("Tol=%e | res=%0.10lf | error=%e\n", TOL[i], res2, fabs(res2-realRes2));
     };
     printf("\n\n");

     //funcao 3
     
     double realRes3 = 0.3715690716013184;
     printf("Valor da integral da f3 calculado no site: %0.16lf\n\n", realRes3);

     printf("Calculando valores de f3 com a funcao adaptativa para diferentes valores de tolerancia:\n");     
     for(int i=0; i < 10; i++)
     {
          double res3 = adaptiva(0, PI/2.0, f3, TOL[i]);
          printf("Tol=%e | res=%0.10lf | error=%e\n", TOL[i], res3, fabs(res3-realRes3));
     };
     
     printf("\nResultados de integrais bem proximo do esperado, e conforme diminuimos a tolerancia o erro diminui conforme o esperado.\n\n");    

     printf("\nQ2) -----------------------------------------------\n\n");

     for(int i=0; i < 3; i++)
     {
          double resProb = probabilidade(S[i]);               
          printf("Para sigma=%lf | res=%0.8e | porcentagem=%0.10lf%\n", S[i], resProb, resProb*100);
     }
     printf("\nResultados de probabilidade esperados, conforme o grafico.\n\n");    
     
     return 0;
}