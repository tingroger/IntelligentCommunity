#include "intelligentcommunity.h"
#include "ui_intelligentcommunity.h"
#include <QHostAddress>
#include <QMessageBox>

IntelligentCommunity::IntelligentCommunity(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntelligentCommunity)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    //[1]向服务端发起请求
    socket->connectToHost(SERVER_IP, SERVER_PORT);
    //[2] 建立与信号readyRead的槽函数
    connect(socket,&QTcpSocket::readyRead,this,&IntelligentCommunity::slot_get_data);

    /* 键盘相关 */
    kb = new Keyboard(this);
    kb->move(0, 225);
    kb->hide();
    //给控件安装事件过滤器
    ui->line_account->installEventFilter(this);
    ui->line_passwd->installEventFilter(this);

    //获取广告文件
    get_video_file();
}

IntelligentCommunity::~IntelligentCommunity()
{
    socket->disconnectFromHost();
    socket->close();
    delete ui;
    delete kb;
}

bool IntelligentCommunity::eventFilter(QObject *watched, QEvent *event)
{
    if ( (watched == ui->line_account || watched == ui->line_passwd)
         && (event->type() == QEvent::MouseButtonPress) )
    {
        kb->show();
        dynamic_cast<QLineEdit *>(watched)->setFocus();
    }
    //其他事件不影响
    return QMainWindow::eventFilter(watched,event);
}


void IntelligentCommunity::slot_get_data()
{
    QByteArray msg = socket->readAll();
    QString ip = socket->peerAddress().toString();
    qDebug() << "ip = " << ip;
//    qDebug() << "msg = " << msg;

    QStringList info = QString::fromUtf8(msg).split(TCP_INFO_SEPARATOR);
    int code = info[0].toInt();
    qDebug() << "code = " << code;
    switch(code)
    {
    case REGISTER_ACK:
        winRegister->register_new_user(info);
        break;
    case LOGIN_ACK:
        tcp_user_login(info);
        break;
    case GET_VIDEO_ACK:
        tcp_video_file(info);
        break;

    default:
        //传输文件
        tcp_write_video_file(msg);
        break;
    }

}

void IntelligentCommunity::on_btn_register_clicked()
{
    winRegister = new WinRegister(this);
    winRegister->setSocket(socket);
    winRegister->show();
    this->hide();
}

void IntelligentCommunity::on_btn_login_clicked()
{
    QString loginInfo;
    loginInfo += (QString::number(LOGIN_CODE));
    loginInfo += (TCP_INFO_SEPARATOR);
    loginInfo += (ui->line_account->text() + TCP_INFO_SEPARATOR);
    loginInfo += (ui->line_passwd->text() + TCP_INFO_SEPARATOR);
    qDebug() << "send msg" << loginInfo;

    if(socket == nullptr)
    {
        qDebug() << "socket connect fail";
        return;
    }
    qint64 ret = socket->write(loginInfo.toUtf8());
    if(ret != loginInfo.length())
    {
        qDebug() << "write socket failed";
        return;
    }
    qDebug() << "write socket return:" << ret;
}

void IntelligentCommunity::on_btn_passwd_back_clicked()
{

}

void IntelligentCommunity::tcp_user_login(const QStringList &list)
{
    if(list.at(1) == "1")
    {
        winUser = new WinUser(this);
        winUser->show();
        //播放广告
        winUser->playVideoWin(videoFile.fileName());
        this->hide();
    }
    else
    {
        QMessageBox::warning(this, "提示", "用户名或密码不正确");
    }
}

void IntelligentCommunity::tcp_video_file(const QStringList &list)
{
    videoFile.setFileName(list.at(1));
    qDebug() << "name " << list.at(1);
    videoFile.open(QIODevice::WriteOnly);
    videoFileSize = list.at(2).toInt();
    qDebug() << "size " << list.at(2);
}

void IntelligentCommunity::tcp_write_video_file(const QByteArray & data)
{
    static qint64 receiveSize = 0;
    if(receiveSize < videoFileSize)
    {
        qint64 writed = videoFile.write(data);
        receiveSize += writed;
        if(receiveSize >= videoFileSize)
        {
            qDebug() << "received size = " << receiveSize;
            videoFile.close();
            receiveSize = 0;
        }
    }
}

/********************************************************************************
 * 向服务端发送请求video文件
 * 信息格式为："CODE:video file name:"
 * 附加的信息为当前的video文件名，若本地已存在则服务端不发送文件
********************************************************************************/
void IntelligentCommunity::get_video_file()
{
    QString videoInfo;
    videoInfo += (QString::number(GET_VIDEO_CODE));
    videoInfo += (TCP_INFO_SEPARATOR);
    videoInfo += (ui->line_account->text() + TCP_INFO_SEPARATOR);
    qDebug() << "send msg" << videoInfo;

    if(socket == nullptr)
    {
        qDebug() << "socket connect fail";
        return;
    }
    qint64 ret = socket->write(videoInfo.toUtf8());
    if(ret != videoInfo.length())
    {
        qDebug() << "write socket failed";
        return;
    }
    qDebug() << "write socket return:" << ret;
}

