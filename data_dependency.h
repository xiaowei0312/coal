#ifndef DATA_DEPENDENCY_H
#define DATA_DEPENDENCY_H

#include <QObject>
#include <QLineEdit>
#include <QString>
#include <QList>

class DataDependency : public QObject
{
private: 
    double __execFormula(char *szFormula);
public:
    QLineEdit *pTarget;
    QList<QLineEdit *> depList, depList_final;
    QString formula;
    int error;
public:
    DataDependency();
    bool depHasEmptyElement();
    void markEmptyDepElement();
    double execFormula();
    bool textIsNotNumber(QString &text);
};

#endif // DATA_DEPENDENCY_H
