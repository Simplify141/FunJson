#include "FunJsonBuilder.h"

// 抽象策略类
class Strategy
{
public:
    virtual FunJson *create(std::vector<Node*>&nodeList)=0; // 策略方法
};
// 具体策略类A
class TreeJsonStrategy : public Strategy
{
public:
    virtual FunJson *create(std::vector<Node*>&nodeList);
};
// 具体策略类B
class RectJsonStrategy : public Strategy
{
public:
    virtual FunJson *create(std::vector<Node*>&nodeList);
};
// 环境类
class Context
{
private:
    Strategy* strategy;
public:
    Strategy* getStrategy();
    void setStrategy(Strategy* strategy);
    FunJson* strategyCreate(std::vector<Node*>nodeList);
};
