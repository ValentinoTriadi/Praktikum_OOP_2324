#include "Expression.hpp"

class NegativeExpression : public UnaryExpression{
    private:
    public:
        NegativeExpression(Expression* x);
        ~NegativeExpression();
        int solve();
};