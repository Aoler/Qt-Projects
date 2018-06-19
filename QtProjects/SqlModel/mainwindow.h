#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
class QSqlTableModel;
class QSqlRelationalTableModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,QSqlDatabase base=QSqlDatabase());
    ~MainWindow();

private slots:

    void on_pushButtonSubmit_clicked();

    void on_pushButtonRepeal_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonAll_clicked();

    void on_pushButtonQuery_clicked();

    void on_pushButtonAscending_clicked();

    void on_pushButtonDescending_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase &sqlBase;
    //QSqlTableModel *tableModle;
    QSqlRelationalTableModel *tableModle;
};

#endif // MAINWINDOW_H
