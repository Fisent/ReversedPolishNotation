//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODEOPERATOR_H
#define REVERSEDPOLISHNOTATION_CNODEOPERATOR_H


#include "CNode.h"


const string ADD = "addition";
const string SUB = "substraction";
const string MUL = "multiplication";
const string DIV = "division";

class CNodeOperator : CNode
{
public:
    CNodeOperator(CNode* left, CNode* right);
    ~CNodeOperator();

};


#endif //REVERSEDPOLISHNOTATION_CNODEOPERATOR_H
