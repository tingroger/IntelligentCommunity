#include "win_admin.h"
#include "ui_win_admin.h"
#include <QFileDialog>

WinAdmin::WinAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WinAdmin)
{
    ui->setupUi(this);
    //初始化TCP服务
    init_tcp_server();
}

WinAdmin::~WinAdmin()
{
    delete ui;
}

void WinAdmin::on_btn_set_video_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开广告文件"), "/home");
    ui->label_video_filename->setText(fileName);
    ui->btn_send_video->setEnabled(true);
}

void WinAdmin::on_btn_send_video_clicked()
{
}

qint64 WinAdmin::send_video_head()
{
}

