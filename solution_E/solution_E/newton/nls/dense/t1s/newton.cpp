#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#include "utils.hpp"
#include "gauss.hpp"
#include "residual.hpp"
#include "sparsity_pattern.hpp"
#include "residual_jacobian.hpp"
#include "dco_timer.hpp"

int main(int c, char* v[]) {
  int n, m;
  pair<int,int> *nz;
  SparsityPattern(v[1],n,m,nz);
  double x[n], delta_x[n], y[n], *J[n];
  for (int i=0;i<n;i++) {
    J[i]=new double[n];
    x[i]=1; // starting point
  }
  Residual(n,m,nz,x,y);
  cout << "n=" << n << endl;
  cout << "m=" << m << endl;
  cout << "Starting from norm(y)=" << norm(n,y) << endl;

  dco::timer time_jac;
  dco::timer time_fac;
  dco::timer time_sol;

  while (norm(n,y)>1e-9) {
    time_jac.resume();
    Residual_Jacobian(n,m,nz,x,y,J);
    time_jac.stop();

    for (int i=0;i<n;i++) y[i]=-y[i];

    time_fac.resume();
    FactorizeInPlace(n,J);
    time_fac.stop();

    double z[n];
    time_sol.resume();
    ForwardSubstitute(n,J,y,z);
    BackwardSubstitute(n,J,z,delta_x);
    time_sol.stop();

    for (int i=0;i<n;i++)
        x[i]=x[i]+delta_x[i];
    Residual(n,m,nz,x,y);
    cout << "New norm(y)=" << norm(n,y) << endl;
  } 
  cout << endl <<  "Final norm(y)=" << norm(n,y) << endl;
  // plot_solution(n,x);

  cout << std::setprecision(3) << std::fixed;
  cout << "Timings:" << endl;
  cout << "Jacobian:      " << time_jac.elapsed() << endl;
  cout << "Factorization: " << time_fac.elapsed() << endl;
  cout << "Solution:      " << time_sol.elapsed() << endl;
  cout << "--------------------" << endl;
  cout << "Sum:           " << time_jac.elapsed()+time_fac.elapsed()+time_sol.elapsed() << endl;

  for (int i=0;i<n;i++) delete [] J[i];
  delete [] nz;
  return 0;
}
