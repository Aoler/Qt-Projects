#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QDir>
#include <QPluginLoader>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->statusBar->setHidden(true);
    //ui->statusBar->addPermanentWidget();
    //ui->menuBar->setHidden(true);
    _titleDock = new QDockWidget();
    _centerWnd = new QMainWindow();
    QVBoxLayout* v1 = new QVBoxLayout();
    v1->setContentsMargins(0,0,0,0);
    v1->setSpacing(50);
    v1->addWidget(_titleDock);
    v1->addWidget(_centerWnd, 1);


    _centerWnd->setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::South);
    _centerWnd->setDockOptions(AnimatedDocks | AllowNestedDocks | AllowTabbedDocks);

    //_centerDock = CreateDock("Center", new QWidget(),Qt::NoDockWidgetArea, QDockWidget::NoDockWidgetFeatures, false);
    _centerDock = CreateDock("Center", new QWidget());
    _leftDock = CreateDock("Left", new QWidget());
    _rightDock = CreateDock("right", new QWidget());
    _bottomDock = CreateDock("bottom", new QWidget());
    //_topDock = QUtil::CreateDock("Top", new QWidget());

    _centerWnd->addDockWidget(Qt::LeftDockWidgetArea, _centerDock);
    _centerWnd->splitDockWidget(_centerDock, _rightDock, Qt::Horizontal);
    //_centerWnd->splitDockWidget(_centerDock, _rightDock, Qt::Horizontal);
    _centerWnd->splitDockWidget(_centerDock, _bottomDock, Qt::Vertical);

//    _leftDock->widget()->setFixedWidth(170);
    _rightDock->widget()->setFixedWidth(300);
//    _bottomDock->widget()->setFixedHeight(150);

    QWidget* centerWgt = new QWidget();
    centerWgt->setLayout(v1);
    this->setCentralWidget(centerWgt);

//    tableWidgt = new QTableView();
//    modle = new QStandardItemModel(7,4,this);
//    for(int row = 0; row < 7; ++row)
//    {
//        for(int colum = 0; colum < 4; ++colum )
//        {

//            QStandardItem *item = new QStandardItem(QString("%1").arg(row*4+colum));
//            modle->setItem(row,colum,item);
//        }

//    }
//    tableWidgt->setModel(modle);
//    _centerDock->setWidget(tableWidgt);

//     titleWindow = new QWidget;
//     QHBoxLayout *titleLayout = new QHBoxLayout;
//     QLabel *name = new QLabel;
//     name->setText("Hello World");
//     titleLayout->addWidget(name);
//     titleWindow->setLayout(titleLayout);

     LoadPlugin();

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::LoadPlugin()
{
//    QString pluginStr = QString("%1../plugins").arg(QCoreApplication::applicationDirPath());
//    qDebug() << "pluginStr:" << pluginStr;

    QDir pluginDir("/Users/mac/Documents/C++/QtProjects/TestManager/OutPut/Debug");
    foreach (QString filename, pluginDir.entryList(QDir::Files))
    {
        qDebug() << "filename:" << filename;
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(filename));
        QObject * plugin = pluginLoader.instance();
        if(plugin)
        {
            pluginInterface = qobject_cast<PluginInterface *>(plugin);
            if(pluginInterface)
            {
                pluginInterface->SetMainWindow(this);
                pluginInterface->LoadUIPlugin();
                //return true;
            }
        }
    }
    return false;
}

void MainWindow::SetWidget(QWidget *widget, DockWidgetPos widgetPos)
{
    switch (widgetPos) {
    case TitleWidget:
        _titleDock->setWidget(widget);
        break;
    case CenterWidget:
        _centerDock->setWidget(widget);
        break;
    case RightWidget:
        _rightDock->setWidget(widget);
        break;
    case BottomWidget:
        _bottomDock->setWidget(widget);
        break;
    default:
        break;
    }
}

QDockWidget* MainWindow::CreateDock(const QString& name, QWidget* wgt, const Qt::DockWidgetAreas areas,
    const QDockWidget::DockWidgetFeatures features, bool isShowCaption)
{
    QDockWidget* dockWgt = new QDockWidget(name);
    dockWgt->setObjectName(name);
    dockWgt->setWidget(wgt);
    //设置dock的停靠属性
    dockWgt->setAllowedAreas(areas);

    //设置dock的特性 //DockWidgetClosable, DockWidgetMovable,DockWidgetFloatable
    dockWgt->setFeatures(features);

    //设置dock是否显示标题栏
    if (!isShowCaption)
    {
        dockWgt->setTitleBarWidget(new QWidget());
    }

    return dockWgt;
}

