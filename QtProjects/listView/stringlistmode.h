#ifndef STRINGLISTMODE_H
#define STRINGLISTMODE_H
#include<QAbstractListModel>
#include<QStringList>

class StringListMode:public QAbstractListModel
{
    Q_OBJECT
public:
    StringListMode(const QStringList &strings,QObject *parent=0)
            :QAbstractListModel(parent),stringList(strings){}
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
private:
    QStringList stringList;
};

#endif // STRINGLISTMODE_H
