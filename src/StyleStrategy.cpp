#include "StyleStrategy.h"
#include "Iterator.h"

void printTreeTree(std::vector<Node *> &nodeList, FunJson *funjson, std::vector<bool> &isLast)
{   
    for (int i = 0; i < nodeList.size(); ++i)
    {
       // std::cout<<nodeList[i]->get_level()<<" "<<nodeList[i]->get_isLast()<<" ";
    }
    for (int i = 0; i < nodeList.size(); ++i)
    {
        std::wstring temp = L"";
        if (nodeList[i]->get_isLast() == true)
        {
            isLast[nodeList[i]->get_level()] = true;
        }
        else
        {
            isLast[nodeList[i]->get_level()] = false;
        }
        for (int j = 1; j < nodeList[i]->get_level(); ++j)
        {
            if (isLast[j])
                temp += L"    ";
            else
                temp += L"│   ";
        }
        if (nodeList[i]->get_isLast())
            temp += L"└─ ";
        else
            temp += L"├─ ";
        std::wstring printResult = nodeList[i]->print();
        temp.append(printResult);
        funjson->addData(temp);
    }
}

void printTreeRect(std::vector<Node *> &nodeList, FunJson *funjson)
{
    for (int i = 0; i < nodeList.size(); ++i)
    {
        std::wstring temp = L"";
        for (int j = 1; j < nodeList[i]->get_level(); ++j)
        {
            temp += L"│   ";
        }
        temp += L"├─ ";
        std::wstring printResult = nodeList[i]->print();
        temp.append(printResult);
        funjson->addData(temp);
    }
}

FunJson *TreeJsonStrategy::create(std::vector<Node *> &nodeList)
{
    FunJson *funjson = new FunJson();
    std::vector<bool> isLast(7, false);
    Aggregate *aggregate = new TreeNodeAggregate(nodeList);
    Iterator *iterator = aggregate->getIterator();
    printTreeTree(nodeList, funjson, isLast);
    return funjson;
}

FunJson *RectJsonStrategy::create(std::vector<Node *> &nodeList)
{
    FunJson *funjson = new FunJson();
    printTreeRect(nodeList, funjson);
    std::vector<std::wstring> datas = funjson->getData();
    for (int i = 0; i < datas.size(); ++i)
    {
        // for (int j = 0; j < datas[i].size(); ++j)
        // {
        //     std::cout << datas[i][j] << " ";
        // }
        int beginSize = datas[i].size();
        for (int j = 0; j < 79 - beginSize; ++j)
            datas[i] = datas[i] + L"─";
        datas[i] += L"┤";
    }
    datas[0].erase(0, 1);
    datas[0].erase(datas[0].size() - 1, 1);
    datas[0] = L"┌" + datas[0] + L"┐";
    datas[datas.size() - 1].erase(0, 1);
    datas[datas.size() - 1].erase(datas[datas.size() - 1].size() - 1, 1);
    datas[datas.size() - 1] = L"└" + datas[datas.size() - 1] + L"┘";
    for (int i = 1; i < 80; ++i)
    {
        if ((datas[datas.size() - 1][i] == L'│') || (datas[datas.size() - 1][i] == L'├'))
        {
            datas[datas.size() - 1].erase(i, 1);
            datas[datas.size() - 1].insert(i, L"┴");
        }
        if ((datas[datas.size() - 1][i] == L' '))
        {
            datas[datas.size() - 1].erase(i, 1);
            datas[datas.size() - 1].insert(i, L"─");
        }
    }
    funjson->setJsonData(datas);
    return funjson;
}

Strategy *Context::getStrategy()
{
    return strategy;
}
void Context::setStrategy(Strategy *strategy)
{
    this->strategy = strategy;
}
FunJson *Context::strategyCreate(std::vector<Node *> nodeList)
{
    return strategy->create(nodeList);
}
