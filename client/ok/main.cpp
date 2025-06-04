#include <QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    LoginWindow w;
    w.show();
    return a.exec();
}
