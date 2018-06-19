#include "plugininterface.h"
#include "mainwindow.h"
#include <QDebug>

PluginInterface::PluginInterface()
{ 
}

PluginInterface::~PluginInterface()
{

}

void PluginInterface::SetMainWindow(MainWindow *mainwnd)
{
    mainwindow = mainwnd;
}

void PluginInterface::LoadUIPlugin()
{
    qDebug() << "PluginInterface::LoadUIPlugin()";
}

void PluginInterface::UnLoadUIPlugin()
{
    qDebug() << "PluginInterface::UnLoadUIPlugin()";
}

void PluginInterface::SetWidget(QWidget *widget, DockWidgetPos widgetPos)
{
    mainwindow->SetWidget(widget,widgetPos);
}
