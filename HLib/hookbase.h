#ifndef HOOKBASE_H
#define HOOKBASE_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include "windows.h"

#define RC_MOUSE 14
#define RC_KEYBOARD 13

class HookBase : public QObject
{
    Q_OBJECT
public:
    explicit HookBase(QObject *parent = 0, int hookType=0);
    ~HookBase();
    bool SetThrottleState(bool NewState);
    bool isHookInstalled();
    bool ThrottleState();
public slots:
    void StartHook();
    void StopHook();
protected:
    virtual void ThrotleChangePreparing() = 0;
    virtual HOOKPROC getHookProc() = 0;
    HHOOK hHook;
    bool isReturnToSystem;
private:
    int HookType;
    bool isHooked;
};

#endif // HOOKBASE_H
