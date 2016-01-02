#include "parameter.h"
#include <QDebug>

/*!
 * Konstruktor initialisiert alle Variablen. Nur aufrufen, falls die Richtigkeit garantiert ist. Diese Klasse hat
 * keine eigene Funktion implementiert um die Parameter zu ueberpruefen.
 * \param _n nr. Intervalle x Richtung
 * \param _m nr. Intervalle y Richtung
 * \param _eps Abbruchsfehler
 * \param _xmin Linke x Grenze
 * \param _xmax Rechte x Grenze
 * \param _ymin Linke y Grenze
 * \param _ymax Rechte y Grenze
 * \param left Array mit linken Randwerten
 * \param right Array mit rechten Randwerten
 * \param bottom Array mit unteren Randwerten
 * \param top Array mit oberen Randwerten
 * \param _max_iteration Maximale Iterationen bis Abbruch
 */
Parameter::Parameter(int _n,
        int _m,
        double _eps,
        double _xmin,
        double _xmax,
        double _ymin,
        double _ymax,
        double *left,
        double *right,
        double *bottom,
        double *top,
        int _max_iteration
        ) :
    n(_n), m(_m),eps(_eps), xmin(_xmin), xmax(_xmax), ymin(_ymin), ymax(_ymax), max_iteration(_max_iteration)
{
    boundaries = new double*[m+1];
    for(int i=0; i<m+1; i++)
        boundaries[i] = new double[n+1];

    for(int i = 1; i<m; i++)
    {
        boundaries[i][0] = left[i];
        boundaries[i][n] = right[i];
    }
    for(int i = 1; i<n; i++)
    {
        boundaries[0][i] = bottom[i];
        boundaries[m][i] = top[i];
    }

    //qDebug() << "Setting Corner Values";
    boundaries[0][0] = 1/2 * (left[0]+bottom[0]);
    boundaries[m][0] = 1/2 * (left[m]+top[0]);
    boundaries[0][n] = 1/2 * (right[0]+bottom[n]);
    boundaries[m][n] = 1/2 * (right[m]+top[n]);
}

/*!
 * Destruktor gibt den allozierten Speicher fuer Boundaries wieder frei.
 */
Parameter::~Parameter()
{
    for(int i = 0; i<m+1; i++)
        delete [] boundaries[i];
    delete []boundaries;
}
