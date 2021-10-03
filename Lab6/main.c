#define _USE_MATH_DEFINES
#include <stdlib.h>
#include "integral.h"

#define PI M_PI

double f1(double x) {
	return cos(x) - 2*sin(x);
}
double f1derivate(double x)
{
     return -sin(x) - 2*cos(x);
}

double f2(double x) {
	return x / sqrt(pow(x, 2.0) + 9);
}

double f3(double x) {
	return pow(x, 2.0) * log(x);
}

double f4(double x) {
	return pow(x, 2.0) * sin(x);
}

int main(void)
{
     double X[6] = {0, PI/6, PI/4, PI/3, PI/2, PI};
     double H[6] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001};
     int N[4] = {2, 3, 4, 5};     

     double res1;
     printf("\n\n-------------------------------------------------\n\n");
     printf("Q1) \n\n");

     for(int k=0; k < 4; k++) 
     {
       for(int i=0; i < 6; i++)
       {
         for(int j=0; j < 6; j++)
         {
              res1 = derivada(N[k], f1, X[i], H[j]);
              printf("derivate method order %d | x=%lf with h=%lf => value calculate=%lf | value real=%lf | with error=%e\n\n", N[k], X[i], H[j], res1, f1derivate(X[i]), fabs(f1derivate(X[i])-res1));
         }
       }
     }
     printf("Vemos que metodos com ordem superior trazem resultados com erros menores e portanto mais precisos.\nAlem disso, com valores menores de h o erro tende-se a ser menor como vimos na aula e no resultado do lab.\nPodemos reduzir arbitrariamente o valor de h para achar um h otimo ou usar um metodo numerico para achar esse h otimo.");

     printf("\n\n-------------------------------------------------\n\n");
     printf("Q2) \n\n");

     int step;

     step = 16;
     printf("*> N = %d passos\n\n", step);
     double Tres2 = trapezio(f2,0,4,step);
     double Sres2 = simpson(f2,0,4,step);
     printf("Trapezio result f1 (with n=%d): %lf ===> comparison with real value: %lf\n\n", step, Tres2, fabs(2.0 - Tres2));
     printf("Simpson result f1 (with n=%d): %lf  ===> comparison with real value: %lf\n\n", step, Sres2, fabs(2.0 - Sres2));     
     
     double Tres3 = trapezio(f3,1,3,step);
     double Sres3 = simpson(f3,1,3,step);
     printf("Trapezio result f2 (with n=%d): %lf  ===> comparison with real value: %lf\n\n",step, Tres3, fabs(6.9986217091241 - Tres3));
     printf("Simpson result f2 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Sres3, fabs(6.9986217091241 - Sres3));     

     double Tres4 = trapezio(f4,0,PI,step);
     double Sres4 = simpson(f4,0,PI,step);     
     printf("Trapezio result f3 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Tres4, fabs(5.8696044010894 - Tres4));
     printf("Simpson result f3 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Sres4, fabs(5.8696044010894 - Sres4));     

     printf("---------------------------------\n\n");

     step = 32;
     printf("*> N = %d passos\n\n", step);
     Tres2 = trapezio(f2,0,4,step);
     Sres2 = simpson(f2,0,4,step);
     printf("Trapezio result f1 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Tres2, fabs(2.0 - Tres2));
     printf("Simpson result f1 (with n=%d): %lf   ===> comparison with real value: %lf\n\n", step, Sres2, fabs(2.0 - Sres2));     
     
     Tres3 = trapezio(f3,1,3,step);
     Sres3 = simpson(f3,1,3,step);
     printf("Trapezio result f2 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Tres3, fabs(6.9986217091241 - Tres3));
     printf("Simpson result f2 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Sres3, fabs(6.9986217091241 - Sres3));     

     Tres4 = trapezio(f4,0,PI,step);
     Sres4 = simpson(f4,0,PI,step);     
     printf("Trapezio result f3 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Tres4, fabs(5.8696044010894 - Tres4));
     printf("Simpson result f3 (with n=%d): %lf   ===> comparison with real value: %lf\n\n",step, Sres4, fabs(5.8696044010894 - Sres4));  

     printf("Como podemos ver o erro do metodo do Simpson eh menor e portanto mais eficiente, e ao aumentarmos o numero de passos de 16 para 32 o erro diminuiu em ambos os metodos!\n\n");
     return 0;
}