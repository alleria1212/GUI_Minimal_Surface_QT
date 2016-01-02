#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * \param parent Uebergibt den Besitzer von MainWindow.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    para = NULL;
    checkvalidDouble =new QDoubleValidator(-1000000000,1000000000,9,NULL);
    checkvalidInt = new QIntValidator(0,1000000,NULL);
    errorMessage = new QErrorMessage(this);
    ui->setupUi(this);
    control = new Controller();
    ui->progressBar->setRange(0,100);
    ui->progressBar_plot->setRange(0,100);
    computed=false;
    connect(ui->quit_button, SIGNAL(clicked(bool)),this, SLOT(close()));
    connect(ui->run_button,SIGNAL(clicked(bool)),this,SLOT(calculate()));
    connect(control,SIGNAL(calculationComplete(double**,int,int,double,double,double,double,bool)),this,SLOT(showPlot(double**,int,int,double,double,double,double,bool)));
    connect(control, SIGNAL(setProgressValue(int)), ui->progressBar, SLOT(setValue(int)));
    connect(control, SIGNAL(setProgressValue(int)), ui->progressBar_plot, SLOT(setValue(int)));
    connect(ui->actionEinstellungenLaden,SIGNAL(triggered(bool)),this,SLOT(loadSetup()));
    connect(ui->actionErgebnis_laden, SIGNAL(triggered()),this, SLOT(loadResults()));
    connect(ui->actionErgebnis_speichern,SIGNAL(triggered()),this,SLOT(saveResults()));
    connect(ui->actionEinstellungenSpeichern,SIGNAL(triggered()),this,SLOT(saveSetup()));
    connect(control, SIGNAL(showMessage(QString)), ui->output_message, SLOT(append(QString)));
    connect(this,SIGNAL(saveResults(const char*)),control,SLOT(save(const char*)));
    connect(this,SIGNAL(loadResults(const char*)),control,SLOT(load(const char*)));

    //Set dafaults
    ui->output_message->setReadOnly(true);
    ui->tab_widget->setCurrentIndex(0);
    ui->run_button->setDefault(true);
}

void MainWindow::loadResults()
{
        QString fileName=QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Results (*.surface)"));
        if(fileName.isEmpty())
            return;
        else
        {
            emit loadResults(fileName.toStdString().c_str());
        }
}
void MainWindow::saveResults()
{
    if(computed==false)
        errorMessage->showMessage(QString("Vor dem Speichern wird eine Berechnung benötigt!"));
    else
    {
    QString fileName =QFileDialog::getSaveFileName(this,tr("Save File"),"",tr("Results (*.surface))"));
        if(fileName.isEmpty())
            return;
        else
        {

        QFile file(fileName.append(".surface"));
                if(!file.open(QIODevice::WriteOnly))
                {
                    QMessageBox::information(this,tr("Unable to open file"),file.errorString());
                    return;
                }
        emit saveResults(fileName.toStdString().c_str());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete errorMessage;
    delete checkvalidDouble;
    delete checkvalidInt;
    if(para)
        delete para;
}


void MainWindow::saveSetup()
{
    QString fileName =QFileDialog::getSaveFileName(this,tr("Save Setup"),"",tr("Setup (*.setup))"));
        if(fileName.isEmpty())
            return;
        else
        {
        QFile file(fileName.append(".setup"));
                if(!file.open(QIODevice::WriteOnly))
                {
                    QMessageBox::information(this,tr("Unable to open file"),file.errorString());
                    return;
                }
        const char* name = fileName.toStdString().c_str();
        std::ofstream off(name);
        off << ui->epsilon_edit->text().toDouble() << ";" << std::endl;      //numerische Parameter
        off << ui->iteration_edit->text().toInt() << ";" << std::endl;
        off << ui->n_edit->text().toInt() << ";" << std::endl;
        off << ui->m_edit->text().toInt() << ";" << std::endl;
        off << ui->xmin_edit->text().toDouble() << ";" << std::endl;       //Gebiet
        off << ui->xmax_edit->text().toDouble() << ";" << std::endl;
        off << ui->ymin_edit->text().toDouble() << ";" << std::endl;
        off << ui->ymax_edit->text().toDouble() << ";" << std::endl;
        QString a=ui->a_edit->text();
        QByteArray aa = a.toLatin1();
        off << aa.data() << ";" << std::endl;          //Randfunktionen
        QString b=ui->b_edit->text();
        QByteArray bb = b.toLatin1();
        off << bb.data() << ";" << std::endl;
        QString c=ui->c_edit->text();
        QByteArray cc = c.toLatin1();
        off << cc.data() << ";" << std::endl;
        QString d=ui->d_edit->text();
        QByteArray dd = d.toLatin1();
        off << dd.data() << ";" << std::endl;
        off.close();

        }
}

/*!
 * \param A Ist ein Zeiger das berechnete Minimalflaeche
 * \param n Beschreibt die Anzahl der Stuetzstellen in x-Richtung
 * \param m Beschreibt die Anzahl der Stutzstellen in y-Richtung
 * \param xmin Steht für die untere x-Grenze des Gebietes
 * \param xmax Steht für die obere x-Grenze des Gebietes
 * \param ymin Steht für die untere y-Grenze des Gebietes
 * \param ymax Steht für die obere y-Grenze des Gebietes
 */
void MainWindow::showPlot(double** A,int n,int m,double xmin,double xmax,double ymin,double ymax, bool changeIndex)
{
    if(changeIndex == 1)
        ui->tab_widget->setCurrentIndex(2);

    if (A!=NULL)
    {
        ui->plot_widget->loadFromData(A,n,m,xmin,xmax,ymin,ymax);
        ui->plot_widget->updateData();
        ui->plot_widget->coordinates()->axes[Qwt3D::X1].setLabelString("y-axis");
        ui->plot_widget->coordinates()->axes[Qwt3D::Y1].setLabelString("x-axis");
        ui->plot_widget->coordinates()->axes[Qwt3D::Z1].setLabelString("z-axis");
        ui->plot_widget->setCoordinateStyle(Qwt3D::BOX);
        ui->plot_widget->updateGL();
        ui->run_button->setEnabled(true);
    }

    ui->run_button->setEnabled(true);
}

void MainWindow::loadSetup()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Load Setup"),"",tr("Setup (*.setup)"));
    if(fileName.isEmpty())
        return;
    else
    {
        std::ifstream in(fileName.toStdString().c_str());
        std::string line;
        getline(in,line,'\n');
        std::istringstream convert(line);
        double eps;
        convert >> eps;
        QString Qeps = QString::number(eps);
        ui->epsilon_edit->setText(Qeps);
        getline(in,line,'\n');
        std::istringstream convert1(line);
        int iteration;
        convert1 >> iteration;
        QString Qiteration = QString::number(iteration);
        ui->iteration_edit->setText(Qiteration);
        getline(in,line,'\n');
        std::istringstream convert2(line);
        int nn;
        convert2 >> nn;
        QString Qn = QString::number(nn);
        ui->n_edit->setText(Qn);
        getline(in,line,'\n');
        std::istringstream convert3(line);
        int mm;
        convert3 >> mm;
        QString Qm = QString::number(mm);
        ui->m_edit->setText(Qm);
        getline(in,line,'\n');
        std::istringstream convert4(line);
        double xmin;
        convert4 >> xmin;
        QString Qxmin = QString::number(xmin);
        ui->xmin_edit->setText(Qxmin);
        getline(in,line,'\n');
        std::istringstream convert5(line);
        double xmax;
        convert5 >> xmax;
        QString Qxmax = QString::number(xmax);
        ui->xmax_edit->setText(Qxmax);
        getline(in,line,'\n');
        std::istringstream convert6(line);
        double ymin;
        convert6 >> ymin;
        QString Qymin  = QString::number(ymin);
        ui->ymin_edit->setText(Qymin);
        getline(in,line,'\n');
        std::istringstream convert7(line);
        double ymax;
        convert7 >> ymax;
        QString Qymax = QString::number(ymax);
        ui->ymax_edit->setText(Qymax);
        getline(in,line,';');
        QString a=QString::fromStdString(line);
        ui->a_edit->setText(a);
        getline(in,line,'\n');
        getline(in,line,';');
        QString b=QString::fromStdString(line);
        ui->b_edit->setText(b);
        getline(in,line,'\n');
        getline(in,line,';');
        QString c=QString::fromStdString(line);
        ui->c_edit->setText(c);
        getline(in,line,'\n');
        getline(in,line,';');
        QString d=QString::fromStdString(line);
        ui->d_edit->setText(d);
        ui->tab_widget->setCurrentIndex(0);
        in.close();
    }
}

void MainWindow::calculate()
{
    ui->output_message->clear();
    ui->run_button->setDisabled(true);
    try
    {
        checkInput();
        checkFunctions();
    }
    catch(const QString error)
    {
        errorMessage->showMessage(error);
        ui->run_button->setEnabled(true);
        return;
    }
    double xmax = ui->xmax_edit->text().toDouble();
    double xmin = ui->xmin_edit->text().toDouble();
    double ymax = ui->ymax_edit->text().toDouble();
    double ymin = ui->ymin_edit->text().toDouble();
    double eps = ui->epsilon_edit->text().toDouble();
    const int max_iteration = ui->iteration_edit->text().toInt();
    const int n = ui->n_edit->text().toInt();
    const int m = ui->m_edit->text().toInt();

    double * left = new double[m+1];
    double * right = new double[m+1];
    double * bottom = new double[n+1];
    double * top = new double[n+1];

    int count_left, count_top, count_right, count_bottom;
    char **names_left, **names_right, **names_top, **names_bottom;
    char *c_left = (char*)malloc(64);
    char *c_right = (char*)malloc(64);
    char *c_bottom = (char*)malloc(64);
    char *c_top = (char*)malloc(64);

    strcpy(c_left, ui->a_edit->text().toLatin1().data());
    strcpy(c_right, ui->c_edit->text().toLatin1().data());
    strcpy(c_bottom, ui->d_edit->text().toLatin1().data());
    strcpy(c_top, ui->b_edit->text().toLatin1().data());

    void *left_eval = evaluator_create(c_left);
    evaluator_get_variables(left_eval,&names_left,&count_left);
    void *top_eval = evaluator_create(c_top);
    evaluator_get_variables(top_eval,&names_top,&count_top);
    void *right_eval = evaluator_create(c_right);
    evaluator_get_variables(right_eval,&names_right,&count_right);
    void *bottom_eval = evaluator_create(c_bottom);
    evaluator_get_variables(bottom_eval,&names_bottom,&count_bottom);

    double hx = (xmax-xmin)/n;
    double hy = (ymax-ymin)/m;
    double tmp, top_val, bottom_val, right_val, left_val;
    bool top_ok, bottom_ok, left_ok, right_ok;

    for(int i=0;i<n+1;++i)
    {
        tmp = xmin + i*hx;
        top_val = evaluator_evaluate(top_eval,count_top,names_top,&tmp);
        bottom_val = evaluator_evaluate(bottom_eval,count_bottom,names_bottom,&tmp);
        top_ok = (top_val != -INFINITY && top_val != INFINITY && top_val != NAN);
        bottom_ok = (bottom_val != -INFINITY && bottom_val != INFINITY && bottom_val != NAN);

        if(!(top_ok && bottom_ok))
        {
            errorMessage->showMessage(QString("Check top and bottom boundaries for possible undefined values."));
            ui->run_button->setEnabled(true);
            return;
        }
        else
        {
            top[i] = top_val;
            bottom[i] = bottom_val;
        }

    }
    for(int i=0;i<m+1;++i)
    {
        tmp = ymin + i*hy;
        left_val = evaluator_evaluate(left_eval,count_left,names_left,&tmp);
        right_val = evaluator_evaluate(right_eval,count_right,names_right,&tmp);
        left_ok = (left_val != -INFINITY && left_val != INFINITY && left_val != NAN);
        right_ok = (right_val != -INFINITY && right_val != INFINITY && right_val != NAN);

        if(!(left_ok && right_ok))
        {
            errorMessage->showMessage(QString("Check left and right boundaries for possible undefined values."));
            ui->run_button->setEnabled(true);
            return;
        }
        else
        {
            left[i] = left_val;
            right[i] = right_val;
        }
    }

   para=new Parameter(n,m,eps,xmin,xmax,ymin,ymax,left,right,bottom,top,max_iteration);
   ui->tab_widget->setCurrentIndex(1);
   control->updateCalculation(para);
   computed=true;
   evaluator_destroy(left_eval);
   evaluator_destroy(right_eval);
   evaluator_destroy(top_eval);
   evaluator_destroy(bottom_eval);
   delete c_left;
   delete c_right;
   delete c_bottom;
   delete c_top;
   delete []left;
   delete []right;
   delete []bottom;
   delete []top;
}

void MainWindow::checkInput() throw(QString)
{
    int pos;
    QString xminstr = ui->xmin_edit->text();
    QString xmaxstr = ui->xmax_edit->text();
    QString ymaxstr = ui->ymax_edit->text();
    QString yminstr = ui->ymin_edit->text();
    QString epsstr = ui->epsilon_edit->text();
    QString max_iterstr = ui->iteration_edit->text();
    QString nstr = ui->n_edit->text();
    QString mstr = ui->m_edit->text();

    pos = ui->xmin_edit->cursorPosition();
    if(checkvalidDouble->validate(xminstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im xmin Textfeld"));
    }

    pos = ui->xmax_edit->cursorPosition();
    if(checkvalidDouble->validate(xmaxstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im xmax Textfeld"));
    }

    pos = ui->ymin_edit->cursorPosition();
    if(checkvalidDouble->validate(yminstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im ymin Textfeld"));
    }

    pos = ui->ymax_edit->cursorPosition();
    if(checkvalidDouble->validate(ymaxstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im ymax Textfeld"));
    }

    if(xminstr>=xmaxstr)
    {
        throw(QString("xmin ist groesser gleich xmax!"));
    }

    if(yminstr>=ymaxstr)
    {
        throw(QString("ymin ist groesser gleich ymax"));
    }

    pos = ui->epsilon_edit->cursorPosition();
    if(checkvalidDouble->validate(epsstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im epsilon Textfeld"));
    }

    pos = ui->iteration_edit->cursorPosition();
    if(checkvalidInt->validate(max_iterstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im iterations Textfeld"));
    }
    pos = ui->n_edit->cursorPosition();
    if(checkvalidInt->validate(nstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im n Textfeld"));
    }
    pos = ui->m_edit->cursorPosition();
    if(checkvalidInt->validate(mstr,pos)<2)
    {
        throw(QString("Ungueltige Eingabe im m Textfeld"));
    }

}

void MainWindow::checkFunctions() throw(QString)
{
    void *left, *right, *bottom, *top;
    char **names;
    int count[4];

    char *c_left = (char*)malloc(64);
    char *c_right = (char*)malloc(64);
    char *c_bottom = (char*)malloc(64);
    char *c_top = (char*)malloc(64);

    strcpy(c_left, ui->a_edit->text().toLatin1().data());
    strcpy(c_right, ui->c_edit->text().toLatin1().data());
    strcpy(c_bottom, ui->d_edit->text().toLatin1().data());
    strcpy(c_top, ui->b_edit->text().toLatin1().data());

    left = evaluator_create(c_left);
    top = evaluator_create(c_top);
    right = evaluator_create(c_right);
    bottom = evaluator_create(c_bottom);

    if(!left)
        throw(QString("Invalid Left Boundaries"));
    if(!right)
        throw(QString("Invalid Right Boundaries"));
    if(!bottom)
        throw(QString("Invalid Bottom Boundaries"));
    if(!top)
        throw(QString("Invalid Top Boundaries"));

    evaluator_get_variables(left, &names, &(count[0]));
    evaluator_get_variables(top, &names, &(count[1]));
    evaluator_get_variables(right, &names, &(count[2]));
    evaluator_get_variables(bottom, &names, &(count[3]));

    if(count[0] > 1)
        throw(QString("Too many Variables in Left Boundary."));
    if(count[1] > 1)
        throw(QString("Too many Variables in Top Boundary."));
    if(count[2] > 1)
        throw(QString("Too many Variables in Right Boundary."));
    if(count[3] > 1)
        throw(QString("Too many Variables in Bottom Boundary."));

    evaluator_destroy(left);
    evaluator_destroy(right);
    evaluator_destroy(top);
    evaluator_destroy(bottom);
    delete c_left;
    delete c_right;
    delete c_bottom;
    delete c_top;
}
