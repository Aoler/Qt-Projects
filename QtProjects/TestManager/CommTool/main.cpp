#include "mainwindow.h"
#include "netform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //NetForm netform;
    MainWindow w;
    w.show();

    return a.exec();
}
