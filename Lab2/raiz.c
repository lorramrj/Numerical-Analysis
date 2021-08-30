#include "raiz.h"

#define TOL 0.5E-8
#define LIM 50

//avaliar o erro relativo entre estimativas consecutivas
//onde o erro relativo avaliado tenha precisao de 8 digitos, isto e, e < 0.5 × 10−8
//limite de convergência 50 passos

int secante (double x0, double x1, double (*f) (double x), double* r){

	int passos = 0;
	double xn=0.0, er=0.0;

	while(passos < LIM)
	{
			if(fabs(f(x0) - f(x1)) < 1E-15)
			{
			    xn = (x0 + x1)/2;
			}
			else 
			{
				xn = x1 - ( (f(x1)*(x1 - x0)) / (f(x1) - f(x0)) );
			}
						
			x0 = x1;
			x1 = xn;

			*r = x1;

			passos++;

			er = (fabs(x1-x0)/fabs(x1));
			printf("xn = %f | f(%f) = %f | error = %e | passo = %d\n", xn, xn, f(xn), er, passos);
			
			if(er < TOL)
			{
				break;
			}
	};

    return (passos == LIM)? 0 : passos;
}


int IQI (double x0, double x1, double x2, double (*f) (double x), double* r)
{
	int passos = 0;
	double A[3][3] = {0}, Ac[3][3] = {0};
	double determinanteA, determinanteAc, c;
	double valorX0 = f(x0), valorX1 = f(x1), valorX2 = f(x2);
	double er = 0.0;

	*r = valorX2;

	while(passos < LIM)
	{

		A[0][0] = valorX0 * valorX0;
		A[0][1] = valorX0;
		A[0][2] = 1;
		A[1][0] = valorX1 * valorX1;
		A[1][1] = valorX1;
		A[1][2] = 1;
		A[2][0] = valorX2 * valorX2;
		A[2][1] = valorX2;
		A[2][2] = 1;
	
		determinanteA = A[0][0] * ((A[1][1] * A[2][2]) - (A[2][1] * A[1][2])) - 
						A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) + 
						A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

		Ac[0][0] = valorX0 * valorX0;
		Ac[0][1] = valorX0;
		Ac[0][2] = x0;
		Ac[1][0] = valorX1 * valorX1;
		Ac[1][1] = valorX1;
		Ac[1][2] = x1;
		Ac[2][0] = valorX2 * valorX2;
		Ac[2][1] = valorX2;
		Ac[2][2] = x2;

		determinanteAc = Ac[0][0] * ((Ac[1][1] * Ac[2][2]) - (Ac[2][1] * Ac[1][2])) - 
						Ac[0][1] * (Ac[1][0] * Ac[2][2] - Ac[2][0] * Ac[1][2]) + 
						Ac[0][2] * (Ac[1][0] * Ac[2][1] - Ac[2][0] * Ac[1][1]);

		
		if(fabs(determinanteA) < 1E-15)
		{
			c = (determinanteAc + determinanteA)/2;
		}
		else {
			c = determinanteAc / determinanteA;
		}	

		x0 = x1;
		x1 = x2;
		x2 = c;		

		valorX0 = valorX1;
		valorX1 = valorX2;
		valorX2 = f(x2);

		*r = c;

		passos++;

		er = (fabs(x2-x1)/fabs(x2));		
		printf("passo: %d | detA: %e | detAc: %e| c: %e| error: %e\n", passos, determinanteA, determinanteAc, c, er);

		if(fabs(er) < TOL)
		{
			break;
		}
	}

	return (passos == LIM)? 0 : passos;
}

