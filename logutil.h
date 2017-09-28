#ifndef LOGUTIL_H
#define LOGUTIL_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class LogUtil:public QObject
{
    Q_OBJECT
private:
    QString logSavedPath;
    QString logName;
    QString logName_error;
    QFile currentFile;
    QFile currentFile_error;
    unsigned int maxFileSize;
    
    LogUtil();
    static LogUtil *pObj;
public:
    enum TYPE{NORMAL,ERROR};
public:   
    static LogUtil *getInstance(); 
    void logInit(const QString &logSavedPath=QString("d:/log/"),unsigned int maxFileSize=10*1024*1024);
    void logWrite(LogUtil::TYPE,const QString &text);
private:
    void logWrite_normal(const QString &text);
    void logWrite_error(const QString &text);
private slots:
    void logClose();
};

#endif // LOGUTIL_H
