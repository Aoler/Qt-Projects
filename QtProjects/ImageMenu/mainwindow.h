#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"tablemodel.h"
#include"stringlistmode.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_New_triggered();

private:
    Ui::MainWindow *ui;
    TableModel *model ;
    StringListMode *modelList;
};

#endif // MAINWINDOW_H
