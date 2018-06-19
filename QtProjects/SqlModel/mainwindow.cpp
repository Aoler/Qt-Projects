#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include<QSqlRelationalTableModel>
#include<QSqlRelationalDelegate>
#include<QTableView>
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent,QSqlDatabase base) :
    QMainWindow(parent),sqlBase(base),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/***********************QSqlQueryModel 模式***************************************/
//    QSqlQueryModel *model=new QSqlQueryModel(this);
//    model->setQuery("select * from student",sqlBase);
//    model->setHeaderData(0,Qt::Horizontal,tr("学号"));
//    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
//    model->setHeaderData(2,Qt::Horizontal,tr("课程"));

//    model->setQuery(QString("insert into student values(5,'雪景',10)"),sqlBase);
//    model->setQuery("select * from student",sqlBase);

//    QTableView *view=new QTableView(this);
//    view->setModel(model);
//    setCentralWidget(view);

/***********************QSqlTableModel 模式***************************************/
//    tableModle=new QSqlTableModel(this,sqlBase);
//    tableModle->setTable("student");
//    tableModle->select();
//    tableModle->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    tableModle->setHeaderData(0,Qt::Horizontal,tr("学号"));
//    tableModle->setHeaderData(1,Qt::Horizontal,tr("姓名"));
//    tableModle->setHeaderData(2,Qt::Horizontal,tr("课程"));
//    ui->tableView->setModel(tableModle);

/***********************QSqlRelationalTableModel 模式***************************************/
     tableModle=new QSqlRelationalTableModel(this,sqlBase);
     tableModle->setTable("student");
     tableModle->setRelation(2,QSqlRelation("course","id","name"));
     tableModle->select();
     tableModle->setHeaderData(0,Qt::Horizontal,tr("学号"));
     tableModle->setHeaderData(1,Qt::Horizontal,tr("姓名"));
     tableModle->setHeaderData(2,Qt::Horizontal,tr("课程"));
     ui->tableView->setModel(tableModle);
     ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonSubmit_clicked()
{
    tableModle->database().transaction();
    if(tableModle->submitAll())
    {
        tableModle->database().commit();

    }
    else
    {
        tableModle->database().rollback();
        QMessageBox::warning(this,tr("tableModle"),tr("dataBase error:%1").arg(tableModle->database().lastError().text()),QMessageBox::Ok);

    }
}

void MainWindow::on_pushButtonRepeal_clicked()
{
    tableModle->revertAll();
}

void MainWindow::on_pushButtonAdd_clicked()
{
    int rowNum=tableModle->rowCount();
    int id=rowNum+1;
    tableModle->insertRow(rowNum);
    tableModle->setData(tableModle->index(rowNum,0),id);
    //tableModle->submitAll();
}

void MainWindow::on_pushButtonDelete_clicked()
{
    int currRow=ui->tableView->currentIndex().row();
    int ok=QMessageBox::warning(this,tr("删除当前行"),tr("你确定删除当前行吗?"),QMessageBox::Ok,QMessageBox::Cancel);
    if(ok==QMessageBox::No)
    {
        tableModle->revertAll();
    }
    else
    {
        tableModle->removeRow(currRow);
        tableModle->submitAll();

    }
}

void MainWindow::on_pushButtonAll_clicked()
{
    tableModle->setTable("student");
    tableModle->select();
}

void MainWindow::on_pushButtonQuery_clicked()
{
    QString name=ui->lineEdit->text();
    tableModle->setFilter(QString("name='%1'").arg(name));
    tableModle->select();
}

void MainWindow::on_pushButtonAscending_clicked()
{
    tableModle->setSort(0,Qt::AscendingOrder);
    tableModle->select();
}

void MainWindow::on_pushButtonDescending_clicked()
{
    tableModle->setSort(0,Qt::DescendingOrder);
    tableModle->select();
}
