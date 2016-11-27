#include <iostream>
#include <string>
#include "CNodes/CNode.h"
#include "CTree.h"
#include "CNodes/CNodeValue.h"
#include "CNodes/CNodeOperator.h"


using namespace std;




int main()
{
    CNodeOperator* c = new CNodeOperator(new CNodeOperator(new CNodeValue(3), new CNodeValue(15), MUL), new CNodeValue(20),ADD);
    cout << c->toString()<< endl;
    bool* result;
    cout << c->calculate(result) << endl;

    return 0;
}