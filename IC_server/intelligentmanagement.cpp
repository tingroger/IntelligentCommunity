#include "intelligentmanagement.h"
#include "ui_intelligentmanagement.h"
#include "user.h"
//#include "db_read_write.h"
#include <QFileInfo>
#include <QMessageBox>

IntelligentManagement::IntelligentManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntelligentManagement)
{
    ui->setupUi(this);

    //初始化数据库
    QFileInfo dbFile(dbPath);
    if(!dbFile.isFile())
    {
        //初始化管理员用户
        User admin("admin", "666666",administrator);
        db = SqlDatabase::get_instance(dbPath);
        db->insert_new_user(admin);
    }
    db = SqlDatabase::get_instance(dbPath);

}

IntelligentManagement::~IntelligentManagement()
{
    delete ui;
}

void IntelligentManagement::on_btn_login_clicked()
{
    QString getAccount = ui->line_account->text();
    QString getPasswd = ui->line_passwd->text();
    User user;
    db->get_user_by_item(account, getAccount, user);
    qDebug() << "预期密码" << user.get_user_passwd();
    qDebug() << "预期卡号" << user.get_user_cardID();
    qDebug() << "角色" << user.get_user_role();
    if(getPasswd == user.get_user_passwd() && user.get_user_role() == user_role::administrator)
    {
        qDebug() << "登录成功";
        win_admin = new WinAdmin(this);
        win_admin->setDB(db);
        win_admin->init_user_table();
        win_admin->show();
        this->hide();
//        win_admin->loadUserTable(User::p_list_user);
    }
    else
    {
        QMessageBox::warning(this, "提示", "检查账户或账号是否正确");
    }
}

