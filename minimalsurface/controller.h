#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <cmath>
#include <QObject>
#include <discretization.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <parameter.h>
#include <QDebug>
#include <QThread>

class MainWindow;
/*!
 * \brief Die Controller Klasse
 *
 * Die Controller Klasse verwaltet die Berechnung der Minimalflaeche und das Speichern/Laden der berechneten Ergebnisse.
 * Sie ist dafuer zustaendig den Forschrittbalken zu aktualisieren und die Berechnung auf Wunsch des Nutzers abzubrechen.
*/
class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
     //! Controller Ist der Standardkonstruktor fuer die Klasse Controller. Es werden die connect-Befehle definiert und ein Objekt der Klasse Discretization erzeugt.
    Controller();
private:
    ~Controller();
    //! numparameter Enthaelt die Daten der Gebietsgroesse, der numerischen Parameter sowie die ausgewerteten Randfunktionen
    Parameter* numparameter;
public:
    //! updateCalculation Aktualisiert den Forschrittsbalken der Berechnung und gibt den aktuellen Fehler und Iterationsschritt in der Konsolenausgabe aus
    void updateCalculation(Parameter* para);
public slots:
    //! showResults Gibt die berechnete Minimalflaeche an das MainWindow zum Plotten weiter
    void showResults(double**,bool);
    //! save Speichert das Ergebnis im .surface Format im angegebenen Verzeichnis ab
    void save(const char*filename);
    //! load Laedt das Ergebnis im.surface Format aus dem angegeben Verzeichnis
    void load(const char*filename);

signals:
    //! calculationComplete Benachrechtigung ueber die fertige Rechnung
    void calculationComplete(double **, int, int, double, double, double, double, bool);
    //! solve Ist Benachrechtigung nach einem Iterationsschritt
    void solve(Parameter *);
    //! setProgressValue Aktualisierung des Forschrittsbalkens
    void setProgressValue(int);
    //! showMessage Ausgabe im Konsolenfenster
    void showMessage(QString);
};

#endif // CONTROLLER_H
