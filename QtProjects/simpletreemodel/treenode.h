#ifndef TREENODE_H
#define TREENODE_H

#include <QString>
#include <QVector>
#include <QPair>
#include <QVariant>



class TreeNode
{
public:
    QString * TID;
    QString * DESCRIPTION;
    QString * UNIT;
    QString * LOW;
    QString * HIGH;
    QString * UUT0;
    QString * UUT1;
public:
    TreeNode();
    QString* Data(unsigned int colum);
private:
    QVector<QString *> nodeData;
};

#endif // TREENODE_H
