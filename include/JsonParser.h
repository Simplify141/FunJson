#include <string>
#include <vector>
#include "Json.h"
#pragma once
// 定义树节点结构体
struct ParserTreeNode {
    std::string key;
    std::string value;
    std::vector<ParserTreeNode*> children;

    // 构造函数
    ParserTreeNode(std::string k, std::string v) : key(k), value(v) {}
};
void parseJson(const nlohmann::json& j, ParserTreeNode& node);
void argsParser(int argc, char* argv[], std::wstring& style, std::wstring& graph,ParserTreeNode* root);