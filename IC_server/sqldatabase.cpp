#include "sqldatabase.h"

const QString dbPath = "./intelligentCommunity.db";
SqlDatabase *SqlDatabase::instance = nullptr;
QSqlDatabase SqlDatabase::database = QSqlDatabase::addDatabase("QSQLITE");

SqlDatabase *SqlDatabase::get_instance(const QString &dbPath)
{
    if(nullptr == instance)
    {
        instance = new SqlDatabase();
        //设置数据库路径，创建user表
        database.setDatabaseName(dbPath);
        instance->create_user_table();
    }
    return instance;
}

bool SqlDatabase::open()
{
    if(openedFlag == false && !database.open())
    {
        qDebug() << "[Error]Failed to open DataBase" << database.lastError();
        return false;
    }
    openedFlag = true;
    return  true;
}

void SqlDatabase::close()
{
    if(openedFlag)
    {
        database.close();
        openedFlag = false;
    }
}

bool SqlDatabase::create_user_table()
{
    instance->open();
    QString cmdCreateTable = QString(
                            "CREATE TABLE IF NOT EXISTS user("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "account varchar(%1) UNIQUE NOT NULL, "
                            "passwd varchar(%2) NOT NULL, "
                            "cardID varchar(%3), "
                            "phone unsigned int64, "
                            "role int NOT NULL);")
                    .arg(USER_ACCOUNT_LEN)
                    .arg(USER_PASSWD_LEN)
                    .arg(USER_CARDID_LEN);

    qDebug() << cmdCreateTable;
    if(!sqlQuery.exec(cmdCreateTable))
    {
        qDebug() << "[Error]Failed to create user table" << database.lastError();
        instance->close();
        return false;
    }
    instance->close();
    return true;
}


bool SqlDatabase::insert_new_user(const User &user)
{
    instance->open();
    QString cmdInsertUser = QString(
                            "INSERT INTO user (account, passwd, cardID, phone, role) "
                            "VALUES('%1', '%2', '%3', %4, %5);")
                    .arg(user.get_user_account())
                    .arg(user.get_user_passwd())
                    .arg(user.get_user_cardID())
                    .arg(user.get_user_phone())
                    .arg(user.get_user_role());
    qDebug() << cmdInsertUser;
    if(!sqlQuery.exec(cmdInsertUser))
    {
        qDebug() << "[Error]Failed to insert new user" << database.lastError();
        instance->close();
        return false;
    }
    instance->close();
    return true;
}

bool SqlDatabase::get_user_by_item(const user_options item,const QString & data, User & user)
{
    instance->open();
    QString cmdGetUser;
    join_cmd_by_item_(cmdGetUser, 0, item, data);
    qDebug() << cmdGetUser;
    if(!sqlQuery.exec(cmdGetUser))
    {
        qDebug() << "[Error]Failed to get user info" << database.lastError();
        instance->close();
        return false;
    }
    else
    {
        //仅取第一个
        while(sqlQuery.next())
        {
            qDebug() << sqlQuery.value(1).toString();
            user.set_user_id(sqlQuery.value(0).toInt());
            user.set_user_account(sqlQuery.value(1).toString());
            user.set_user_passwd(sqlQuery.value(2).toString());
            user.set_user_cardID(sqlQuery.value(3).toString());
            user.set_user_phone(sqlQuery.value(4).toUInt());
            user.set_user_role(static_cast<user_role>(sqlQuery.value(5).toInt()));

        }
    }
    instance->close();
    return true;
}
bool SqlDatabase::del_user_by_item(const user_options item, const QString & data)
{
    instance->open();
    QString cmdDelUser;
    join_cmd_by_item_(cmdDelUser, 1, item, data);
    qDebug() << cmdDelUser;
    if(!sqlQuery.exec(cmdDelUser))
    {
        qDebug() << "[Error]Failed to del user by item" << database.lastError();
        instance->close();
        return false;
    }
    instance->close();
    return true;
}

void SqlDatabase::join_cmd_by_item_(QString &cmd, int option, const user_options item, const QString &data)
{
    QString itemStr;
    User::convert_options_to_str(item, itemStr);
    switch (option)
    {
    case 0:
        if(item == account || item == passwd || item == cardID)
            cmd = QString("SELECT * FROM user WHERE %1='%2';").arg(itemStr, data);
        else
            cmd = QString("SELECT * FROM user WHERE %1=%2;").arg(itemStr, data);
        break;
    case 1:
        if(item == account || item == passwd || item == cardID)
            cmd = QString("DELETE FROM user WHERE %1='%2';").arg(itemStr, data);
        else
            cmd = QString("DELETE FROM user WHERE %1=%2;").arg(itemStr, data);
        break;
    }
}
