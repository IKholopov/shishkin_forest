#pragma once

#include "IExp.h"
#include "IStm.h"

namespace IR {

class Move: public IStm {
public:
    std::unique_ptr<const IExp> Destination;
    std::unique_ptr<const IExp> Source;

    Move(const IExp* destination, const IExp* source):
        Destination(destination), Source(source)
    {}

    ACCEPT_IR_VISITOR
};

}
