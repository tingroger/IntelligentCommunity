/********************************************************************************
** Form generated from reading UI file 'win_register.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_REGISTER_H
#define UI_WIN_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinRegister
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *line_account;
    QSpacerItem *verticalSpacer;
    QLineEdit *line_phone;
    QLineEdit *line_check_passwd;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *line_passwd;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_submit;
    QPushButton *btn_back;

    void setupUi(QWidget *WinRegister)
    {
        if (WinRegister->objectName().isEmpty())
            WinRegister->setObjectName(QString::fromUtf8("WinRegister"));
        WinRegister->resize(800, 480);
        layoutWidget = new QWidget(WinRegister);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 50, 451, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        line_account = new QLineEdit(layoutWidget);
        line_account->setObjectName(QString::fromUtf8("line_account"));
        sizePolicy.setHeightForWidth(line_account->sizePolicy().hasHeightForWidth());
        line_account->setSizePolicy(sizePolicy);
        line_account->setMinimumSize(QSize(200, 0));
        line_account->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(line_account, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        line_phone = new QLineEdit(layoutWidget);
        line_phone->setObjectName(QString::fromUtf8("line_phone"));
        sizePolicy.setHeightForWidth(line_phone->sizePolicy().hasHeightForWidth());
        line_phone->setSizePolicy(sizePolicy);
        line_phone->setMinimumSize(QSize(200, 0));
        line_phone->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(line_phone, 2, 1, 1, 1);

        line_check_passwd = new QLineEdit(layoutWidget);
        line_check_passwd->setObjectName(QString::fromUtf8("line_check_passwd"));
        sizePolicy.setHeightForWidth(line_check_passwd->sizePolicy().hasHeightForWidth());
        line_check_passwd->setSizePolicy(sizePolicy);
        line_check_passwd->setMinimumSize(QSize(200, 0));
        line_check_passwd->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(line_check_passwd, 6, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 7, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        line_passwd = new QLineEdit(layoutWidget);
        line_passwd->setObjectName(QString::fromUtf8("line_passwd"));
        sizePolicy.setHeightForWidth(line_passwd->sizePolicy().hasHeightForWidth());
        line_passwd->setSizePolicy(sizePolicy);
        line_passwd->setMinimumSize(QSize(200, 0));
        line_passwd->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(line_passwd, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);
        label_1->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_1, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_submit = new QPushButton(layoutWidget);
        btn_submit->setObjectName(QString::fromUtf8("btn_submit"));
        sizePolicy.setHeightForWidth(btn_submit->sizePolicy().hasHeightForWidth());
        btn_submit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btn_submit);

        btn_back = new QPushButton(layoutWidget);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        sizePolicy.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btn_back);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WinRegister);

        QMetaObject::connectSlotsByName(WinRegister);
    } // setupUi

    void retranslateUi(QWidget *WinRegister)
    {
        WinRegister->setWindowTitle(QCoreApplication::translate("WinRegister", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("WinRegister", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("WinRegister", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("WinRegister", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_1->setText(QCoreApplication::translate("WinRegister", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        btn_submit->setText(QCoreApplication::translate("WinRegister", "\346\217\220\344\272\244", nullptr));
        btn_back->setText(QCoreApplication::translate("WinRegister", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinRegister: public Ui_WinRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_REGISTER_H
