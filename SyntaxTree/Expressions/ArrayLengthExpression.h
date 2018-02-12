#ifndef ARRAYLENGTHEXPRESSION_H
#define ARRAYLENGTHEXPRESSION_H
#include "common.h"

#include "Expression.h"

namespace AST {

struct ArrayLengthExpression : public IExpression {
    std::unique_ptr<const IExpression> ArrayExpression;

    ArrayLengthExpression(Coordinates coords,
                          const IExpression* arrayExpression) :
        ArrayExpression(arrayExpression),
        coords(coords)
    {}

    ACCEPT_AST_VISITOR
};

}

#endif // ARRAYLENGTHEXPRESSION_H
