#include "interp.h"

void regular (int n, double a, double b, double (*f) (double x), double* xi, double* yi)
{
    int idx = 0;
	xi[idx] = a;
	yi[idx] = f(xi[idx]);
	idx++;

    double step = (b-a)/(n-1);
	for(int i=0; i < n-2; i++)
	{
		xi[idx] = xi[idx-1] + step;
		yi[idx] = f(xi[idx]);
		idx++;
	}

	xi[idx] = b;
	yi[idx] = f(xi[idx]);
}

void chebyshev (int n, double a, double b, double (*f) (double x), double* xi, double* yi)
{
	int beta = 1, idx=0;

	for(beta;  beta <= 2*n - 1; beta+=2)
	{
		xi[idx] = ((b-a)/2) * cos((beta*PI)/(2*n)) + (a+b)/2;
		yi[idx] = f(xi[idx]);
		idx++;
	}
}

double lagrange (int n, double* xi, double* yi, double x) 
{
	double Px = 0;
	double Lx = 0;
	double num=0;
	double den=0;

	for(int i=0; i<n; i++)
	{
	    Lx = 0;
		num=1;
		den=1;
		for(int j=0; j<n; j++)
		{
			if(j != i){
				num*= (x - xi[j]);
				den*= (xi[i] - xi[j]);
			}
		}
		Lx = num/den; 
		Px += yi[i]*Lx;
	}
	return Px;
}
