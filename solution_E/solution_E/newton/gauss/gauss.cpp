// A=L*U
void FactorizeInPlace(int n, double** A) {
  for (int k=0;k<n;k++) {
    for (int i=k+1;i<n;i++) A[i][k]/=A[k][k];
    for (int j=k+1;j<n;j++)
      for (int i=k+1;i<n;i++)
        A[i][j]-=A[i][k]*A[k][j];
  }
}

// L*y=b
void ForwardSubstitute(int n, double** LU, double* b, double* y) {
  for (int i=0;i<n;i++) {
    y[i]=b[i];
    for (int j=0;j<i;j++)
      y[i]-=LU[i][j]*y[j];
  }
}

// U*x=y
void BackwardSubstitute(int n, double** LU, double* y, double* x) {
  for (int i=n-1;i>=0;i--) {
    x[i]=y[i];
    for (int j=n-1;j>i;j--)
      x[i]-=LU[i][j]*x[j];
    x[i]/=LU[i][i];
  }
}
