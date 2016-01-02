#include <cmath>
#include <iostream>

double norm(int n, double *x) {
  double res=0;
  for (int i=0;i<n;i++) res+=x[i]*x[i];
  return std::sqrt(res);
}

void plot_solution(int n, double *x) {
  for (int i=0;i<n;i++)
    std::cout << i << " " << x[i] << std::endl;
}

void print(int n, double *v) {
  std::cout.precision(2);
  for (int i=0;i<n;i++)
    std::cout << v[i] << std::endl;
}

void print(int n, double **m) {
  std::cout.precision(2);
  for (int j=0;j<n;j++) {
    for (int i=0;i<n;i++)
      std::cout << m[j][i] << " ";
    std::cout << std::endl;
  }
}

void print(int m, int n, double **A) {
  std::cout.precision(2);
  for (int j=0;j<m;j++) {
    for (int i=0;i<n;i++)
      std::cout << A[j][i] << " ";
    std::cout << std::endl;
  }
}
