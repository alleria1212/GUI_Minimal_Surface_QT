#include "controller.h"

Controller::Controller()
{
    Discretization * solver = new Discretization();
    solver->moveToThread(&workerThread);
    connect(&workerThread,SIGNAL(finished()),solver,SLOT(deleteLater()));
    connect(this, SIGNAL(solve(Parameter*)), solver, SLOT(solve(Parameter*)));
    connect(solver, SIGNAL(calculationComplete(double**,bool)), this, SLOT(showResults(double**,bool)));
    connect(solver, SIGNAL(setProgressValue(int)), this, SIGNAL(setProgressValue(int)));
    connect(solver, SIGNAL(showMessage(QString)), this, SIGNAL(showMessage(QString)));
    workerThread.start();
}

/*!
 * \param para Enthaelt die zur Rechnung benoetigten Eingabedaten
 */
void Controller::updateCalculation(Parameter* para)
{
    emit setProgressValue(0);

    try
    {
        emit showMessage(QString("Initializing Parameters"));
        numparameter=para;
        emit setProgressValue(5);
        emit showMessage(QString("Starting Solver"));
        emit solve(para);
    }
    catch(QString error)
    {
        emit showMessage(QString("Fehler Gefunden: " +error));
    }

}

/*!
 * \param A Enthaelt die numerisch berechnete Loesung der Minimalflaeche
 */
void Controller::showResults(double** A, bool indexChanged)
{
    emit calculationComplete(A,
                             numparameter->m-1,
                             numparameter->n-1,
                             numparameter->xmin,
                             numparameter->xmax,
                             numparameter->ymin,
                             numparameter->ymax,
                             indexChanged
                             );
}

/*!
 * \param filename Dateiname vom gespeicherten Ergebnis
 */
void Controller::save(const char* filename)
{
    {
        const int n=numparameter->n;
        const int m=numparameter->m;
            std::ofstream file(filename);
            file << "n;" << "m;" << "iteration;" << "epsilon;" << "xmin;" << "xmax;" <<"ymin;"<<"ymax;" << std::endl;
            file << numparameter->n << ";"<< numparameter->m << ";"<< numparameter->max_iteration << ";"<< numparameter->eps << ";"<< numparameter->xmin << ";"<< numparameter->xmax << ";"<< numparameter->ymin << ";"<< numparameter->ymax << ";" << std::endl;
            file << std::endl;
            file << "Werte;" << std::endl;

        for(int i=0;i<m+1;++i)
        {
            for(int k=0;k<n+1;++k)
            {
                file<<numparameter->boundaries[i][k]<<";";
            }
           file << std::endl;
        }
        file.close();
    }
}
/*!
 * \param filename Dateiname des geladenen Ergebnisses
 */
  void Controller::load(const char* filename)
  {
      std::ifstream file(filename);
      std::string line;
      double ** results;
      double doublevalues[5]; //contains epsilon and xmin/xmax/ymin/ymax
      int integers[3]; //contains n,m and iterations
      getline(file,line,'\n'); //go to the next line
         for (int i=0;i<3;++i)
         {
             getline(file,line,';'); //save the inputvalues
             std::istringstream convert(line);
             convert >> integers[i];
         }
         for (int i=0;i<5;++i)
         {
             getline(file,line,';'); //save the inputvalues (Epsilon, xmin,xmax,ymin,ymax)
             std::istringstream convert(line);
             convert >> doublevalues[i];
         }
         if(integers[0]>6)
         {
             getline(file,line,'\n'); //go to the next line
         }
          getline(file,line,'\n'); //go to the next line
          getline(file,line,'\n'); //go to the next line
          const int n = integers[0];
          const int m = integers[1];
          results = new double*[m+1];
          for(int i=0;i<m+1;++i)
              results[i] = new double[n+1];
          for(int i=0;i<(m+1);++i)
          {
              for(int k=0;k<(n+1);++k)
              {
                  getline(file,line,';');
                  std::istringstream convert(line);
                  convert >> results[i][k];
              }
              getline(file,line,'\n');
          }
          double **A;
          A=new double*[m-1];
          for(int i=0;i<(m-1);++i)
          {
              A[i]=new double[n-1];
          }
          for(int i=0;i<(m-1);++i)
          {
              for(int k=0;k<(n-1);++k)
              {
                   A[i][k]=results[i+1][k+1];
              }
          }
          emit calculationComplete(A,m-1,n-1,doublevalues[1],doublevalues[2],doublevalues[3],doublevalues[4],1);
          for(int i=0;i<(m+1);++i)
              delete [] results[i];

          for(int i=0;i<(m-1);++i)
             delete [] A[i];

          delete [] results;
          delete [] A;
          file.close();
  }


Controller::~Controller()
{
    workerThread.quit();
    workerThread.wait();
}

