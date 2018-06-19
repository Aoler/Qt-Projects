#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H
#include <QString>

class  RegexpInterface
{

public:
    virtual ~RegexpInterface() {}
    virtual QString Regexp(const QString &message) = 0;
};

Q_DECLARE_INTERFACE(RegexpInterface,"Plugin.RegexpInterface/1.0")

#endif // PLUGIN_INTERFACE_H
