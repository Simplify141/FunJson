#include <iostream>
#include <string>
#include <vector>
#include "JsonParser.h"
#include "TreeNode.h"
#pragma once
class FunJson
{
private:
    std::vector<std::wstring> json_data;

public:
    FunJson();
    void addData(std::wstring data);
    std::vector<std::wstring> getData();
    void setJsonData(std::vector<std::wstring> data);
    void drawData();
};

class FunJsonBuilder
{
private:
public:
    FunJsonBuilder();
    ~FunJsonBuilder();
    virtual void NodeConstructor(ParserTreeNode *root, std::wstring graph)=0;
    virtual void TreeConstructor()=0;
    virtual FunJson * createFunJson(std::wstring style)=0;
};

class FunJsonBuilderTest : public FunJsonBuilder
{
private:
    std::vector<Node *> nodeList;
    TreeNode *root;

public:
    FunJsonBuilderTest();
    ~FunJsonBuilderTest();
    virtual void NodeConstructor(ParserTreeNode *root, std::wstring graph);
    virtual void TreeConstructor();
    virtual FunJson * createFunJson(std::wstring style);
};

class FunJsonDirector
{
private:
    FunJsonBuilder *funjsonBuilder;

public:
    FunJsonDirector(FunJsonBuilder *funjsonBuilder);
    FunJson * buildFunJson(ParserTreeNode *root, std::wstring graph, std::wstring style);
};