#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QtGui/QDialog>

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog {
    Q_OBJECT
public:
    LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    void closeEvent ( QCloseEvent * event );

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LoginDialog *ui;
    bool loginSuccess;

private slots:
    void lockBtnClicked();
};

#endif // DIALOG_LOGIN_H
