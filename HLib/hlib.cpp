#include "hlib.h"
#include <QDebug>
#include <QMessageBox>

HHOOK MouseHook::hHook;
void (*MouseHook::MouseCallback)(MouseHInfo mi);
HHOOK KeyboardHook::hHook;
bool KeyboardHook::isReturnToSystem = true;
void (*KeyboardHook::KeyCallback)(KeyboardHInfo ki);
QVector<int> KeyboardHook::KeyBuffer=QVector<int>(256,0);

void MouseHook::StartHook(void (*callback)(MouseHInfo))
{
    if (!isHooked) {
        MouseCallback = callback;
        HINSTANCE inst = GetModuleHandle(NULL);
        hHook = NULL;
        hHook = SetWindowsHookEx(
                    WH_MOUSE_LL,
                    H_MouseHookProc,
                    inst,
                    0);
        if(hHook == NULL)
            QMessageBox::information(
                        0,
                        "Information",
                        "MouseHook failed with code "+
                        QString::number(GetLastError()));
        isHooked=true;
    }
}

void MouseHook::StopHook()
{
    if (hHook != NULL&&isHooked) {
        if(!UnhookWindowsHookEx(hHook)) {
            QMessageBox::information(
                        0,
                        "Information",
                        "MouseHook failed with code "+
                        QString::number(GetLastError()));
        }
        isHooked=false;
    }
}

LRESULT CALLBACK MouseHook::H_MouseHookProc(
        int nCode,
        WPARAM wParam,
        LPARAM lParam)
{
    MSLLHOOKSTRUCT* ms = (MSLLHOOKSTRUCT*)lParam;
    MouseHInfo mi{wParam,ms->pt,ms->mouseData};
    MouseCallback(mi);
    return CallNextHookEx(hHook,nCode,wParam, lParam);
}


void KeyboardHook::StartHook(void (*callback)(KeyboardHInfo))
{
    if (!isHooked) {
        KeyCallback = callback;
        HINSTANCE inst = GetModuleHandle(NULL);
        hHook = NULL;
        hHook = SetWindowsHookEx(
                    WH_KEYBOARD_LL,
                    H_KeyHookProc,
                    inst,
                    0);
        if(hHook == NULL)
            QMessageBox::information(
                        0,
                        "Information",
                        "KeyboardHook failed with code "+
                        QString::number(GetLastError()));
        isHooked=true;
    }
}

void KeyboardHook::StopHook()
{
    if (hHook != NULL && isHooked) {
        if(!UnhookWindowsHookEx(hHook)) {
            QMessageBox::information(
                        0,
                        "Information",
                        "KeyboardHook failed with code "+
                        QString::number(GetLastError()));
        }
        isHooked=false;
    }
}

LRESULT CALLBACK KeyboardHook::H_KeyHookProc(
        int nCode,
        WPARAM wParam,
        LPARAM lParam)
{
    KBDLLHOOKSTRUCT* ks = (KBDLLHOOKSTRUCT*)lParam;
    qDebug() << nCode<<" "<<wParam<<" "<<ks->dwExtraInfo<<" "<<ks->flags<<" "<<ks->vkCode<<" "<<ks->scanCode<<" "<<VK_VOLUME_MUTE;
    KeyboardHInfo ki{wParam,ks->vkCode,ks->flags};
    if (isReturnToSystem) {
        if (wParam==WM_KEYDOWN || wParam==WM_SYSKEYDOWN) {
            KeyBuffer[ks->vkCode]=1;
        }
        if (wParam==WM_KEYUP || wParam==WM_SYSKEYUP) {
            KeyBuffer[ks->vkCode]=0;
        }
    }
    KeyCallback(ki);
    if(isReturnToSystem)
        return CallNextHookEx(hHook,nCode, wParam, lParam);
    else
        return 1;
}

bool KeyboardHook::SetKeyboardThrottle(bool throttle)
{
    if (isHooked) {
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
        isReturnToSystem = !throttle;
        return true;
    }
    return false;
}
