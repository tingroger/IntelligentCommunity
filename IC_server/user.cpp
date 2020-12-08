#include "user.h"
//std::list<User> *User::p_list_user = new std::list<User>;

int User::get_user_id() const
{
    return m_user_id;
}

QString User::get_user_account() const
{
    return m_user_account;
}

QString User::get_user_passwd() const
{
    return m_user_passwd;
}

QString User::get_user_cardID() const
{
    return m_user_cardID;
}

//QString User::get_user_account_qstr() const
//{
//    return QString::fromStdString(m_user_account);
//}

//QString User::get_user_passwd_qstr() const
//{
//    return QString::fromStdString(m_user_passwd);
//}

//QString User::get_user_cardID_qstr() const
//{
//    return QString::fromStdString(m_user_cardID);
//}

QString User::get_user_role_str() const
{
    switch (m_user_role)
    {
    case administrator:
            return "管理员";
    case resident:
            return "业主";
    }
    return "未定义";
}

user_role User::get_user_role() const
{
    return m_user_role;
}

void User::set_user_id(int user_id)
{
    m_user_id = user_id;
}

void User::set_user_account(const QString &user_account)
{
    m_user_account = user_account;
}

void User::set_user_passwd(const QString &user_passwd)
{
    m_user_passwd = user_passwd;
}

void User::set_user_role(const user_role &user_role)
{
    m_user_role = user_role;
}

void User::set_user_role_from_str(const QString role)
{
    if(role == "业主")
        m_user_role = resident;
    else if(role == "管理员")
        m_user_role = administrator;
}

void User::set_user_phone(const ulong &user_phone)
{
    m_user_phone = user_phone;
}

void User::convert_options_to_str(const user_options option, QString & str)
{
    switch (option)
    {
    case id:
        str = "id";
        return;
    case account:
        str = "account";
        return;
    case passwd:
        str = "passwd";
        return;
    case cardID:
        str = "cardID";
        return;
    case phone:
        str = "phone";
        return;
    case role:
        str = "role";
        return;
//    default:
//        str = "unkonwn";
//        return;
    }
}

//void User::update_user_by_id(const QString &id, const user_options &options, const QString &info)
//{
//    for(std::list<User>::iterator it = p_list_user->begin(); it != p_list_user->end(); ++it)
//    {
//        if(id == QString::number(it->m_user_id))
//        {
//            switch (options)
//            {
//            case account:
//                it->m_user_account = info.toStdString();
//                break;
//            case passwd:
//                it->m_user_passwd = info.toStdString();
//                break;
//            case cardID:
//                it->m_user_cardID = info.toStdString();
//                break;
//            case phone:
//                it->m_user_phone = info.toULong();
//                break;
//            case role:
//                it->set_user_role_from_qstr(info);
//                break;
//            default:
//                break;
//            }
//            return;
//        }
//    }
//}

//void User::del_user_by_id(const QString & id)
//{
//    for(std::list<User>::iterator it = p_list_user->begin(); it != p_list_user->end(); ++it)
//    {
//        if(id == QString::number(it->m_user_id))
//        {
//            p_list_user->erase(it);
//            break;
//        }
//    }
//}

void User::set_user_cardID(const QString &user_cardID)
{
    m_user_cardID = user_cardID;
}


ulong User::get_user_phone() const
{
    return m_user_phone;
}



//QStringList *User::get_user_info()
//{
//    QStringList *list = new QStringList;
//    (*list) << QString::number(m_user_id) <<
//                 get_user_account() <<
//                 get_user_passwd() <<
//                 get_user_cardID() <<
//                 QString::number(m_user_phone) <<
//                 get_user_role_qstr();

//    return list;

//}
