#include<utility>
#include "../../../utils/Eigen/Core"
#include "../../../utils/Eigen/Sparse"
using namespace std;

void Residual_Jacobian(int n, int m, pair<int,int> *nz, double* x, double* y, Eigen::SparseMatrix<double>* J);
