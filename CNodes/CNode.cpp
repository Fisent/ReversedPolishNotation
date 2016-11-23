//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#include "CNode.h"
#include <sstream>


CNode::CNode(CNode *left, CNode *right, double value)
{
    this->left = left;
    this->right = right;
    this->value = value;
}

CNode::CNode()
{

}

double CNode::getValue()
{
    return value;
}

CNode* CNode::getRight()
{
    return right;
}

CNode* CNode::getLeft()
{
    return left;
}

CNode::~CNode()
{
    delete right;
    delete left;
}

string CNode::getType()
{
    return type;
}

string CNode::toString()
{
    std::ostringstream os;
    os << value;
    string val = os.str();


    if(type == VAL) return "[ + " + type + ", val: " + val + "]" + "\n";
    return "[ " + type + ", val: " + val + " left: " + left->toString() + " right: " + right->toString() + "]\n";
}

