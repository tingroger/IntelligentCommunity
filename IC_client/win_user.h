#ifndef WIN_USER_H
#define WIN_USER_H

#include <QMainWindow>
#include <QProcess>
#include "common_header.h"
namespace Ui {
class WinUser;
}

class WinUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit WinUser(QWidget *parent = nullptr);
    ~WinUser();

    void playVideoWin(const QString & fileName);

private slots:
    void slot_close_video();

private:
    Ui::WinUser *ui;
    QProcess proPlayVideo;
};

#endif // WIN_USER_H
