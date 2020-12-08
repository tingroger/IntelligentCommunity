#ifndef USER_H
#define USER_H

#include "common_header.h"
#define USER_ID_BASE 100000

enum user_role {administrator =1, resident};
enum user_options {id, account, passwd, cardID, phone, role};

class User
{
public:
    explicit User(){}

    explicit User(QString account, QString passwd, user_role role=resident,
         QString cardID = "", unsigned long phone = 0)
        :m_user_account(account),
          m_user_passwd(passwd),
          m_user_cardID(cardID),
          m_user_phone(phone),
          m_user_role(role){}

    int get_user_id() const;
    QString get_user_account() const;
    QString get_user_passwd() const;
    QString get_user_cardID() const;
    user_role get_user_role() const;
    QString get_user_role_str() const;
    ulong get_user_phone() const;

    void set_user_id(int user_id);
    void set_user_account(const QString &user_account);
    void set_user_passwd(const QString &user_passwd);
    void set_user_cardID(const QString &user_cardID);
    void set_user_role(const user_role &user_role);
    void set_user_role_from_str(const QString role);
    void set_user_phone(const ulong &user_phone);

    static void convert_options_to_str(const user_options option, QString & str);

private:
    int m_user_id = 0;
    QString m_user_account;
    QString m_user_passwd;
    QString m_user_cardID = "";
    ulong m_user_phone=0;
    user_role m_user_role=resident;

};

#endif // USER_H
