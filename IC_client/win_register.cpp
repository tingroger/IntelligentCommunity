#include "win_register.h"
#include "ui_win_register.h"
#include <QMessageBox>


WinRegister::WinRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WinRegister)
{
    ui->setupUi(this);

    /* 键盘相关 */
    kb = new Keyboard(this);
    kb->move(0, 225);
    kb->hide();
    //给控件安装事件过滤器
    ui->line_account->installEventFilter(this);
    ui->line_phone->installEventFilter(this);
    ui->line_passwd->installEventFilter(this);
    ui->line_check_passwd->installEventFilter(this);
}

WinRegister::~WinRegister()
{
    delete ui;
    delete kb;
}

bool WinRegister::eventFilter(QObject *watched, QEvent *event)
{
    if ( (watched == ui->line_account || watched == ui->line_passwd ||
          watched == ui->line_phone || watched == ui->line_check_passwd)
         && (event->type() == QEvent::MouseButtonPress) )
    {
        kb->show();
        dynamic_cast<QLineEdit *>(watched)->setFocus();
    }
    //其他事件不影响
    return QMainWindow::eventFilter(watched,event);

}


void WinRegister::on_btn_submit_clicked()
{
    if(ui->line_passwd->text() != ui->line_check_passwd->text())
    {
        QMessageBox::warning(this, "提示", "两次密码输入不一致");
        return;
    }
    else if(ui->line_phone->text().toULongLong() > 99999999999 ||
            ui->line_phone->text().toULongLong() < 10000000000)
    {
        QMessageBox::warning(this, "提示", "手机号码格式不符合要求");
        return;
    }

    QString registerInfo;
    registerInfo += (QString::number(REGISTER_CODE));
    registerInfo += (TCP_INFO_SEPARATOR);
    registerInfo += (ui->line_account->text() + TCP_INFO_SEPARATOR);
    registerInfo += (ui->line_passwd->text() + TCP_INFO_SEPARATOR);
    registerInfo += (ui->line_phone->text() + TCP_INFO_SEPARATOR);
    qDebug() << "send msg" << registerInfo;

    if(socket == nullptr)
    {
        qDebug() << "socket connect fail";
        return;
    }
    qint64 ret = socket->write(registerInfo.toUtf8());
    if(ret != registerInfo.length())
    {
        qDebug() << "write socket failed";
        return;
    }
    qDebug() << "write socket return:" << ret;
}

void WinRegister::setSocket(QTcpSocket *value)
{
    socket = value;
}

void WinRegister::register_new_user(const QStringList & info)
{
        if(info.at(1) == "1")
        {
            QMessageBox::information(this, "提示", "注册成功");
        }
        else
        {
           QMessageBox::warning(this, "提示", "注册失败，该用户名已注册");
        }
}

void WinRegister::on_btn_back_clicked()
{
    this->parentWidget()->show();
    this->close();
}
