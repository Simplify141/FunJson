#include <iostream>
#include <vector>
#include <string>
#include "Node.h"
class TreeNode
{
private:
    Node* node;
    int allChildNum;
public:
    void setNode(Node* node);
    void setAllChildNum(int allChildNum);

    Node* getNode();
    int getAllChildNum();

    virtual std::vector<TreeNode *> getChilds()=0;
    virtual void addChild(TreeNode *child)=0;
    virtual void deleleChild(TreeNode *child)=0;
    virtual void print()=0;
};

class TreeLeafNode : public TreeNode
{
private:
public:
    virtual std::vector<TreeNode *> getChilds();
    virtual void addChild(TreeNode *child);
    virtual void deleleChild(TreeNode *child);
    virtual void print();
};

class TreeMidNode : public TreeNode
{
private:
    std::vector<TreeNode *> childs;

public:
    virtual std::vector<TreeNode *> getChilds();
    virtual void addChild(TreeNode *child);
    virtual void deleleChild(TreeNode *child);
    virtual void print();
};
