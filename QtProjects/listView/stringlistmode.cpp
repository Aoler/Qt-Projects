#include "stringlistmode.h"

int StringListMode::rowCount(const QModelIndex &parent) const
{
    return stringList.count();
}

QVariant StringListMode::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.row()>=stringList.size())
        return QVariant();
    if(role==Qt::DisplayRole||role==Qt::EditRole)
        return stringList.at(index.row());
    else
        return QVariant();
}

QVariant StringListMode::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    if(orientation==Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);

}

Qt::ItemFlags StringListMode::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index)|Qt::ItemIsEditable;
}

bool StringListMode::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid()&&role==Qt::EditRole)
    {
        stringList.replace(index.row(),value.toString());
        emit dataChanged(index,index);
        return true;

    }
    return false;
}

bool StringListMode::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count-1);
    for(int row=0;row<count;++row){
        stringList.insert(row,"XX");
    }
    endInsertRows();
    return true;
}

bool StringListMode::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent,row,row+count-1);
    for(int row=0;row<count;++row){
        stringList.removeAt(row);
    }
    endRemoveRows();
    return true;

}





