#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QIntValidator>
#include <QErrorMessage>
#include <matheval.h>
#include <QFile>
#include <QString>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}
/*!
 * \brief Die MainWindow Klasse
 *
 * Die MainWindow Klasse enthaelt alle Ui Elemente sowie die Funktionen und Variablen welche fuer die korrekte Funktionalitaet, das Speichern/Laden
 * sowie der Anzeige der Minimalflaeche notwendig sind.
 *
 * Ausserdem benutzt die Klasse zum Einlesen der Randfunktionen die Bibliothek matheval.h.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class Controller;
    friend struct Parameter;
   //! MainWindow Ist der Standardkonstruktor fuer die Klasse MainWindow. Es werden die connect-Befehle definiert, das Ui, Variablen zur Fehlerüberprüfung und ein Controller Objekt erzeugt.
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
  //! ui Enthaelt alle ui Elemente
    Ui::MainWindow *ui;
  //! control Verwaltet die Berechnung sowie das Ergebnis
    Controller* control;
      //! para Enthaelt alle fuer die Berechnung benoetigten Eingabedaten
    Parameter* para;
      //! checkvalidDouble Ueberprueft die Gueltigkeit der Eingabe (Double)
    QDoubleValidator* checkvalidDouble;
    //! checkvalidInt Ueberprueft die Gueltigkeit der Eingabe (Int)
    QIntValidator* checkvalidInt;
    //! errorMessage Sendet beim Fehlerfall entsprechende Fehlermeldungen
    QErrorMessage* errorMessage;
    //! computed Ueberprueft ob schon eine Berechnung durchgefuehrt wurde.
    bool computed;
    //! checkInput ueberprueft die Gueltigkeit der numerischen Parameter und von der Gebietsgroesse
    void checkInput() throw(QString);
    //! checkFunctions ueberprueft die Gueltigkeit der Randfunktionen
    void checkFunctions() throw(QString);

public slots:
    //! showPlot stellt die berechneten Daten graphisch dar
    void showPlot(double**,int,int,double,double,double,double,bool);
    //! calculate ruft die Funktionen checkInput und checkFunctions auf, wertet die Randfunktionsn aus und startet anschliessend die Berechnung
    void calculate();
    //! loadResults ermittelt den Namen im .minimal Format und das Verzeichnis auf welchen das Ergebnis geladen werden soll
    void loadResults();
    //! saveResults ermittelt den Namen im .minimal Format und das Verzeichnis auf welchen das Ergebnis gespeichert werden soll
    void saveResults();
    //! loadSetup laedt aus einer vom Nutzer gewaehlten .setup Datei die Einstellungen auf
    void loadSetup();
    //! loadSetup speichert die Einstellungen als .setup Datei ab
    void saveSetup();


signals:
    void loadComplete(double**,int,int,double,double,double,double);
    //! saveResults sendet den Speicherauftrag zum Controller weiter
    void saveResults(const char*);
    //! loadResults sendet den Ladeauftrag zum Controller weiter
    void loadResults(const char*);
};


#endif // MAINWINDOW_H

