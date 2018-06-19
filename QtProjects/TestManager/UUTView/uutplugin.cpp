#include "uutplugin.h"
#include <QDebug>

UUTPlugin::UUTPlugin()
{
    uutview = new UUTView;
}

void UUTPlugin::LoadUIPlugin()
{
    qDebug() << "UUTPlugin::LoadUIPlugin()";
    SetWidget(uutview,RightWidget);
}

void UUTPlugin::UnLoadUIPlugin()
{

}
