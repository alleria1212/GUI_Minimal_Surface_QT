#ifndef DISCRETIZATION_H
#define DISCRETIZATION_H

#include <vector>
#include <parameter.h>
#include <solverfunctions.h>
#include <numeric>
#include <functional>
#include <QThread>
#include <QObject>
#include <time.h>
#include "dco_t1s/dco_t1s_type.hpp"

//! Klasse zur Auslagerung der Berechnung
class Discretization : public QObject
{
    Q_OBJECT
    //! QThread fuer die Berechnung
    QThread workerThread;
private:
    //! Speicherung des Ergebnisses in Double Array
    double **A;
    //! Ergebnis in Vektorform
    std::vector<double>* b;
    //! Numerische Parameter fuer die Berechnung
    Parameter* condition;
public:
    //! Konstruktor
    Discretization();
    //! Destruktor
    ~Discretization();

public slots:
    //! Schreiben des Ergebnisses in Matrix A
    void fillA();
    //! Loesungsfunktion
    void solve(Parameter *) throw(const char*);

signals:
    //! Signal fuer fertige Berechnung
    void calculationComplete(double**,bool);
    //! Signal fuer Fortgeschrittenheit der Berechnung
    void setProgressValue(int);
    //! Signal fuer Konsolenausgabe
    void showMessage(QString);
};

#endif // DISCRETIZATION_H
