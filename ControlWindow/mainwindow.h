#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QThread>
#include "hookthreadobject.h"
#include "screenmaker.h"

namespace Ui {
class MainWindow;
}

struct SendMouseStruct{
    int dx;
    int dy;
    int mouseData;
    int flags;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::MainWindow *ui;
    QThread thr_Hook;
    QThread thr_Screen;
    HookThreadObject HookObject;
    ScreenMaker ScreenObject;
public slots:
    void DrawPixmap();
private slots:
    void on_actionThrottle_triggered(bool checked);
    void on_actionStartHook_triggered();
    void on_actionStopHook_triggered();
    void on_actionAction1_triggered();
    void on_actionAction2_triggered();
    void on_actionAction_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();

signals:
    void SetMouseHook();
    void ReleaseMouseHook();
    void SetKeyboardHook();
    void ReleaseKeyboardHook();
};

#endif // MAINWINDOW_H