#include "discretization.h"
#include <QDebug>

/*!
 * Konstruktor setzt Zeiger von A und b auf NULL.
 */
Discretization::Discretization()
{
    //Setze A und b auf NULL
    A = NULL;
    b = NULL;
}

/*!
 * Destrtuktor loescht A und b, falls diese alloziert sind.
 */
Discretization::~Discretization()
{
    //Loesche A falls alloziert
    if(A)
    {
        for(int i = 0; i<condition->n-1; i++)
            delete [] A[i];
        delete []A;
    }

    //Loesche b falls alloziert
    if(b)
        delete b;
}

/*!
 * solve Berechnet die Loesung des Minimalflaechenproblems. Es wird die Newton Iteration verwendet um die Loesung
 * des nichtlinearen Gleichungssystems zu berechnen. Als Startvektor wird der eine Grobe Schaetzung anhand der Randwerte
 * verwendet. Der aktuelle Fehler wird mithilfe der Funktion minsurface_residual berechnet und mittels der 2-Norm abgeschaetzt.
 * Die Jacobi-Matrix wird in minsurface_jacobian numerisch berechnet und durch LR-Zerlegung nach der Schrittweite geloest.
 * Die Iteration bricht ab, falls der Fehler unter eine Benutzerdefinierte Grenze faellt, oder die maximale Iteration erreicht wurde.
 *
 * \param numparameter Uebergibt dem Programm die numerischen Parameter fuer die Berechnung.
 */
void Discretization::solve(Parameter * numparameter) throw(const char*)
{
    //Initialize Calculation
    emit setProgressValue(10);
    condition = numparameter;
    const int n=condition->n;
    const int m=condition->m;

    //Set the size of Vectors
    int size_z = (n-1)*(m-1);

    //Create Vectors for Vector z and Residual R
    //std::vector<double> z,R;
    std::vector<dco_t1s_type> z,R;
    z.reserve(size_z);
    R.reserve(size_z);
    double mean=0;                    // berechne Mittelwert der Randfunktionen fuer besseren Startvektor
    for (int i=0;i<n+1;i++)
    {
        mean+=condition->boundaries[0][i];
        mean+=condition->boundaries[m][i];

    }
    for (int i=0;i<m+1;i++)
    {
        mean+=condition->boundaries[i][0];
        mean+=condition->boundaries[i][n];
    }
    mean= mean/(2*(n+1)+2*(m+1));
    //emit showMessage(QString("mean:" + QString::number((double)mean)));
    for (int i=0; i < size_z;i++)
        z[i]=mean;                     // setze Startvektor auf Mittelwert

    //Initialize Sparse Matrix to store Jacobian Matrix, and Vectors to store Results
    Eigen::SparseMatrix<double> * J = new Eigen::SparseMatrix<double>(size_z,size_z);
    J->reserve(9*size_z);
    Eigen::VectorXd R_eigen(size_z), dz_eigen(size_z);

    //Calculate Residual
    minsurface_residual(condition,z,R);
    clock_t tmptime = clock();

    //Start Iteration of Newton
    emit setProgressValue(20);
    int iteration = 0;
    while (vector_norm(R,size_z) > condition->eps && iteration < condition->max_iteration) {
      //Iterate
      iteration++;

      //Calculate Jacobian
      tmptime = clock();
      minsurface_jacobian_dco(condition, z, J);
      tmptime = clock() - tmptime;
      emit showMessage(QString("Calculated Jacobian in: " + QString::number(((double)tmptime)/CLOCKS_PER_SEC) + " seconds"));

      //Prepare Z for decomposition
      for (int i=0;i<size_z;i++)
          R_eigen[i]=-R[i].v;

      //Create LU Decomposition for J and solve for step size
      tmptime = clock();

      Eigen::SparseLU<Eigen::SparseMatrix<double> >solver(*J);
      dz_eigen= solver.solve(R_eigen);

      tmptime = clock() - tmptime;
      emit showMessage(QString("Calculated next step in: " + QString::number(((double)tmptime)/CLOCKS_PER_SEC) + " seconds"));

      //Calculate next Iteration
      for (int i=0;i<size_z;i++)
          z[i]=z[i]+dz_eigen[i];
      minsurface_residual(condition,z,R);

      emit showMessage(QString("Current Iteration: " + QString::number(iteration) +  "\nCurrent Error: " + QString::number(vector_norm(R,size_z).v)+ "\n")) ;
      emit setProgressValue((int)(20+ (60/condition->max_iteration) * iteration));
      fillA();
      emit calculationComplete(A,0);
    }

    emit setProgressValue(80);
    emit showMessage(QString("Iteration finished with :" + QString::number(iteration) + " Iterations"));
    if(iteration == condition->max_iteration && vector_norm(R,size_z) > condition->eps)
        emit showMessage(QString("Newton Iteration did not converge to the desired Error"));

    delete J;
    //b=new std::vector<double>(z);
    emit setProgressValue(100);
    fillA();
    emit calculationComplete(A,1);
}

/*!
 * fillA fuellt die Matrix A mit der letzten berechneten Loesung. Der Einfachheit halber wird die abgespeicherte Matrix aus
 * den numerischen Parametern verwendet. Es koennte das gleiche mit dem Loesungsvektor b erzielt werden.
 */
void Discretization::fillA()
{
    A=new double*[condition->m-1];
    for(int i = 0; i<condition->m-1; i++)
        A[i] = new double[condition->n-1];

    for(int i= 0; i < condition->m-1; i++)
    {
        for(int j = 0; j< condition->n-1; j++)
        {
            //A[i][j] = b[(condition->n-1)*(i-1) + (j-1)];
            A[i][j] = condition->boundaries[i+1][j+1];
        }
    }

}
