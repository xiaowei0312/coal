#include "dialog_search.h"
#include "ui_dialog_search.h"
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include <QDate>
#include "dbutil.h"
#include "smsutil.h"
#include "dialog_find.h"
#include "globalconfig.h"
#include "mainwindow.h"
#include "user.h"
#include <QtGui>

SearchDialog::SearchDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::SearchDialog)
{
    nTotalSmsPromptFlag = 0;    //Ĭ�ϲ��������Ż�����ʾ(�ܹ�����%1�����ɹ�%2����ʧ��%3��)
    ui->setupUi(this);
    ui->m_pTreeWidget->clear();
    ui->m_pTreeWidget->setColumnWidth(4,150);
    
    ui->m_pSearchLineEdit->setValidator(new QRegExpValidator(
                        QRegExp("^\\d{1,11}$"),this));
    
    m_nSearchFlag = 0;
    m_nCurrentPage = 1;
    m_nMaxPage = 1;
    m_nCountPerPage = 15;
    setBtnsStatus();
    
    headers 
        << QString::fromLocal8Bit("ȫˮ") 
        << QString::fromLocal8Bit("��")
        << QString::fromLocal8Bit("�ӷ�")
        << QString::fromLocal8Bit("�Ϳ�")
        << QString::fromLocal8Bit("�߿�")
        << QString::fromLocal8Bit("��")
        << QString::fromLocal8Bit("����");
    
    connect(ui->m_pSearchLineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(editTextChanged(const QString &)));
    connect(ui->m_pSearchBtn,SIGNAL(clicked()),this,SLOT(searchBtnClicked()));
    
    connect(ui->m_pSelectAllBtn,SIGNAL(clicked()),this,SLOT(selectAllClicked()));
    connect(ui->m_pSelectRevertBtn,SIGNAL(clicked()),this,SLOT(selectRevertClicked()));
    connect(ui->m_pSendSmsBtn,SIGNAL(clicked()),this,SLOT(sendSmsClicked()));
    
    connect(ui->m_pFirstPageBtn,SIGNAL(clicked()),this,SLOT(firstPageClicked()));
    connect(ui->m_pLastPageBtn,SIGNAL(clicked()),this,SLOT(lastPageClicked()));
    connect(ui->m_pPreviousPageBtn,SIGNAL(clicked()),this,SLOT(previousPageClicked()));
    connect(ui->m_pNextPageBtn,SIGNAL(clicked()),this,SLOT(nextPageClicked()));
    connect(ui->m_pTreeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem *,int)),this,SLOT(itemDbClicked(QTreeWidgetItem *,int)));
}

SearchDialog::~SearchDialog()
{
    delete ui;
}


void SearchDialog::changeEvent(QEvent *e)
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

void SearchDialog::setBtnsStatus()
{
    ui->m_pFirstPageBtn->setEnabled(true);
    ui->m_pLastPageBtn->setEnabled(true);
    ui->m_pNextPageBtn->setEnabled(true);
    ui->m_pPreviousPageBtn->setEnabled(true);
    ui->m_pSearchBtn->setEnabled(true);
    ui->m_pSelectAllBtn->setEnabled(true);
    ui->m_pSelectRevertBtn->setEnabled(true);
    ui->m_pSendSmsBtn->setEnabled(true);
    
    if(m_nSearchFlag == 0)    //δ��ʼ
    {
        ui->m_pFirstPageBtn->setEnabled(false);
        ui->m_pLastPageBtn->setEnabled(false);
        ui->m_pNextPageBtn->setEnabled(false);
        ui->m_pPreviousPageBtn->setEnabled(false);
        ui->m_pSearchBtn->setEnabled(false);
        ui->m_pSelectAllBtn->setEnabled(false);
        ui->m_pSelectRevertBtn->setEnabled(false);
        ui->m_pSendSmsBtn->setEnabled(false);
    }
    if(m_nCurrentPage==1)
    {
        ui->m_pPreviousPageBtn->setEnabled(false);
        ui->m_pFirstPageBtn->setEnabled(false);
    }
    if(m_nCurrentPage==m_nMaxPage)
    {
        ui->m_pNextPageBtn->setEnabled(false);
        ui->m_pLastPageBtn->setEnabled(false);
    }
    
    if(m_oDataList.size()==0)
    {
        ui->m_pSelectAllBtn->setEnabled(false);
        ui->m_pSelectRevertBtn->setEnabled(false);
        ui->m_pSendSmsBtn->setEnabled(false);
    }
}

void SearchDialog::editTextChanged(const QString &text)
{
    if(!text.trimmed().isEmpty())
        ui->m_pSearchBtn->setEnabled(true);
    else
        ui->m_pSearchBtn->setEnabled(false);
    
    if(text.isNull() || text.trimmed().size() != 4)
        return;
    QStringList names;
    QList<QStringList> values;
    names << "data_303";
    QString expressions = QString("data_303 like '\%%1\%'").arg(text);
    expressions += " order by add_time desc";
    expressions += " limit 0,10";

    if(!DBUtil::getInstance()->select_distinct("t_coal_detection",names,expressions,values))
        return;
    if(values.size()==0)
        return;
    QStringList compList;
    for(int i=0;i<values.size();i++)
        compList << values.value(i).value(0);
    
    pCompleter = new QCompleter(compList,this);
    pCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->m_pSearchLineEdit->setCompleter(pCompleter);
}

void SearchDialog::showData(QList<QStringList> values)
{
    ui->m_pTreeWidget->clear();
    this->m_oDataList.clear();
    
    for(int i=0;i<values.size();i++)
    {
        QStringList current = values.value(i);
        QString smsFlag = current.value(5),szSmsFlag;
        current.pop_back();
        switch(smsFlag.toInt())
        {
        case 0:
            szSmsFlag = QString::fromLocal8Bit("δ����");
            break;
        case 1:
            szSmsFlag = QString::fromLocal8Bit("�ѷ���");
            break;
        default:
            szSmsFlag = QString::fromLocal8Bit("����ʧ��");
            break;
        }
        current.push_back(szSmsFlag);
       
        QTreeWidgetItem *pItem = new QTreeWidgetItem(current);
        //������ʱ��Ϊ���죬��ѡ�У�����ѡ
//        QString szAddTime = current.value(5);
//        QStringList szTmp = szAddTime.split(" ");
//        QStringList addTimeSplit = szTmp[0].split("-");
//        QDate today = QDate::currentDate();
//        
//        if((today.year() == addTimeSplit[0].toInt()) 
//            && (today.month()==addTimeSplit[1].toInt())
//            && (today.day() == addTimeSplit[2].toInt()))
//            pItem->setCheckState(0,Qt::Checked);     
//        else
//            pItem->setCheckState(0,Qt::Unchecked);
//        
        pItem->setCheckState(0,Qt::Unchecked);
        m_oDataList << pItem;
        ui->m_pTreeWidget->addTopLevelItem(pItem);
    }
    ui->m_pPageLabel->setText(QString::fromLocal8Bit("��%1ҳ / ��%2ҳ").arg(m_nCurrentPage).arg(m_nMaxPage));
}

void SearchDialog::searchData()
{
    QStringList names;
    QList<QStringList> values;
    QString expressions = "(id = '%1' or data_303 = '%2') and is_deleted = 0";
    expressions += " order by add_time desc";
    expressions += " limit %3,%4";
    
    names << "id" << "data_303" << "data_305" << "data_301" << "add_time" << "sms_flag";
    expressions = expressions.arg(m_szSearchKey).arg(m_szSearchKey)
            .arg((m_nCurrentPage-1) * m_nCountPerPage)
            .arg(m_nCountPerPage);
    
    if(!DBUtil::getInstance()->select("t_coal_detection",names,expressions,values))
    {
        QMessageBox:: critical(this,QString::fromLocal8Bit("����ʧ��"),
            QString::fromLocal8Bit("����ʧ�ܣ����������ַ�����ʽ�Ƿ���ȷ"));
        return;
    }
    if(values.size()==0)
    {
        QMessageBox:: critical(this,QString::fromLocal8Bit("����ʧ��"),
            QString::fromLocal8Bit("û���ҵ���Ӧ����"));
        return;
    }
    
    showData(values);
    setBtnsStatus();
}

int SearchDialog::getMaxPage()
{
    QStringList names;
    QList<QStringList> values;
    QString expressions("(id = '%1' or data_303 = '%2') and is_deleted = 0");
    
    names << "count(*)";
    expressions = expressions.arg(m_szSearchKey).arg(m_szSearchKey);
    
    if(!DBUtil::getInstance()->select("t_coal_detection",names,expressions,values))
    {
        QMessageBox:: critical(this,QString::fromLocal8Bit("����ʧ��"),
                               QString::fromLocal8Bit("����ʧ�ܣ����������ַ�����ʽ�Ƿ���ȷ"));
        return 0;
    }
    int totalCount = ((QString)values.value(0).value(0)).toInt();
    return (totalCount - 1) / m_nCountPerPage + 1;
}

void SearchDialog::searchBtnClicked()
{
    QString key = ui->m_pSearchLineEdit->text();
    if(key.trimmed().isEmpty())
        return;
    
    this->m_nSearchFlag = 1;
    this->m_nCurrentPage = 1;
    this->m_szSearchKey = key;

    this->m_nMaxPage = getMaxPage();
    searchData();
}

void SearchDialog::firstPageClicked()
{
    this->m_nCurrentPage = 1;
    searchData();
}
void SearchDialog::lastPageClicked()
{
    this->m_nCurrentPage = this->m_nMaxPage;
    searchData();
}
void SearchDialog::previousPageClicked()
{
    m_nCurrentPage--;
    if(m_nCurrentPage<1)
        m_nCurrentPage = 1;
    searchData();
}
void SearchDialog::nextPageClicked()
{
    m_nCurrentPage++;
    if(m_nCurrentPage > m_nMaxPage)
        m_nCurrentPage = m_nMaxPage;
    searchData();
}

void SearchDialog::itemDbClicked(QTreeWidgetItem *item,int column)
{
    FindDialog *pFindDialog = new FindDialog(this);
    pFindDialog->move((qApp->desktop()->width() - pFindDialog->width())/2,95);
    pFindDialog->showDataById(item->text(0));
    pFindDialog->show();
}

void  SearchDialog::selectAllClicked()
{
    for(int i=0;i<m_oDataList.size();i++)
        m_oDataList.value(i)->setCheckState(0,Qt::Checked);
    ui->m_pTreeWidget->repaint();
}
void  SearchDialog::selectRevertClicked()
{
    for(int i=0;i<m_oDataList.size();i++)
    {
        QTreeWidgetItem *pTmp = m_oDataList.value(i);
        if(pTmp->checkState(0))
            pTmp->setCheckState(0,Qt::Unchecked);
        else
            pTmp->setCheckState(0,Qt::Checked);
    }
}
void  SearchDialog::sendSmsClicked()
{
    int size = 0;
    sendingIdList.clear();
    QString mobile = "";
    
    //�ж��Ƿ���ú���ֶΣ�û��ú���ֶβ�������
    //����Ҫ���͵Ķ�������
    for(int i=0;i<m_oDataList.size();i++)
    {
        QTreeWidgetItem *pTmp = m_oDataList.value(i);
        if(!pTmp->checkState(0))
            continue;
        if(pTmp->text(2).isEmpty())
        {
            pTmp->setText(2,QString::fromLocal8Bit("��ú"));
            //pTmp->setSelected(true);
            //QMessageBox::information(this,QString::fromLocal8Bit("���ݲ�����"),QString::fromLocal8Bit("ѡ�е�����ȱ�ٱ���ġ�ú�֡��ֶΣ��벹ȫ�����·���"));
            //return;
        }
        size++;
        mobile = pTmp->text(1);
        sendingIdList << pTmp->text(0); //��id�������ڷ��Ͷ����б�
    }
    if(size==0)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ���κ�����"));
        return;
    }
    this->nTotalSmsPromptFlag = 1;  //�������Ż�����ʾ
    this->nCount = 1;   //�ϲ�����
    this->nErrCount = 0;
    this->nDealCount = 0;
    
     
    //�ж�Ҫ���͵ĵ绰����
    if(mobile.isNull() || mobile.trimmed().isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("���ŷ����쳣"),QString::fromLocal8Bit("�Ҳ���Ҫ���͵��ֻ�����"));
        return;
    }
    QStringList mobileList = mobile.split(QRegExp("[; ]"));
   
    //ѭ�����ɶ�������
    QString smsContent;
    QString splitStr1 = "                                                                        ";
    QString splitStr2 = "===============";
    splitStr1 = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    //splitStr2 = "\t\t\t\t\t";
    //smsContent += splitStr1;
    //for(int i=0;i<m_oDataList.size();i++)
    for(int i=m_oDataList.size()-1;i>=0;i--)
    {
        QTreeWidgetItem *pTmp = m_oDataList.value(i);
        if(!pTmp->checkState(0))
            continue;
        smsContent += splitStr1;
        smsContent += pTmp->text(2) + ":";
        smsContent += generateContent(pTmp->text(0));//id ú��
        smsContent += splitStr1;
        smsContent += splitStr2;
    }
    smsContent = smsContent.left(smsContent.length()-splitStr2.length());
    
    //���Ͷ���
    QString phone = ((MainWindow*)this->parent())->currentUser->phone;
    QStringList smsContentList;
    smsContentList << smsContent << phone;
    for(int i=0;i<mobileList.size();i++)
        (new SmsUtil(this))->sendMsg((QString)mobileList.value(i),smsContentList);
}

QString SearchDialog::generateContent(const QString &id)
{
    if(id.isNull() || id.trimmed().isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("���ŷ����쳣"),QString::fromLocal8Bit("�Ҳ���Ҫ���͵�����id"));
        return 0;
    }
    
    //��ȡnames
    QStringList smsNames;
    QList<QStringList> smsValues;
    QString smsExpressions("coal_detection_id = %1");
    smsNames << "objnames";
    smsExpressions = smsExpressions.arg(id);
    if(!DBUtil::getInstance()->select("t_coal_sms",smsNames,smsExpressions,smsValues))
    {
        QMessageBox::information(this,QString::fromLocal8Bit("db select error"),QString::fromLocal8Bit("����ʧ�ܣ����ϵͳ��־"));
        return 0;
    }
    if(smsValues.size()==0)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("���ŷ����쳣"),QString::fromLocal8Bit("û���ҵ����ݶ�Ӧ�Ķ����ֶ��б�(t_coal_sms)"));
        return 0;
    }
    QString cols = smsValues.value(0).value(0);
    cols = cols.replace("checkBox","data");
    
    //��ȡ���
    QStringList names;
    QList<QStringList> values;
    QString expressions("id = %1 and is_deleted = 0");
    //names << "data_200" << "data_201" << "data_202" << "data_203" << "data_213" << "data_223" << "data_224";
    names = cols.split(" ");
    expressions = expressions.arg(id);
    if(!DBUtil::getInstance()->select("t_coal_detection",names,expressions,values))
    {
        QMessageBox::information(this,QString::fromLocal8Bit("db select error"),QString::fromLocal8Bit("����ʧ�ܣ����ϵͳ��־"));
        return 0;
    }
    
    QStringList strs = values.value(0);
    QString finalMsg;
    
    for(int i=0;i<strs.size();i++)
    {
        QString tmp = (QString)strs.value(i);
        if(tmp.isNull() || tmp.trimmed().isEmpty())
            continue;
        finalMsg += (QString)(GlobalConfig::pStaticEditNames->value((QString)names.value(i))).value(1)+ strs[i];
    }
    return finalMsg;
}

void SearchDialog::smsSendCompleteSlot(int error,const QString &errMsg)
{
    QStringList names,values;
    QString expressions;
    names << "sms_flag";
    QString smsFlag = "1";
    smsFlag = "1";
     
    if(error)
    {
        QMessageBox::information(this,QString::fromLocal8Bit("���ŷ���ʧ��"),errMsg);
        this->nErrCount++;
        smsFlag = "2";
    }
    values << smsFlag;
    expressions = "id in (";
    for(int i=0,len=sendingIdList.size();i<len;i++)
    {
        expressions += sendingIdList.value(i);
        if(i!=len-1)
            expressions += ",";
    }
    expressions += ")";
    
    if(!DBUtil::getInstance()->update("t_coal_detection",names,values,expressions))
        QMessageBox::information(this,QString::fromLocal8Bit("���ݿ����ʧ��"),QString::fromLocal8Bit("���ݿ����ʧ��"));
    
    if(!this->nTotalSmsPromptFlag)
        return;
    if(++(this->nDealCount) == this->nCount)
    {
        QString res = QString::fromLocal8Bit("�����͡�%1�������ɹ���%2������ʧ�ܡ�%3����")
            .arg(this->nCount)
            .arg(this->nCount - this->nErrCount)
            .arg(this->nErrCount);
        QMessageBox::information(this,QString::fromLocal8Bit("�������"),res);
        searchData();
    }
    
        
}
