/********************************************************************************
** Form generated from reading UI file 'intelligentcommunity.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTELLIGENTCOMMUNITY_H
#define UI_INTELLIGENTCOMMUNITY_H

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

class Ui_IntelligentCommunity
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_account;
    QLabel *label_2;
    QLineEdit *line_passwd;
    QPushButton *btn_login;
    QPushButton *btn_passwd_back;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *IntelligentCommunity)
    {
        if (IntelligentCommunity->objectName().isEmpty())
            IntelligentCommunity->setObjectName(QString::fromUtf8("IntelligentCommunity"));
        IntelligentCommunity->resize(800, 480);
        IntelligentCommunity->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(IntelligentCommunity);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 80, 421, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
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
        line_account->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(line_account, 0, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        line_passwd = new QLineEdit(layoutWidget);
        line_passwd->setObjectName(QString::fromUtf8("line_passwd"));
        line_passwd->setMaximumSize(QSize(200, 16777215));
        line_passwd->setCursor(QCursor(Qt::ArrowCursor));
        line_passwd->setContextMenuPolicy(Qt::DefaultContextMenu);
        line_passwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(line_passwd, 1, 1, 1, 2);

        btn_login = new QPushButton(layoutWidget);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setMinimumSize(QSize(0, 30));
        btn_login->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(btn_login, 2, 2, 1, 1);

        btn_passwd_back = new QPushButton(layoutWidget);
        btn_passwd_back->setObjectName(QString::fromUtf8("btn_passwd_back"));
        QFont font;
        font.setUnderline(true);
        btn_passwd_back->setFont(font);
        btn_passwd_back->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        btn_passwd_back->setFlat(true);

        gridLayout->addWidget(btn_passwd_back, 3, 2, 1, 1);

        btn_register = new QPushButton(layoutWidget);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        btn_register->setMinimumSize(QSize(0, 30));
        btn_register->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(btn_register, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        IntelligentCommunity->setCentralWidget(centralWidget);

        retranslateUi(IntelligentCommunity);

        QMetaObject::connectSlotsByName(IntelligentCommunity);
    } // setupUi

    void retranslateUi(QMainWindow *IntelligentCommunity)
    {
        IntelligentCommunity->setWindowTitle(QCoreApplication::translate("IntelligentCommunity", "\346\231\272\350\203\275\347\244\276\345\214\272", nullptr));
        label->setText(QCoreApplication::translate("IntelligentCommunity", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("IntelligentCommunity", "\345\257\206 \347\240\201", nullptr));
        btn_login->setText(QCoreApplication::translate("IntelligentCommunity", "\347\231\273\345\275\225", nullptr));
        btn_passwd_back->setText(QCoreApplication::translate("IntelligentCommunity", "\345\257\206\347\240\201\346\211\276\345\233\236", nullptr));
        btn_register->setText(QCoreApplication::translate("IntelligentCommunity", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntelligentCommunity: public Ui_IntelligentCommunity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTELLIGENTCOMMUNITY_H
