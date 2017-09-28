#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindow;
}

class User;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent ( QCloseEvent * event );
    //QString currentUser;
    User *currentUser;
private:
    Ui::MainWindow *ui;
private slots:
    void loginSlot();
    void settingSlot();
    void findDetectionSlot();
    void systemExitSlot();
public slots:
    void addDetectionSlot();
    void actionsEnabled(bool enabled);
    void setCurrentUser(const QStringList &userInfo);
    User *getCurrentUser();
};

#endif // MAINWINDOW_H
