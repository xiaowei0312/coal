#ifndef DIALOG_SETTING_H
#define DIALOG_SETTING_H

#include <QtGui/QDialog>

class User;
namespace Ui {
    class SettingDialog;
}

class SettingDialog : public QDialog {
    Q_OBJECT
public:
    SettingDialog(QWidget *parent = 0);
    ~SettingDialog();
    void closeEvent ( QCloseEvent * event );

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SettingDialog *ui;
    bool settingSuccess;
    User *currentUser;
    
    bool verifyOldPassword(const QString username,const QString &pwd);
    bool updatePassword(const QString username,const QString &pwd);
    bool updateUserInfo(const QString &username,const QString &alias,const QString &phone);

private slots:
    void settingBtnClicked();
    void updateUserClicked();
};

#endif // DIALOG_SETTING_H
