/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Sep 11 12:51:11 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_add;
    QAction *action_find;
    QAction *action_exit;
    QAction *action_login;
    QAction *action_setting;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 600);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        action_add = new QAction(MainWindow);
        action_add->setObjectName(QString::fromUtf8("action_add"));
        action_add->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_add->setIcon(icon);
        action_find = new QAction(MainWindow);
        action_find->setObjectName(QString::fromUtf8("action_find"));
        action_find->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_find->setIcon(icon1);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_exit->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon2);
        action_login = new QAction(MainWindow);
        action_login->setObjectName(QString::fromUtf8("action_login"));
        action_login->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_login->setIcon(icon3);
        action_setting = new QAction(MainWindow);
        action_setting->setObjectName(QString::fromUtf8("action_setting"));
        action_setting->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_setting->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1000, 24));
        menuBar->setDefaultUp(false);
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(action_login);
        toolBar->addAction(action_add);
        toolBar->addAction(action_find);
        toolBar->addAction(action_setting);
        toolBar->addAction(action_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\205\244\350\264\250\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        action_add->setText(QApplication::translate("MainWindow", "\347\205\244\350\264\250\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        action_add->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_find->setText(QApplication::translate("MainWindow", "\347\205\244\350\264\250\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        action_find->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        action_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_login->setText(QApplication::translate("MainWindow", "\351\224\201\345\256\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_login->setToolTip(QApplication::translate("MainWindow", "Login First", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_login->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0, QApplication::UnicodeUTF8));
        action_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        action_setting->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        menuBar->setStyleSheet(QApplication::translate("MainWindow", "display:none;", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
