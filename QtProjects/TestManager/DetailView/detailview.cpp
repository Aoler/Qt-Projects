#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "detailview.h"
#include "ui_detailview.h"

DetailView::DetailView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailView)
{
    ui->setupUi(this);
    QVector<QVariant>  headerData;
    QMap<QString,TreeGroupData> treeGroupData;
    GetData(headerData, treeGroupData);
    model = new TreeModel(headerData, treeGroupData);
    ui->treeView->setModel(model);
    ui->treeView->expandAll();

}

DetailView::~DetailView()
{
    delete ui;
}

void DetailView::GetData(QVector<QVariant> &headerData, QMap<QString,TreeGroupData> &treeGroupData)
{


    QFile file("/Users/mac/Desktop/IAH512__Chamber1.csv");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "fail to open file";
        return;
    }
     QTextStream data(&file);

    QString line;
    //QStringList headerData;
    //QMap<QString,TreeGroupData> treeGroupData;
    if(!data.atEnd())
    {
        line = data.readLine();
//        QStringList list = line.split(",");
//        headerData << list; //获取Title
        headerData << "TID"<<"DESCRIPTION"<<"FUNCTION"<<"TIMEOUT"
                   <<"PARAM1"<<"PARAM2"<<"UNIT"<<"LOW"<<"HIGH"<<"KEY"<<"VAL";
    }

    while (!data.atEnd())
    {
        line = data.readLine();
        QStringList list = line.split(",");
        QString groupName;

         groupName = list[0];
         QVector<QVariant> lineData;
        for(int i = 1 ; i < list.size() ; ++i) //skip group data
        {
            lineData << list[i];
        }
         treeGroupData[groupName].push_back(lineData);

    }
    qDebug() << "read all file";
}
