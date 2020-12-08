#ifndef EDITABLE_TABLE_H
#define EDITABLE_TABLE_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include "common_header.h"

class EditableTable :public QSqlQueryModel
{
public:
    explicit EditableTable(){}

    //重写父类的虚函数
    virtual bool setData(const QModelIndex &index, const QVariant &value,
                         int role = Qt::EditRole) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
};

#endif // EDITABLE_TABLE_H
