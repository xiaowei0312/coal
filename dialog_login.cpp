#include "dialog_login.h"
#include "ui_dialog_login.h"
#include "dbutil.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    loginSuccess = false;
    connect(ui->pLoginBtn,SIGNAL(clicked()),this,SLOT(lockBtnClicked()));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::changeEvent(QEvent *e)
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


void LoginDialog::lockBtnClicked()
{
    QString username = ui->pUsernameEdit->text().trimmed();
    QString password = ui->pPasswordEdit->text().trimmed();
    if(username.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("����ʧ��"),
            QString::fromLocal8Bit("�û�������Ϊ��"));
        return;
    }
    
    QStringList names;
    QList<QStringList> values;
    names << "id" << "username" << "alias" << "phone" ;
    QString expressions = "username = '%1' and password = '%2' and is_deleted = 0";
    expressions = expressions.arg(username).arg(password);
    
    if(!DBUtil::getInstance()->select("t_user",names,expressions,values))
    {
        QMessageBox:: critical(this,QString::fromLocal8Bit("����ʧ��"),
            QString::fromLocal8Bit("����ʧ�ܣ����������ַ�����ʽ�Ƿ���ȷ"));
        return;
    }
    if(values.size()==0)
    {
        QMessageBox:: critical(this,QString::fromLocal8Bit("����ʧ��"),
            QString::fromLocal8Bit("�û��������������"));
        return;
    }
    
    ((MainWindow *)this->parent())->setCurrentUser(values.value(0));
    ((MainWindow *)this->parent())->actionsEnabled(true);
    this->loginSuccess = true;
    this->close();
}

void LoginDialog::closeEvent ( QCloseEvent * event )
{
    
    if(!loginSuccess)
    {
        switch(QMessageBox::question(this,QString::fromLocal8Bit("�ر�ȷ��"),
            QString::fromLocal8Bit("ȷ��Ҫ�ر���?"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel))
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
