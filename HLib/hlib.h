#ifndef HLIB_H
#define HLIB_H

#include "hlib_global.h"
#include "windows.h"
#include <QVector>

struct HLIBSHARED_EXPORT MouseHInfo
{
public:
    WPARAM wParam;
    POINT Point;
    DWORD MouseData;
};

struct HLIBSHARED_EXPORT KeyboardHInfo
{
public:
    WPARAM wParam;
    DWORD VirtualKey;
    DWORD Flags;
};

class MouseHook
{
public:
    void StartHook(void (*callback)(MouseHInfo mi));
    void StopHook();
private:
    bool isHooked=false;
    static HHOOK hHook;
    static LRESULT CALLBACK H_MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
    static void (*MouseCallback)(MouseHInfo mi);
};

class KeyboardHook
{
public:
    void StartHook(void (*callback)(KeyboardHInfo ki));
    void StopHook();
    bool SetKeyboardThrottle(bool throttle);
private:
    bool isHooked=false;
    static HHOOK hHook;
    static bool isReturnToSystem;
    static LRESULT CALLBACK H_KeyHookProc(int nCode, WPARAM wParam, LPARAM lParam);
    static void (*KeyCallback)(KeyboardHInfo ki);
    static QVector<int> KeyBuffer;
};

class HLIBSHARED_EXPORT HookManager
{
public:
    HLib();
    MouseHook Mouse;
    KeyboardHook Keyboard;
};

#endif // HLIB_H
