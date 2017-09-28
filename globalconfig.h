#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QStringList>

class GlobalConfig : public QObject
{
private:
    static int loadEditNames();
private:
    GlobalConfig();
public:
    static QMap<QString,QStringList> *pStaticEditNames;
    static void loadNeccessaryConfiguration();
};

#endif // GLOBALCONFIG_H
