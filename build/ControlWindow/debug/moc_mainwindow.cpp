/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ControlWindow/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[410];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "SetScreencastState"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "state"
QT_MOC_LITERAL(4, 37, 10), // "DrawPixmap"
QT_MOC_LITERAL(5, 48, 8), // "QPixmap*"
QT_MOC_LITERAL(6, 57, 6), // "pixmap"
QT_MOC_LITERAL(7, 64, 27), // "on_actionThrottle_triggered"
QT_MOC_LITERAL(8, 92, 7), // "checked"
QT_MOC_LITERAL(9, 100, 28), // "on_actionStartHook_triggered"
QT_MOC_LITERAL(10, 129, 27), // "on_actionStopHook_triggered"
QT_MOC_LITERAL(11, 157, 26), // "on_actionAction1_triggered"
QT_MOC_LITERAL(12, 184, 26), // "on_actionAction2_triggered"
QT_MOC_LITERAL(13, 211, 25), // "on_actionAction_triggered"
QT_MOC_LITERAL(14, 237, 24), // "on_actionStart_triggered"
QT_MOC_LITERAL(15, 262, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(16, 286, 11), // "resizeEvent"
QT_MOC_LITERAL(17, 298, 13), // "QResizeEvent*"
QT_MOC_LITERAL(18, 312, 5), // "event"
QT_MOC_LITERAL(19, 318, 26), // "on_actionStart_2_triggered"
QT_MOC_LITERAL(20, 345, 17), // "MouseHookCallback"
QT_MOC_LITERAL(21, 363, 10), // "MouseInfo*"
QT_MOC_LITERAL(22, 374, 2), // "mi"
QT_MOC_LITERAL(23, 377, 15), // "KeyHookCallback"
QT_MOC_LITERAL(24, 393, 13), // "KeyboardInfo*"
QT_MOC_LITERAL(25, 407, 2) // "ki"

    },
    "MainWindow\0SetScreencastState\0\0state\0"
    "DrawPixmap\0QPixmap*\0pixmap\0"
    "on_actionThrottle_triggered\0checked\0"
    "on_actionStartHook_triggered\0"
    "on_actionStopHook_triggered\0"
    "on_actionAction1_triggered\0"
    "on_actionAction2_triggered\0"
    "on_actionAction_triggered\0"
    "on_actionStart_triggered\0"
    "on_actionStop_triggered\0resizeEvent\0"
    "QResizeEvent*\0event\0on_actionStart_2_triggered\0"
    "MouseHookCallback\0MouseInfo*\0mi\0"
    "KeyHookCallback\0KeyboardInfo*\0ki"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   87,    2, 0x0a /* Public */,
       7,    1,   90,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    1,  100,    2, 0x08 /* Private */,
      19,    1,  103,    2, 0x08 /* Private */,
      20,    1,  106,    2, 0x08 /* Private */,
      23,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetScreencastState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->DrawPixmap((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 2: _t->on_actionThrottle_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actionStartHook_triggered(); break;
        case 4: _t->on_actionStopHook_triggered(); break;
        case 5: _t->on_actionAction1_triggered(); break;
        case 6: _t->on_actionAction2_triggered(); break;
        case 7: _t->on_actionAction_triggered(); break;
        case 8: _t->on_actionStart_triggered(); break;
        case 9: _t->on_actionStop_triggered(); break;
        case 10: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 11: _t->on_actionStart_2_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->MouseHookCallback((*reinterpret_cast< MouseInfo*(*)>(_a[1]))); break;
        case 13: _t->KeyHookCallback((*reinterpret_cast< KeyboardInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SetScreencastState)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::SetScreencastState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
