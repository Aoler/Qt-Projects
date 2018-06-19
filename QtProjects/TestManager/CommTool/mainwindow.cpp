#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QTreeView>
#include <QSplitter>
#include <QTextEdit>

#include "treemodel.h"
#include "netform.h"
//#include "mianform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //int count = ui->stackedWidget->count();
    //ui->stackedWidget->currentWidget()->setWindowTitle("hello");
    QStringList headerList;
    headerList << "Type";
    model = new TreeModel(headerList,this);

    QVector<QVariant> typeData;
    typeData.append("ZmqRequst");
    typeData.append("ZmqReplier");
    typeData.append("ZmqRequester");
    typeData.append("ZmqSubscriber");
    typeData.append("TcpClient");
    typeData.append("TcpServer");
    typeData.append("SerialPort");


    model->setupModelData(typeData);

    treeView = new QTreeView(this);
    treeView->setModel(model);



    stackedWidget = new QStackedWidget();
    netform = new NetForm();
    stackedWidget->addWidget(netform);
//    netform->show();

//    lab1 = new QLabel(tr("This is window 1"));
//    stackedWidget->addWidget(lab1);
//    lab2 = new QLabel(tr("This is window 2"));
//    stackedWidget->addWidget(lab2);
//    lab3 = new QLabel(tr("This is window 3"));
//    stackedWidget->addWidget(lab3);


    //布局；
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(treeView);
    mainLayout->addWidget(stackedWidget,0,Qt::AlignHCenter);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->setStretchFactor(treeView,1);
    mainLayout->setStretchFactor(stackedWidget,3);
    this->centralWidget()->setLayout(mainLayout);
    //connect(ui->listWidget,SIGNAL(currentRowChanged(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));



}

MainWindow::~MainWindow()
{
    delete ui;
}
