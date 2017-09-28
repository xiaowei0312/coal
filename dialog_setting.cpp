#include "dialog_setting.h"
#include "ui_dialog_setting.h"
#include "dbutil.h"
#include "mainwindow.h"
#include "user.h"
#include <QMessageBox>
#include <QCloseEvent>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    settingSuccess = false;
    currentUser = ((MainWindow*)this->parent())->getCurrentUser();
    ui->pUsernameEditReadOnly->setText(currentUser->username);
    ui->pUsernameEdit->setText(currentUser->username);
    ui->pAliasEdit->setText(currentUser->alias);
    ui->pPhoneEdit->setText(currentUser->phone);
    
    connect(ui->pSettingBtn,SIGNAL(clicked()),this,SLOT(settingBtnClicked()));
    connect(ui->pChangeBasicBtn,SIGNAL(clicked()),this,SLOT(updateUserClicked()));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SettingDialog::closeEvent ( QCloseEvent * event )
{
    if(!settingSuccess)
    {
        switch(QMessageBox::question(this,QString::fromLocal8Bit("关闭确认"),
            QString::fromLocal8Bit("确定要关闭吗?"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel))
        {
        case QMessageBox::Ok:
            break;
        default:
             event->ignore();
            return;
        }
    }
    event->accept();
}

void SettingDialog::updateUserClicked()
{
    QString username,alias,phone;
    username = ui->pUsernameEdit->text().trimmed();
    alias = ui->pAliasEdit->text().trimmed();
    phone = ui->pPhoneEdit->text().trimmed();
    if(!updateUserInfo(username,alias,phone))
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("基本信息修改失败"),
            QString::fromLocal8Bit("SQLite内部异常，请查看系统日志"));
        return; 
    }
    QMessageBox::information(this,QString::fromLocal8Bit("成功"),
            QString::fromLocal8Bit("基本信息修改成功"));
    this->settingSuccess = true;
    ((MainWindow*)this->parent())->setCurrentUser(QStringList() << currentUser->id << username << alias << phone);
    this->close();
}

void SettingDialog::settingBtnClicked()
{
    QString pwd1,pwd2,pwd3;
    pwd1 = ui->pOldPwdEdit->text().trimmed();
    pwd2 = ui->pNewPwdEdit->text().trimmed();
    pwd3 = ui->pRePwdEdit->text().trimmed();
    
    if(pwd2 != pwd3)
    {
         QMessageBox::information(this,QString::fromLocal8Bit("密码修改失败"),
            QString::fromLocal8Bit("两次新密码输入不一致"));
         return;
    }
    if(pwd1 == pwd2)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("密码修改失败"),
            QString::fromLocal8Bit("新旧密码不能一样"));
         return;
    }
     
    if(!verifyOldPassword(currentUser->username,pwd1))
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("密码修改失败"),
            QString::fromLocal8Bit("原始密码不正确"));
        return; 
    }
    if(!updatePassword(currentUser->username,pwd2))
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("密码修改失败"),
            QString::fromLocal8Bit("SQLite内部异常，请查看系统日志"));
        return; 
    }
    
    QMessageBox::information(this,QString::fromLocal8Bit("成功"),
            QString::fromLocal8Bit("密码修改成功"));
    
    this->settingSuccess = true;
    this->close();
}

bool SettingDialog::verifyOldPassword(const QString username,const QString &pwd)
{
    QStringList names;
    QList<QStringList> values;
    names << "id";
    QString expressions = "username = '%1' and password = '%2' and is_deleted = 0";
    expressions = expressions.arg(username).arg(pwd);
    
    if(!DBUtil::getInstance()->select("t_user",names,expressions,values))
        return false;
    if(values.size()==0)
        return false;
    return true;
}

bool SettingDialog::updatePassword(const QString username,const QString &pwd)
{
    QStringList names,values;
    QString expressions = "username = '%1'";
    expressions = expressions.arg(username);
    names << "password";
    values << pwd;
    
    return DBUtil::getInstance()->update("t_user",names,values,expressions);
}

bool SettingDialog::updateUserInfo(const QString &username,const QString &alias,const QString &phone)
{
    QStringList names,values;
    QString expressions = "username = '%1'";
    expressions = expressions.arg(currentUser->username);
    names << "username" << "alias" << "phone";
    values << username << alias << phone;
    
    return DBUtil::getInstance()->update("t_user",names,values,expressions);
}
