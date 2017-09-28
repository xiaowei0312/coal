/********************************************************************************
** Form generated from reading ui file 'dialog_setting.ui'
**
** Created: Mon Sep 11 17:57:45 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOG_SETTING_H
#define UI_DIALOG_SETTING_H

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
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *pChangeBasicTab;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *pUsernameEdit;
    QLineEdit *pAliasEdit;
    QLineEdit *pPhoneEdit;
    QPushButton *pChangeBasicBtn;
    QWidget *pChangePwdTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pUsernameEditReadOnly;
    QLineEdit *pOldPwdEdit;
    QLineEdit *pNewPwdEdit;
    QLineEdit *pRePwdEdit;
    QPushButton *pSettingBtn;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QString::fromUtf8("SettingDialog"));
        SettingDialog->resize(374, 272);
        horizontalLayout_3 = new QHBoxLayout(SettingDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tabWidget = new QTabWidget(SettingDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        pChangeBasicTab = new QWidget();
        pChangeBasicTab->setObjectName(QString::fromUtf8("pChangeBasicTab"));
        verticalLayout_6 = new QVBoxLayout(pChangeBasicTab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(pChangeBasicTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(pChangeBasicTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(pChangeBasicTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pUsernameEdit = new QLineEdit(pChangeBasicTab);
        pUsernameEdit->setObjectName(QString::fromUtf8("pUsernameEdit"));

        verticalLayout_5->addWidget(pUsernameEdit);

        pAliasEdit = new QLineEdit(pChangeBasicTab);
        pAliasEdit->setObjectName(QString::fromUtf8("pAliasEdit"));

        verticalLayout_5->addWidget(pAliasEdit);

        pPhoneEdit = new QLineEdit(pChangeBasicTab);
        pPhoneEdit->setObjectName(QString::fromUtf8("pPhoneEdit"));

        verticalLayout_5->addWidget(pPhoneEdit);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        pChangeBasicBtn = new QPushButton(pChangeBasicTab);
        pChangeBasicBtn->setObjectName(QString::fromUtf8("pChangeBasicBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pChangeBasicBtn->setIcon(icon);

        verticalLayout_6->addWidget(pChangeBasicBtn);

        tabWidget->addTab(pChangeBasicTab, QString());
        pChangePwdTab = new QWidget();
        pChangePwdTab->setObjectName(QString::fromUtf8("pChangePwdTab"));
        verticalLayout_3 = new QVBoxLayout(pChangePwdTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(pChangePwdTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label = new QLabel(pChangePwdTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        label_3 = new QLabel(pChangePwdTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(pChangePwdTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pUsernameEditReadOnly = new QLineEdit(pChangePwdTab);
        pUsernameEditReadOnly->setObjectName(QString::fromUtf8("pUsernameEditReadOnly"));
        pUsernameEditReadOnly->setEnabled(false);
        pUsernameEditReadOnly->setReadOnly(true);

        verticalLayout_2->addWidget(pUsernameEditReadOnly);

        pOldPwdEdit = new QLineEdit(pChangePwdTab);
        pOldPwdEdit->setObjectName(QString::fromUtf8("pOldPwdEdit"));
        pOldPwdEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pOldPwdEdit);

        pNewPwdEdit = new QLineEdit(pChangePwdTab);
        pNewPwdEdit->setObjectName(QString::fromUtf8("pNewPwdEdit"));
        pNewPwdEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pNewPwdEdit);

        pRePwdEdit = new QLineEdit(pChangePwdTab);
        pRePwdEdit->setObjectName(QString::fromUtf8("pRePwdEdit"));
        pRePwdEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pRePwdEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        pSettingBtn = new QPushButton(pChangePwdTab);
        pSettingBtn->setObjectName(QString::fromUtf8("pSettingBtn"));
        pSettingBtn->setIcon(icon);

        verticalLayout_3->addWidget(pSettingBtn);

        tabWidget->addTab(pChangePwdTab, QString());

        horizontalLayout_3->addWidget(tabWidget);


        retranslateUi(SettingDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("SettingDialog", "\344\277\256\346\224\271\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("SettingDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SettingDialog", "\345\210\253  \345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SettingDialog", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", 0, QApplication::UnicodeUTF8));
        pChangeBasicBtn->setText(QApplication::translate("SettingDialog", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pChangeBasicTab), QApplication::translate("SettingDialog", "\350\256\276\347\275\256\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SettingDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingDialog", "\345\216\237\345\247\213\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SettingDialog", "\345\206\215\346\254\241\350\276\223\345\205\245\357\274\232", 0, QApplication::UnicodeUTF8));
        pSettingBtn->setText(QApplication::translate("SettingDialog", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pChangePwdTab), QApplication::translate("SettingDialog", "\344\277\256\346\224\271\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SettingDialog);
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTING_H
