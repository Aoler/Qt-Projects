#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QTableView>
#include "common.h"
#include "plugininterface.h"

class QStandardItemModel;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void SetWidget(QWidget *widget, DockWidgetPos widgetPos);
private:
    QDockWidget* CreateDock(const QString& name, QWidget* wgt,
        const Qt::DockWidgetAreas areas = Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea,
        const QDockWidget::DockWidgetFeatures features = QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable,
        bool isShowCaption = true);
    bool LoadPlugin();


private:
    Ui::MainWindow *ui;
    QDockWidget  *_titleDock;
    QMainWindow *_centerWnd;
    QDockWidget* _centerDock;
    QDockWidget* _leftDock;
    QDockWidget* _rightDock;
    QDockWidget* _bottomDock;

    QTableView  * tableWidgt;
    QStandardItemModel *modle;

    QWidget *mwindow;
    QWidget *titleWindow;

    PluginInterface *pluginInterface;

};

#endif // MAINWINDOW_H
