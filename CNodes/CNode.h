//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#ifndef REVERSEDPOLISHNOTATION_CNODE_H
#define REVERSEDPOLISHNOTATION_CNODE_H

#include <string>

using namespace std;



class CNode
{
public:
    virtual string toString() = 0;
    //obliczba wartosc dzieci i zwraca ją, zaplikowawszy do swojego operatora
    virtual double calculate(bool* result) = 0;
};


#endif //REVERSEDPOLISHNOTATION_CNODE_H
