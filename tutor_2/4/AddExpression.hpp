#include "Expression.hpp"

class AddExpression : public BinaryExpression{
    private:
    public:
        AddExpression(Expression* x, Expression* y);
        ~AddExpression();
        int solve();

};
