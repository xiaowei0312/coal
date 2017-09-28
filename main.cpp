#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QTextCodec>
#include "mainwindow.h"
#include "logutil.h"
#include "dbutil.h"
#include <QDebug>
#include "dialog_search.h"
#include "smsutil.h"
#include "globalconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
//    QDate now = QDate::currentDate();
//    QDate upDate(2017,10,30);
//    if(now >= upDate)
//        return -1;
    
    QObject::connect(&a,SIGNAL(aboutToQuit()),LogUtil::getInstance(),SLOT(logClose()));
    QObject::connect(&a,SIGNAL(aboutToQuit()),DBUtil::getInstance(),SLOT(dbClose()));
    
    GlobalConfig::loadNeccessaryConfiguration();
    LogUtil::getInstance()->logInit("./log/", 5*1024*1024);
    DBUtil::getInstance()->dbInit("./data/","QSQLITE","coal.db","",0,"","");
    
    MainWindow w;
//    w.move((QApplication::desktop()->width() - w.width())/2,
//           (QApplication::desktop()->height() - w.height())/2 );
    w.move((QApplication::desktop()->width() - w.width())/2,
          10);
    w.show();
//    
//    SmsUtil::getInstance()->sendMsg("18135100170",
//       QStringList() << "121" << "122" << "123.34" << "12314" << "121" << "13143" << "13134");
//    QString content = QString::fromLocal8Bit(
//            "检测结果：全水131.2000;检测结果：;"
//            );
//    (new SmsUtil(&w))->sendMsg("18135100160",content);
    
    return a.exec();
}
