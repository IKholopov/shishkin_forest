#pragma once
#include "common.h"

#include <unordered_map>
#include "IExp.h"
#include "IStm.h"
#include "StringSymbol.h"
#include "Label.h"

namespace IRTranslate {

interface ISubtreeWrapper {
    virtual ~ISubtreeWrapper() { }

    virtual const IR::IExp* ToExp() = 0;
    virtual const IR::IStm* ToStm() = 0;
    virtual const IR::IStm* ToConditional(const IR::Label* trueLabel,
                                          const IR::Label* falseLabel) = 0;
    virtual void AcceptVisitor(IR::IIRVisitor* visitor) const = 0;
};

typedef std::unordered_map<const StringSymbol*, std::unique_ptr<ISubtreeWrapper>> IRForest;
  
}
