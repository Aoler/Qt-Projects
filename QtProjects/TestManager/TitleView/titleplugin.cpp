#include "titleplugin.h"
#include <QDebug>


TitlePlugin::TitlePlugin()
{
    titleView = new TitleView;
}


void TitlePlugin::LoadUIPlugin()
{
    qDebug() << "TitlePlugin::LoadUIPlugin()";
    SetWidget(titleView,TitleWidget);
}

void TitlePlugin::UnLoadUIPlugin()
{

}
