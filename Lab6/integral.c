#include "integral.h"

double derivada_ord2(double (*f) (double x), double x, double h)
{
	return ((*f)(x+h)-(*f)(x-h))/(2*h);
};

double derivada (int n, double (*f) (double x), double x, double h)
{
	if(n==2)
	{
		return derivada_ord2(f, x, h);
	}
	else
	{	
		return (pow(2.0, n-1) * derivada(n-1, f, x, h/2) - derivada(n-1, f, x, h)) / ((pow(2.0, n-1))-1);
	}
};

double trapezio(double (*f) (double), double a, double b, int n) {
 
  double x, sum=0;
  double h=fabs(b-a)/n;

  for(int i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }

  return (h/2.0)*(f(a)+f(b)+2.0*sum);  
};

double simpson(double (*f) (double),double a,double b,int n){
  
  double x,sum, h;
  h=fabs(b-a)/n;
  
  sum=0;
  for(int i=1;i<n;i++){
    x=a+i*h;
	sum = (i%2==0) ? sum+2*f(x) : sum+4*f(x);
  }

  return (h/3)*(f(a)+f(b)+sum);  
}
 

