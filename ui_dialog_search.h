/********************************************************************************
** Form generated from reading ui file 'dialog_search.ui'
**
** Created: Wed Sep 27 23:04:20 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOG_SEARCH_H
#define UI_DIALOG_SEARCH_H

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
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *m_pSearchLineEdit;
    QPushButton *m_pSearchBtn;
    QTreeWidget *m_pTreeWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *m_pSelectAllBtn;
    QLabel *label;
    QToolButton *m_pSelectRevertBtn;
    QLabel *label_7;
    QToolButton *m_pSendSmsBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *m_pPageLabel;
    QLabel *label_5;
    QToolButton *m_pFirstPageBtn;
    QLabel *label_2;
    QToolButton *m_pPreviousPageBtn;
    QLabel *label_3;
    QToolButton *m_pNextPageBtn;
    QLabel *label_4;
    QToolButton *m_pLastPageBtn;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(768, 425);
        verticalLayout = new QVBoxLayout(SearchDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(SearchDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        m_pSearchLineEdit = new QLineEdit(SearchDialog);
        m_pSearchLineEdit->setObjectName(QString::fromUtf8("m_pSearchLineEdit"));

        horizontalLayout_2->addWidget(m_pSearchLineEdit);

        m_pSearchBtn = new QPushButton(SearchDialog);
        m_pSearchBtn->setObjectName(QString::fromUtf8("m_pSearchBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pSearchBtn->setIcon(icon);

        horizontalLayout_2->addWidget(m_pSearchBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        m_pTreeWidget = new QTreeWidget(SearchDialog);
        new QTreeWidgetItem(m_pTreeWidget);
        m_pTreeWidget->setObjectName(QString::fromUtf8("m_pTreeWidget"));

        verticalLayout->addWidget(m_pTreeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_pSelectAllBtn = new QToolButton(SearchDialog);
        m_pSelectAllBtn->setObjectName(QString::fromUtf8("m_pSelectAllBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/select-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pSelectAllBtn->setIcon(icon1);
        m_pSelectAllBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pSelectAllBtn);

        label = new QLabel(SearchDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        m_pSelectRevertBtn = new QToolButton(SearchDialog);
        m_pSelectRevertBtn->setObjectName(QString::fromUtf8("m_pSelectRevertBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/select-reverse.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pSelectRevertBtn->setIcon(icon2);
        m_pSelectRevertBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pSelectRevertBtn);

        label_7 = new QLabel(SearchDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        m_pSendSmsBtn = new QToolButton(SearchDialog);
        m_pSendSmsBtn->setObjectName(QString::fromUtf8("m_pSendSmsBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/sms1.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pSendSmsBtn->setIcon(icon3);
        m_pSendSmsBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pSendSmsBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        m_pPageLabel = new QLabel(SearchDialog);
        m_pPageLabel->setObjectName(QString::fromUtf8("m_pPageLabel"));

        horizontalLayout->addWidget(m_pPageLabel);

        label_5 = new QLabel(SearchDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        m_pFirstPageBtn = new QToolButton(SearchDialog);
        m_pFirstPageBtn->setObjectName(QString::fromUtf8("m_pFirstPageBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/pagehead.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pFirstPageBtn->setIcon(icon4);
        m_pFirstPageBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pFirstPageBtn);

        label_2 = new QLabel(SearchDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        m_pPreviousPageBtn = new QToolButton(SearchDialog);
        m_pPreviousPageBtn->setObjectName(QString::fromUtf8("m_pPreviousPageBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/pageup.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pPreviousPageBtn->setIcon(icon5);
        m_pPreviousPageBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pPreviousPageBtn);

        label_3 = new QLabel(SearchDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        m_pNextPageBtn = new QToolButton(SearchDialog);
        m_pNextPageBtn->setObjectName(QString::fromUtf8("m_pNextPageBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/pagedown.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pNextPageBtn->setIcon(icon6);
        m_pNextPageBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pNextPageBtn);

        label_4 = new QLabel(SearchDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        m_pLastPageBtn = new QToolButton(SearchDialog);
        m_pLastPageBtn->setObjectName(QString::fromUtf8("m_pLastPageBtn"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/pagetail.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pLastPageBtn->setIcon(icon7);
        m_pLastPageBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(m_pLastPageBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SearchDialog", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        m_pSearchBtn->setText(QApplication::translate("SearchDialog", "  \346\220\234\347\264\242   ", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = m_pTreeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("SearchDialog", "\347\237\255\344\277\241\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("SearchDialog", "\346\267\273\345\212\240\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("SearchDialog", "\351\207\207\346\240\267\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("SearchDialog", "\347\205\244\347\247\215", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("SearchDialog", "\345\217\227\346\243\200\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("SearchDialog", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = m_pTreeWidget->isSortingEnabled();
        m_pTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = m_pTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(4, QApplication::translate("SearchDialog", "2015-07-20 18:33:32", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("SearchDialog", "2015-07-20", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("SearchDialog", "18135100170", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("SearchDialog", "1", 0, QApplication::UnicodeUTF8));
        m_pTreeWidget->setSortingEnabled(__sortingEnabled);

        m_pSelectAllBtn->setText(QApplication::translate("SearchDialog", "\345\205\250\351\200\211", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        m_pSelectRevertBtn->setText(QApplication::translate("SearchDialog", "\345\217\215\351\200\211", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        m_pSendSmsBtn->setText(QApplication::translate("SearchDialog", "\347\237\255\344\277\241\351\200\232\347\237\245", 0, QApplication::UnicodeUTF8));
        m_pPageLabel->setText(QApplication::translate("SearchDialog", "\347\254\2541\351\241\265 / \345\205\2611\351\241\265", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        m_pFirstPageBtn->setText(QApplication::translate("SearchDialog", "\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        m_pPreviousPageBtn->setText(QApplication::translate("SearchDialog", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        m_pNextPageBtn->setText(QApplication::translate("SearchDialog", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        m_pLastPageBtn->setText(QApplication::translate("SearchDialog", "\345\260\276\351\241\265 ", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SearchDialog);
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SEARCH_H
