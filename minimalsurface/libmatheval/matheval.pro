#-------------------------------------------------
#
# Project created by QtCreator 2015-07-31T19:50:56
#
#-------------------------------------------------

QT       -= core gui

TARGET = matheval
TEMPLATE = lib

DESTDIR = ../libmatheval/lib

DEFINES += MATHEVAL_LIBRARY
INCLUDEPATH += /usr/local/include/guile/2.0 \
    /usr/local/include/

SOURCES += \
    include/error.c \
    include/g77_interface.c \
    include/matheval.c \
    include/node.c \
    include/parser.c \
    include/scanner.c \
    include/symbol_table.c \
    include/xmalloc.c \
    include/xmath.c

HEADERS += \
    include/common.h \
    include/error.h \
    include/matheval.h \
    include/node.h \
    include/parser.h \
    include/symbol_table.h \
    include/xmalloc.h \
    include/xmath.h \
    config.h

macx: {
    target.path = /usr/local/lib
    INSTALLS += target
}
