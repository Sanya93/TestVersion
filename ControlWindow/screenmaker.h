#ifndef SCREENMAKER_H
#define SCREENMAKER_H

#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QScreen>
#include <QGuiApplication>

class ScreenMaker : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(bool Runing READ Runing WRITE setRuning NOTIFY RuningChanged)
    //bool m_Runing;

public:
    explicit ScreenMaker(QObject *parent = 0);
    ~ScreenMaker();
    //bool Runing() const;

signals:
    void DrawPixmap(QPixmap *pixmap);
    //void RuningChanged(bool Runing);

public slots:
    //void setRuning(bool Runing);
    void SetTimerState(bool state);
private slots:
    void TimerCallback();
private:
        QTimer* Timer;
        int index=0;
        QPixmap *ScreenPixmap[2];
};

#endif // SCREENMAKER_H
