//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODEVALUE_H
#define REVERSEDPOLISHNOTATION_CNODEVALUE_H


#include "CNode.h"

class CNodeValue : public CNode
{
public:
    CNodeValue(double value);
    string toString();
    double calculate(bool* result);
private:
    double value;
};


#endif //REVERSEDPOLISHNOTATION_CNODEVALUE_H
