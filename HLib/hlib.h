#ifndef HLIB_H
#define HLIB_H

#include "hlib_global.h"
#include "windows.h"
#include <QVector>
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include "hookbase.h"

struct HLIBSHARED_EXPORT MouseInfo
{
public:
    WPARAM wParam;
    POINT Point;
    DWORD MouseData;
};

struct HLIBSHARED_EXPORT KeyboardInfo
{
public:
    WPARAM wParam;
    DWORD VirtualKey;
    DWORD Flags;
};

class MouseHook: public HookBase
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
    static LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam);
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
    static LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam);
};

class HLIBSHARED_EXPORT HookManager: public QObject
{
    Q_OBJECT
public:
    HookManager();
    ~HookManager();
    void StartHook(int HookType);
    void StopHook(int HookType);
    bool SetThrottleState(int HookType, bool NewState);
signals:
    void MouseRecieve(MouseInfo* mi);
    void KeyboardRecieve(KeyboardInfo* ki);
    void SetMouseHook();
    void ReleaseMouseHook();
    void SetKeyboardHook();
    void ReleaseKeyboardHook();
 private:
    QThread MouseThread, KeyboardThread;
    MouseHook Mouse;
    KeyboardHook Keyboard;
private slots:
    void MouseSlot(MouseInfo* mi);
    void KeyboardSlot(KeyboardInfo* ki);
};

#endif // HLIB_H
