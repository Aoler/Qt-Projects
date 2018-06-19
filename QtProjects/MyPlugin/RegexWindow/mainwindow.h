#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "regexpinterface.h"

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
    void on_btFilter_clicked();

private:
    bool LoadPlugin();

private:
    Ui::MainWindow *ui;
    RegexpInterface *regexpInterface;
};

#endif // MAINWINDOW_H
