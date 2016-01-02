#ifndef PARAMETER_H
#define PARAMETER_H

#include <vector>

//! Struct zum Speichern der numerischen Parameter fuer die Berechnung
struct Parameter
{
    //! Konstruktor
    Parameter(int _n,
            int _m,
            double _eps,
            double _xmin,
            double _xmax,
            double _ymin,
            double _ymax,
            double * left,
            double * right,
            double * bottom,
            double * top,
            int _max_iteration
            );
    //! Destruktor
    ~Parameter();

    //! Anzahl Intervalle in x und y Richtung
    int n, m;

    //! Abbruchsfehler, Intervallgrenzen
    double eps, xmin, xmax, ymin, ymax;

    //! Maximale Iterationen
    int max_iteration;

    //! Randwerte als volle Matrix gespeichert
    double ** boundaries;

};

#endif // PARAMETER_H
