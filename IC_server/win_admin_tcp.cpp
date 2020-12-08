#include "win_admin.h"
#include "ui_win_admin.h"
#include <QFileInfo>

void WinAdmin::init_tcp_server()
{
    server = new QTcpServer;
    //监听客户端
    if(!server->listen(QHostAddress::Any,SERVER_PORT))
    {
        qDebug() << "TCP server listen failed";
        return;
    }

    //建立newConnection信号的槽连接
    connect(server,&QTcpServer::newConnection,this, &WinAdmin::slot_new_client);

}


void WinAdmin::slot_new_client()
{
    qDebug() << "TCP new connection";
    //接受挂起的连接作为已连接的QTcpSocket
    socket = server->nextPendingConnection();

    //当客户端有信息(数据块)到达时，会发送readyRead()，建立与该信号对应的槽函数
    connect(socket, &QTcpSocket::readyRead, this, &WinAdmin::slot_get_data);

}

void WinAdmin::slot_get_data()
{
    QByteArray msg = socket->readAll();
    QString ip = socket->peerAddress().toString();
    qDebug() << "ip = " << ip;
    qDebug() << "msg = " << msg;

    QStringList info = QString::fromUtf8(msg).split(TCP_INFO_SEPARATOR);
    int code = info[0].toInt();
    qDebug() << "code = " << code;
    switch(code)
    {
    case REGISTER_CODE:
        tcp_register_new_user(info);
        break;
    case LOGIN_CODE:
        tcp_user_login(info);
        break;
    case GET_VIDEO_CODE:
        tcp_video_file(info);
        break;
    }
}

void WinAdmin::tcp_register_new_user(const QStringList &list)
{
    User *newUser = new User;
    newUser->set_user_role(resident);
    newUser->set_user_account(list.at(1));
    newUser->set_user_passwd(list.at(2));
    newUser->set_user_phone(list.at(3).toULong());

    QString registerACK;
    registerACK += QString::number(REGISTER_ACK);
    registerACK += TCP_INFO_SEPARATOR;
    if(db->insert_new_user(*newUser))
    {
        init_user_table();
        registerACK += "1";
    }
    else
    {
        registerACK += "0";
    }
    socket->write(registerACK.toUtf8());
}

void WinAdmin::tcp_user_login(const QStringList &list)
{
    bool isNewUser = false;
    QString loginACK;
    loginACK += QString::number(LOGIN_ACK);
    loginACK += TCP_INFO_SEPARATOR;

    User user;
    if(db->get_user_by_item(account, list.at(1), user) &&
            list.at(2) == user.get_user_passwd())
    {
        loginACK += "1";
        isNewUser = true;
    }
    else {
        loginACK += "0";
    }
    socket->write(loginACK.toUtf8());

   if(isNewUser)
   {
       static int row = 0;
       ui->table_login_user->setRowCount(row+1);
        QString ip = socket->peerAddress().toString();
        qDebug() << "ip = " << ip;
        qDebug() << "account = " << list.at(1);
        QTableWidgetItem *newLoginIP = new QTableWidgetItem(ip);
        QTableWidgetItem *newLoginAccount = new QTableWidgetItem(list.at(1));
        ui->table_login_user->setItem(row, 0, newLoginIP);
        ui->table_login_user->setItem(row, 1, newLoginAccount);
//        ui->table_login_user->show();
        ++row;
   }
}

void WinAdmin::tcp_video_file(const QStringList &list)
{
    //文件名为空或者客户端已有该文件则返回
    if(ui->label_video_filename->text() == "" ||
       ui->label_video_filename->text() == list.at(1))
        return;

    //获取文件信息
    QFileInfo fileinfo(ui->label_video_filename->text());

    QString videoFileACK;
    videoFileACK += QString::number(GET_VIDEO_ACK);
    videoFileACK += TCP_INFO_SEPARATOR;
    videoFileACK += (fileinfo.fileName() + TCP_INFO_SEPARATOR);
    videoFileACK += (QString::number(fileinfo.size()) + TCP_INFO_SEPARATOR);
    socket->write(videoFileACK.toUtf8());

    //准备文件
    videoFile.setFileName(ui->label_video_filename->text());
    videoFile.open(QIODevice::ReadOnly);

   //写入文件
    static qint64 sendSize = 0;
    while(sendSize < fileinfo.size())
    {
        QByteArray data = videoFile.read(TRANSFER_MAX_SIZE);
        qint64 writed = socket->write(data);
        sendSize += writed;
        qDebug() << "send size = " << sendSize;
        emit sig_send_video();
    }
    qDebug() << fileinfo.size();
    qDebug() << videoFile.size();

    if(sendSize == fileinfo.size())
    {
        qDebug() << "发送文件成功";
        videoFile.close();
        sendSize = 0;
    }
    else if(sendSize > fileinfo.size())
    {
        qDebug() << "发送文件失败";
        videoFile.close();
        sendSize = 0;
    }

//    connect(this, &WinAdmin::sig_send_video, this, &WinAdmin::slot_send_video_file);
//    emit sig_send_video();
}

void WinAdmin::slot_send_video_file()
{
    static qint64 sendSize = 0;
    if(sendSize < videoFile.size())
    {
        QByteArray data = videoFile.read(TRANSFER_MAX_SIZE);
        qint64 writed = socket->write(data);
        qDebug() << "write size = "<< writed;
        sendSize += writed;
        emit sig_send_video();
    }
    else if(sendSize == videoFile.size())
    {
        videoFile.close();
        sendSize = 0;
    }
    else
    {
        qDebug() << "发送文件失败";
    }
}
