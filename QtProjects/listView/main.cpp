#include "stringlistmode.h"
#include <QApplication>
#include<QListView>
#include<QTableView>
#include<QErrorMessage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QErrorMessage *dialog = new QErrorMessage();
//    dialog->showMessage("错误信息");

    QStringList list;
    list<<"a"<<"b"<<"c";
    //QAbstractItemModel *model=new StringListMode(list);
    StringListMode model(list);
    QListView listView;
    listView.setModel(&model);
    listView.show();

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    model.insertRows(2,2,QModelIndex());
    model.removeRows(4,2,QModelIndex());


    return a.exec();
}
