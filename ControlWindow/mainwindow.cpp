#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTime>
#include <QMessageBox>
#include <QEvent>
#include <QMoveEvent>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    SCREEN_WIDTH = screen->size().width();
    SCREEN_HEIGHT = screen->size().height();
    ui->ScreenBox->installEventFilter(this);
    connect(this,&MainWindow::SetScreencastState,&ScreenObject,&ScreenMaker::SetTimerState);
    connect(&ScreenObject,&ScreenMaker::DrawPixmap,this,&MainWindow::DrawPixmap);
    connect(&HookManager::Mouse,SIGNAL(MouseRecieve(MouseInfo*)),this,SLOT(MouseHookCallback(MouseInfo*)));
    connect(&HookManager::Keyboard,SIGNAL(KeyboardRecieve(KeyboardInfo*)),this,SLOT(KeyHookCallback(KeyboardInfo*)));
//    ScreenObject.moveToThread(&thr_Screen);
//    thr_Screen.start();
}

MainWindow::~MainWindow()
{
    emit SetScreencastState(false);
//    QThread::sleep(1);
    delete ui;
//    thr_Screen.terminate();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (qobject_cast<QGLWidget*>(obj)==ui->ScreenBox) {
      SendMouseStruct sms;
      sms.mouseData=0;
      sms.dx=0;
      sms.dy=0;
      bool mouse =false;
      if (event->type()==QEvent::MouseMove) {
          QMouseEvent *me = static_cast<QMouseEvent*>(event);
          sms.dx = (double)me->x()/ui->ScreenBox->width()*65535;
          sms.dy = (double)me->y()/ui->ScreenBox->height()*65535;
          sms.flags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
          mouse=true;
      }
      if (event->type()==QEvent::MouseButtonPress ||
          event->type()==QEvent::MouseButtonDblClick)
      {
          QMouseEvent *me = static_cast<QMouseEvent*>(event);
          switch (me->button()) {
          case Qt::LeftButton:
              sms.flags = MOUSEEVENTF_LEFTDOWN;
              break;
          case Qt::RightButton:
              sms.flags = MOUSEEVENTF_RIGHTDOWN;
              break;
          case Qt::MidButton:
              sms.flags = MOUSEEVENTF_MIDDLEDOWN;
              break;
          default:
              break;
          }
          mouse=true;
      }
      if (event->type()==QEvent::MouseButtonRelease)
      {
          QMouseEvent *me = static_cast<QMouseEvent*>(event);
          switch (me->button()) {
          case Qt::LeftButton:
              sms.flags = MOUSEEVENTF_LEFTUP;
              break;
          case Qt::RightButton:
              sms.flags = MOUSEEVENTF_RIGHTUP;
              break;
          case Qt::MidButton:
              sms.flags = MOUSEEVENTF_MIDDLEUP;
              break;
          default:
              break;
          }
          mouse=true;
      }
      if (event->type()==QEvent::Wheel) {
          QWheelEvent *we = static_cast<QWheelEvent*>(event);
          sms.mouseData = we->delta();
          sms.flags = MOUSEEVENTF_WHEEL;
          mouse=true;
      }

      if (mouse) {
//          qDebug()<< sms.dx<< " "<<sms.dy<<" "<<sms.flags <<" "<< sms.mouseData;
      }
  }
  return false;
}

void MainWindow::DrawPixmap(QPixmap *pixmap)
{
    ui->ScreenBox->DrawPixmap(pixmap);
}

void MainWindow::on_actionStartHook_triggered()
{
    HookManager::Keyboard.InitHook();
}

void MainWindow::on_actionStopHook_triggered()
{
    HookManager::Keyboard.DestroyHook();
     ui->actionThrottle->setChecked(false);
}

void MainWindow::on_actionThrottle_triggered(bool checked)
{
    if (!HookManager::Keyboard.SetThrottleState(checked))
        ui->actionThrottle->setChecked(false);
}

void MainWindow::on_actionStart_triggered()
{
    HookManager::Mouse.InitHook();
}

void MainWindow::on_actionStop_triggered()
{
    HookManager::Mouse.DestroyHook();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    double mx = (double)ui->centralWidget->size().width()/SCREEN_WIDTH;
    double my = (double)ui->centralWidget->size().height()/SCREEN_HEIGHT;
    double m = qMin(mx, my);
    ui->ScreenBox->resize(SCREEN_WIDTH*m,SCREEN_HEIGHT*m);
}

void MainWindow::on_actionAction1_triggered()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = VK_LMENU;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void press_alpha(INPUT& ip,int code)
{
    ip.ki.wVk = code;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = code;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void MainWindow::on_actionAction2_triggered()
{
    QThread::sleep(5);
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    press_alpha(ip, 0x53);
    press_alpha(ip, 0x55);
    press_alpha(ip, 0x4B);
    press_alpha(ip, 0x41);
}

void MainWindow::on_actionAction_triggered()
{
    QThread::sleep(3);
    INPUT ip;
    ip.type = INPUT_MOUSE;
    ip.mi.dwExtraInfo=0;
    ip.mi.time=0;

    ip.mi.dwFlags=32769;
    ip.mi.dx=1146;
    ip.mi.dy=62901;
    ip.mi.mouseData=0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.mi.dwFlags=2;
    ip.mi.dx=0;
    ip.mi.dy=0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.mi.dwFlags=4;

    SendInput(1, &ip, sizeof(INPUT));

}


void MainWindow::on_actionStart_2_triggered(bool checked)
{
    emit SetScreencastState(checked);
}

void MainWindow::MouseHookCallback(MouseInfo* mi)
{
    qDebug() << mi->Point.x << " " << mi->Point.y << " " << mi->wParam;
    delete mi;
}

void MainWindow::KeyHookCallback(KeyboardInfo *ki)
{
    int flag = 0;
    if (ki->wParam==257 || ki->wParam==261) flag = KEYEVENTF_KEYUP;
    SendKeyStruct sks;
    sks.flag = flag;
    sks.VirtualKey = ki->VirtualKey;
    delete ki;
    qDebug() << "keyboard " << sks.flag << " " << sks.VirtualKey;
}
