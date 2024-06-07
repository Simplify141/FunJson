#include "FunJsonBuilder.h"
#include "StyleStrategy.h"
#include "Node.h"
#include <locale>
#include <codecvt>
#include <iostream>
FunJson::FunJson()
{
}

void FunJson::addData(std::wstring data)
{
    json_data.push_back(data);
}
std::vector<std::wstring> FunJson::getData()
{
    return json_data;
}
void FunJson::setJsonData(std::vector<std::wstring> data)
{
    json_data = data;
}
void FunJson::drawData()
{
    setlocale(LC_ALL, "chs");
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    for (auto line : json_data)
    {
        std::cout << converter.to_bytes(line) << std::endl;
    }
};

FunJsonBuilder::FunJsonBuilder(){

};
FunJsonBuilder::~FunJsonBuilder(){

};

FunJsonBuilderTest::FunJsonBuilderTest(){

};

FunJsonBuilderTest::~FunJsonBuilderTest(){

};

void leftIteration(ParserTreeNode *root, NodeFactory *factory, std::vector<Node *> &nodeList, std::wstring graph, int level)
{
    std::wstring key(root->key.begin(), root->key.end());
    std::wstring value(root->value.begin(), root->value.end());
    if (root->children.size() == 0)
    {
        LeafNode *tempLeaf;
        if (root->value != "")
            tempLeaf = factory->createLeafNode(graph, key + L": " + value);
        else
            tempLeaf = factory->createLeafNode(graph, key + L": ");
        tempLeaf->set_level(level);
        nodeList.push_back(tempLeaf);
    }
    else
    {
        MidNode *tempMid = factory->createMidNode(graph, key);
        tempMid->set_level(level);
        nodeList.push_back(tempMid);
        for (auto child : root->children)
        {
            leftIteration(child, factory, nodeList, graph, level + 1);
        }
    }
};
void checkLast(std::vector<Node *> &nodeList)
{
    for (int i = 0; i < nodeList.size() - 1; i++)
    {
        for (int j = i + 1; j < nodeList.size(); j++)
        {
            if (nodeList[i]->get_level() == nodeList[j]->get_level())
            {
                nodeList[i]->set_isLast(false);
                break;
            }
            else if (nodeList[i]->get_level() == nodeList[j]->get_level() + 1)
            {
                nodeList[i]->set_isLast(true);
                break;
            }
        }
        bool temp = false;
        for (int j = i + 1; j < nodeList.size(); j++)
        {

            if (nodeList[i]->get_level() >= nodeList[j]->get_level())
            {
                temp = true;
            }
        }
        nodeList[i]->set_isLast(!temp || nodeList[i]->get_isLast());
    }
    nodeList[nodeList.size() - 1]->set_isLast(true);
};
void FunJsonBuilderTest::NodeConstructor(ParserTreeNode *root, std::wstring graph)
{
    if (graph == L"slice")
    {
        NodeFactory *sliceFactory = new SliceNodeFactory();
        leftIteration(root, sliceFactory, nodeList, graph, 0);
    }
    else if (graph == L"heart")
    {
        NodeFactory *heartFactory = new HeartNodeFactory();
        leftIteration(root, heartFactory, nodeList, graph, 0);
    }
    checkLast(this->nodeList);
};

// void iterCreateTree(TreeNode *root, std::vector<Node *> nodeList, int start, int end)
// {
//     root->setNode(nodeList[start]);
//     for (int i = start + 1; i < end; i++)
//     {
//         if (nodeList[i]->get_level() == nodeList[start]->get_level())
//         {
//             return;
//         }

//         else if (nodeList[i]->get_level() == nodeList[start]->get_level() + 1)
//         {

//             if (dynamic_cast<MidNode *>(nodeList[i]))
//             {
//                 TreeNode *temp = new TreeMidNode();
//                 temp->setNode(nodeList[i]);
//                 temp->getNode()->print();
//                 temp->setParent(root);
//                 root->addChild(temp);
//                 iterCreateTree(temp, nodeList, i, end);
//             }
//             else if (dynamic_cast<LeafNode *>(nodeList[i]))
//             {
//                 TreeNode *temp = new TreeLeafNode();
//                 temp->setNode(nodeList[i]);
//                 temp->setParent(root);
//                 temp->getNode()->print();
//                 root->addChild(temp);
//             }
//         }
//     }
// }

// int childNumUpdate(TreeNode *root)
// {
//     if (dynamic_cast<TreeLeafNode *>(root))
//     {
//         return 1;
//     }
//     int num = 0;
//     int childNum = root->getChilds().size();
//     for (int i = 0; i < childNum; i++)
//     {
//         TreeNode *temp = root->getChilds()[i];
//         num += childNumUpdate(temp);
//     }
//     root->setAllChildNum(num);
// };

void FunJsonBuilderTest::TreeConstructor()
{
    root = new TreeMidNode();
    // iterCreateTree(root, nodeList, 0, nodeList.size());
    // childNumUpdate(root);
};

FunJson *FunJsonBuilderTest::createFunJson(std::wstring style)
{
    Context *context = new Context();
    FunJson *funjson;
    if (style == L"tree")
    {
        Strategy *strategy = new TreeJsonStrategy();
        context->setStrategy(strategy);
        funjson = strategy->create(this->nodeList);
        return funjson;
    }
    else if (style == L"rect")
    {
        Strategy *strategy = new RectJsonStrategy();
        context->setStrategy(strategy);
        funjson = strategy->create(this->nodeList);
        return funjson;
    }
    return NULL;
};

FunJsonDirector::FunJsonDirector(FunJsonBuilder *funjsonBuilder)
{
    this->funjsonBuilder = funjsonBuilder;
}

FunJson *FunJsonDirector::buildFunJson(ParserTreeNode *root, std::wstring graph, std::wstring style)
{
    funjsonBuilder->NodeConstructor(root, graph);
    // funjsonBuilder->TreeConstructor();
    FunJson *funjson = funjsonBuilder->createFunJson(style);
    return funjson;
};
