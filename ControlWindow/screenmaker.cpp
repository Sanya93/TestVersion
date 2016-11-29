#include "screenmaker.h"
#include <QDebug>
#include <QTime>
#include <QThread>
#include "windows.h"
#include <QtWinExtras/QtWin>

ScreenMaker::ScreenMaker(QObject *parent) : QObject(parent)
{
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this,SLOT(TimerCallback()));
    ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
    ScreenPixmap[0] = nullptr;
    ScreenPixmap[1] = nullptr;
    GetPixmap(CurrentBuffer);
}

ScreenMaker::~ScreenMaker()
{
    Timer->deleteLater();
}

void ScreenMaker::SetTimerState(bool state)
{
    if (state) {
        Timer->start(40);
    }
    else {
        Timer->stop();
    }
}

void ScreenMaker::TimerCallback()
{
    emit DrawPixmap(ScreenPixmap[CurrentBuffer]);
    CurrentBuffer = (CurrentBuffer+1)%2;
    GetPixmap(CurrentBuffer);
}

/*void ScreenMaker::GetPixmap(int index)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        if (ScreenPixmap[index])
            delete ScreenPixmap[index];
        ScreenPixmap[index] = new QPixmap(screen->grabWindow(0));
    }
}*/

void ScreenMaker::GetPixmap(int index)
{
    HDC hdc = GetDC(NULL);
    HDC hCapture = CreateCompatibleDC(hdc);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, ScreenWidth, ScreenHeight);
    SelectObject(hCapture, hBitmap);
    BitBlt(hCapture,0,0,ScreenWidth,ScreenHeight,hdc,0,0,SRCCOPY);
    if (ScreenPixmap[index])
        delete ScreenPixmap[index];
    QPixmap pic = QtWin::fromHBITMAP(hBitmap);
    ScreenPixmap[index] = new QPixmap(pic);
    DeleteObject(hBitmap);
    DeleteObject(hCapture);
    ReleaseDC(NULL,hdc);
}
