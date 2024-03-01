#include "AddExpression.hpp"

AddExpression::AddExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {}

AddExpression::~AddExpression() {}

int AddExpression::solve() {
    return x->solve() + y->solve();
}

