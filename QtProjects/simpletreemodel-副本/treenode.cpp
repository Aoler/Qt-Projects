#include "treenode.h"

TreeNode::TreeNode()
{
    nodeData.append(this->TID);
    nodeData.append(this->DESCRIPTION);
    nodeData.append(this->UNIT);
    nodeData.append(this->LOW);
    nodeData.append(this->HIGH);
    nodeData.append(this->UUT0);
    nodeData.append(this->UUT1);
}

TreeNode::TreeNode(const TreeNode &treeNode)
{
    TID = treeNode.TID;
    DESCRIPTION = treeNode.DESCRIPTION;
    UNIT = treeNode.UNIT;
    LOW = treeNode.LOW;
    HIGH = treeNode.HIGH;
    UUT0 = treeNode.UUT0;
    UUT1 = treeNode.UUT1;
}

const TreeNode &TreeNode::operator =(const TreeNode &treeNode)
{
    TID = treeNode.TID;
    DESCRIPTION = treeNode.DESCRIPTION;
    UNIT = treeNode.UNIT;
    LOW = treeNode.LOW;
    HIGH = treeNode.HIGH;
    UUT0 = treeNode.UUT0;
    UUT1 = treeNode.UUT1;
    return *this;
}

const QString &TreeNode::Data(unsigned int colum) const
{
    switch (colum) {
    case 0:
        return this->TID;
    case 1:
        return this->DESCRIPTION;
    case 2:
        return this->UNIT;
    case 3:
        return this->LOW;
    case 4:
       return this->HIGH;
    case 5:
        return this->UUT0;
    case 6:
        return this->UUT1;
    default:
        return QString();
    }
}

void TreeNode::SetData(const QList<QVariant> &list)
{
    for(int i = 0 ; i < list.size() ; ++i)
    {
        switch (i) {
        case 0:
            this->TID = list.at(0).toString();
            break;
        case 1:
            this->DESCRIPTION = list.at(1).toString();
            break;
        case 2:
            this->UNIT = list.at(2).toString();
            break;
        case 3:
            this->LOW = list.at(3).toString();
            break;
        case 4:
            this->HIGH = list.at(4).toString();
            break;
        case 5:
            this->UUT0 = list.at(5).toString();
            break;
        case 6:
            this->UUT1 = list.at(6).toString();
            break;
        default:
            break;
        }
    }
}

int TreeNode::Count() const
{
    return nodeData.size();
}
