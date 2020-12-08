#include "intelligentmanagement.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IntelligentManagement w;
    w.show();

    return a.exec();
}
