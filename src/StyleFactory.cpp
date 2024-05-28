#include "StyleFactory.h"

void printTreeTree(TreeNode *root, FunJson *funjson, std::vector<bool> &isLast)
{
    if (root == nullptr && root->getChilds().empty())
        return;

    for (int i = 0; i < root->getChilds().size(); ++i)
    {
        TreeNode *child = root->getChilds()[i];
        if (i != root->getChilds().size() - 1)
        {
            std::wstring temp = L"";
            isLast[child->getNode()->get_level()] = false;
            for (int j = 1; j < child->getNode()->get_level(); ++j)
            {
                if (isLast[j])
                    temp += L"    ";
                else
                    temp += L"│   ";
            }
            temp += L"├─ ";
            std::wstring printResult = child->getNode()->print();
            temp.append(printResult);
            funjson->addData(temp);
            printTreeTree(child, funjson, isLast);
        }
        else
        {
            std::wstring temp = L"";
            isLast[child->getNode()->get_level()] = true;
            for (int j = 1; j < child->getNode()->get_level(); ++j)
            {
                if (isLast[j])
                    temp += L"    ";
                else
                    temp += L"│   ";
            }
            temp += L"└─ ";
            std::wstring printResult = child->getNode()->print();
            temp.append(printResult);
            funjson->addData(temp);
            printTreeTree(child, funjson, isLast);
        }
    }
}

void printTreeRect(TreeNode *root, FunJson *funjson)
{
    if (root == nullptr && root->getChilds().empty())
        return;

    for (int i = 0; i < root->getChilds().size(); ++i)
    {
        TreeNode *child = root->getChilds()[i];
        std::wstring temp = L"";
        for (int j = 1; j < child->getNode()->get_level(); ++j)
        {
            temp += L"│   ";
        }
        temp += L"├─ ";
        std::wstring printResult = child->getNode()->print();
        temp.append(printResult);
        funjson->addData(temp);
        printTreeRect(child, funjson);
    }
}

FunJson *TreeJsonFactory::create(TreeNode *root, std::wstring style)
{
    FunJson *funjson = new FunJson();
    std::vector<bool> isLast(7, false);
    printTreeTree(root, funjson, isLast);
    return funjson;
}

FunJson *RectJsonFactory::create(TreeNode *root, std::wstring style)
{
    FunJson *funjson = new FunJson();
    printTreeRect(root, funjson);
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
         if ( (datas[datas.size() - 1][i] == L' '))
        {
            datas[datas.size() - 1].erase(i, 1);
            datas[datas.size() - 1].insert(i, L"─");
        }
    }
    funjson->setJsonData(datas);
    return funjson;
}