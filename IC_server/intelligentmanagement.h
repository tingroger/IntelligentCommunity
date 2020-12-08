#ifndef INTELLIGENTMANAGEMENT_H
#define INTELLIGENTMANAGEMENT_H

#include <QMainWindow>
#include "win_admin.h"
#include "sqldatabase.h"


namespace Ui {
class IntelligentManagement;
}

class IntelligentManagement : public QMainWindow
{
    Q_OBJECT

public:
    explicit IntelligentManagement(QWidget *parent = nullptr);
    ~IntelligentManagement();


private slots:
    void on_btn_login_clicked();

private:
    Ui::IntelligentManagement *ui;
    WinAdmin * win_admin = nullptr;
    SqlDatabase *db = nullptr;
};

#endif // INTELLIGENTMANAGEMENT_H
