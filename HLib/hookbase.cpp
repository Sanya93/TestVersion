#include "hookbase.h"

HookBase::HookBase(QObject *parent, int hookType)
    : QObject(parent), HookType(hookType)
{
}

HookBase::~HookBase()
{
}

void HookBase::StartHook()
{
    if (!isHooked) {
        HINSTANCE instance = GetModuleHandle(NULL);
        hHook = NULL;
        hHook = SetWindowsHookEx(
                    HookType,
                    getHookProc(),
                    instance,
                    0);
        if(hHook == NULL)
            QMessageBox::information(
                        0,
                        "Information",
                        "Hook starting failed with code "+
                        QString::number(GetLastError()));
        isHooked=true;
    }
}

void HookBase::StopHook()
{
    if (hHook != NULL && isHooked) {
        if(!UnhookWindowsHookEx(hHook)) {
            QMessageBox::information(
                        0,
                        "Information",
                        "Hook stoping failed with code "+
                        QString::number(GetLastError()));
        }
        isHooked=false;
    }
}

bool HookBase::SetThrottleState(bool NewState)
{
    if (isHooked) {
        if (!isReturnToSystem==NewState)
            return true;
        ThrotleChangePreparing();
        isReturnToSystem = !NewState;
        return true;
    }
    return false;
}

bool HookBase::isHookInstalled()
{
    return isHooked;
}

bool HookBase::ThrottleState()
{
    return isReturnToSystem;
}
