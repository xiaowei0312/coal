#ifndef DIALOG_FIND_H
#define DIALOG_FIND_H

#include <QtGui/QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QSignalMapper>
#include <data_dependency.h>

namespace Ui {
    class FindDialog;
}

class FindDialog : public QDialog {
    Q_OBJECT
public:
    FindDialog(QWidget *parent = 0);
    ~FindDialog();
    void closeEvent ( QCloseEvent * event );
    void showDataById(const QString &id);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::FindDialog *ui;
    QSignalMapper *signalMapper;
    bool needSave;
    bool isMarked;
    QList<QLineEdit*> editList1,editList2;
    QList<QCheckBox*> checkList;
    QStringList colNameList,colValList,colNameList_print;
    QList<DataDependency*> dataDepList;
        
    QCompleter *pCompleter;
private:
    bool saveData();
    bool updateData(const QString &id);
    bool printData(const QString &id);
    bool saveOrUpdateData();
    void editListInit();
    void checkListInit();
    void colListInit();
    void updateNeedSave(bool flag);
   
    
    void addMarks();
    void clearMarks();
    void clearMark(QLineEdit *pLinEdit);
    void addMark(QLineEdit *pLineEdit);
    void generateData(QLineEdit *pLinEdit);
    int generateDependencies();
    int generateFinalDependencies();
    void getFinalDepList(QLineEdit *pLineEdit,QList<QLineEdit *> &finalDepList);
    void addEventFilter();
    int getEditIndex(QLineEdit *pEdit);
    
private slots:    
    void btn_find_clicked();
    void btn_print_clicked();
    void btn_exit_clicked();
    void btn_update_clicked();
    
    void edit_text_changed(const QString &text);
    void check_state_changed(int);
    void edit_text_changed_mapper(int i);
    void searchkey_text_changed(const QString &text);
    void printPreview(QPrinter *printer);
public slots:
    bool eventFilter(QObject *,QEvent *); 
};

#endif // DIALOG_FIND_H
