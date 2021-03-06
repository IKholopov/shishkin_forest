#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H
#include "common.h"

#include "Statement.h"

namespace AST {

struct WhileStatement : public IStatement
{
    std::unique_ptr<const IExpression> Condition;
    std::unique_ptr<const IStatement> Body;

    WhileStatement(const Coordinates& coords,
                   const IExpression* condition,
                   const IStatement* statement) :
        Condition(condition),
        Body(statement),
        coords(coords)
    {}

    ACCEPT_AST_VISITOR
};

}

#endif
