#ifndef SOLVERFUNCTIONS_H
#define SOLVERFUNCTIONS_H

#include "parameter.h"
#include <cmath>
#include <utility>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <QDebug>


/*!
 * solverfunctions Implementiert die Funktionen zur Berechnung des Residuums und der Jacobimatrix des Minimalflaechenproblems
 */


template <typename T>
/*!
 * \brief minsurface_residual berechnet das Residuum des Minimalflaechenproblems
 *
 * Die Implementierung der Funktion wurde generisch gehalten, sodass Vektoren jedes Typen uebergeben werden koennen. Dies ermoeglicht
 * die Implementierung eigener Funktionen zur Berechung der Jacobimatrix, z.B. mit colouring.
 * Die Funktion berechnet minsurface_residual(z) = R mithilfer der numerischen Parameter
 * \param params: Numerische Parameter
 * \param z: aktuelle Loesung
 * \param R: Residuum aktueller Loesung
 */
void minsurface_residual(Parameter * params, const std::vector<T> & z, std::vector<T> & R)
{
    //Schrittweiten
    T h_x = (params->xmax - params->xmin)/params->n;
    T h_y=  (params->ymax - params->ymin)/params->m;
    std::vector<std::vector<T> > tmp_mat;

    for(int i=0; i<params->m+1; i++)
    {
        tmp_mat.push_back(std::vector<T>(params->n+1));
        for(int j=0; j<params->n+1; j++)
            tmp_mat[i][j] = params->boundaries[i][j];
    }

    //Fuellen von z in die Volle Matrix der Parameter
    for(int i= 1; i < params->m; i++)
    {
        for(int j = 1; j< params->n ; j++)
        {
            params->boundaries[i][j] = z[(params->n-1)*(i-1) + (j-1)].v;
            tmp_mat[i][j] = z[(params->n-1)*(i-1) + (j-1)];
        }
    }



    //Inisialisierung von R als Matrix
    std::vector<std::vector<T> > R_mat;
    for(int i = 0; i<params->m-1; i++)
        R_mat.push_back(std::vector<T>(params->n-1));

    //Berechnung von R als Matrix
    for(int i = 1; i< params->m; i++)
    {
        for(int j=1; j< params->n ; j++)
        {
            // Temp values
            T ziij = tmp_mat[i+1][j];
            T zij = tmp_mat[i][j];
            T zj = tmp_mat[i-1][j];
            T zijj = tmp_mat[i][j+1];
            T zi = tmp_mat[i][j-1];
            T ziijj = tmp_mat[i+1][j+1];
            T zii = tmp_mat[i+1][j-1];
            T zjj = tmp_mat[i-1][j+1];
            T z0 = tmp_mat[i-1][j-1];

            T tmp_I = (1+((ziij - zj)/(2*h_x)*(ziij - zj)/(2*h_x))) * (zi - 2*zij + zijj)/(h_y*h_y);
            T tmp_II = -1/(8*h_x*h_x*h_y*h_y) * (ziij - zj) * (zijj - zi) * (ziijj - zjj - zii + z0);
            T tmp_III = (1+((zijj - zi)/(2*h_y)*(zijj - zi)/(2*h_y))) * (zj - 2*zij + ziij)/(h_x * h_x) ;

            R_mat[i-1][j-1] = tmp_I + tmp_II + tmp_III;
        }
    }

    //Speicherung von R als Vektor
    for(int i = 0; i< params->m-1; i++)
    {
        for(int j = 0; j< params->n-1; j++)
        {
            R[(params->n-1)*i+j] = R_mat[i][j];
        }
    }
}

template <typename T>
/*!
 * \brief minsurface_jacobian: Berechnet die Jacobimatrix des Residuums
 *
 * Numerische Berechnung der Jacobimatrix J(R) fuer das Newton Verfahren. Die Jacobimatrix wird als Duennbesetzte Matrix
 * aus allen nicht null Werten erstellt.
 * \param params: Numerische Parameter
 * \param z: Aktuelle Loesung
 * \param R: Aktuelles Residuum
 * \param J: Jacobimatrix
 */
void minsurface_jacobian(Parameter * params, const std::vector<T> & z, const std::vector<T> & R, Eigen::SparseMatrix<double> *J)
{
    //Initialize Parameters
    int size_z = (params->n-1)*(params->m-1);
    double eps = 1e-04;

    //Initialize Temporary Vectors
    std::vector<Eigen::Triplet<T> > tripletList;
    std::vector<T> temp_eps(size_z);
    for(int i=0; i<size_z; i++)
        temp_eps[i] = z[i];
    std::vector<T> temp_sol(size_z);

    //Calculate non-zero entries
    for(int i=0; i<size_z; i++)
    {
        temp_eps[i] += eps;
        minsurface_residual(params, temp_eps, temp_sol);
        for(int j=0; j<size_z; j++)
        {
            double temp_der;
            temp_der = (temp_sol[j] - R[j])/eps;
            if(temp_der)
            {
                tripletList.push_back(Eigen::Triplet<T>(j,i,temp_der));
            }
        }
        temp_eps[i] -= eps;
    }

    J->setFromTriplets(tripletList.begin(),tripletList.end());
}

template <typename T>
void minsurface_jacobian_dco(Parameter * params, const std::vector<T> & z, Eigen::SparseMatrix<double> *J)
{
    //Initialize Parameters
    int size_z = (params->n-1)*(params->m-1);

    //Initialize Temporary Vectors
    std::vector<Eigen::Triplet<double> > tripletList;
    std::vector<T> temp_eps(size_z);
    for(int i=0; i<size_z; i++)
    {
        temp_eps[i] = z[i];
    }
    std::vector<T> temp_sol(size_z);
    double temp_der;

    //Calculate non-zero entries
    for(int i=0; i<size_z; i++)
    {
        temp_eps[i].t = 1;
        minsurface_residual(params, temp_eps, temp_sol);
        temp_eps[i].t = 0;
        for(int j=0; j<size_z; j++)
        {
            temp_der = temp_sol[j].t;
            if(temp_der)
                tripletList.push_back(Eigen::Triplet<double>(j,i,temp_der));
        }
    }


    J->setFromTriplets(tripletList.begin(),tripletList.end());
}

template<typename T>
/*!
 * \brief vector_norm: Einfache Implementierung der 2-Norm fuer Vektoren vom typen T
 * \param z: Vektor
 * \param n: Laenge des Vektors
 * \return: Wurzel der Quadrate
 */
T vector_norm(std::vector<T> &z, int n)
{
    T tmp = 0;
    for(int i=0; i<n; i++)
    {
        tmp = tmp + z[i]*z[i];
    }
    return sqrt(tmp);
}

#endif // SOLVERFUNCTIONS_H

