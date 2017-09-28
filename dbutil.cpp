#include "dbutil.h"
#include <QMessageBox>
#include <QtCore>
#include "logutil.h"
#include <QDebug>

DBUtil *DBUtil::pObj = NULL;

DBUtil::DBUtil()
{
}

DBUtil *DBUtil::getInstance()
{
    if(pObj==NULL)
        pObj = new DBUtil();
    return pObj;
}

QSqlDatabase DBUtil::dbInit(const QString &dbSavedPath,const QString &driver,const QString &dbName,
            const QString &hostname,int port,const QString &username,const QString &password)
{
    int flag = 0;
    QDir dir(dbSavedPath),dirTmp;
    if(!dir.exists())
    {
        if(!dirTmp.mkpath(dbSavedPath))
        {
            QMessageBox::critical(NULL,QString::fromLocal8Bit("初始化数据库失败"),QString::fromLocal8Bit("无法创建必须的data目录"));
            qApp->quit();
        }
        flag = 1;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbSavedPath + "/" + dbName);
    db.setUserName(username);
    db.setPassword(password);
    db.setHostName(hostname);
    db.setPort(port);
    
    if(!db.isValid())
    {
          QMessageBox::critical(NULL,QString::fromLocal8Bit("错误"),
                QString::fromLocal8Bit("数据库初始化失败：请检查是否有相应的驱动程序,") + db.lastError().driverText());
            qApp->quit();  
    }
    
    if(flag)    //执行数据表初始化
    {
        QFile file(":/coal.sql");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::critical(NULL,QString::fromLocal8Bit("错误"),
                QString::fromLocal8Bit("打开文件失败: 读取初始化表结构(coal.sql)失败"));
            qApp->quit();
        }
        
        //读取文件内容
        QTextStream in(&file);
        QString sqls,line;
        while(1){
            line = in.readLine();
            if(line.isNull())
                break;
            sqls += line;
        }
        QStringList sqlList = sqls.split(";");
        
        QSqlQuery query(getConnection());
        for(int i=0;i<sqlList.size();i++)
        {
            QString sql = sqlList.value(i);
            if(sql.isNull() || sql.trimmed().isEmpty())
                continue;
            if(!query.exec(sql))
            {
                 LogUtil::getInstance()->logWrite(LogUtil::ERROR,query.lastError().databaseText() + " [" + sql + "]");
                 QMessageBox::critical(NULL,QString::fromLocal8Bit("错误"),
                    QString::fromLocal8Bit("初始化表结构失败: ") + db.lastError().databaseText());
                 qApp->quit();
            }else
            {
                LogUtil::getInstance()->logWrite(LogUtil::NORMAL,sql);
            }
        }
    }
    return db;
}

QSqlDatabase DBUtil::getConnection()
{
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isValid())
        db = dbInit();
    if(!db.isOpen())
        db.open();
    
    if(!db.isOpen())
    {
        QMessageBox::critical(NULL,
            QString::fromLocal8Bit("系统错误"),
            QString::fromLocal8Bit("无法打开数据库，系统异常退出"));
        LogUtil::getInstance()->logWrite(LogUtil::ERROR,
            QString::fromLocal8Bit("无法打开数据库，系统异常退出:") + db.lastError().databaseText());
        qApp->quit();
    }
    return db;
}

/*
    插入函数.
    构造SQL插入语句.
*/
bool DBUtil::insert(const QString &table, QStringList &names, QStringList &values)
{
    if (names.size() != values.size())
        return false;
 
    QSqlQuery query(getConnection());
    QString sql = QString("insert into ") + table + QString("(");
 
    for (int i=0; i < names.size(); i++)
    {
        sql = sql + names.value(i);
        if (i != names.size() - 1)
            sql+=QString(",");
        else
            sql = sql + QString(")");
    }
    sql = sql + QString("values (");
 
    for (int i = 0; i < values.size(); i++)
    {
        if(values.value(i) == NULL)
            sql += "null";
        else
            sql += QString("'") + QString(values.value(i)).trimmed() + QString("'");
        if (i != values.size()-1)
            sql += QString(",");
    }
    sql = sql + QString(")");
 
    //qDebug() << sql;
    if (query.exec(sql))
    {
        LogUtil::getInstance()->logWrite(LogUtil::NORMAL,sql);
        return true;
    }
    else
    {
        LogUtil::getInstance()->logWrite(LogUtil::ERROR,query.lastError().databaseText() + " [" + sql + "]");
        return false;
    }
}
 
/*
    修改函数.
    构造SQL修改语句.
*/
bool DBUtil::update(const QString &table, QStringList &names, QStringList &values, QString &expression)
{
    if (names.size() != values.size())
        return false;
 
    //UPDATE 表名称 SET 列名称 = 新值 WHERE 列名称 = 某值
    QSqlQuery query(getConnection());
    QString sql = QString("update ")+table+QString(" set ");
    for (int i = 0; i < names.size(); i++)
    {
        sql = sql + names.value(i);
        sql = sql + QString(" = '");
        sql = sql + QString(values.value(i)).trimmed();
        sql = sql + QString("'");
        if (i != names.size()-1)
            sql = sql + QString(" ,");
    }
 
    sql = sql + QString(" where ") + expression;
    
    //qDebug() << sql;
    if (query.exec(sql))
    {
        LogUtil::getInstance()->logWrite(LogUtil::NORMAL,sql);
        return true;
    }
    else
    {
        LogUtil::getInstance()->logWrite(LogUtil::ERROR,query.lastError().databaseText() + " [" + sql + "]");
        return false;
    }
}

/*
    删除函数.
    构造SQL删除语句.
*/
bool DBUtil::del(const QString &table, QString &expression)
{
    //DELETE FROM 表名称 WHERE 列名称 = 值
    QSqlQuery query(getConnection());
    QString sql = QString("delete from ") + table + QString(" where ") + expression;
 
    if (query.exec(sql))
        return true;
    else
        return false;
}

bool DBUtil::select(const QString &table,QStringList &names,QString &expression,QList<QStringList> &values)
{
    //DELETE FROM 表名称 WHERE 列名称 = 值
    QSqlQuery query(getConnection());
    
    QString sql = QString("select ");
    for (int i = 0; i < names.size(); i++)
    {
        sql = sql + names.value(i);
        if (i != names.size()-1)
            sql = sql + QString(" ,");
    }
    
    sql += (" from " + table + QString(" where ") + expression);
    
    //qDebug() << sql;
    if (!query.exec(sql))
        return false;
 
    while (query.next())
    {
        QStringList list;
        for (int i = 0; i < names.size(); i++)
            list << query.value(i).toString();
        values << list;
    }
    return true;
}
bool DBUtil::select_distinct(const QString &table,QStringList &names,QString &expression,QList<QStringList> &values)
{
    //DELETE FROM 表名称 WHERE 列名称 = 值
    QSqlQuery query(getConnection());
    
    QString sql = QString("select distinct(");
    for (int i = 0; i < names.size(); i++)
    {
        sql = sql + names.value(i);
        if (i != names.size()-1)
            sql = sql + QString(" ,");
    }
    
    sql += (") from " + table + QString(" where ") + expression);
    
    //qDebug() << sql;
    if (!query.exec(sql))
        return false;
 
    while (query.next())
    {
        QStringList list;
        for (int i = 0; i < names.size(); i++)
            list << query.value(i).toString();
        values << list;
    }
    return true;
}
 
void DBUtil::getValues(const QString &table, QStringList &values)
{
    QSqlQuery query(getConnection());
    QString sql = QString("select * from ") + table;
    query.exec(sql);
    while (query.next())
        values << query.value(0).toString();
}

int DBUtil::getLastInsertId()
{
    QSqlQuery query(getConnection());
    QString sql = "select last_insert_rowid()";
    query.exec(sql);
    query.next();
    return query.value(0).toInt();
}


void DBUtil::dbClose()
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.isOpen())
        db.close();
    if(db.isValid())
        db.removeDatabase("QSQLITE");
}

bool DBUtil::beginTransaction()
{
    return QSqlDatabase::database().transaction();
}

bool DBUtil::transactionCommit()
{
    return QSqlDatabase::database().commit();
}

bool DBUtil::transactionRollback()
{
    return QSqlDatabase::database().rollback();
}

