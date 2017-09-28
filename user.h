#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
public:
    User();
    User(const QString &id,const QString &username,const QString &password,const QString &alias,const QString &phone);
    QString id;
    QString username;
    QString password;
    QString alias;
    QString phone;
};

#endif // USER_H
