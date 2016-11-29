/****************************************************************************
** Meta object code from reading C++ file 'hlib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../HLib/hlib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hlib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MouseHook_t {
    QByteArrayData data[5];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MouseHook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MouseHook_t qt_meta_stringdata_MouseHook = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MouseHook"
QT_MOC_LITERAL(1, 10, 12), // "MouseRecieve"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "MouseInfo*"
QT_MOC_LITERAL(4, 35, 2) // "mi"

    },
    "MouseHook\0MouseRecieve\0\0MouseInfo*\0"
    "mi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MouseHook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void MouseHook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MouseHook *_t = static_cast<MouseHook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MouseRecieve((*reinterpret_cast< MouseInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MouseHook::*_t)(MouseInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MouseHook::MouseRecieve)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MouseHook::staticMetaObject = {
    { &HookBase::staticMetaObject, qt_meta_stringdata_MouseHook.data,
      qt_meta_data_MouseHook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MouseHook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MouseHook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MouseHook.stringdata0))
        return static_cast<void*>(const_cast< MouseHook*>(this));
    return HookBase::qt_metacast(_clname);
}

int MouseHook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HookBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MouseHook::MouseRecieve(MouseInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_KeyboardHook_t {
    QByteArrayData data[5];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyboardHook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyboardHook_t qt_meta_stringdata_KeyboardHook = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KeyboardHook"
QT_MOC_LITERAL(1, 13, 15), // "KeyboardRecieve"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "KeyboardInfo*"
QT_MOC_LITERAL(4, 44, 2) // "ki"

    },
    "KeyboardHook\0KeyboardRecieve\0\0"
    "KeyboardInfo*\0ki"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyboardHook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void KeyboardHook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeyboardHook *_t = static_cast<KeyboardHook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->KeyboardRecieve((*reinterpret_cast< KeyboardInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KeyboardHook::*_t)(KeyboardInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KeyboardHook::KeyboardRecieve)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject KeyboardHook::staticMetaObject = {
    { &HookBase::staticMetaObject, qt_meta_stringdata_KeyboardHook.data,
      qt_meta_data_KeyboardHook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KeyboardHook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyboardHook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KeyboardHook.stringdata0))
        return static_cast<void*>(const_cast< KeyboardHook*>(this));
    return HookBase::qt_metacast(_clname);
}

int KeyboardHook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HookBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void KeyboardHook::KeyboardRecieve(KeyboardInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_HookManager_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HookManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HookManager_t qt_meta_stringdata_HookManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HookManager"
QT_MOC_LITERAL(1, 12, 12), // "MouseRecieve"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "MouseInfo*"
QT_MOC_LITERAL(4, 37, 2), // "mi"
QT_MOC_LITERAL(5, 40, 15), // "KeyboardRecieve"
QT_MOC_LITERAL(6, 56, 13), // "KeyboardInfo*"
QT_MOC_LITERAL(7, 70, 2), // "ki"
QT_MOC_LITERAL(8, 73, 12), // "SetMouseHook"
QT_MOC_LITERAL(9, 86, 16), // "ReleaseMouseHook"
QT_MOC_LITERAL(10, 103, 15), // "SetKeyboardHook"
QT_MOC_LITERAL(11, 119, 19), // "ReleaseKeyboardHook"
QT_MOC_LITERAL(12, 139, 9), // "MouseSlot"
QT_MOC_LITERAL(13, 149, 12) // "KeyboardSlot"

    },
    "HookManager\0MouseRecieve\0\0MouseInfo*\0"
    "mi\0KeyboardRecieve\0KeyboardInfo*\0ki\0"
    "SetMouseHook\0ReleaseMouseHook\0"
    "SetKeyboardHook\0ReleaseKeyboardHook\0"
    "MouseSlot\0KeyboardSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HookManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,
      10,    0,   62,    2, 0x06 /* Public */,
      11,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   64,    2, 0x08 /* Private */,
      13,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void HookManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HookManager *_t = static_cast<HookManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MouseRecieve((*reinterpret_cast< MouseInfo*(*)>(_a[1]))); break;
        case 1: _t->KeyboardRecieve((*reinterpret_cast< KeyboardInfo*(*)>(_a[1]))); break;
        case 2: _t->SetMouseHook(); break;
        case 3: _t->ReleaseMouseHook(); break;
        case 4: _t->SetKeyboardHook(); break;
        case 5: _t->ReleaseKeyboardHook(); break;
        case 6: _t->MouseSlot((*reinterpret_cast< MouseInfo*(*)>(_a[1]))); break;
        case 7: _t->KeyboardSlot((*reinterpret_cast< KeyboardInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HookManager::*_t)(MouseInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HookManager::MouseRecieve)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HookManager::*_t)(KeyboardInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HookManager::KeyboardRecieve)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (HookManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HookManager::SetMouseHook)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (HookManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HookManager::ReleaseMouseHook)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (HookManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HookManager::SetKeyboardHook)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (HookManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HookManager::ReleaseKeyboardHook)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject HookManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HookManager.data,
      qt_meta_data_HookManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HookManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HookManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HookManager.stringdata0))
        return static_cast<void*>(const_cast< HookManager*>(this));
    return QObject::qt_metacast(_clname);
}

int HookManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void HookManager::MouseRecieve(MouseInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HookManager::KeyboardRecieve(KeyboardInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HookManager::SetMouseHook()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void HookManager::ReleaseMouseHook()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void HookManager::SetKeyboardHook()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void HookManager::ReleaseKeyboardHook()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
