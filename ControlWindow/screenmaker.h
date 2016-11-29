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

public:
    explicit ScreenMaker(QObject *parent = 0);
    ~ScreenMaker();

signals:
    void DrawPixmap(QPixmap *pixmap);

public slots:
    void SetTimerState(bool state);

private slots:
    void TimerCallback();

private:
    void GetPixmap(int index);
    int ScreenWidth, ScreenHeight;
    QTimer* Timer;
    int CurrentBuffer=0;
    QPixmap *ScreenPixmap[2];
};

#endif // SCREENMAKER_H
