
#include <stdlib.h>
#include "ode.h"

double f(double t, double y) {
     return t*y + t*t*t;
}

double fres(double t) {
     return exp(t*t/2) - t*t - 2;
}

int main(void)
{
     double h = 0.001;
     double tol = pow(10.0, -12.0);
     double yn1, yn2, yres;
     
     double t0=0;
     double t1=2.4;
     double y0=-1.0;

     yres = fres(2.4);
     printf("\n\n");
     printf("=============================================");
     printf("\n---------> Avaliacao para t=%lf\n\n", t1);
     yn1 = RungeKutta(t0, t1, h, y0, f);
     printf("Runge Kutta com h fixo para t=2.4 => y(2.4)=%lf | y(2.4)=%lf (resultado real) | erro = %e\n", yn1, yres, fabs(yn1-yres));

     printf("\n");
     yn2 = RungeKuttaAcoplado(t0, t1, y0, f, tol);
     printf("Runge Kutta com passo h adaptativo para t=2.4 => y(2.4)=%lf | y(2.4)=%lf (resultado real) | erro = %e\n\n", yn2, yres, fabs(yn2-yres));  

     printf("Vemos que com o passo h fixo tivemos um erro menor porem um numero de passos cerca de x6 maior do que o metodo com passo h adaptativo!\n");
     printf("Como esperado ele respeita o erro local maximo tolerado, e nao o global\n");
     printf("=============================================");

     printf("\n\n=============================================");     
     printf("\n---------> Avaliando para diferentes t1's: \n");
     double t[5] = {0.9, 1.0, 1.8, 2.8, 3.5};

     for(int i=0; i<5; i++){
          yres = fres(t[i]);

          printf("\nAvaliacao para t=%lf\n\n", t[i]);
          yn1 = RungeKutta(t0, t[i], h, y0, f);
          printf("Runge Kutta com h fixo para t=2.4 => y(2.4)=%lf | y(2.4)=%lf (resultado real) | erro = %e\n", yn1, yres, fabs(yn1-yres));

          printf("\n");
          yn2 = RungeKuttaAcoplado(t0, t[i], y0, f, tol);
          printf("Runge Kutta com passo h adaptativo para t=2.4 => y(2.4)=%lf | y(2.4)=%lf (resultado real) | erro = %e\n\n", yn2, yres, fabs(yn2-yres));  
     }
     printf("=============================================");

     return 0;
}