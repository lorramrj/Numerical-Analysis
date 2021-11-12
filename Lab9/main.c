
#include <stdio.h>
#include <stdlib.h>
#include "massamola.h"

#define N 1000
 
int main(void)
{
     double ti=0.0, tf = 100;
     double x0=200, y0=0;
     double *x, *y;
     x = (double *) malloc(sizeof(double)*N);
     y = (double *) malloc(sizeof(double)*N);
     if(x == NULL || y == NULL) 
     {
          printf("Erro ao alocar memoria!");
               exit(1);
     }

     simula(x0, y0, tf, N, x, y);
     printf("\n\n-----------------------------\n");     
     printf("Para n=%d passos:\n", N);

     for(int j=0; j<N; j++)
     {   
       printf("t=%lf => (x,y)=(%lf,%lf)\n", ti, x[j], y[j]);
       ti+=0.1;
     }

     //int n[7] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
     /*
     for(int i=0; i<5; i++)
     {
          x = (double *) malloc(sizeof(double)*n[i]);
          y = (double *) malloc(sizeof(double)*n[i]);
          if(x == NULL || y == NULL) 
          {
               printf("Erro ao alocar memoria!");
               exit(1);
          }

          simula(x0, y0, tf, n[i], x, y);
          
          printf("\n\n-----------------------------\n");
          printf("Para n=%d passos:\n", n[i]);
          for(int j=0; j<n[i]; j++)
          {   
               if(i==0)
               {
                    printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
               }

               if(i==1)
               {
                    if(j % 10 == 0) {
                         printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
                    }
               }
               
               if(i==2) 
               {
                    if(j % 100 == 0) {
                         printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
                    }
               }
               
               if(i==3) 
               {
                    if(j % 1000 == 0) {
                         printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
                    }
               }
               /*
               if(i==4) 
               {
                    if(j % 10000 == 0) {
                         printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
                    }
               }

               if(i==5) 
               {
                    if(j % 100000 == 0) {
                         printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
                    }
               }
              
               if(i==6) 
               {
                    if(j % 1000000 == 0) {
                         printf("(x,y)=(%lf,%lf)\n", x[j], y[j]);
                    }
               }
          }
          free(x);
          free(y);
     }
     */

     return 0;
}