/****************************************************************************
** Meta object code from reading C++ file 'screenmaker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ControlWindow/screenmaker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenmaker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScreenMaker_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScreenMaker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScreenMaker_t qt_meta_stringdata_ScreenMaker = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ScreenMaker"
QT_MOC_LITERAL(1, 12, 10), // "DrawPixmap"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QPixmap*"
QT_MOC_LITERAL(4, 33, 6), // "pixmap"
QT_MOC_LITERAL(5, 40, 13), // "SetTimerState"
QT_MOC_LITERAL(6, 54, 5), // "state"
QT_MOC_LITERAL(7, 60, 13) // "TimerCallback"

    },
    "ScreenMaker\0DrawPixmap\0\0QPixmap*\0"
    "pixmap\0SetTimerState\0state\0TimerCallback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScreenMaker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

       0        // eod
};

void ScreenMaker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScreenMaker *_t = static_cast<ScreenMaker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DrawPixmap((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 1: _t->SetTimerState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->TimerCallback(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScreenMaker::*_t)(QPixmap * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScreenMaker::DrawPixmap)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ScreenMaker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScreenMaker.data,
      qt_meta_data_ScreenMaker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScreenMaker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreenMaker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenMaker.stringdata0))
        return static_cast<void*>(const_cast< ScreenMaker*>(this));
    return QObject::qt_metacast(_clname);
}

int ScreenMaker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ScreenMaker::DrawPixmap(QPixmap * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
