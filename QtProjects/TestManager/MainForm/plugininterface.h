#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include "common.h"
#include <QObject>

class MainWindow;


class PluginInterface
{
public:
    PluginInterface();
    virtual ~PluginInterface();
public:
    void SetMainWindow(MainWindow *mainwnd);
    virtual void LoadUIPlugin();
    virtual void UnLoadUIPlugin();
protected:
    void SetWidget(QWidget *widget, DockWidgetPos widgetPos);
private:
     MainWindow *mainwindow;
};

Q_DECLARE_INTERFACE(PluginInterface,"Plugin.PluginInterface/1.0")
#endif // PLUGININTERFACE_H
