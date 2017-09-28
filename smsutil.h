#ifndef SMSUTIL_H
#define SMSUTIL_H

#include <QObject>
#include <qtsoap.h>

class SmsUtil:public QObject
{
    Q_OBJECT
private:
    QString username;
    QString password;
    QString productNum;
    QString wsdlUrl;
    QString actionUrl;
    QString ns;
    QString smsTpl;
    QtSoapHttpTransport *pHttp;
    static SmsUtil *pObj;
    QWidget *fromWidget;
    int error;
    QString errorMsg;
private:
    void setErrorStatus(const QString &resText);
public:
    SmsUtil(QWidget *pWidget);
    void smsInit(const QString username,const QString password,QString smsTpl);
    //static SmsUtil *getInstance();
    int sendMsg(const QString &mobile,const QStringList &args);
    int sendMsg(const QString &mobile,const QString &content);
private slots:
    void onResponse();
signals:
    void smsSendComplete(int error,const QString &);
};

#endif // SMSUTIL_H
