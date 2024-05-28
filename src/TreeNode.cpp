#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeNode.h"

void TreeNode::setNode(Node *nodes)
{
    this->node = nodes;
}
void TreeNode::setAllChildNum(int allChildNum)
{
    this->allChildNum = allChildNum;
}

Node *TreeNode::getNode()
{
    return this->node;
}

int TreeNode::getAllChildNum()
{
    return this->allChildNum;
}



std::vector<TreeNode *> TreeLeafNode::getChilds()
{
    //std::cout << "Leaf Node has no childs" << std::endl;
    return std::vector<TreeNode *>();
}

void TreeLeafNode::addChild(TreeNode *child)
{
    std::cout << "Leaf Node cannot have childs" << std::endl;
}
void TreeLeafNode::deleleChild(TreeNode *child)
{
    std::cout << "Leaf Node cannot have childs" << std::endl;
}
void TreeLeafNode::print()
{
    getNode()->print();
}

std::vector<TreeNode *> TreeMidNode::getChilds()
{
    return childs;
}

void TreeMidNode::addChild(TreeNode *child)
{
    childs.push_back(child);
}
void TreeMidNode::deleleChild(TreeNode *child)
{
    childs.erase(std::find(childs.begin(), childs.end(), child));
}
void TreeMidNode::print()
{
    getNode()->print();
}
