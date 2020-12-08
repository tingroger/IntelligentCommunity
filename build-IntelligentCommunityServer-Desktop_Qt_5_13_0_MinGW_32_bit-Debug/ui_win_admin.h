/********************************************************************************
** Form generated from reading UI file 'win_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_ADMIN_H
#define UI_WIN_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinAdmin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_user;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QPushButton *btn_refresh;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QTableWidget *table_login_user;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_video_filename;
    QPushButton *btn_set_video_file;
    QPushButton *btn_send_video;

    void setupUi(QMainWindow *WinAdmin)
    {
        if (WinAdmin->objectName().isEmpty())
            WinAdmin->setObjectName(QString::fromUtf8("WinAdmin"));
        WinAdmin->resize(682, 452);
        centralwidget = new QWidget(WinAdmin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_user = new QWidget();
        tab_user->setObjectName(QString::fromUtf8("tab_user"));
        gridLayout_2 = new QGridLayout(tab_user);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_add = new QPushButton(tab_user);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        verticalLayout->addWidget(btn_add);

        btn_del = new QPushButton(tab_user);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));

        verticalLayout->addWidget(btn_del);

        btn_refresh = new QPushButton(tab_user);
        btn_refresh->setObjectName(QString::fromUtf8("btn_refresh"));

        verticalLayout->addWidget(btn_refresh);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        widget = new QWidget(tab_user);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(widget);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_user, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        table_login_user = new QTableWidget(tab);
        if (table_login_user->columnCount() < 2)
            table_login_user->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_login_user->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_login_user->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_login_user->setObjectName(QString::fromUtf8("table_login_user"));

        gridLayout_3->addWidget(table_login_user, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 70, 401, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_video_filename = new QLabel(layoutWidget);
        label_video_filename->setObjectName(QString::fromUtf8("label_video_filename"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_video_filename->sizePolicy().hasHeightForWidth());
        label_video_filename->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_video_filename);

        btn_set_video_file = new QPushButton(layoutWidget);
        btn_set_video_file->setObjectName(QString::fromUtf8("btn_set_video_file"));

        horizontalLayout_2->addWidget(btn_set_video_file);

        btn_send_video = new QPushButton(layoutWidget);
        btn_send_video->setObjectName(QString::fromUtf8("btn_send_video"));
        btn_send_video->setEnabled(false);

        horizontalLayout_2->addWidget(btn_send_video);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        WinAdmin->setCentralWidget(centralwidget);

        retranslateUi(WinAdmin);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WinAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *WinAdmin)
    {
        WinAdmin->setWindowTitle(QCoreApplication::translate("WinAdmin", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("WinAdmin", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_add->setText(QCoreApplication::translate("WinAdmin", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        btn_del->setText(QCoreApplication::translate("WinAdmin", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        btn_refresh->setText(QCoreApplication::translate("WinAdmin", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_user), QCoreApplication::translate("WinAdmin", "\350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_login_user->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WinAdmin", "IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_login_user->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WinAdmin", "\350\264\246\345\217\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("WinAdmin", "\347\231\273\345\275\225\347\224\250\346\210\267", nullptr));
        label_video_filename->setText(QString());
        btn_set_video_file->setText(QCoreApplication::translate("WinAdmin", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        btn_send_video->setText(QCoreApplication::translate("WinAdmin", "\351\203\250\347\275\262\345\271\277\345\221\212", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("WinAdmin", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinAdmin: public Ui_WinAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_ADMIN_H
