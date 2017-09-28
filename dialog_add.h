#ifndef DIALOG_ADD_H
#define DIALOG_ADD_H

#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QSignalMapper>
#include <QMutex>
#include "data_dependency.h"

namespace Ui
{
    class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = 0);
    ~AddDialog();
    void closeEvent ( QCloseEvent * event );

private:
     QMutex mutex;
    Ui::AddDialog *ui;
    QSignalMapper *signalMapper;
    bool needSave;
    bool isMarked;
    QList<QLineEdit*> editList1,editList2;
    QList<QCheckBox*> checkList;
    QStringList colNameList,colValList,colNameList_print;
    QList<DataDependency*> dataDepList;
    
    QCompleter *pCompleter;

private:
    bool saveData(int *id);
    bool updateData(const QString &id);
    bool printData(const QString &id);
    bool saveOrUpdateData(int *id);
    void editListInit();
    void checkListInit();
    void colListInit();
    void updateNeedSave(bool flag);
    void addMarks();
    void addMark(QLineEdit *pLineEdit);
    void clearMarks();
    void clearMark(QLineEdit *pLinEdit);
    void generateData(QLineEdit *pLinEdit);
    int generateDependencies();
    int generateFinalDependencies();
    void getFinalDepList(QLineEdit *pLineEdit,QList<QLineEdit *>&finalDepList);
    void addEventFilter();
    
    int getEditIndex(QLineEdit *pLineEdit);

private slots:
    void btn_save_next_clicked();
    void btn_add_clicked(bool successPrompt = true);
    void btn_print_clicked();
    void btn_exit_clicked();
    void edit_text_changed(const QString &text);
    void check_state_changed(int);
    void edit_text_changed_mapper(int i);
    void printPreview(QPrinter*);
public slots:
     bool eventFilter(QObject *,QEvent *); 
};
#endif // DIALOG_ADD_H
