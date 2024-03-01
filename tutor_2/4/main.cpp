#include "Expression.hpp"
#include "AddExpression.hpp"
#include "SubstractExpression.hpp"
#include "NegativeExpression.hpp"
#include <iostream>
using namespace std;
    

int main (){
    AddExpression *e = new AddExpression(
        new TerminalExpression(4),
        new TerminalExpression(6)
        );
    cout << "Add Expression" << " " << e->solve() << endl;

    SubstractExpression *f = new SubstractExpression(
        new TerminalExpression(4),
        new TerminalExpression(6)
        );
    cout << "Substract Expression" << " " << f->solve() << endl;

    NegativeExpression *g = new NegativeExpression(
        new TerminalExpression(1)
    );
    cout << "Negative Expression" << " " << g->solve() << endl;

    return 0;
}