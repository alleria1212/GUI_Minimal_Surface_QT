#ifndef PLOT
#define PLOT

#include <qwt3d_surfaceplot.h>

//! Plot Widget verwendet von qwtplot3d
class Plot : public Qwt3D::SurfacePlot
{

public:
    //! Konstruktor mit Standardargument
    Plot(QWidget * _parent = NULL);
};

/*!
 * Der Konstruktor setzt die Achsenbeschriftungen und Coordinatentypen des Plots und aktualisiert die Anzeige.
 */
Plot::Plot(QWidget *_parent)
{
  setTitle("(>^.^)> Hier koennte ihre Werbung stehen <(^.^<)");

  coordinates()->axes[Qwt3D::X1].setLabelString("x-axis");
  coordinates()->axes[Qwt3D::Y1].setLabelString("y-axis");
  setCoordinateStyle(Qwt3D::BOX);

  updateData();
  updateGL();
}

#endif // PLOT

