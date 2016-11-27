//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#include "CNodeValue.h"
#include <sstream>

string CNodeValue::toString()
{
    ostringstream stream;
    stream << value;
    string toReturn = stream.str();
    return toReturn;
}

CNodeValue::CNodeValue(double value)
{
    this->value = value;
}

double CNodeValue::calculate(bool* result)
{
    result = (bool* ) true;
    return value;
}

