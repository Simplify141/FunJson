#include "JsonParser.h"
#include "Json.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
// 递归函数，用于将JSON对象转换为ParserTreeNode
void parseJson(const nlohmann::json &j, ParserTreeNode* node)
{
    for (const auto &item : j.items())
    {
        ParserTreeNode* child=new ParserTreeNode(item.key(), item.value().is_string() ? item.value().get<std::string>() : "");
        if (item.value().is_object() || item.value().is_array())
        {
            parseJson(item.value(), child);
        }
        node->children.push_back(child);
    }
}

void argsParser(int argc, char *argv[], std::wstring &style, std::wstring &graph,ParserTreeNode *root)
{   
    // 解析命令行参数
    std::string jsonPath;
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);

        if (arg == "-f" && i + 1 < argc)
        {   
            i++;
            std::cout << "JSON file: " << argv[i] << std::endl;
            jsonPath = argv[i];
        }
        else if (arg == "-s" && i + 1 < argc)
        {   
            i++;
            std::cout << "Style: " << argv[i] << std::endl;
            style =std::wstring(argv[i], argv[i] + std::strlen(argv[i])) ;
        }
        else if (arg == "-i" && i + 1 < argc)
        {   
            i++;
            std::cout << "Icon family: " << argv[i] << std::endl;
            graph=std::wstring(argv[i], argv[i] + std::strlen(argv[i]));
        }
        else
        {
            std::cerr << "Unknown argument: " << arg << std::endl;
        }
    }
    // 读取JSON文件
    std::ifstream ifs(jsonPath);
    if (!ifs.is_open())
    {
        std::cerr << "Failed to open file: " << jsonPath << std::endl;
        exit(1);
    }
    std::stringstream ss;
    ss << ifs.rdbuf();
    std::string jsonStr = ss.str();
    //std::cout << "JSON string: \n " << jsonStr << std::endl;
    ifs.close();
    nlohmann::json j=nlohmann::json::parse(jsonStr);
    // 将JSON对象转换为ParserTreeNode
    parseJson(j, root);

}