#include "smsutil.h"
#include <QMessageBox>


SmsUtil *SmsUtil::pObj = NULL;
SmsUtil::SmsUtil(QWidget *pFromWidget)
{
    this->username = "cjbkwhy";
    this->password = "cjbkwhy123456";
    this->smsTpl = QString::fromLocal8Bit("本次检测结果如下：%1[%2]【陈家堡坤旺化验】");
    
    this->productNum = "1001";
    this->wsdlUrl = "http://115.29.52.221:24663/Service/?wsdl";
    //this->wsdlUrl = "http://115.29.52.221:24663/Service";
    this->actionUrl = "http://tempuri.org/I_Order/SubmitSms";
    this->ns = "http://tempuri.org/";
    this->error = 0;
    
    this->fromWidget = pFromWidget;
    
    pHttp = new QtSoapHttpTransport(this);
    connect(pHttp, SIGNAL(responseReady()), this, SLOT(onResponse()));
    connect(this,SIGNAL(smsSendComplete(int,const QString &)),fromWidget,SLOT(smsSendCompleteSlot(int,const QString &)));
}

//SmsUtil *SmsUtil::getInstance()
//{
//    if(pObj == NULL)
//        pObj = new SmsUtil();
//    return pObj;
//}

void SmsUtil::smsInit(const QString username,const QString password,QString smsTpl)
{
    this->username = username;
    this->password = password;
    this->smsTpl = smsTpl;
}

int SmsUtil::sendMsg(const QString &mobile,const QStringList &args)
{
    this->error = 0;
    QString content = smsTpl;
    for(int i=0;i<args.size();i++)
        content = content.arg((QString)args.value(i));
    
    // 设置动作    // 设置主机
    pHttp->setAction(actionUrl);
    pHttp->setHost("115.29.52.221",24663);

    // 设置方法及参数
    QtSoapMessage message;
    message.setMethod(QtSoapQName("SubmitSms",this->ns));
    message.addMethodArgument("username", this->ns, username);
    message.addMethodArgument("password", this->ns, password);
    message.addMethodArgument("mobileNum", this->ns, mobile);
    message.addMethodArgument("content", this->ns, content);
    message.addMethodArgument("productNum", this->ns, productNum);
    qDebug() << message.toXmlString();
    
    // 提交请求
    pHttp->submitRequest(message,wsdlUrl);
    return 0;
}

int SmsUtil::sendMsg(const QString &mobile,const QString &msg)
{
    this->error = 0;
    QString content = smsTpl.arg(msg);
    
    // 设置动作    // 设置主机
    pHttp->setAction(actionUrl);
    pHttp->setHost("115.29.52.221",24663);


    // 设置方法及参数
    QtSoapMessage message;
    message.setMethod(QtSoapQName("SubmitSms",this->ns));
    message.addMethodArgument("username", this->ns, username);
    message.addMethodArgument("password", this->ns, password);
    message.addMethodArgument("mobileNum", this->ns, mobile);
    message.addMethodArgument("content", this->ns, content);
    message.addMethodArgument("productNum", this->ns, productNum);
    qDebug() << message.toXmlString();
    
    // 提交请求
    pHttp->submitRequest(message,wsdlUrl);
    return 0;
}

void SmsUtil::onResponse()
{
    const QtSoapMessage &response = pHttp->getResponse();
    
    QDomDocument doc;  
    QString error = "";  
    int row = 0, column = 0;  
  
    if(!doc.setContent(response.toXmlString(), false, &error, &row, &column)){  
        qDebug() << "parse string failed:" << row << "---" << column <<":" <<error;  
        return;  
    }
    
    QDomElement root = doc.documentElement(); 
    QString result = root.firstChild().firstChild().firstChild().toElement().text();  
    qDebug() << response.toXmlString();
    qDebug() << result;
    setErrorStatus(result);
    emit smsSendComplete(this->error,this->errorMsg);
}
void SmsUtil::setErrorStatus(const QString &resText)
{
    QByteArray ba = resText.toLatin1();//QString 转换为 char*  
    const char *s = ba.data();  
    while(*s) 
    {
        char tmp = *s;
        if (tmp <'0' || tmp>'9')  
        {
            this->error = 1;
            this->errorMsg = resText;
            return;
        }
        s++;  
    }
    this->error = 0;
}
