#ifndef HOOKBASE_H
#define HOOKBASE_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <QMetaObject>
#include "windows.h"
#include "hlib_global.h"

class HLIBSHARED_EXPORT HookBase : public QObject
{
    Q_OBJECT
public:
    explicit HookBase(QObject *parent = 0, int hookType=0);
    ~HookBase();
    bool SetThrottleState(bool NewState);
    bool isHookInstalled();
    bool ThrottleState();
    void InitHook();
    void DestroyHook();
protected slots:
    void StartHook();
    void StopHook();
protected:
    virtual void ThrotleChangePreparing() = 0;
    virtual HOOKPROC getHookProc() = 0;
    HHOOK hHook;
    bool isReturnToSystem = true;

    QThread *o_thread;
    QThread *p_thread;
private:
    int HookType;
    bool isHooked;
};

#endif // HOOKBASE_H
