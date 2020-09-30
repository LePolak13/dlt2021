#include "chrono.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chrono w;
    w.show();

    return a.exec();
}
