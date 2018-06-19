#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class CPubliser;
class CReplier;
class CRequester;
class CSubscriber;

class TreeModel;
class QStackedWidget;
class QTreeView;
class QLabel;
class NetForm;

class mianform;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TreeModel *model;
    QTreeView *treeView;
    QStackedWidget *stackedWidget;

    QLabel *lab1;
    QLabel *lab2;
    QLabel *lab3;

    NetForm *netform;
    mianform * m_form;
};

#endif // MAINWINDOW_H
