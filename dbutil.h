#ifndef DBUTIL_H
#define DBUTIL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DBUtil:public QObject
{
    Q_OBJECT
private:
    static DBUtil *pObj;
    DBUtil();
public:
    static DBUtil *getInstance();
    QSqlDatabase dbInit(const QString &dbSavedPath="d:/",const QString &driver="QSQLITE",const QString &dbName="coal.db",
                      const QString &hostname="",int port=0,const QString &username="",const QString &password="");
    QSqlDatabase getConnection();
    
    bool insert(const QString &table, QStringList &names,QStringList &values);
    bool update(const QString &table, QStringList &names,QStringList &values, QString &expression);
    bool del(const QString &table, QString &expression);
    bool select(const QString &table,QStringList &names,QString &expression,QList<QStringList> &values);
    bool select_distinct(const QString &table,QStringList &names,QString &expression,QList<QStringList> &values);
    void getValues(const QString &table, QStringList &values);
    int getLastInsertId();
    bool beginTransaction();
    bool transactionCommit();
    bool transactionRollback();
   
public slots:
    void dbClose();
};

#endif // DBUTIL_H
