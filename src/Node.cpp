#include "Node.h"

Node::Node() {}
Node::~Node() {}

LeafNode::LeafNode(std::wstring graph_name, std::wstring node_name)
{
    set_graph(graph_name);
    set_node_name(node_name);
}
LeafNode::~LeafNode()
{
}

void LeafNode::set_graph(std::wstring graph_name)
{
    graph = graph_name;
}
void LeafNode::set_node_name(std::wstring node_name)
{
    this->node_name = node_name;
}
void LeafNode::set_level(int levels)
{
    this->level = levels;
}
void LeafNode::set_isLast(bool isLast)
{
    this->isLast = isLast;
}
bool LeafNode::get_isLast()
{
    return isLast;
}
std::wstring LeafNode::get_graph()
{
    return graph;
}
std::wstring LeafNode::get_node_name()
{
    return node_name;
}
int LeafNode::get_level()
{
    return level;
}
std::wstring LeafNode::print()
{
    std::wstring temp = L"";
    temp += this->graph + this->node_name;
    return temp;
}

SliceLeafNode::SliceLeafNode(std::wstring graph_name, std::wstring node_name) : LeafNode(graph_name, node_name)
{
    set_graph(L"◆ ");
}
SliceLeafNode::~SliceLeafNode()
{
}

HeartLeafNode::HeartLeafNode(std::wstring graph_name, std::wstring node_name) : LeafNode(graph_name, node_name)
{
    set_graph(L"♥ ");
}
HeartLeafNode::~HeartLeafNode()
{
}

MidNode::MidNode(std::wstring graph_name, std::wstring node_name)
{
    set_graph(graph_name);
    set_node_name(node_name);
}
MidNode::~MidNode()
{
}

void MidNode::set_level(int levels)
{
    this->level = levels;
}

void MidNode::set_isLast(bool isLast)
{
    this->isLast = isLast;
}
bool MidNode::get_isLast()
{
    return isLast;
}
void MidNode::set_graph(std::wstring graph_name)
{
    graph = graph_name;
}
void MidNode::set_node_name(std::wstring node_name)
{
    this->node_name = node_name;
}

std::wstring MidNode::get_graph()
{
    return graph;
}
std::wstring MidNode::get_node_name()
{
    return node_name;
}

int MidNode::get_level()
{
    return level;
}

std::wstring MidNode::print()
{
    std::wstring temp = L"";
    temp += this->graph + this->node_name;
    return temp;
}

SliceMidNode::SliceMidNode(std::wstring graph_name, std::wstring node_name) : MidNode(graph_name, node_name)
{
    set_graph(L"◇ ");
}
SliceMidNode::~SliceMidNode()
{
}

HeartMidNode::HeartMidNode(std::wstring graph_name, std::wstring node_name) : MidNode(graph_name, node_name)
{
    set_graph(L"♡ ");
}
HeartMidNode::~HeartMidNode()
{
}

LeafNode *SliceNodeFactory::createLeafNode(std::wstring graph_name, std::wstring node_name)
{
    return new SliceLeafNode(graph_name, node_name);
}
MidNode *SliceNodeFactory::createMidNode(std::wstring graph_name, std::wstring node_name)
{
    return new SliceMidNode(graph_name, node_name);
}

LeafNode *HeartNodeFactory::createLeafNode(std::wstring graph_name, std::wstring node_name)
{
    return new HeartLeafNode(graph_name, node_name);
}
MidNode *HeartNodeFactory::createMidNode(std::wstring graph_name, std::wstring node_name)
{
    return new HeartMidNode(graph_name, node_name);
}
