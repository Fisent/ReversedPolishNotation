//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#include "CNodeValue.h"
#include <sstream>
#include <map>
#include <iostream>

string CNodeValue::toString()
{
    ostringstream stream;
    stream << value;
    string toReturn = stream.str();
    return toReturn;
}

CNodeValue::CNodeValue(string value)
{
    this->value = value;
}

double CNodeValue::calculate(bool* result, std::map<string, double> &dict)
{
    result = (bool* ) true;
    if(dict.find(value) != dict.end())
    {
        return dict[value];
    }
    else
    {
        dict[value] = ask(value);
        return dict.at(value);
    }
}


