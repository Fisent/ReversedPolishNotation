//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CTREE_H
#define REVERSEDPOLISHNOTATION_CTREE_H


#include "CNodes/CNode.h"
#include <string>
#include <vector>

class CTree
{
private:
    CNode* root;
    std::string expression;
public:
    CTree(CNode* root);
    ~CTree();
    void generate(std::string s);
    double calculate();
    string toString();

};


#endif //REVERSEDPOLISHNOTATION_CTREE_H
