#include "treenode.h"

TreeNode::TreeNode()
{
    TID = new QString;
    DESCRIPTION = new QString;
    UNIT = new QString;
    LOW = new QString;
    HIGH = new QString;
    UUT0 = new QString;
    UUT1 = new QString;

    nodeData.append(this->TID);
    nodeData.append(this->DESCRIPTION);
    nodeData.append(this->UNIT);
    nodeData.append(this->LOW);
    nodeData.append(this->HIGH);
    nodeData.append(this->UUT0);
    nodeData.append(this->UUT1);
}

QString *TreeNode::Data(unsigned int colum)
{
    return nodeData[colum];
}
