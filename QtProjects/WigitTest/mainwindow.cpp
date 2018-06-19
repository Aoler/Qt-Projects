#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setDisplayFormat("yyyy年MM月dd日");
    qDebug() << "heloo";

}

MainWindow::~MainWindow()
{
    delete ui;
}
