//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CTREE_H
#define REVERSEDPOLISHNOTATION_CTREE_H


#include "CNodes/CNode.h"
#include <string>
#include <vector>
#include <map>


class CTree
{
private:
    CNode* root;
    std::string expression;
public:
    map<string, double> * values;
    CTree();
    ~CTree();
    void generatePostfix(string input);
    void generateInfix(string input);
    double calculate();
    string toString();
    //zwraca tablice stringow
    string* splitPostfix(string input, int* len);
    static string* splitInfix(string input);

};


#endif //REVERSEDPOLISHNOTATION_CTREE_H
