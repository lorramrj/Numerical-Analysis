#include <math.h>
#include "matriz.h"
#include "sistlinear.h"

#define PI 3.1415

double* mmq (int m, int n, double** A, double* b);

double mmq_norma2 (int m, int n, double** A, double* b, double* x);

void ajuste (int n, double* t, double* c, double* a, double* b);