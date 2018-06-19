#include "detailplugin.h"
#include <QDebug>

DetailPlugin::DetailPlugin()
{
    detailView = new DetailView;
}

void DetailPlugin::LoadUIPlugin()
{
    qDebug() << "DetailPlugin::LoadUIPlugin()";
    SetWidget(detailView,CenterWidget);
}

void DetailPlugin::UnLoadUIPlugin()
{

}
