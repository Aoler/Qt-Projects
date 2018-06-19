#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDir>
#include <QPluginLoader>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!LoadPlugin())
    {
        QMessageBox::information(this,"Error","Load plugin fail");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::LoadPlugin()
{
//    QString pluginStr = QString("%1../plugins").arg(QCoreApplication::applicationDirPath());
//    qDebug() << "pluginStr:" << pluginStr;

    QDir pluginDir("/Users/mac/Documents/C++/QtProjects/plugins");
    foreach (QString filename, pluginDir.entryList(QDir::Files))
    {
        qDebug() << "filename:" << filename;
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(filename));
        QObject * plugin = pluginLoader.instance();
        if(plugin)
        {
            regexpInterface = qobject_cast<RegexpInterface *>(plugin);
            if(regexpInterface)
                return true;
        }
    }
    return false;
}

void MainWindow::on_btFilter_clicked()
{
    QString str = regexpInterface->Regexp(ui->lineString->text());
    ui->labelResult->setText(str);
}
