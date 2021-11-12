#include "massamola.h"

double f_gravidade(double m, double g) {
  return m*g;
}

double f_vento(double t, double w0)
{
  return w0 * exp(-t/20.0);
}

double f_mola(double k, double r, double d, double norm_d)
{
  return -1 * k * (norm_d - r) * (d/norm_d);
}

void forca(double t, double x, double y, double* fx, double* fy)
{
  double k, r, m, g, w0, norm_d;
  
  k = 0.5;
  r = 200.0;
  m = 2.0;
  g = 9.8;
  w0 = 20.0;
  norm_d= sqrt(pow(x, 2.0) + pow(y, 2.0));
  //printf("norm_d=%lf\n", norm_d);

  //printf("f_vento= %lf | f_mola_x= %lf | f_mola_y= %lf | f_gravidade= %lf\n\n", f_vento(t, w0), f_mola(k, r, x, norm_d), f_mola(k, r, y, norm_d), f_gravidade(m,g));
  *fx = f_vento(t, w0) + f_mola(k, r, x, norm_d);
  *fy = f_gravidade(m,g) + f_mola(k, r, y, norm_d);  
}

double evolui(double t, double h, double x, double y, double xp, double yp, double* xn, double* yn)
{
    double  *fx_corr, *fy_corr;
    double m=2.0, coef=0.002;

    fx_corr = (double *) malloc(sizeof(double));
    fy_corr = (double *) malloc(sizeof(double));

    forca(t, x, y, fx_corr, fy_corr);

    *xn = x + (1 - coef)*(x - xp) + h*h*(*fx_corr/m);
    *yn = y + (1 - coef)*(y - yp) + h*h*(*fy_corr/m);

    free(fx_corr);
    free(fy_corr);

    return t+h;
}

void simula(double x0, double y0, double t_final, int n, double* x, double* y)
{
  int cont=0;
  double t, h=0.1, x_ant, y_ant, x_corr, y_corr;
  double *x_pos, *y_pos;  
  x_pos = (double *) malloc(sizeof(double));
  y_pos = (double *) malloc(sizeof(double));

  if(x_pos == NULL || y_pos == NULL) 
  {
      printf("Erro ao alocar memoria!");
      exit(1);
  }  

  //calcular, xant, y_ant inicial por Euler. Mas como o corpo esta em repouso em t0, logo v0=0.
  x_ant=x0;
  y_ant=y0;

  x_corr=x0;
  y_corr=y0;
  t=0;

  //h = (t_final/n);
  while (t <= t_final)
  {
    //printf("cont=%d\n", cont);
    //printf("h= %lf | t=%lf | x_corr=%lf | y_corr=%lf | x_ant=%lf | y_ant=%lf | x_pos=%lf | y_pos=%lf\n",h, t, x_corr, y_corr, x_ant, y_ant, *x_pos, *y_pos);    
    //printf("\n--------------------------------\n");
    t = evolui(t, h, x_corr, y_corr, x_ant, y_ant, x_pos, y_pos);
    
    x[cont] = *x_pos;
    y[cont] = *y_pos;

    x_ant = x_corr;
    y_ant = y_corr;
    x_corr = *x_pos;
    y_corr = *y_pos;

    cont++;
  };
  free(x_pos);
  free(y_pos);
}

