//
// Created by Łukasz Zieniewicz on 16/11/16.
//

#include "CTree.h"
#include "CNodes/CNodeOperator.h"
#include "CNodes/CNodeValue.h"
#include <stack>
#include <iostream>
#include <string>
#include <sstream>

CTree::CTree()
{
    values = new map<string, double>();
    values->operator[]("one") = 1.0;
}

CTree::~CTree()
{
    delete values;
}

void CTree::generatePostfix(std::string s)
{
    stack<CNode*>* st = new stack<CNode*>();
    int* length = new int();
    string* tab = splitPostfix(s, length);
    for(int i = 0; i<(*length);i++)
    {
        string current = tab[i];
        CNode* node1;
        CNode* node2;
        if(current == "*" || current == "-" || current == "/" || current == "+")
        {
            if(st->size() == 0)
            {
                cout << "BLAD: brak dwoch argumentow dla operacji: " << current << ", generuje wartosci 1 i 1" << endl;
                st->push(new CNodeValue("one"));
                st->push(new CNodeValue("one"));
            }
            if(st->size() == 1)
            {
                cout << "BLAD: brak argumentow dla operacji: " << current << ", generuje wartosc 1" << endl;
                st->push(new CNodeValue("one"));
            }
            node1 = st->top();
            st->pop();
            node2 = st->top();
            st->pop();
        }
        if(current == "*" ) st->push(new CNodeOperator(node1, node2, MUL));
        else if(current == "+" ) st->push(new CNodeOperator(node1, node2, ADD));
        else if(current == "-" ) st->push(new CNodeOperator(node1, node2, SUB));
        else if(current == "/" ) st->push(new CNodeOperator(node1, node2, DIV));
        else
        {
            CNodeValue* node = new CNodeValue(current);
            st->push(node);
        }
    }
    if(st->size()!=0)
    {
        cout << "BLAD: w wyrazeniu pozostały"
    }
    root = st->top();
    delete st;
}

string CTree::toString()
{
    return "CTree: " + root->toString();
}

double CTree::calculate()
{
    bool* result = (bool*) true;
    return root->calculate(result, *values);
}

string* CTree::splitPostfix(string s, int* len)
{
    string* out = new string[100];
    int outLen = 0;
    string buffer = "";

    for(char c : s)
    {
        if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            if(buffer != "")
            {
                out[outLen++] = buffer;
                (*len)++;
                buffer = "";
            }
            string s(1,c);
            out[outLen++] = s;
        }
        else if(c == ' ' && buffer != "")
        {
            out[outLen++] = buffer;
            buffer = "";
        }
        else if(c == ' '){}
        else
        {
            string temp(1,c);
            buffer += temp;
        }
    }

    if(buffer != "") out[outLen++] = buffer;
    (*len) = outLen;
    return out;
}

string *CTree::splitInfix(string input)
{
    string* out = new string[3];
    out[0] = ""; out[1] = ""; out[2] = "";
    int counter = 0;
    bool flagFound = false;
    for(int i = 0; i<input.length(); i++)
    {
        if(input[i] == '(')counter++;
        if(input[i] == ')')counter--;
        if(counter == 1 && (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'))
        {
            string s(1,input[i]);
            out[0] = s;
            //TODO
            string out1 = "";
            string out2 = "";
            for(int j = 1; j<i; j++)
            {
                out1 += string(1,input[j]);
            }
            for(int j = i+1; j<input.length()-1; j++)
            {
                out2 += string(1,input[j]);
            }
            flagFound = true;
            out[1] = out1;
            out[2] = out2;
        }
    }
    if(!flagFound)
    {
        out[1] = input;
    }

    return out;
}

void CTree::generateInfix(string input)
{
    root = CNode::generateInfix(input);
}
