/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include <screenwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStartHook;
    QAction *actionStopHook;
    QAction *actionThrottle;
    QAction *actionAction1;
    QAction *actionAction2;
    QAction *actionAction;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionStart_2;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    ScreenWidget *ScreenW;
    QMenuBar *menuBar;
    QMenu *menuKeyHook;
    QMenu *menuAction1;
    QMenu *menuMouseHook;
    QMenu *menuScreen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(400, 300);
        actionStartHook = new QAction(MainWindow);
        actionStartHook->setObjectName(QStringLiteral("actionStartHook"));
        actionStopHook = new QAction(MainWindow);
        actionStopHook->setObjectName(QStringLiteral("actionStopHook"));
        actionStopHook->setCheckable(false);
        actionThrottle = new QAction(MainWindow);
        actionThrottle->setObjectName(QStringLiteral("actionThrottle"));
        actionThrottle->setCheckable(true);
        actionAction1 = new QAction(MainWindow);
        actionAction1->setObjectName(QStringLiteral("actionAction1"));
        actionAction2 = new QAction(MainWindow);
        actionAction2->setObjectName(QStringLiteral("actionAction2"));
        actionAction = new QAction(MainWindow);
        actionAction->setObjectName(QStringLiteral("actionAction"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStart_2 = new QAction(MainWindow);
        actionStart_2->setObjectName(QStringLiteral("actionStart_2"));
        actionStart_2->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ScreenW = new ScreenWidget(centralWidget);
        ScreenW->setObjectName(QStringLiteral("ScreenW"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScreenW->sizePolicy().hasHeightForWidth());
        ScreenW->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ScreenW);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuKeyHook = new QMenu(menuBar);
        menuKeyHook->setObjectName(QStringLiteral("menuKeyHook"));
        menuAction1 = new QMenu(menuBar);
        menuAction1->setObjectName(QStringLiteral("menuAction1"));
        menuMouseHook = new QMenu(menuBar);
        menuMouseHook->setObjectName(QStringLiteral("menuMouseHook"));
        menuScreen = new QMenu(menuBar);
        menuScreen->setObjectName(QStringLiteral("menuScreen"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuKeyHook->menuAction());
        menuBar->addAction(menuAction1->menuAction());
        menuBar->addAction(menuMouseHook->menuAction());
        menuBar->addAction(menuScreen->menuAction());
        menuKeyHook->addAction(actionStartHook);
        menuKeyHook->addAction(actionStopHook);
        menuKeyHook->addAction(actionThrottle);
        menuAction1->addAction(actionAction1);
        menuAction1->addAction(actionAction2);
        menuAction1->addAction(actionAction);
        menuMouseHook->addAction(actionStart);
        menuMouseHook->addAction(actionStop);
        menuScreen->addAction(actionStart_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionStartHook->setText(QApplication::translate("MainWindow", "StartHook", 0));
        actionStopHook->setText(QApplication::translate("MainWindow", "StopHook", 0));
        actionThrottle->setText(QApplication::translate("MainWindow", "Throttle", 0));
        actionAction1->setText(QApplication::translate("MainWindow", "Action1", 0));
        actionAction2->setText(QApplication::translate("MainWindow", "Action2", 0));
        actionAction->setText(QApplication::translate("MainWindow", "Action3", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        actionStart_2->setText(QApplication::translate("MainWindow", "Start", 0));
        menuKeyHook->setTitle(QApplication::translate("MainWindow", "KeyHook", 0));
        menuAction1->setTitle(QApplication::translate("MainWindow", "Action", 0));
        menuMouseHook->setTitle(QApplication::translate("MainWindow", "MouseHook", 0));
        menuScreen->setTitle(QApplication::translate("MainWindow", "Screen", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
