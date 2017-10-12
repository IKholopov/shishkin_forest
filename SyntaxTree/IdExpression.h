#ifndef IDEXPRESSION_H
#define IDEXPRESSION_H
#include "common.h"

#include "Expression.h"
#include "Id.h"

struct IdExpression : public IExpression {
    const Id* ExpressionId;

    IdExpression(const Id* id) :
        ExpressionId(id) { }
    ~IdExpression() { delete ExpressionId; }

    ACCEPT_VISITOR
};
#endif // IDEXPRESSION_H
