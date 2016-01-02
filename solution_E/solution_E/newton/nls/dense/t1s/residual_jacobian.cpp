#include<cmath>
#include<iostream>
using namespace std;
#include "dco_t1s_type.hpp"
#include "residual.hpp"

void Residual_Jacobian(int n, int m, pair<int,int> *nz, double* x, double* y, double**J) {
  dco_t1s_type *t1s_x=new dco_t1s_type[n];
  dco_t1s_type *t1s_y=new dco_t1s_type[n];
  for (int i=0;i<n;i++) t1s_x[i]=x[i];
  for (int i=0;i<n;i++) {
      t1s_x[i].t=1;
      Residual(n,m,nz,t1s_x,t1s_y);
      t1s_x[i].t=0;
      for (int j=0;j<n;j++) J[j][i]=t1s_y[j].t;
  }
  for (int i=0;i<n;i++) y[i]=t1s_y[i].v;
  delete [] t1s_y;
  delete [] t1s_x;
}
