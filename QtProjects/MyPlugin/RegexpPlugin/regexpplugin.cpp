#include "regexpplugin.h"
#include <QRegExp>
#include <QtPlugin>

QString RegexpPlugin::Regexp(const QString &message)
{
    QRegExp rx("\\d+");
    rx.indexIn(message);
    QString str = rx.cap(0);
    return str;
}


//Q_EXPORT_PLUGIN2(regexpplugin,RegexpPlugin);
