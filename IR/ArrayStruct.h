#pragma once

#include "Exp.h"

namespace IR {

namespace ArrayStruct {

// Array format: [Length, 0, 1, ..., n - 1]

const int ElementsOffset = 1;

IExp* GetElement(const IExp* base, const IExp* elementNumber);
IExp* GetLength(const IExp* base);
IStm* AddReference(IExp* base);
IStm* RemoveReference(IExp* base);

}

}


