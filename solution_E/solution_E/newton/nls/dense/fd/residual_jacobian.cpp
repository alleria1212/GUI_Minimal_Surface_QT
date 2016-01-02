#include<cmath>
#include<iostream>
using namespace std;
#include "dco_t1s_type.hpp"
#include "residual.hpp"
#include "utils.hpp"

void Residual_Jacobian(int n, int m, pair<int,int> *nz, double* x, double* y, double**J) {
  const double h=1e-7;
  double *xmh=new double[n];
  double *xph=new double[n];
  double *ymh=new double[n];
  double *yph=new double[n];
  for (int i=0;i<n;i++) xph[i]=xmh[i]=x[i];
  for (int i=0;i<n;i++) {
      xph[i]+=h;
      Residual(n,m,nz,xph,yph);
      xph[i]-=h;
      xmh[i]-=h;
      Residual(n,m,nz,xmh,ymh);
      xmh[i]+=h;
      for (int j=0;j<n;j++) J[j][i]=(yph[j]-ymh[j])/(2*h);
  }
  //print(n,J);
  Residual(n,m,nz,x,y);
  delete [] yph;
  delete [] ymh;
  delete [] xph;
  delete [] xmh;
}
