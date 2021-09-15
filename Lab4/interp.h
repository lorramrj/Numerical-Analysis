#include<stdio.h>
#include<math.h>

#define PI 3.1416

void regular (int n, double a, double b, double (*f) (double x), double* xi, double* yi);

void chebyshev (int n, double a, double b, double (*f) (double x), double* xi, double* yi);

double lagrange (int n, double* xi, double* yi, double x);