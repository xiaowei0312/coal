#include "logutil.h"
#include <QDate>
#include <QMessageBox>
#include <QDir>

LogUtil *LogUtil::pObj = NULL;
LogUtil::LogUtil()
{ 
    
}

LogUtil *LogUtil::getInstance()
{
    if(!pObj)
        pObj = new LogUtil();
    return pObj;
}

void LogUtil::logInit(const QString &logSavedPath,unsigned int maxFileSize)
{
    QDir dir(logSavedPath),dirTmp;
    if(!dir.exists())
        dirTmp.mkpath(logSavedPath);
    
    QDate today = QDate::currentDate();
    this->logSavedPath = logSavedPath;
    this->maxFileSize = maxFileSize;
    this->logName = (logSavedPath + "/" + "%1-%2-%3.log")
        .arg(today.year(),4,10,QLatin1Char('0'))
        .arg(today.month(),2,10,QLatin1Char('0'))
        .arg(today.day(),2,10,QLatin1Char('0'));
    currentFile.setFileName(logName);
    
    this->logName_error = (logSavedPath + "/" + "error-%1-%2-%3.log")
        .arg(today.year(),4,10,QLatin1Char('0'))
        .arg(today.month(),2,10,QLatin1Char('0'))
        .arg(today.day(),2,10,QLatin1Char('0'));
    currentFile_error.setFileName(logName_error);
}

void LogUtil::logWrite_normal(const QString &text)
{
    QDateTime now = QDateTime::currentDateTime();
    QDate today = now.date();
    QTime time = now.time();
    
    //判断文件大小是否超过上限
    if(currentFile.exists() && currentFile.size() > maxFileSize)
    {
        //关闭之前的文件
        currentFile.close();
        
        //创建新文件
        this->logName = (logSavedPath + "/" + "%1-%2-%3.log")
            .arg(today.year(),4,10,QLatin1Char('0'))
            .arg(today.month(),2,10,QLatin1Char('0'))
            .arg(today.day(),2,10,QLatin1Char('0'));
        currentFile.setFileName(this->logName);
        for(int i=0;!currentFile.exists();i++)
        {
            this->logName += ("_" + i);
            currentFile.setFileName(this->logName);
            if(i==5)    //Something errors.
                break;
        }
    }
    
    //判断文件是否打开
    if(!currentFile.isOpen())
    {
        if (!currentFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),
                QString::fromLocal8Bit("日志文件[") + this->logName + QString::fromLocal8Bit("]打开出错"));
            return;
        }
    }
    
    //写入文件
    QTextStream out(&currentFile);
    QString logText = QString("[%1-%2-%3 %4:%5:%6] %7")
        .arg(today.year(),4,10,QLatin1Char('0'))
        .arg(today.month(),2,10,QLatin1Char('0'))
        .arg(today.day(),2,10,QLatin1Char('0'))
        .arg(time.hour(),2,10,QLatin1Char('0'))
        .arg(time.minute(),2,10,QLatin1Char('0'))
        .arg(time.second(),2,10,QLatin1Char('0'))
        .arg(text);
    out << logText << "\n";
}

void LogUtil::logWrite_error(const QString &text)
{
    QDateTime now = QDateTime::currentDateTime();
    QDate today = now.date();
    QTime time = now.time();
    
    //判断文件大小是否超过上限
    if(currentFile_error.exists() && currentFile_error.size() > maxFileSize)
    {
        //关闭之前的文件
        currentFile_error.close();
        
        //创建新文件
        this->logName_error = (logSavedPath + "/" + "error-%1-%2-%3.log")
            .arg(today.year(),4,10,QLatin1Char('0'))
            .arg(today.month(),2,10,QLatin1Char('0'))
            .arg(today.day(),2,10,QLatin1Char('0'));
        currentFile_error.setFileName(this->logName_error);
        for(int i=0;!currentFile_error.exists();i++)
        {
            this->logName += ("_" + i);
            currentFile_error.setFileName(this->logName_error);
            if(i==5)    //Something errors.
                break;
        }
    }
    
    //判断文件是否打开
    if(!currentFile_error.isOpen())
    {
        if (!currentFile_error.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),
                QString::fromLocal8Bit("日志文件[") + this->logName_error + QString::fromLocal8Bit("]打开出错"));
            return;
        }
    }
    
    //写入文件
    QTextStream out(&currentFile);
     QString logText = QString("[%1-%2-%3 %4:%5:%6] %7")
        .arg(today.year(),4,10,QLatin1Char('0'))
        .arg(today.month(),2,10,QLatin1Char('0'))
        .arg(today.day(),2,10,QLatin1Char('0'))
        .arg(time.hour(),2,10,QLatin1Char('0'))
        .arg(time.minute(),2,10,QLatin1Char('0'))
        .arg(time.second(),2,10,QLatin1Char('0'))
        .arg(text);
    out << logText << "\n";
}

void LogUtil::logWrite(LogUtil::TYPE type,const QString &text)
{
    switch(type)
    {
    case LogUtil::NORMAL:
        logWrite_normal(text);
        break;
    case LogUtil::ERROR:
        logWrite_error(text);
        break;
    default:
        break;
    }
}

void LogUtil::logClose()
{
    //关闭文件
    currentFile.close();
    currentFile_error.close();
}
