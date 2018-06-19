#include "mainwindow.h"
#include"connection.h"
#include <QApplication>
#include<QTextCodec>
#include<QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    if(!creatConnection("sqlModel.db")) return 1;
    QSqlDatabase db=QSqlDatabase::database("sqlModel");
    MainWindow w(0,db);
    w.show();

    return a.exec();
}
