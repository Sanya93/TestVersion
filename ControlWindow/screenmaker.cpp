#include "screenmaker.h"

ScreenMaker::ScreenMaker(QObject *parent) : QObject(parent)
{
    //Timer = new QTimer(this);
    //connect(Timer, SIGNAL(timeout()),this,SLOT(TimerCallback()));
}

ScreenMaker::~ScreenMaker()
{
    //delete Timer;
}

/*bool ScreenMaker::Runing() const
{
    return m_Runing;
}*/

/*void ScreenMaker::setRuning(bool Runing)
{
    if (m_Runing == Runing)
        return;

    m_Runing = Runing;
    if (m_Runing) {
        Timer->start(40);
    }
    else {
        Timer->stop();
    }
    emit RuningChanged(Runing);
}*/

/*void ScreenMaker::TimerCallback()
{

}*/

/*void ScreenMaker::MainLoop()
{
    ScreenPixmap = QPixmap();
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        ScreenPixmap = screen->grabWindow(0);
        QPixmap *pic = new QPixmap(ScreenPixmap);
        emit DrawPixmap(pic);

    }
}*/
