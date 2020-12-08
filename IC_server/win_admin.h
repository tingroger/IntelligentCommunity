#ifndef WIN_ADMIN_H
#define WIN_ADMIN_H

#include <QMainWindow>
#include <QTableView>
#include "sqldatabase.h"
#include "editable_table.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class WinAdmin;
}

class WinAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit WinAdmin(QWidget *parent = nullptr);
    ~WinAdmin();

    /*user 相关*/
    void setDB(SqlDatabase *value);
    void init_user_table();

    /*TCP 相关*/
    void init_tcp_server();
    void tcp_register_new_user(const QStringList & list);
    void tcp_user_login(const QStringList & list);
    void tcp_video_file(const QStringList & list);
    qint64 send_video_head();

private slots:
    /*user 相关*/
    void slot_get_clicked_index(const QModelIndex &index);
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_refresh_clicked();

    /*TCP 相关*/
    void slot_new_client();
    void slot_get_data();
    void slot_send_video_file();

    /*setting 相关*/
    void on_btn_set_video_file_clicked();
    void on_btn_send_video_clicked();

signals:
    void sig_send_video();

private:
    Ui::WinAdmin *ui;

    /*user 相关*/
    SqlDatabase *db = nullptr;
    EditableTable *tableModel = nullptr;
    QTableView* view = nullptr;
    QModelIndex clickedIndex;

    /*TCP 相关*/
    QTcpServer *server = nullptr;
    QTcpSocket *socket = nullptr;
    QFile videoFile;
};

#endif // WIN_ADMIN_H
