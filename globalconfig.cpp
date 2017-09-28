#include "globalconfig.h"
#include <QDomDocument>
#include <QFile>
#include <QDebug>

QMap<QString,QStringList> *GlobalConfig::pStaticEditNames = NULL;
GlobalConfig::GlobalConfig()
{
}

void GlobalConfig::loadNeccessaryConfiguration()
{
    loadEditNames();
}

int GlobalConfig::loadEditNames()
{
    if(pStaticEditNames)
        return 0;
    pStaticEditNames = new QMap<QString,QStringList>();
    
    QDomDocument doc;  
    QFile file(":/config/sms.xml");
    QString error = "";  
    int row = 0, column = 0;  
    if (!file.open(QIODevice::ReadOnly)) return -2;  
  
    if(!doc.setContent(&file, false, &error, &row, &column)){  
        qDebug() << "parse file failed:" << row << "---" << column <<":" <<error;  
        file.close();  
        return -1;  
    }  
    file.close();  
    
    QDomElement root = doc.documentElement(); 
    if(root.tagName() != "list")
        return -3;
    QDomNode node = root.firstChild();  
    while(!node.isNull()) {  //item loop
        QDomElement element = node.toElement(); // try to convert the node to an element.  
        if(element.tagName() == "item")
        {    
            QString objname,text,smstext;
            QDomNode tmpNode = element.firstChild(); 
            while(!tmpNode.isNull()){
                QDomElement tmpElement = tmpNode.toElement();
                if(tmpElement.tagName()=="objname")
                    objname = tmpElement.text();
                else if(tmpElement.tagName()=="text")
                    text = tmpElement.text();
                else if(tmpElement.tagName()=="smstext")
                    smstext = tmpElement.text();
                tmpNode = tmpNode.nextSibling();
            }
            pStaticEditNames->insert(objname,(QStringList() << text << smstext));
        }
        node = node.nextSibling();  
    }  
    return 0;  
}
