#ifndef REGEXPPLUGIN_H
#define REGEXPPLUGIN_H
#include <QObject>
#include "regexpinterface.h"

class  RegexpPlugin : public QObject,RegexpInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "qt-project.RegexpInterface" FILE "RegexpPlugin.json")

    /*其中，Q_PLUGIN_METADATA(...)宏,它基本是这些宏里最重要的一个，因为
    MOC会根据这个宏生成很多跟该插件相关的东西，包括元信息、获取插件实例的函数等。可用它可以将插件导出，其作用类似于老版本
    Qt中的 Q_EXPORT_PLUGIN2 宏*/

    Q_INTERFACES(RegexpInterface)
    /*Q_INTERFACES 在Qt的元对象系统中注册该接口 */
public:
    QString Regexp(const QString &message) override;
};

#endif // REGEXPPLUGIN_H
