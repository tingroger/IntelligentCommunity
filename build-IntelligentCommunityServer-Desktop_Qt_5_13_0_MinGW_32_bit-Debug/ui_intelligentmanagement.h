/********************************************************************************
** Form generated from reading UI file 'intelligentmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTELLIGENTMANAGEMENT_H
#define UI_INTELLIGENTMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntelligentManagement
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_login;
    QLabel *label;
    QLineEdit *line_account;
    QLineEdit *line_passwd;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *IntelligentManagement)
    {
        if (IntelligentManagement->objectName().isEmpty())
            IntelligentManagement->setObjectName(QString::fromUtf8("IntelligentManagement"));
        IntelligentManagement->resize(400, 300);
        IntelligentManagement->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(IntelligentManagement);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(71, 74, 281, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_login = new QPushButton(layoutWidget);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btn_login, 2, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_account = new QLineEdit(layoutWidget);
        line_account->setObjectName(QString::fromUtf8("line_account"));

        gridLayout->addWidget(line_account, 0, 1, 1, 2);

        line_passwd = new QLineEdit(layoutWidget);
        line_passwd->setObjectName(QString::fromUtf8("line_passwd"));
        line_passwd->setCursor(QCursor(Qt::ArrowCursor));
        line_passwd->setContextMenuPolicy(Qt::DefaultContextMenu);
        line_passwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(line_passwd, 1, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        IntelligentManagement->setCentralWidget(centralWidget);

        retranslateUi(IntelligentManagement);

        QMetaObject::connectSlotsByName(IntelligentManagement);
    } // setupUi

    void retranslateUi(QMainWindow *IntelligentManagement)
    {
        IntelligentManagement->setWindowTitle(QCoreApplication::translate("IntelligentManagement", "\346\231\272\350\203\275\347\244\276\345\214\272\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_login->setText(QCoreApplication::translate("IntelligentManagement", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("IntelligentManagement", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("IntelligentManagement", "\345\257\206 \347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntelligentManagement: public Ui_IntelligentManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTELLIGENTMANAGEMENT_H
