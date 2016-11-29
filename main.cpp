#include <iostream>
#include <string>
#include "CNodes/CNode.h"
#include "CTree.h"
#include "CNodes/CNodeValue.h"
#include "CNodes/CNodeOperator.h"


using namespace std;




const string CLEAR = "clear";
const string POSTFIX = "postfix";
const string INFIX = "infix";
const string CHANGEVARIABLE = "change";
const string PRINTTREE = "print";
const string CALCULATE = "calculate";
const string QUIT = "quit";
const string HELP = "help";

void console()
{
    CTree* tree = new CTree();
    bool running = true;
    string input;
    string arg0;
    while(running)
    {
        cout << ">";
        cin >> input;
        if(input == CLEAR) tree = new CTree();
        else if(input == POSTFIX)
        {
            string toEvaluate;
            cout << "Wpisz wyrazenie w postaci postfiksowej: ";
            cin >> toEvaluate;
            tree->generatePostfix(toEvaluate);
        }
        else if(input == INFIX)
        {
            string toEvaluate;
            cout << "Wpisz wyrazenie w postaci infiksowej: ";
            cin >> toEvaluate;
            tree->generateInfix(toEvaluate);
        }
        else if(input == CHANGEVARIABLE)
        {
            cout << "Wpisz nazwe zmiennej, ktora chcesz zmienic: ";
            string zmienna;
            cin >> zmienna;
            cout << "Wpisz nowa wartosc: ";
            double value;
            cin >> value;
            tree->values->operator[](zmienna) = value;
        }
        else if(input == CALCULATE)
        {
            cout << "wynik: " <<tree->calculate() << endl;
        }
        else if(input == PRINTTREE)
        {
            cout << tree->toString() << endl;
        }
        else if(input == QUIT)
        {
            running = false;
        }
        else if(input == HELP)
        {
            cout << "Komendy: postfix, infix, calculate, change(zmienia wartosc zmiennej, lub dodaje te zmienna), print, clear" << endl;
        }
    }
}

int main()
{
    console();
    return 0;
}