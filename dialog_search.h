#ifndef DIALOG_SEARCH_H
#define DIALOG_SEARCH_H

#include <QtGui/QDialog>
#include <QList>
#include <QString>
#include <QTreeWidgetItem>
#include <QCompleter>

namespace Ui {
    class SearchDialog;
}

class SearchDialog : public QDialog {
    Q_OBJECT
public:
    SearchDialog(QWidget *parent = 0);
    ~SearchDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SearchDialog *ui;
    QString m_szSearchKey;
    int m_nCurrentPage;
    int m_nSearchFlag;
    int m_nMaxPage;
    int m_nCountPerPage;
    QList<QTreeWidgetItem *> m_oDataList; 
    QStringList headers;
    QStringList sendingIdList;
    QCompleter *pCompleter;
    
    int nCount; //要发送的短信条数
    int nErrCount;
    int nDealCount;
    int nTotalSmsPromptFlag;
    
    void setBtnsStatus();
    int getMaxPage();
    void searchData();
    void showData(QList<QStringList> values);
    QString generateContent(const QString &id);

private slots:
    void editTextChanged(const QString &);
    void searchBtnClicked();
 
    void selectAllClicked();
    void selectRevertClicked();
    void sendSmsClicked();

    void firstPageClicked();
    void lastPageClicked();
    void previousPageClicked();
    void nextPageClicked();
    void itemDbClicked(QTreeWidgetItem *item,int column);
public slots:
    void smsSendCompleteSlot(int error,const QString &errMsg);
};

#endif // DIALOG_SEARCH_H
