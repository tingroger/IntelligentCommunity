#ifndef INTELLIGENTCOMMUNITY_H
#define INTELLIGENTCOMMUNITY_H

#include <QMainWindow>
#include <QTcpSocket>
#include "common_header.h"
#include "keyboard.h"
#include "win_register.h"
#include "win_user.h"

namespace Ui {
class IntelligentCommunity;
}

class IntelligentCommunity : public QMainWindow
{
    Q_OBJECT

public:
    explicit IntelligentCommunity(QWidget *parent = nullptr);
    ~IntelligentCommunity() override;

    /* 键盘相关 */
    bool eventFilter(QObject *watched, QEvent *event) override;

    /* TCP相关 */
    void tcp_user_login(const QStringList & list);
    void tcp_video_file(const QStringList & list);
    void tcp_write_video_file(const QByteArray & data);
    void get_video_file();

private slots:
    void slot_get_data();
    void on_btn_register_clicked();
    void on_btn_login_clicked();
    void on_btn_passwd_back_clicked();

private:
    Ui::IntelligentCommunity *ui;
    QTcpSocket *socket = nullptr;
    Keyboard * kb = nullptr;
    WinRegister * winRegister = nullptr;
    WinUser * winUser = nullptr;
    QFile videoFile;
    qint64 videoFileSize = 0;
};

#endif // INTELLIGENTCOMMUNITY_H
