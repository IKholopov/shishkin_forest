#pragma once

#include "IExp.h"

namespace IR {

class Binop : public IExp {
public:
    enum TBinop {
      TB_PLUS,
      TB_MINUS,
      TB_OR,
      TB_AND,
      TB_MUL,
      TB_MOD
    };

    const TBinop Operation;
    std::unique_ptr<const IExp> LeftExpression;
    std::unique_ptr<const IExp> RightExpression;

    Binop(TBinop operation, const IExp* leftExpression,
          const IExp* rightExpression, const Coords& coords=Coords()) :
        Operation(operation),
        LeftExpression(leftExpression),
        RightExpression(rightExpression),
        coords(coords)
    {}

    ACCEPT_IR_VISITOR
};

}
