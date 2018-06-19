#ifndef TREENODE_H
#define TREENODE_H

#include <QString>
#include <QVector>
#include <QPair>
#include <QVariant>
#include <QStringList>


class TreeNode
{
public:
    QString  TID;
    QString  DESCRIPTION;
    QString  UNIT;
    QString  LOW;
    QString  HIGH;
    QString  UUT0;
    QString  UUT1;
public:
    TreeNode();
    TreeNode(const TreeNode &treeNode);
    const TreeNode& operator = (const TreeNode &treeNode);
    const QString& Data(unsigned int colum) const;
    void SetData(const QList<QVariant> &list);
    int Count() const;
private:
    QVector<QString> nodeData;
};

#endif // TREENODE_H
