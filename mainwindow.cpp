#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_add.h"
#include "dialog_find.h"
#include "dialog_search.h"
#include "dialog_login.h"
#include "dialog_setting.h"
#include "user.h"
#include <QDebug>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentUser = NULL;
    connect(this->ui->action_add,SIGNAL(triggered()),this,SLOT(addDetectionSlot()));
    connect(this->ui->action_find,SIGNAL(triggered()),this,SLOT(findDetectionSlot()));
    connect(this->ui->action_exit,SIGNAL(triggered()),this,SLOT(systemExitSlot()));
    connect(this->ui->action_login,SIGNAL(triggered()),this,SLOT(loginSlot()));
    connect(this->ui->action_setting,SIGNAL(triggered()),this,SLOT(settingSlot()));
}

MainWindow::~MainWindow()
{
    if(currentUser)
    {
        delete currentUser;
        currentUser = NULL;
    }
    delete ui;
}

void MainWindow::setCurrentUser(const QStringList &userInfo)
{
    this->currentUser = new User();
    currentUser->id = userInfo.value(0);
    currentUser->username = userInfo.value(1);
    currentUser->alias = userInfo.value(2);
    currentUser->phone = userInfo.value(3);
    this->setWindowTitle(QString::fromLocal8Bit("煤质管理") + " - " + currentUser->alias);
}

User *MainWindow::getCurrentUser()
{
    return currentUser;
}

void MainWindow::actionsEnabled(bool enabled)
{
    ui->action_add->setEnabled(enabled);
    ui->action_find->setEnabled(enabled);
    ui->action_setting->setEnabled(enabled);
}

void MainWindow::loginSlot()
{
    actionsEnabled(false);
    
    LoginDialog *pLoginDialog = new LoginDialog(this);
    pLoginDialog->setModal(true);
    pLoginDialog->show();
}

void MainWindow::settingSlot()
{
    if(currentUser == NULL)
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("失败"),
            QString::fromLocal8Bit("找不到当前用户信息"));
         return; 
    }
    SettingDialog *pSettingDialog = new SettingDialog(this);
    pSettingDialog->show();
}

void MainWindow::addDetectionSlot()
{
    if(currentUser == NULL)
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("失败"),
            QString::fromLocal8Bit("找不到当前用户信息"));
         return; 
    }
    AddDialog *pAddDialog = new AddDialog(this);
//    pAddDialog->move((qApp->desktop()->width() - pAddDialog->width())/2,
//           (qApp->desktop()->height() - pAddDialog->height())/2 + 20);
     pAddDialog->move((qApp->desktop()->width() - pAddDialog->width())/2,95);
    pAddDialog->show();
}

void MainWindow::findDetectionSlot()
{
    if(currentUser == NULL)
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("失败"),
            QString::fromLocal8Bit("找不到当前用户信息"));
         return; 
    }
    SearchDialog *pSearchDialog = new SearchDialog(this);
//     pSearchDialog->move((qApp->desktop()->width() - pSearchDialog->width())/2,
//           (qApp->desktop()->height() - pSearchDialog->height())/2 + 20);
        //pSearchDialog->move((qApp->desktop()->width() - pSearchDialog->width())/2,95);
     pSearchDialog->show();
}

void MainWindow::systemExitSlot()
{
    switch(QMessageBox::question(this,QString::fromLocal8Bit("退出确认"),QString::fromLocal8Bit("确定要退出系统吗?"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel))
    {
    case QMessageBox::Ok:
        qApp->quit();
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    switch(QMessageBox::question(this,QString::fromLocal8Bit("退出确认"),QString::fromLocal8Bit("确定要退出系统吗?"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel))
    {
    case QMessageBox::Ok:
        event->accept();
        return;
    default:
        break;
    }
    event->ignore();
}

