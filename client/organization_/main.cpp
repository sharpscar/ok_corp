#include "organization.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    organization w;
    w.show();
    return a.exec();
}
