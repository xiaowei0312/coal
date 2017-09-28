/********************************************************************************
** Form generated from reading ui file 'dialog_login.ui'
**
** Created: Mon Sep 11 12:25:10 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOG_LOGIN_H
#define UI_DIALOG_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *pUsernameEdit;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *pPasswordEdit;
    QLabel *label_5;
    QPushButton *pLoginBtn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(372, 199);
        horizontalLayout_2 = new QHBoxLayout(LoginDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pUsernameEdit = new QLineEdit(LoginDialog);
        pUsernameEdit->setObjectName(QString::fromUtf8("pUsernameEdit"));

        horizontalLayout->addWidget(pUsernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        pPasswordEdit = new QLineEdit(LoginDialog);
        pPasswordEdit->setObjectName(QString::fromUtf8("pPasswordEdit"));
        pPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(pPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(LoginDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        pLoginBtn = new QPushButton(LoginDialog);
        pLoginBtn->setObjectName(QString::fromUtf8("pLoginBtn"));
        pLoginBtn->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pLoginBtn->setIcon(icon);

        verticalLayout->addWidget(pLoginBtn);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\351\224\201\345\256\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206  \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        pLoginBtn->setText(QApplication::translate("LoginDialog", "\350\247\243\351\224\201", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LoginDialog);
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_LOGIN_H
