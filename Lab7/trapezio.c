#include "trapezio.h"

double adaptiva (double a, double b, double (*f) (double x), double tol) {
    
    double m = (a+b)/2;

    double Tab = (b-a)*(f(a)+f(b))/2;
    double Tam = (m-a)*(f(a)+f(m))/2;
    double Tmb = (b-m)*(f(m)+f(b))/2;
    double delta = Tab - (Tam + Tmb);

    if(fabs(delta) > 3*tol)
        return adaptiva(a, m, f, tol/2) + adaptiva(m,b,f,tol/2);
    else
        return Tam + Tmb - delta/3;     
};

double p(double x) {
    return 1.0/sqrt(2.0*PI) * exp((-x*x)/2.0);
};

double probabilidade (double sigma) {
  double tol = 0.00000001;
  return adaptiva(-1*sigma, sigma, p, tol);
};
