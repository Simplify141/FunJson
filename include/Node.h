#include <iostream>
#include <string>
class Node
{
private:
public:
    Node();
    ~Node();
    virtual std::wstring print() = 0;
    virtual int get_level() = 0;
};
class LeafNode : public Node
{
private:
    std::wstring graph;
    std::wstring node_name;
    int level;

public:
    void set_level(int levels);
    void set_graph(std::wstring graph_name);
    void set_node_name(std::wstring node_name);

    virtual int get_level();
    std::wstring get_graph();
    std::wstring get_node_name();

    LeafNode(std::wstring graph_name, std::wstring node_name);
    ~LeafNode();

    virtual std::wstring print();
};
class SliceLeafNode : public LeafNode
{
private:
public:
    SliceLeafNode(std::wstring graph_name, std::wstring node_name);
    ~SliceLeafNode();
};
class HeartLeafNode : public LeafNode
{
private:
public:
    HeartLeafNode(std::wstring graph_name, std::wstring node_name);
    ~HeartLeafNode();
};

class MidNode : public Node
{
private:
    std::wstring graph;
    std::wstring node_name;
    int level;

public:
    void set_level(int levels);
    void set_graph(std::wstring graph_name);
    void set_node_name(std::wstring node_name);

    virtual int get_level();
    std::wstring get_graph();
    std::wstring get_node_name();

    MidNode(std::wstring graph_name, std::wstring node_name);
    ~MidNode();

    virtual std::wstring print();
};
class SliceMidNode : public MidNode
{
private:
public:
    SliceMidNode(std::wstring graph_name, std::wstring node_name);
    ~SliceMidNode();
};
class HeartMidNode : public MidNode
{
private:
public:
    HeartMidNode(std::wstring graph_name, std::wstring node_name);
    ~HeartMidNode();
};

class NodeFactory
{
public:
    virtual LeafNode *createLeafNode(std::wstring graph_name, std::wstring node_name) = 0;
    virtual MidNode *createMidNode(std::wstring graph_name, std::wstring node_name) = 0;
};
class SliceNodeFactory : public NodeFactory
{
public:
    virtual LeafNode *createLeafNode(std::wstring graph_name, std::wstring node_name);
    virtual MidNode *createMidNode(std::wstring graph_name, std::wstring node_name);
};
class HeartNodeFactory : public NodeFactory
{
public:
    virtual LeafNode *createLeafNode(std::wstring graph_name, std::wstring node_name);
    virtual MidNode *createMidNode(std::wstring graph_name, std::wstring node_name);
};
