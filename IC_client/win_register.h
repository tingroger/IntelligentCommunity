#ifndef WIN_REGISTER_H
#define WIN_REGISTER_H

#include <QMainWindow>
#include "common_header.h"
#include "keyboard.h"
#include <QTcpSocket>

namespace Ui {
class WinRegister;
}

class WinRegister : public QMainWindow
{
    Q_OBJECT

public:
    explicit WinRegister(QWidget *parent = nullptr);
    ~WinRegister();

    /* 键盘相关 */
    bool eventFilter(QObject *watched, QEvent *event) override;
//    void setKB(Keyboard *value);

    void setSocket(QTcpSocket *value);
    void register_new_user(const QStringList & list);

private slots:
    void on_btn_submit_clicked();

    void on_btn_back_clicked();

private:
    Ui::WinRegister *ui;
    QTcpSocket *socket = nullptr;
    Keyboard * kb = nullptr;
};

#endif // WIN_REGISTER_H
