#ifndef DETAILPLUGIN_H
#define DETAILPLUGIN_H
#include "plugininterface.h"
#include "detailview.h"
#include <QObject>

class DetailPlugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "qt-project.PluginInterface" FILE "DetailView.json")

    /*其中，Q_PLUGIN_METADATA(...)宏,它基本是这些宏里最重要的一个，因为
    MOC会根据这个宏生成很多跟该插件相关的东西，包括元信息、获取插件实例的函数等。可用它可以将插件导出，其作用类似于老版本
    Qt中的 Q_EXPORT_PLUGIN2 宏*/

    Q_INTERFACES(PluginInterface)
public:
    DetailPlugin();
public:
    virtual void LoadUIPlugin() override;
    virtual void UnLoadUIPlugin() override;
private:
    DetailView *detailView;
};

#endif // DETAILPLUGIN_H
