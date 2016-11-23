//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODE_H
#define REVERSEDPOLISHNOTATION_CNODE_H

#include <string>

using namespace std;



class CNode
{
protected:
    double value;
    CNode* right;
    CNode* left;
    string type;
public:
    string getType();
    CNode();
    CNode(CNode* left, CNode* right, double value);
    ~CNode();
    double getValue();
    CNode* getRight();
    CNode* getLeft();
    string toString();
    //obliczba wartosc dzieci i zwraca ją, zaplikowawszy do swojego operatora
    double calculate();
};


#endif //REVERSEDPOLISHNOTATION_CNODE_H
