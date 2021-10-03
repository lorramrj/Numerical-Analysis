#include<stdio.h>
#include<math.h>

double derivada_ord2 (double (*f) (double x), double x, double h);

double derivada (int n, double (*f) (double x), double x, double h);

double trapezio (double (*f) (double), double a, double b, int n);

double simpson (double (*f) (double), double a, double b, int n);

