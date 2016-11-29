/*#include "hookthreadobject.h"

HookThreadObject::HookThreadObject(QObject *parent) : QObject(parent)
{

}

void HookThreadObject::SetMouseHook()
{
    HMan.Mouse.StartHook(MouseHookCallback);
}

void HookThreadObject::SetKeyboardHook()
{
    HMan.Keyboard.StartHook(KeyHookCallback);
}

void HookThreadObject::ReleaseMouseHook()
{
    HMan.Mouse.StopHook();
}

void HookThreadObject::ReleaseKeyboardHook()
{
    HMan.Keyboard.SetKeyboardThrottle(false);
    HMan.Keyboard.StopHook();
}

bool HookThreadObject::KeyboardBlock(bool state)
{
    return HMan.Keyboard.SetKeyboardThrottle(state);
}

void HookThreadObject::finish()
{
    HMan.Mouse.StopHook();
    HMan.Keyboard.StopHook();
}

void HookThreadObject::KeyHookCallback(KeyboardHInfo ki)
{
    int flag = 0;
    if (ki.wParam==257 || ki.wParam==261) flag = KEYEVENTF_KEYUP;
    SendKeyStruct sks;
    sks.flag = flag;
    sks.VirtualKey = ki.VirtualKey;
    qDebug() << "keyboard " << sks.flag << " " << sks.VirtualKey;
}

void HookThreadObject::MouseHookCallback(MouseHInfo mi)
{
    qDebug() << mi.Point.x << " " << mi.Point.y << " " << mi.wParam;
}
*/
