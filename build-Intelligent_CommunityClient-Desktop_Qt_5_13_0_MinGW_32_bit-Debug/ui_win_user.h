/********************************************************************************
** Form generated from reading UI file 'win_user.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_USER_H
#define UI_WIN_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinUser
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *WinUser)
    {
        if (WinUser->objectName().isEmpty())
            WinUser->setObjectName(QString::fromUtf8("WinUser"));
        WinUser->resize(800, 480);
        centralwidget = new QWidget(WinUser);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WinUser->setCentralWidget(centralwidget);

        retranslateUi(WinUser);

        QMetaObject::connectSlotsByName(WinUser);
    } // setupUi

    void retranslateUi(QMainWindow *WinUser)
    {
        WinUser->setWindowTitle(QCoreApplication::translate("WinUser", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinUser: public Ui_WinUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_USER_H
