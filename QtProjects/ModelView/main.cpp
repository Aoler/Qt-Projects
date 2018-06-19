#include <QApplication>
#include<QTreeView>
#include<QListView>
#include<QStandardItemModel>
#include<QPixmap>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel model;
    QStandardItem *parent=model.invisibleRootItem();
    QStandardItem *item0=new QStandardItem;
    item0->setText("Item 0");
    QPixmap pix(50,50);
    pix.fill("red");
    item0->setIcon(QIcon(pix));
    item0->setToolTip("indexA");

    parent->appendRow(item0);
    parent=item0;

    QStandardItem *item1=new QStandardItem;
    QPixmap pix1(50,50);
    pix1.fill("blue");
    item1->setData("B",Qt::EditRole);
    item1->setData("indexB",Qt::ToolTipRole);
    item1->setData(QIcon(pix1),Qt::DecorationRole);
    parent->appendRow(item1);

    QTreeView view;
    view.setModel(&model);
    view.show();
    return a.exec();
}
