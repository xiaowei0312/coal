#include "data_dependency.h"
#include <QStack>
#include <QDebug>
#include <QRegExpValidator>
#include <QMessageBox>

DataDependency::DataDependency()
{
    error = 0;
}

bool DataDependency::textIsNotNumber(QString &text)
{
    int pos = 0;
    QRegExpValidator numReg(QRegExp("^([1-9]\\d{0,15}|0)(\\.\\d{1,4})?$"),this);
    if(text.isNull() || text.trimmed().isEmpty())  //依赖项为空
        return true;
    if(numReg.validate(text,pos) != QValidator::Acceptable) //依赖项不是纯数字（或者小数）
        return true;
    return false;
}

bool DataDependency::depHasEmptyElement()
{
    QString text;
    for(int i=0;i<depList_final.size();i++)
    {
        text = depList_final[i]->text();
        if(textIsNotNumber(text))
            return true;
    }
    return false;
}

void DataDependency::markEmptyDepElement()
{
//    for(int i=0;i<depList.size();i++)
//    {
//        if(depList.value(i)->text().trimmed().isEmpty())
//        {
//            depList.value(i)->setStyleSheet("QLineEdit{border:1px solid green}");
//        }
//    }
    for(int i=0;i<depList.size();i++)
    {
        depList.value(i)->setStyleSheet("QLineEdit{border:1px solid green}");
    }
}

double DataDependency::__execFormula(char *szFormula)
{
    QStack<double> stack1;
    QStack<char> stack2;
    
    int status = 0;
    double dTmp = 0;    //数字
    double tmp = 10;       //小数计算因子，10,100-->1000
    int count = 0;
    QString text;
    char *szTmp;
    
    //qDebug() << szFormula;
    while(1){
        char c = *szFormula++;
        //qDebug() << c;
        if(c>='0' && c<='9'){
            if(status == 0){
                dTmp = 0;
                tmp = 10;
                status = 1; //计算数字
            }
            if(status == 1)
                dTmp = dTmp * 10 + (c - '0');
            else if(status == 2){
                dTmp = dTmp + (c-'0')/tmp;
                tmp *= 10;
            }
        }else if(c=='.'){
            if(status == 1)
                status = 2; //计算数字(小数点之后)
            else{
                QMessageBox::critical(NULL,QString::fromLocal8Bit("公式错误"),
                     QString::fromLocal8Bit("公式错误，出现不可预期的小数点"),QMessageBox::Ok);
                exit(-1);
            }
        }else{
            if(status != 0){ //数字处理完毕
                if(!stack2.empty()){    
                    switch(stack2.top()){
                    case '-':
                        dTmp *= -1;
                        stack2.pop();
                        stack2.push('+');
                        break;
                    case '*':
                        dTmp *= stack1.pop();
                        stack2.pop();
                        break;
                    case '/':
                        if(dTmp == 0){
                            error = 1;
                            return -1;
                        }
                        dTmp = stack1.pop() / dTmp;
                        stack2.pop();
                        break;
                    }
                }
                stack1.push(dTmp);
                status = 0;
            }
            
            if(c == 0)
                break;  //跳出循环
            
            switch(c){
            case ' ':
                continue;
            case '+':
            case '-':
            case '*':
            case '/':
                stack2.push(c);
                continue;
            case 'n':
                status = 2;
                c = *szFormula++;
                text = depList[c-'0'-1]->text();
                if(textIsNotNumber(text)){
                    //qDebug() << QString("Text[") + text + "]is Not number.";
                    error = 1;
                    return -1;
                }
                dTmp = text.toDouble();
                break;
            case '(':
                status = 2;
                szTmp = szFormula;
                count = 0;
                while(*szTmp && count!=1){
                    char t = *szTmp++;
                    if(t == '(')
                        count--;
                    else if(t == ')')
                        count++;
                }
                *(--szTmp) = 0;
                if((dTmp = __execFormula(szFormula))==-1){
                    if(error == 1){
                        return -1;
                    }
                }
                szFormula = szTmp + 1;
                break;
            default:
                QMessageBox::critical(NULL,QString::fromLocal8Bit("公式错误"),
                     QString::fromLocal8Bit("公式错误，出现不可预期字符:") + szFormula ,QMessageBox::Ok);
                exit(-1);
            }
        }
    }
    
    while(!stack2.empty())
    {
        stack1.push(stack1.pop() + stack1.pop());
        stack2.pop();
    }
    return stack1.pop();
}

double DataDependency::execFormula()
{
    error = 0;
    QByteArray ba = formula.toLatin1();
    char *szFormula = ba.data();
    return  __execFormula(szFormula);
}
