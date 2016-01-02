/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionErgebnis_laden;
    QAction *actionErgebnis_speichern;
    QAction *actionEinstellungenLaden;
    QAction *actionEinstellungenSpeichern;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tab_widget;
    QWidget *parameter_tab;
    QGridLayout *gridLayout;
    QPushButton *quit_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *run_button;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *definitionsbereich;
    QGridLayout *gridLayout_5;
    QLabel *xmin_label;
    QLineEdit *xmin_edit;
    QLabel *xmax_label;
    QLineEdit *xmax_edit;
    QLabel *ymin_label;
    QLineEdit *ymin_edit;
    QLabel *ymax_label;
    QLineEdit *ymax_edit;
    QGroupBox *numerische_parameter;
    QGridLayout *gridLayout_4;
    QLabel *epsilon_label;
    QLabel *iteration_label;
    QLineEdit *epsilon_edit;
    QLineEdit *iteration_edit;
    QLineEdit *m_edit;
    QLabel *n_label;
    QLineEdit *n_edit;
    QLabel *m_label;
    QGroupBox *grenzen;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLineEdit *d_edit;
    QLineEdit *b_edit;
    QFrame *bottom_line;
    QLabel *c_label;
    QFrame *right_line;
    QLabel *d_label;
    QLabel *a_label;
    QLabel *b_label;
    QLineEdit *c_edit;
    QFrame *top_line;
    QLineEdit *a_edit;
    QFrame *left_line;
    QSpacerItem *verticalSpacer;
    QWidget *console_tab;
    QGridLayout *gridLayout_3;
    QProgressBar *progressBar;
    QTextEdit *output_message;
    QSpacerItem *verticalSpacer_2;
    QWidget *view_tab;
    QGridLayout *gridLayout_7;
    Plot *plot_widget;
    QProgressBar *progressBar_plot;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(690, 536);
        actionErgebnis_laden = new QAction(MainWindow);
        actionErgebnis_laden->setObjectName(QStringLiteral("actionErgebnis_laden"));
        actionErgebnis_speichern = new QAction(MainWindow);
        actionErgebnis_speichern->setObjectName(QStringLiteral("actionErgebnis_speichern"));
        actionEinstellungenLaden = new QAction(MainWindow);
        actionEinstellungenLaden->setObjectName(QStringLiteral("actionEinstellungenLaden"));
        actionEinstellungenSpeichern = new QAction(MainWindow);
        actionEinstellungenSpeichern->setObjectName(QStringLiteral("actionEinstellungenSpeichern"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tab_widget = new QTabWidget(centralWidget);
        tab_widget->setObjectName(QStringLiteral("tab_widget"));
        tab_widget->setLayoutDirection(Qt::LeftToRight);
        parameter_tab = new QWidget();
        parameter_tab->setObjectName(QStringLiteral("parameter_tab"));
        gridLayout = new QGridLayout(parameter_tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        quit_button = new QPushButton(parameter_tab);
        quit_button->setObjectName(QStringLiteral("quit_button"));

        gridLayout->addWidget(quit_button, 9, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 2, 1, 1);

        run_button = new QPushButton(parameter_tab);
        run_button->setObjectName(QStringLiteral("run_button"));

        gridLayout->addWidget(run_button, 8, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 7, 4, 1, 1);

        definitionsbereich = new QGroupBox(parameter_tab);
        definitionsbereich->setObjectName(QStringLiteral("definitionsbereich"));
        gridLayout_5 = new QGridLayout(definitionsbereich);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        xmin_label = new QLabel(definitionsbereich);
        xmin_label->setObjectName(QStringLiteral("xmin_label"));

        gridLayout_5->addWidget(xmin_label, 0, 0, 1, 1);

        xmin_edit = new QLineEdit(definitionsbereich);
        xmin_edit->setObjectName(QStringLiteral("xmin_edit"));

        gridLayout_5->addWidget(xmin_edit, 0, 1, 1, 1);

        xmax_label = new QLabel(definitionsbereich);
        xmax_label->setObjectName(QStringLiteral("xmax_label"));

        gridLayout_5->addWidget(xmax_label, 1, 0, 1, 1);

        xmax_edit = new QLineEdit(definitionsbereich);
        xmax_edit->setObjectName(QStringLiteral("xmax_edit"));

        gridLayout_5->addWidget(xmax_edit, 1, 1, 1, 1);

        ymin_label = new QLabel(definitionsbereich);
        ymin_label->setObjectName(QStringLiteral("ymin_label"));

        gridLayout_5->addWidget(ymin_label, 2, 0, 1, 1);

        ymin_edit = new QLineEdit(definitionsbereich);
        ymin_edit->setObjectName(QStringLiteral("ymin_edit"));

        gridLayout_5->addWidget(ymin_edit, 2, 1, 1, 1);

        ymax_label = new QLabel(definitionsbereich);
        ymax_label->setObjectName(QStringLiteral("ymax_label"));

        gridLayout_5->addWidget(ymax_label, 3, 0, 1, 1);

        ymax_edit = new QLineEdit(definitionsbereich);
        ymax_edit->setObjectName(QStringLiteral("ymax_edit"));

        gridLayout_5->addWidget(ymax_edit, 3, 1, 1, 1);

        gridLayout_5->setColumnStretch(0, 1);

        gridLayout->addWidget(definitionsbereich, 7, 3, 3, 1);

        numerische_parameter = new QGroupBox(parameter_tab);
        numerische_parameter->setObjectName(QStringLiteral("numerische_parameter"));
        gridLayout_4 = new QGridLayout(numerische_parameter);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        epsilon_label = new QLabel(numerische_parameter);
        epsilon_label->setObjectName(QStringLiteral("epsilon_label"));

        gridLayout_4->addWidget(epsilon_label, 0, 0, 1, 1);

        iteration_label = new QLabel(numerische_parameter);
        iteration_label->setObjectName(QStringLiteral("iteration_label"));

        gridLayout_4->addWidget(iteration_label, 1, 0, 1, 1);

        epsilon_edit = new QLineEdit(numerische_parameter);
        epsilon_edit->setObjectName(QStringLiteral("epsilon_edit"));

        gridLayout_4->addWidget(epsilon_edit, 0, 1, 1, 1);

        iteration_edit = new QLineEdit(numerische_parameter);
        iteration_edit->setObjectName(QStringLiteral("iteration_edit"));

        gridLayout_4->addWidget(iteration_edit, 1, 1, 1, 1);

        m_edit = new QLineEdit(numerische_parameter);
        m_edit->setObjectName(QStringLiteral("m_edit"));

        gridLayout_4->addWidget(m_edit, 3, 1, 1, 1);

        n_label = new QLabel(numerische_parameter);
        n_label->setObjectName(QStringLiteral("n_label"));

        gridLayout_4->addWidget(n_label, 2, 0, 1, 1);

        n_edit = new QLineEdit(numerische_parameter);
        n_edit->setObjectName(QStringLiteral("n_edit"));

        gridLayout_4->addWidget(n_edit, 2, 1, 1, 1);

        m_label = new QLabel(numerische_parameter);
        m_label->setObjectName(QStringLiteral("m_label"));

        gridLayout_4->addWidget(m_label, 3, 0, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);

        gridLayout->addWidget(numerische_parameter, 7, 0, 3, 2);

        grenzen = new QGroupBox(parameter_tab);
        grenzen->setObjectName(QStringLiteral("grenzen"));
        gridLayout_6 = new QGridLayout(grenzen);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label = new QLabel(grenzen);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 4, 5, 1, 1);

        d_edit = new QLineEdit(grenzen);
        d_edit->setObjectName(QStringLiteral("d_edit"));

        gridLayout_6->addWidget(d_edit, 8, 5, 1, 1);

        b_edit = new QLineEdit(grenzen);
        b_edit->setObjectName(QStringLiteral("b_edit"));

        gridLayout_6->addWidget(b_edit, 1, 5, 1, 1);

        bottom_line = new QFrame(grenzen);
        bottom_line->setObjectName(QStringLiteral("bottom_line"));
        bottom_line->setFrameShape(QFrame::HLine);
        bottom_line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(bottom_line, 7, 5, 1, 1);

        c_label = new QLabel(grenzen);
        c_label->setObjectName(QStringLiteral("c_label"));

        gridLayout_6->addWidget(c_label, 4, 8, 1, 1);

        right_line = new QFrame(grenzen);
        right_line->setObjectName(QStringLiteral("right_line"));
        right_line->setFrameShape(QFrame::VLine);
        right_line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(right_line, 4, 7, 1, 1);

        d_label = new QLabel(grenzen);
        d_label->setObjectName(QStringLiteral("d_label"));

        gridLayout_6->addWidget(d_label, 8, 3, 1, 1);

        a_label = new QLabel(grenzen);
        a_label->setObjectName(QStringLiteral("a_label"));

        gridLayout_6->addWidget(a_label, 4, 0, 1, 1);

        b_label = new QLabel(grenzen);
        b_label->setObjectName(QStringLiteral("b_label"));

        gridLayout_6->addWidget(b_label, 1, 3, 1, 1);

        c_edit = new QLineEdit(grenzen);
        c_edit->setObjectName(QStringLiteral("c_edit"));

        gridLayout_6->addWidget(c_edit, 4, 9, 1, 1);

        top_line = new QFrame(grenzen);
        top_line->setObjectName(QStringLiteral("top_line"));
        top_line->setFrameShape(QFrame::HLine);
        top_line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(top_line, 2, 5, 1, 1);

        a_edit = new QLineEdit(grenzen);
        a_edit->setObjectName(QStringLiteral("a_edit"));

        gridLayout_6->addWidget(a_edit, 4, 1, 1, 1);

        left_line = new QFrame(grenzen);
        left_line->setObjectName(QStringLiteral("left_line"));
        left_line->setFrameShape(QFrame::VLine);
        left_line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(left_line, 4, 4, 1, 1);


        gridLayout->addWidget(grenzen, 5, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        tab_widget->addTab(parameter_tab, QString());
        console_tab = new QWidget();
        console_tab->setObjectName(QStringLiteral("console_tab"));
        gridLayout_3 = new QGridLayout(console_tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        progressBar = new QProgressBar(console_tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 0, 0, 1, 2);

        output_message = new QTextEdit(console_tab);
        output_message->setObjectName(QStringLiteral("output_message"));

        gridLayout_3->addWidget(output_message, 1, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        tab_widget->addTab(console_tab, QString());
        view_tab = new QWidget();
        view_tab->setObjectName(QStringLiteral("view_tab"));
        gridLayout_7 = new QGridLayout(view_tab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        plot_widget = new Plot(view_tab);
        plot_widget->setObjectName(QStringLiteral("plot_widget"));

        gridLayout_7->addWidget(plot_widget, 1, 0, 1, 1);

        progressBar_plot = new QProgressBar(view_tab);
        progressBar_plot->setObjectName(QStringLiteral("progressBar_plot"));
        progressBar_plot->setValue(0);

        gridLayout_7->addWidget(progressBar_plot, 0, 0, 1, 1);

        tab_widget->addTab(view_tab, QString());

        gridLayout_2->addWidget(tab_widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 690, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionEinstellungenLaden);
        toolBar->addAction(actionEinstellungenSpeichern);
        toolBar->addAction(actionErgebnis_laden);
        toolBar->addAction(actionErgebnis_speichern);

        retranslateUi(MainWindow);

        tab_widget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Minimalflaechen", 0));
        actionErgebnis_laden->setText(QApplication::translate("MainWindow", "Ergebnis laden", 0));
        actionErgebnis_laden->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionErgebnis_speichern->setText(QApplication::translate("MainWindow", "Ergebnis speichern", 0));
        actionErgebnis_speichern->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionEinstellungenLaden->setText(QApplication::translate("MainWindow", "Einstellungen laden", 0));
        actionEinstellungenSpeichern->setText(QApplication::translate("MainWindow", "Einstellungen speichern", 0));
        quit_button->setText(QApplication::translate("MainWindow", "Quit", 0));
        run_button->setText(QApplication::translate("MainWindow", "Run", 0));
        definitionsbereich->setTitle(QApplication::translate("MainWindow", "Gebietsgr\303\266\303\237e:", 0));
        xmin_label->setText(QApplication::translate("MainWindow", "xmin:", 0));
        xmin_edit->setText(QApplication::translate("MainWindow", "-0.5", 0));
        xmax_label->setText(QApplication::translate("MainWindow", "xmax:", 0));
        xmax_edit->setText(QApplication::translate("MainWindow", "0.5", 0));
        ymin_label->setText(QApplication::translate("MainWindow", "ymin:", 0));
        ymin_edit->setText(QApplication::translate("MainWindow", "-0.5", 0));
        ymax_label->setText(QApplication::translate("MainWindow", "ymax:", 0));
        ymax_edit->setText(QApplication::translate("MainWindow", "0.5", 0));
        numerische_parameter->setTitle(QApplication::translate("MainWindow", "Numerische Parameter:", 0));
#ifndef QT_NO_TOOLTIP
        epsilon_label->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Fehlergrenze</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        epsilon_label->setText(QApplication::translate("MainWindow", "epsilon:", 0));
        iteration_label->setText(QApplication::translate("MainWindow", "iterations:", 0));
        epsilon_edit->setText(QApplication::translate("MainWindow", "1e-09", 0));
        iteration_edit->setText(QApplication::translate("MainWindow", "20", 0));
        m_edit->setText(QApplication::translate("MainWindow", "30", 0));
        n_label->setText(QApplication::translate("MainWindow", "stuetz_x:", 0));
        n_edit->setText(QApplication::translate("MainWindow", "30", 0));
        m_label->setText(QApplication::translate("MainWindow", "stuetz_y:", 0));
        grenzen->setTitle(QApplication::translate("MainWindow", "Randfunktionen:", 0));
        label->setText(QApplication::translate("MainWindow", "           Gebiet", 0));
        d_edit->setText(QApplication::translate("MainWindow", "0", 0));
        b_edit->setText(QApplication::translate("MainWindow", "0", 0));
        c_label->setText(QApplication::translate("MainWindow", "c:", 0));
        d_label->setText(QApplication::translate("MainWindow", "d:", 0));
        a_label->setText(QApplication::translate("MainWindow", "a:", 0));
        b_label->setText(QApplication::translate("MainWindow", "b:", 0));
        c_edit->setText(QApplication::translate("MainWindow", "1", 0));
        a_edit->setText(QApplication::translate("MainWindow", "1", 0));
        tab_widget->setTabText(tab_widget->indexOf(parameter_tab), QApplication::translate("MainWindow", "Einstellungen", 0));
        tab_widget->setTabText(tab_widget->indexOf(console_tab), QApplication::translate("MainWindow", "Konsolenausgabe", 0));
        tab_widget->setTabText(tab_widget->indexOf(view_tab), QApplication::translate("MainWindow", "Anzeige", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
