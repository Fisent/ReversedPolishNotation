//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#include "CNode.h"
#include "../CTree.h"
#include "CNodeValue.h"
#include "CNodeOperator.h"
#include <sstream>
#include <iostream>


double CNode::ask(string value)
{
    cout << "Wpisz wartosc zmiennej " << value << ": ";
    double out;
    cin >> out;
}

CNode *CNode::generateInfix(string input)
{
    cout << "generateInfix: "<< input << endl;
    string* tab = CTree::splitInfix(input);
    cout << tab[0] << ":" << tab[1] << ":" << tab[2] << endl;
    if(tab[0] == "")
    {
        return new CNodeValue(tab[1]);
    }
    else
    {
        if(tab[0] == "+")return new CNodeOperator(CNode::generateInfix(tab[1]), CNode::generateInfix(tab[2]), ADD);
        if(tab[0] == "-")return new CNodeOperator(CNode::generateInfix(tab[1]), CNode::generateInfix(tab[2]), SUB);
        if(tab[0] == "*")return new CNodeOperator(CNode::generateInfix(tab[1]), CNode::generateInfix(tab[2]), MUL);
        if(tab[0] == "/")return new CNodeOperator(CNode::generateInfix(tab[1]), CNode::generateInfix(tab[2]), DIV);
    }
}


