#include "hlib.h"

KeyboardHook* KeyboardHook::Self;
MouseHook* MouseHook::Self;

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
    connect(this, SIGNAL(SetMouseHook()),&Mouse,SLOT(StartHook()));
    connect(this, SIGNAL(ReleaseMouseHook()),&Mouse,SLOT(StopHook()));
    connect(this, SIGNAL(SetKeyboardHook()),&Keyboard,SLOT(StartHook()));
    connect(this, SIGNAL(ReleaseKeyboardHook()),&Keyboard,SLOT(StopHook()));
    connect(&Mouse,SIGNAL(MouseRecieve(MouseInfo*)),this,SLOT(MouseSlot(MouseInfo*)));
    connect(&Keyboard,SIGNAL(KeyboardRecieve(KeyboardInfo*)),this,SLOT(KeyboardSlot(KeyboardInfo*)));
    Mouse.moveToThread(&MouseThread);
    Keyboard.moveToThread(&KeyboardThread);
    MouseThread.start();
    KeyboardThread.start();
}

HookManager::~HookManager()
{
    MouseThread.terminate();
    KeyboardThread.terminate();
}

void HookManager::StartHook(int HookType)
{
    switch (HookType) {
    case RC_MOUSE:
        emit SetMouseHook();
        break;
    case RC_KEYBOARD:
        emit SetKeyboardHook();
        break;
    default:
        break;
    }
}

void HookManager::StopHook(int HookType)
{
    switch (HookType) {
    case RC_MOUSE:
        if (Mouse.isHookInstalled()) {
            Mouse.SetThrottleState(false);
            emit ReleaseMouseHook();
        }
        break;
    case RC_KEYBOARD:
        if (Keyboard.isHookInstalled()) {
            Keyboard.SetThrottleState(false);
            emit ReleaseKeyboardHook();
        }
        break;
    default:
        break;
    }
}

bool HookManager::SetThrottleState(int HookType, bool NewState)
{
    switch (HookType) {
    case RC_MOUSE:
        return Mouse.SetThrottleState(NewState);
    case RC_KEYBOARD:
        return Keyboard.SetThrottleState(NewState);
    default:
        return false;
    }
}

void HookManager::MouseSlot(MouseInfo *mi)
{
    emit MouseRecieve(mi);
}

void HookManager::KeyboardSlot(KeyboardInfo *ki)
{
    emit KeyboardRecieve(ki);
}
