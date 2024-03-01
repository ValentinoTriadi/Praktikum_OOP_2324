#include "Expression.hpp"

class SubstractExpression : public BinaryExpression{
    private:
    public:
        SubstractExpression(Expression* x, Expression* y);
        ~SubstractExpression();
        int solve();

};