#include "win_admin.h"
#include "ui_win_admin.h"
#include <QSizePolicy>
#include "user.h"


void WinAdmin::setDB(SqlDatabase *value)
{
    db = value;
}

void WinAdmin::init_user_table()
{
    if(db == nullptr)
        return;

    db->open();
    //创建一个可编辑的model对象，注意：必须在堆上创建
    if(tableModel == nullptr)
        tableModel= new EditableTable;
    //设置表的列名
    tableModel->setHeaderData(1,Qt::Horizontal,QObject::tr("姓名"));
    //发送命令
    tableModel->setQuery("select * from user");
    //定义View
    if(view == nullptr)
    {
        view = new QTableView;
        //栅格布局
        QGridLayout *pLayout = new QGridLayout(ui->widget);
        pLayout->addWidget(view, 0, 0);
        view->resize(ui->widget->width(), ui->widget->height());
        //单击则选择整行
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        //单击并触发删除按钮则删除所在行
        connect(view, &QTableView::clicked, this, &WinAdmin::slot_get_clicked_index);
    }
    view->setModel(tableModel);
    view->show();

    db->close();
}

void WinAdmin::slot_get_clicked_index(const QModelIndex &index)
{
    qDebug() << "clicked index = " << index.row() << " ," << index.column();
    clickedIndex = index;
}

void WinAdmin::on_btn_add_clicked()
{
    User newUser;
    db->insert_new_user(newUser);
    init_user_table();
}

void WinAdmin::on_btn_del_clicked()
{
    QModelIndex index = tableModel->index(clickedIndex.row(),0,QModelIndex());//rowNum,columnNum为行列号
    QString id = index.data().toString();
    qDebug() << "selected id = " << id;
    db->del_user_by_item(user_options::id, id);
    init_user_table();
}

void WinAdmin::on_btn_refresh_clicked()
{
    init_user_table();
}

