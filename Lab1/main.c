#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "taylor.h"
#define PI M_PI

int main(void)
{
     double x1 = PI/10;
     double x2 = PI/8;
     double x3 = PI/6;
     double x4 = PI/4;
     double x5 = PI/3;

     printf("\nPI/10=%g | PI/8=%g | PI/6=%g | PI/4=%g | PI/3=%g", x1, x2, x3, x4, x5);
     printf("\n\n");
     
     printf("=> Para PI/10 => tan(PI/10)= %g", tan(x1));
     printf("\ntan1(PI/10)=%g com erro=%e", tan1(x1), tan(x1) - tan1(x1));
     printf("\ntan2(PI/10)=%g com erro=%e", tan2(x1), tan(x1) - tan2(x1));     
     printf("\n\n");

     printf("=> Para PI/8 => tan(PI/8)= %g", tan(x2));
     printf("\ntan1(PI/8)=%g com erro=%e", tan1(x2), tan(x2) - tan1(x2));
     printf("\ntan2(PI/8)=%g com erro=%e", tan2(x2), tan(x2) - tan2(x2));     
     printf("\n\n");

     printf("=> Para PI/6 => tan(PI/6)= %g", tan(x3));
     printf("\ntan1(PI/6)=%g com erro=%e", tan1(x3), tan(x3) - tan1(x3));
     printf("\ntan2(PI/6)=%g com erro=%e", tan2(x3), tan(x3) - tan2(x3));     
     printf("\n\n");

     printf("=> Para PI/4 => tan(PI/4)= %g", tan(x4));
     printf("\ntan1(PI/4)=%g com erro=%e", tan1(x4), tan(x4) - tan1(x4));
     printf("\ntan2(PI/4)=%g com erro=%e", tan2(x4), tan(x4) - tan2(x4));     
     printf("\n\n");

     printf("=> Para PI/3 => tan(PI/3)= %g", tan(x5));
     printf("\ntan1(PI/3)=%g com erro=%e", tan1(x5), tan(x5) - tan1(x5));
     printf("\ntan2(PI/3)=%g com erro=%e", tan2(x5), tan(x5) - tan2(x5));     
     printf("\n\n");

     printf("Avalidando os valores testados percebemos que a funcao tan1(x) tem um error menor em comparacao a tan2(x) para tan(x) em torno de x=0.\nPortanto tan1(x) e uma melhor aproximacao para tan(x) em torno de x=0");
     printf("\n\n");
	
     return 0;
}