#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);
    ui->uutWidget->setLayout(layout);

    form = new Form();
    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->addWidget(form);
    ui->widget->setLayout(layout2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
