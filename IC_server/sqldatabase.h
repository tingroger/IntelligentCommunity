#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include "common_header.h"
#include <QSqlQuery>
#include <QSqlError>
#include "user.h"

extern const QString dbPath;

class SqlDatabase
{
public:
    static SqlDatabase *get_instance(const QString & dbPath);
    bool open();
    void close();
    bool create_user_table();
    bool get_user_by_item(const user_options item,const QString & data, User & user);
    bool insert_new_user(const User & user);
    bool del_user_by_item(const user_options item,const QString & data);

//    static QSqlDatabase getDatabase();

//    bool getOpenedFlag() const;

private:
    //设为单例模式
    SqlDatabase(){}
    SqlDatabase(const SqlDatabase & other) = delete;
    SqlDatabase & operator=(const SqlDatabase & other) = delete;
    static SqlDatabase *instance;
    static QSqlDatabase database;

    bool openedFlag=false;//防止重复打开或关闭
    QSqlQuery sqlQuery;

    void join_cmd_by_item_(QString & cmd,int option,  const user_options item, const QString & data);

};

#endif // SQLDATABASE_H
