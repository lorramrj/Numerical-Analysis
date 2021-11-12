#include "ode.h"

double RungeKutta(double t0, double t1, double h, double y0, double (*f) (double t, double y)) {
  double k1, k2, k3, k4;
  double t, y, yn, tn;
  int cont=0;

  tn = t0;
  yn = y0;
  while (tn < (t1 - h/2.0)) {
    t = tn;
    y = yn;

    k1 = h * f(t,y);
    k2 = h * f(t + h/2, y + (k1/2));
    k3 = h * f(t + h/2, y + (k2/2));
    k4 = h * f(t + h,   y + k3);

    yn = y + 1.0/6 * (k1 + 2*k2 + 2*k3 + k4);
    tn = t + h;
    cont++;
  }
  printf("Metodo RungeKutta executado %d vezes.\n", cont);
  return yn;
}

double RungeKuttaAcoplado (double t0, double t1, double y0, double (*f) (double t, double y), double tol) {
  double k1, k2, k3, k4, k5, k6;
  double t, y, yn, ynn, tn, delta, lim;
  double h = pow(10.0, -7.0);
  int control;
  int cont=0;
 
  double *a = criavet(6);
  a[0]=1;
  a[1]=1.0/5;
  a[2]=3.0/10;
  a[3]=3.0/5;
  a[4]=1;
  a[5]=7.0/8;

  double **b = criamattri(5);
  b[0][0] = 1.0/5;
  b[1][0] = 3.0/40;
  b[1][1] = 9.0/40;
  b[2][0] = 3.0/10;
  b[2][1] = -9.0/10;
  b[2][2] = 6.0/5;    
  b[3][0] = -11.0/54;
  b[3][1] = 5.0/2;
  b[3][2] = -70.0/27;
  b[3][3] = 35.0/27;      
  b[4][0] = 1631.0/55296;
  b[4][1] = 175.0/512;
  b[4][2] = 575.0/13824;
  b[4][3] = 44275.0/110592;      
  b[4][4] = 253.0/4096;        
  
  double *c = criavet(6);
  c[0] = 37.0/378;
  c[1] = 0;
  c[2] = 250.0/621;
  c[3] = 125.0/594;
  c[4] = 0;
  c[5] = 512.0/1771;          

  double *cc = criavet(6);
  cc[0] = 2825.0/27648;
  cc[1] = 0;
  cc[2] = 18575.0/48384;
  cc[3] = 13525.0/55296;
  cc[4] = 277.0/14336;
  cc[5] = 1.0/4;          

  tn = t0;
  yn = y0;
  control=1;
  while (tn < (t1-h/2.0)) {
    t = tn;

    if(control)
    {
        y = yn;
    }    

    k1 = h * f(t,y);
    k2 = h * f(t + a[1]*h, y + b[0][0]*k1);
    k3 = h * f(t + a[2]*h, y + b[1][0]*k1 + b[1][1]*k2);
    k4 = h * f(t + a[3]*h, y + b[2][0]*k1 + b[2][1]*k2 + b[2][2]*k3);
    k5 = h * f(t + a[4]*h, y + b[3][0]*k1 + b[3][1]*k2 + b[3][2]*k3 + b[3][3]*k4);
    k6 = h * f(t + a[5]*h, y + b[4][0]*k1 + b[4][1]*k2 + b[4][2]*k3 + b[4][3]*k4 + b[4][4]*k5);

    yn = y + c[0]*k1 + c[1]*k2 + c[2]*k3 + c[3]*k4 + c[4]*k5 + c[5]*k6;
    ynn = y + cc[0]*k1 + cc[1]*k2 + cc[2]*k3 + cc[3]*k4 + cc[4]*k5 + cc[5]*k6;

    delta = fabs(yn - ynn);
    lim = pow(tol/delta, 1.0/5);

    if(lim >= 1.0)
    {
        h = fmin(1.2, lim)*h;
        tn = t + h;
        control=1;
    }
    else 
    {
        tn = tn - h;
        h =  0.9*lim*h;  
        tn = tn + h;
        control=0;
    }
    cont++;
  }
  printf("Metodo RungeKutta executado %d vezes.\n", cont);
  return yn;
}