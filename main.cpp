#include "DesctopApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesctopApp w;
    w.show();
    return a.exec();
}
