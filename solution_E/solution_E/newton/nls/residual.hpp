#include<utility>
using namespace std;

template<class T>
void Residual(int n, int m, pair<int,int>* nz, T *x, T *y) {
        for (int i=0;i<n;i++) y[i]=x[i];
        for (int i=0;i<m;i++) {
          int yc=nz[i].first;
          int xc=nz[i].second;
          if (xc!=yc){
              //y[xc]=y[xc]+x[yc];
              y[yc]=y[yc]+x[xc];
          }
        }
        for (int i=0;i<n;i++) y[i]=x[i]*(y[i]+n);
}
