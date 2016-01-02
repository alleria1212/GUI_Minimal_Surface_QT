#-------------------------------------------------
#
# Project created by QtCreator 2015-07-05T15:51:55
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets printsupport
}
QMAKE_CXXFLAGS+=-O3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += opengl

TARGET = minimalsurface
TEMPLATE = app

INCLUDEPATH += "Eigen/"

SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    discretization.cpp \
    parameter.cpp \
    dco_t1s/dco_t1s_type.cpp

HEADERS  += mainwindow.h \
    controller.h \
    discretization.h \
    parameter.h \
    solverfunctions.h \
    plot.h \
    dco_t1s/dco_t1s_type.hpp

FORMS    += mainwindow.ui

LIBS += -L$$PWD/qwtplot3d/lib/ -lqwtplot3d \
    -L$$PWD/libmatheval/lib/ -lmatheval

INCLUDEPATH += $$PWD/qwtplot3d/include \
    $$PWD/libmatheval/include
DEPENDPATH += $$PWD/qwtplot3d/include \
    $$PWD/libmatheval/include

macx {
    QMAKE_MAC_SDK = macosx10.11
}
