#ifndef HLIB_H
#define HLIB_H

#include "hlib_global.h"
#include "windows.h"
#include <QVector>
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QMetaObject>
#include "hookbase.h"

#define RC_MOUSE 14
#define RC_KEYBOARD 13

struct HLIBSHARED_EXPORT MouseInfo
{
public:
    WPARAM   wParam;
    POINT     Point;
    DWORD MouseData;
};

struct HLIBSHARED_EXPORT KeyboardInfo
{
public:
    WPARAM    wParam;
    DWORD VirtualKey;
    DWORD      Flags;
};

class  MouseHook: public HookBase
{
    Q_OBJECT
public:
    explicit MouseHook(QObject *parent = 0);
    ~MouseHook();
signals:
    void MouseRecieve(MouseInfo* mi);
protected:
    void ThrotleChangePreparing();
    HOOKPROC getHookProc();
private:
    static MouseHook* Self;
    static LRESULT CALLBACK HookCallback(int nCode,
                                         WPARAM wParam,
                                         LPARAM lParam);
};

class KeyboardHook: public HookBase
{
    Q_OBJECT
public:
    explicit KeyboardHook(QObject *parent = 0);
    ~KeyboardHook();
signals:
    void KeyboardRecieve(KeyboardInfo* ki);
protected:
    void ThrotleChangePreparing();
    HOOKPROC getHookProc();
private:
    static KeyboardHook* Self;
    QVector<int> KeyBuffer;
    static LRESULT CALLBACK HookCallback(int nCode,
                                         WPARAM wParam,
                                         LPARAM lParam);
};

class HLIBSHARED_EXPORT HookManager: public QObject
{
    Q_OBJECT
public:
    HookManager();
    ~HookManager();
    static MouseHook Mouse;
    static KeyboardHook Keyboard;
};

#endif // HLIB_H
