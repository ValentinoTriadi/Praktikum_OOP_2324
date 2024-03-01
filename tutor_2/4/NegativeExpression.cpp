#include "NegativeExpression.hpp"

NegativeExpression::NegativeExpression(Expression* x) : UnaryExpression(x) {}

NegativeExpression::~NegativeExpression() {}

int NegativeExpression::solve() {
    return -x->solve();
}