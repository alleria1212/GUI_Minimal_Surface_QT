#include<cmath>
#include<iostream>
using namespace std;
#include "dco_a1s_type.hpp"
#include "residual.hpp"

extern dco_a1s_tape_entry dco_a1s_tape[DCO_A1S_TAPE_SIZE];

void Residual_Jacobian(int n, int m, pair<int,int> *nz, double* x, double* y, double**J) {
  dco_a1s_type *a1s_x=new dco_a1s_type[n];
  dco_a1s_type *a1s_y=new dco_a1s_type[n];
  for (int i=0;i<n;i++) a1s_x[i]=x[i];
  Residual(n,m,nz,a1s_x,a1s_y);
  for (int i=0;i<n;i++) y[i]=a1s_y[i].v;
  for (int i=0;i<n;i++) {
    dco_a1s_tape[a1s_y[i].va].a=1;
    dco_a1s_interpret_tape();
    for (int j=0;j<n;j++) J[i][j]=dco_a1s_tape[a1s_x[j].va].a;
    dco_a1s_zero_adjoints();
  }
  delete [] a1s_y;
  delete [] a1s_x;
}
