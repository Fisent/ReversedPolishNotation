//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#include "CTree.h"

CTree::CTree(CNode *root)
{
    this->root = root;
}

CTree::~CTree()
{
    delete root;
}

void CTree::generate(std::string s)
{

}

string CTree::toString()
{
    return "CTree: " + root->toString();
}
