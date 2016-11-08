#ifndef HOOKTHREADOBJECT_H
#define HOOKTHREADOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include "hlib.h"

struct SendKeyStruct{
    int flag;
    int VirtualKey;
};

class HookThreadObject : public QObject
{
    Q_OBJECT
public:
    explicit HookThreadObject(QObject *parent = 0);
    bool KeyboardBlock(bool state);
signals:

public slots:
    void finish();
    void SetMouseHook();
    void SetKeyboardHook();
    void ReleaseMouseHook();
    void ReleaseKeyboardHook();
private:
    HookManager HMan;
    static void MouseHookCallback(MouseHInfo mi);
    static void KeyHookCallback(KeyboardHInfo ki);
};

#endif // HOOKTHREADOBJECT_H
