#include "Iterator.h"

TreeNodeIterator::TreeNodeIterator(std::vector<Node*> nodeList)
{
    this->nodeList = nodeList;
    this->index = 0;
}

Node *TreeNodeIterator::first()
{
    return nodeList.empty()? nullptr : nodeList[0];
}

Node *TreeNodeIterator::next()
{
    return nodeList[++index];
}


TreeNodeAggregate::TreeNodeAggregate(std::vector<Node*> nodeList)
{
    this->nodeList = nodeList;
}
Iterator* TreeNodeAggregate::getIterator()
{
    return new TreeNodeIterator(this->nodeList);
}