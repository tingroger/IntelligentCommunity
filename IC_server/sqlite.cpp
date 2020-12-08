#include "sqlite.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

Sqlite *Sqlite::instance = nullptr;
sqlite3 *Sqlite::db = nullptr;

Sqlite::Sqlite(const char *dbPath)
{
    //初始化db
    int ret = sqlite3_open(dbPath, &db); //参数一，传入参数  参数二，传出参数
    if(ret != SQLITE_OK)
    {
        qDebug() << "[open database error]" << sqlite3_errmsg(db);
        sqlite3_close(db);
    }
}

int Sqlite::create_user_table()
{
    int ret = 0;
    char *errmsg = nullptr;
    char createTableCmd[CMD_BUFFER_SIZE];
    ret = sprintf_s(createTableCmd, CMD_BUFFER_SIZE,
                    "CREATE TABLE IF NOT EXISTS user("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "account varchar(%d) UNIQUE NOT NULL, "
                    "passwd varchar(%d) NOT NULL, "
                    "cardID varchar(%d), "
                    "role int NOT NULL, "
                    "phone unsigned int64);",
                    USER_ACCOUNT_LEN,
                    USER_PASSWD_LEN,
                    USER_CARDID_LEN);

    if(ret < 0)
    {
        qDebug() << "[create table cmd error] check command buffer size";
        return ret;
    }

    ret = sqlite3_exec(db, createTableCmd, nullptr, nullptr, &errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[create user table error]" << errmsg;
    }
    qDebug()<<"[create user table ok]";
    return ret;
}

int Sqlite::insert_user(const User & user)
{
    int ret = 0;
    char *errmsg = nullptr;
    char insertUserCmd[CMD_BUFFER_SIZE];
    ret = sprintf_s(insertUserCmd, CMD_BUFFER_SIZE,
                    "INSERT INTO user (account, passwd, cardID, role, phone) "
                    "values('%s', '%s', '%s', %d, %ld);",
                    user.get_user_account().c_str(),
                    user.get_user_passwd().c_str(),
                    user.get_user_cardID().c_str(),
                    user.get_user_role(),
                    user.get_user_phone());
    if(ret < 0)
    {
        qDebug() << "[insert cmd error] check command buffer size";
        return ret;
    }

    ret = sqlite3_exec(db, insertUserCmd, nullptr, nullptr,&errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[user table insert info error]" << errmsg;
    }
    qDebug()<<"[user table insert info ok]";
    return ret;
}

int Sqlite::update_user_by_id(const int id, const user_options option, std::string value)
{
    int ret = 0;
    char *errmsg = nullptr;
    char updateUserCmd[CMD_BUFFER_SIZE];
    switch (option)
    {
    case account:
        ret = sprintf_s(updateUserCmd, CMD_BUFFER_SIZE,
                        "UPDATE user SET account='%d' WHERE id=%d;",
                        value.c_str(),
                        id);
        if(ret < 0)
        {
            qDebug() << "[update user account cmd error] check command buffer size";
            return ret;
        }
        break;
    case passwd:
        ret = sprintf_s(updateUserCmd, CMD_BUFFER_SIZE,
                        "UPDATE user SET passwd='%d' WHERE id=%d;",
                        value.c_str(),
                        id);
        if(ret < 0)
        {
            qDebug() << "[update user passwd cmd error] check command buffer size";
            return ret;
        }
        break;
    case cardID:
        ret = sprintf_s(updateUserCmd, CMD_BUFFER_SIZE,
                        "UPDATE user SET cardID='%d' WHERE id=%d;",
                        value.c_str(),
                        id);
        if(ret < 0)
        {
            qDebug() << "[update user cardID cmd error] check command buffer size";
            return ret;
        }
        break;
    case phone:
        ret = sprintf_s(updateUserCmd, CMD_BUFFER_SIZE,
                        "UPDATE user SET phone=%uLd WHERE id=%d;",
                        strtoull(value.c_str(), nullptr,10),
                        id);
        if(ret < 0)
        {
            qDebug() << "[update user phone cmd error] check command buffer size";
            return ret;
        }
        break;
    case role:
        ret = sprintf_s(updateUserCmd, CMD_BUFFER_SIZE,
                        "UPDATE user SET role='%d' WHERE id=%d;",
                        atoi(value.c_str()),
                        id);
        if(ret < 0)
        {
            qDebug() << "[update user role cmd error] check command buffer size";
            return ret;
        }
        break;
    default:
        return -1;
    }

    ret = sqlite3_exec(db, updateUserCmd, nullptr, nullptr, &errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[update user by id error]" << errmsg;
    }
    return ret;
}

int Sqlite::del_user_by_id(int id)
{
    int ret = 0;
    char *errmsg = nullptr;
    char delUserCmd[CMD_BUFFER_SIZE];
    ret = sprintf_s(delUserCmd, CMD_BUFFER_SIZE,
                    "DELETE FROM user WHERE id=%d;",
                    id);
    if(ret < 0)
    {
        qDebug() << "[delete user cmd error] check command buffer size";
        return ret;
    }

    ret = sqlite3_exec(db, delUserCmd, nullptr, nullptr, &errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[delete user by id error]" << errmsg;
    }
    return ret;
}
/********************************************************************************
show_user_info()回调函数
********************************************************************************/
int callback_show_info(void* data ,int cols,char** value,char** name)
{
    qDebug() << "data = " << data;
    for(int i = 0; i < cols; ++i)
    {
        qDebug() << "name = "<< name[i];
        qDebug() << "value = "<< value[i] ;
    }
    return  0;
}

int Sqlite::show_user_info()
{
    char *errmsg = nullptr;
    int ret = sqlite3_exec(db, "SELECT * FROM user", callback_show_info, nullptr,&errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[show all uer info error]" << errmsg;
    }
    qDebug()<<"[show all user info ok]";
    return ret;
}

int Sqlite::close_db()
{
    if(db != nullptr)
    {
        int ret = sqlite3_close(db);
        db = nullptr;
        return ret;
    }
    return 0;
}

/********************************************************************************
get_user_passwd_by_account()回调函数
********************************************************************************/
int callback_get_user(void * data ,int cols,char** value,char** name)
{
    User *user = nullptr;
    if(data == NULL)
    {
        qDebug() << "data == nullptr";
        user = new User;
    }
    else
    {
        qDebug() << "data != nullptr";
        user = reinterpret_cast<User *>(data);
    }

    for(int i=0; i< cols; ++i)
    {
        char *endptr = nullptr;
        if(!strncmp(name[i], "id", strlen(name[i])+1))
            user->set_user_id(atoi(value[i]));
        else if(!strncmp(name[i], "account", strlen(name[i])+1))
        {
            user->set_user_account(value[i]);
            qDebug() << value[i];
        }
        else if(!strncmp(name[i], "passwd", strlen(name[i])+1))
            user->set_user_passwd(value[i]);
        else if(!strncmp(name[i], "cardID", strlen(name[i])+1))
            user->set_user_cardID(value[i]);
        else if(!strncmp(name[i], "role", strlen(name[i])+1))
            user->set_user_role(static_cast<user_role>(atoi(value[i])));
        else if(!strncmp(name[i], "phone", strlen(name[i])+1))
            user->set_user_phone(strtoul(value[i], &endptr, 10));
        else
            return 0;
    }
//    if(data == NULL)
//        User::p_list_user->push_back(*user);
    return 0;
}
int Sqlite::get_user_by_account(const std::string & account, User & user)
{
    int ret = 0;
    char *errmsg = nullptr;
    char getPasswdCmd[CMD_BUFFER_SIZE];
    ret = sprintf_s(getPasswdCmd, CMD_BUFFER_SIZE,
                    "SELECT * FROM user WHERE account='%s';",
                    account.c_str());
    if(ret < 0)
    {
        qDebug() << "[select passswd cmd error] check command buffer size";
        return ret;
    }

    ret = sqlite3_exec(db, getPasswdCmd, callback_get_user, &user, &errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[select user info error]" << errmsg;
    }
    return ret;
}

int Sqlite::get_user_info()
{
    char *errmsg = nullptr;
    int ret = sqlite3_exec(db, "SELECT * FROM user", callback_get_user, nullptr,&errmsg);
    if(ret != SQLITE_OK)
    {
        qDebug()<<"[select all uer error]" << ret << errmsg;
    }
    return ret;
}
