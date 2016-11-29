//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODE_H
#define REVERSEDPOLISHNOTATION_CNODE_H

#include <string>
#include <map>

using namespace std;



class CNode
{
public:
    virtual string toString() = 0;
    //obliczba wartosc dzieci i zwraca ją, zaplikowawszy do swojego operatora
    virtual double calculate(bool* result, std::map<string, double> &dict) = 0;
    double ask(string value);
    static CNode* generateInfix(string input);
};


#endif //REVERSEDPOLISHNOTATION_CNODE_H
