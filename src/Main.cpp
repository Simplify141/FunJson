#include <iostream>
#include <vector>
#include <string>
#include "JsonParser.h"
#include "FunJsonBuilder.h"
int main(int argc, char* argv[]) {
    
    std::wstring style;
    std::wstring graph;
    ParserTreeNode* root=new ParserTreeNode("root", "");
    argsParser(argc, argv, style, graph, root);
    FunJsonBuilder* builder=new FunJsonBuilderTest();
    FunJsonDirector* director=new FunJsonDirector(builder);
    FunJson* funjson=director->buildFunJson(root,graph,style);
    funjson->drawData();
}
