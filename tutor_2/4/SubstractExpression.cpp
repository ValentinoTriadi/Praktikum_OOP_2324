#include "SubstractExpression.hpp"

SubstractExpression::SubstractExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {}

SubstractExpression::~SubstractExpression() {}

int SubstractExpression::solve() {
    return x->solve() - y->solve();
}