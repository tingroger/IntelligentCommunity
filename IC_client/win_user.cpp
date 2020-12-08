#include "win_user.h"
#include "ui_win_user.h"
#include <QLabel>
#include <QPushButton>

WinUser::WinUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WinUser)
{
    ui->setupUi(this);
}

WinUser::~WinUser()
{
    delete ui;
}

//("http://apis.juhe.cn/simpleWeather/query?city=%E5%B9%BF%E5%B7%9E&key=2000cd9e62ec9131b6fcf5a02e2150c0");
void WinUser::playVideoWin(const QString & fileName)
{
    if(proPlayVideo.state() == QProcess::Running)
    {
        proPlayVideo.kill();
        proPlayVideo.waitForFinished();
    }

    QLabel *lable_video = new QLabel(ui->centralwidget);
    lable_video->resize(800, 480);
    lable_video->move(0, 0);
    lable_video->setText("");
    QPushButton *btn_close_video = new QPushButton(lable_video);
    connect(btn_close_video, &QPushButton::clicked, this, &WinUser::slot_close_video);

    //创建可选参数列表
    //mpalyer -slave -quiet -wid 窗口ID号 媒体的路径
    QStringList argments;
    argments << "-slave" << "-quiet" << "-wid"
             << QString::number(lable_video->winId())
             << fileName;
    qDebug() << argments;
    //利用第三方播放器来实现视频播放
    proPlayVideo.start("mplayer",argments);
}

void WinUser::slot_close_video()
{
   dynamic_cast<QLabel *>(sender())->close();
   proPlayVideo.kill();

}

