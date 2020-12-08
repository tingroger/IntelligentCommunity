#include "intelligentcommunity.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IntelligentCommunity w;
    w.show();

    return a.exec();
}
