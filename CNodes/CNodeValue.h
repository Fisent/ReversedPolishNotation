//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODEVALUE_H
#define REVERSEDPOLISHNOTATION_CNODEVALUE_H


#include <map>
#include "CNode.h"

class CNodeValue : public CNode
{
public:
    CNodeValue(string value);
    string toString();
    double calculate(bool* result, std::map<string, double> &dict);
private:
    string value;
};


#endif //REVERSEDPOLISHNOTATION_CNODEVALUE_H
