#include "user.h"

User::User()
{
}

User::User(const QString &id,const QString &username,const QString &password,const QString &alias,const QString &phone)
{
    this->id = id;
    this->username = username;
    this->password = password;
    this->alias = alias;
    this->phone = phone;
}
