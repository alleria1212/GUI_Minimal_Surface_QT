/****************************************************************************
** Meta object code from reading C++ file 'discretization.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../minimalsurface/discretization.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'discretization.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Discretization_t {
    QByteArrayData data[9];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Discretization_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Discretization_t qt_meta_stringdata_Discretization = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Discretization"
QT_MOC_LITERAL(1, 15, 19), // "calculationComplete"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "double**"
QT_MOC_LITERAL(4, 45, 16), // "setProgressValue"
QT_MOC_LITERAL(5, 62, 11), // "showMessage"
QT_MOC_LITERAL(6, 74, 5), // "fillA"
QT_MOC_LITERAL(7, 80, 5), // "solve"
QT_MOC_LITERAL(8, 86, 10) // "Parameter*"

    },
    "Discretization\0calculationComplete\0\0"
    "double**\0setProgressValue\0showMessage\0"
    "fillA\0solve\0Parameter*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Discretization[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       4,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   50,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void Discretization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Discretization *_t = static_cast<Discretization *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calculationComplete((*reinterpret_cast< double**(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setProgressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->fillA(); break;
        case 4: _t->solve((*reinterpret_cast< Parameter*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Discretization::*_t)(double * * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Discretization::calculationComplete)) {
                *result = 0;
            }
        }
        {
            typedef void (Discretization::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Discretization::setProgressValue)) {
                *result = 1;
            }
        }
        {
            typedef void (Discretization::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Discretization::showMessage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Discretization::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Discretization.data,
      qt_meta_data_Discretization,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Discretization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Discretization::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Discretization.stringdata0))
        return static_cast<void*>(const_cast< Discretization*>(this));
    return QObject::qt_metacast(_clname);
}

int Discretization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Discretization::calculationComplete(double * * _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Discretization::setProgressValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Discretization::showMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
