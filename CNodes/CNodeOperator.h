//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODEOPERATOR_H
#define REVERSEDPOLISHNOTATION_CNODEOPERATOR_H


#include "CNode.h"


static const string ADD = "addition";
static const string SUB = "substraction";
static const string MUL = "multiplication";
static const string DIV = "division";

class CNodeOperator : public CNode
{
public:
    CNodeOperator(CNode* left, CNode* right, string operation);
    ~CNodeOperator();
    string getOperation();
    void setOperation(string operation);
    string toString();
    double calculate(bool* result, std::map<string, double> &dict);
private:
    string operation;
    CNode* left;
    CNode* right;
};


#endif //REVERSEDPOLISHNOTATION_CNODEOPERATOR_H
