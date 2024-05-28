#include "FunJsonBuilder.h"

class FunJsonFactory
{
public:
    virtual FunJson *create(TreeNode *root, std::wstring style) = 0;
};

class TreeJsonFactory : public FunJsonFactory
{
public:
    FunJson *create(TreeNode *root, std::wstring style);
};

class RectJsonFactory : public FunJsonFactory
{
public:
    FunJson *create(TreeNode *root, std::wstring style);
};
