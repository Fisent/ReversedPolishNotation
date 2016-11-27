//
// Created by Łukasz Zieniewicz on 16/11/16.
//
#include <sstream>
#include "CNodeOperator.h"

CNodeOperator::CNodeOperator(CNode *left, CNode *right, string operation)
{
    this->left = left;
    this->right = right;
    this->operation = operation;
}

CNodeOperator::~CNodeOperator()
{
    delete right;
    delete left;
}

string CNodeOperator::getOperation()
{
    return operation;
}

void CNodeOperator::setOperation(string operation)
{
    this->operation = operation;
}

double CNodeOperator::calculate(bool* result)
{
    result = (bool*) true;
    if(operation == "addition")
    {
        return right->calculate(result) + left->calculate(result);
    }
    if(operation == "substraction")
    {
        return right->calculate(result) - left->calculate(result);
    }
    if(operation == "multiplication")
    {
        return right->calculate(result) * left->calculate(result);
    }
    if(operation == "division")
    {
        return right->calculate(result) / left->calculate(result);
    }
    else result = (bool*) false;
    return -1;
}

string CNodeOperator::toString()
{
    ostringstream stream1;
    stream1 << left->toString();
    string toReturn = "<" + stream1.str() + ", ";
    ostringstream stream2;
    stream2 << right->toString();
    toReturn += stream2.str() + " " + operation + " >";
    return toReturn;
}
