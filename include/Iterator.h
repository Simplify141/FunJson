#include "Node.h"
#include <vector>
// 抽象迭代器
class Iterator
{
public:
    virtual Node *first() = 0;

    virtual Node *next() = 0;
};

// 具体迭代器
class TreeNodeIterator : public Iterator
{
private:
    std::vector<Node *> nodeList;
    int index;

public:
    TreeNodeIterator(std::vector<Node *> nodeList);

    Node *first();

    Node *next();
};
// 抽象聚合
class Aggregate
{
public:
    virtual Iterator *getIterator() = 0;
};
// 具体聚合
class TreeNodeAggregate : public Aggregate
{

private:
    std::vector<Node *> nodeList;

public:
    TreeNodeAggregate(std::vector<Node *> nodeList);
    virtual Iterator *getIterator();
};
