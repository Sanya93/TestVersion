#include "screenmaker.h"
#include <QDebug>
#include <QTime>
#include <QThread>

ScreenMaker::ScreenMaker(QObject *parent) : QObject(parent)
{
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this,SLOT(TimerCallback()));
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        ScreenPixmap[0] = new QPixmap(screen->grabWindow(0));
        QThread::sleep(5);
        ScreenPixmap[1] = new QPixmap(screen->grabWindow(0));
        //QPixmap *pic = new QPixmap(ScreenPixmap);

    }
}

ScreenMaker::~ScreenMaker()
{
    Timer->deleteLater();
}

void ScreenMaker::SetTimerState(bool state)
{
    if (state) {
        Timer->start(20);
    }
    else {
        Timer->stop();
    }
}

void ScreenMaker::TimerCallback()
{
    index = (index+1)%2;
    //pix->fill(QColor(qrand()%255,qrand()%255,qrand()%255));
    //ScreenPixmap = new QPixmap();
    //ScreenPixmap->load("C:\\Users\\Admin\\Desktop\\TestVersion\\build\\ControlWindow\\debug\\1.png");
    //emit DrawPixmap(ScreenPixmap);
    //Timer->stop();

    //emit DrawPixmap(0);
    emit DrawPixmap(ScreenPixmap[index]);
}

/*void ScreenMaker::MainLoop()
{

}*/
