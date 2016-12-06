#include "hlib.h"

KeyboardHook* KeyboardHook::Self;
MouseHook* MouseHook::Self;

MouseHook HookManager::Mouse;
KeyboardHook HookManager::Keyboard;

MouseHook::MouseHook(QObject *parent)
    :HookBase(parent,RC_MOUSE)
{
    Self = this;
}

MouseHook::~MouseHook()
{
}

LRESULT CALLBACK MouseHook::HookCallback(
        int nCode,
        WPARAM wParam,
        LPARAM lParam)
{
    MSLLHOOKSTRUCT* ms = (MSLLHOOKSTRUCT*)lParam;
    MouseInfo* mi = new MouseInfo{wParam,ms->pt,ms->mouseData};
    emit Self->MouseRecieve(mi);
    if(Self->isReturnToSystem)
        return CallNextHookEx(Self->hHook,nCode,wParam, lParam);
    else
        return 1;
}

void MouseHook::ThrotleChangePreparing()
{
    //some code
}

HOOKPROC MouseHook::getHookProc()
{
    return MouseHook::HookCallback;
}

KeyboardHook::KeyboardHook(QObject *parent)
    :HookBase(parent,RC_KEYBOARD)
{
    Self = this;
    KeyBuffer = QVector<int>(256,0);
}

KeyboardHook::~KeyboardHook()
{
}

LRESULT CALLBACK KeyboardHook::HookCallback(
        int nCode,
        WPARAM wParam,
        LPARAM lParam)
{
    KBDLLHOOKSTRUCT* ks = (KBDLLHOOKSTRUCT*)lParam;
    KeyboardInfo* ki = new KeyboardInfo{wParam,ks->vkCode,ks->flags};
    if (Self->isReturnToSystem) {
        if (wParam==WM_KEYDOWN || wParam==WM_SYSKEYDOWN) {
            Self->KeyBuffer[ks->vkCode]=1;
        }
        if (wParam==WM_KEYUP || wParam==WM_SYSKEYUP) {
            Self->KeyBuffer[ks->vkCode]=0;
        }
    }
    emit Self->KeyboardRecieve(ki);
    if(Self->isReturnToSystem)
        return CallNextHookEx(Self->hHook,nCode, wParam, lParam);
    else
        return 1;
}

void KeyboardHook::ThrotleChangePreparing()
{
    for (int i=0; i<KeyBuffer.size();i++){
        if (KeyBuffer[i]==1) {
            INPUT ip;
            ip.type = INPUT_KEYBOARD;
            ip.ki.dwExtraInfo=0;
            ip.ki.time=0;
            ip.ki.wScan=0;
            ip.ki.wVk=i;
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
            KeyBuffer[i]=0;
        }
    }
}

HOOKPROC KeyboardHook::getHookProc()
{
    return KeyboardHook::HookCallback;
}

HookManager::HookManager()
{
}

HookManager::~HookManager()
{
}
