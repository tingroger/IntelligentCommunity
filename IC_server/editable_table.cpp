#include "editable_table.h"
#include "user.h"
#include "sqldatabase.h"

bool EditableTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //不可编辑列返回false
    if(index.column() == 0)
        return  false;

    SqlDatabase::get_instance(dbPath)->open();
    qDebug() << __FUNCTION__ << __LINE__;
    //为了获取得到id
    QModelIndex idIndex = QSqlQueryModel::index(index.row(),0);
    int id = data(idIndex).toInt();

    qDebug() << "id =" << id << "index =" << index.column();

    qDebug() << __FUNCTION__ << __LINE__;
    //设置单元格上的内容
    QSqlQuery query;
    QString item;
    User::convert_options_to_str(static_cast<user_options>(index.column()), item);
    QString cmdUpate = QString("UPDATE user SET %1 = ? where id = ?").arg(item);
    query.prepare(cmdUpate);
    query.addBindValue(value);
    query.addBindValue(id);
    if(!query.exec())
    {
        qDebug() << "Update select cell info error";
        SqlDatabase::get_instance(dbPath)->close();
        return  false;
    }
    //清除操作
    clear();
    //刷新
    setQuery("select * from user");

    SqlDatabase::get_instance(dbPath)->close();
    return true;
}

Qt::ItemFlags EditableTable::flags(const QModelIndex &index) const
{
//    qDebug() << __FUNCTION__ << __LINE__;
   //获取当前条目的标志
   Qt::ItemFlags flags = QSqlQueryModel::flags(index);

   //根据列的可编辑情况，设置对应的标志
   if(index.column() > 0 || index.column() < 6)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志
   return flags;
}
