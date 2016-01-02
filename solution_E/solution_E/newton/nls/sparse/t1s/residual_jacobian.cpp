#include<cmath>
#include<iostream>
using namespace std;

#include "residual.hpp"
#include "residual_jacobian.hpp"
#include "jsp.hpp"
#include "dco_t1s_type.hpp"
#include "../../../utils/ColPack/include/ColPack/ColPackHeaders.h"
#include "../../../utils/ColPack/include/ColPack/GraphColoringInterface.h"
#include "utils.hpp"

//#define DEBUG

void Residual_Jacobian(int n, int m, pair<int,int> *nz, double* x, double* y, Eigen::SparseMatrix<double>* J) {

    static bool firstRun = true;
    static ColPack::BipartiteGraphPartialColoringInterface * g;
    static double** colPackSeedMatrix;
    static double** compressedJacobian;
    static int seedRowCount, seedColCount;
    static unsigned int** colPackSparsityPattern;

    const double h=1e-7;
    dco_t1s_type *x_dco=new dco_t1s_type[n];
    dco_t1s_type *y_dco=new dco_t1s_type[n];

    if(firstRun) {
        firstRun = false;

        jsp x_jsp[n];
        jsp y_jsp[n];
        for(int i = 0; i<n; i++){
            x_jsp[i].v = x[i];
            x_jsp[i].nz.insert(i);
        }
        Residual(n,m,nz,x_jsp,y_jsp);

//#define DEBUG
#ifdef DEBUG
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(y_jsp[i].nz.find(j) != y_jsp[i].nz.end()) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
            cout << endl;
        }
#endif //DEBUG

        int maxNumberOfNonzerosPerRow=0;
        for (int i = 0; i < n; i++)
            if (y_jsp[i].nz.size() > maxNumberOfNonzerosPerRow)
                maxNumberOfNonzerosPerRow = y_jsp[i].nz.size();
        cout << "max number of nonzeros per row = " << maxNumberOfNonzerosPerRow << endl;

        // allocate memory for SparseCompressedRow format
        colPackSparsityPattern = new unsigned int*[n];
        for (int i = 0; i < n; i++)
            colPackSparsityPattern[i] = new unsigned int[maxNumberOfNonzerosPerRow+1];

        // convert jsp to SparseCompressedRow
        for (int i = 0; i < n; i++) {
            colPackSparsityPattern[i][0] = y_jsp[i].nz.size();
            int idx = 1;
            for (MYSET<int>::iterator j = y_jsp[i].nz.begin(); j != y_jsp[i].nz.end(); j++) {
                colPackSparsityPattern[i][idx] = *j;
                idx++;
            }
        }

        // build up graph
        g = new ColPack::BipartiteGraphPartialColoringInterface(SRC_MEM_ADOLC, colPackSparsityPattern, n, n);
        g->PartialDistanceTwoColoring("SMALLEST_LAST", "COLUMN_PARTIAL_DISTANCE_TWO");

        //From the coloring information, create and return the seed matrix
        colPackSeedMatrix = g->GetSeedMatrix(&seedRowCount, &seedColCount);

        g->PrintColumnPartialColoringMetrics();;

        // allocate memory for compressed Jacobian
        compressedJacobian = new double*[n];
        for (int i = 0; i < n; i++)
            compressedJacobian[i] = new double[seedColCount];
        //print(seedRowCount,seedColCount,colPackSeedMatrix);

    } // endif firstRun

    std::vector< Eigen::Triplet<double> > tripletList;

    for (int i=0; i<n; i++) {
        x_dco[i] = x[i];
    }
    for(int i = 0; i < seedColCount; i++) {
        // TODO: generate column of seed-matrix
        for(int j = 0; j < n; j++){
            x_dco[j].t = colPackSeedMatrix[j][i];
        }

        Residual(n,m,nz,x_dco,y_dco);

        for(int j = 0; j < seedRowCount; j++) {
            compressedJacobian[j][i] = y_dco[j].t;
        }
    }
    //print(seedRowCount,seedColCount,compressedJacobian);

    // Recover Jacobian matrix
    // =======================

    // recovered Jacobian data (coordinate format)
    unsigned int* rowIndex = NULL;
    unsigned int* colIndex = NULL;
    double*       jacValue = NULL;

    ColPack::JacobianRecovery1D* jr1d = new ColPack::JacobianRecovery1D;
    int nnz = jr1d->RecoverD2Cln_CoordinateFormat(g, compressedJacobian, colPackSparsityPattern, &rowIndex, &colIndex, &jacValue);

    for (int i = 0; i < nnz; i++) {
        tripletList.push_back(Eigen::Triplet<double>(rowIndex[i],colIndex[i],jacValue[i]));
    }
    J->setFromTriplets(tripletList.begin(), tripletList.end());

    delete jr1d; // also frees recovered Jacobian memory 

#ifdef DEBUG
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (*J).coeff(i,j) << " ";
        } cout << endl;
    }
#endif //DEBUG

    Residual(n,m,nz,x,y);
    delete [] x_dco;
    delete [] y_dco;
}
