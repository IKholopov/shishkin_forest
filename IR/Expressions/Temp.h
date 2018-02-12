#pragma once

#include "IExp.h"
#include "TempAddress.h"
#include <memory>
#include <string>

namespace AR = ActivationRecords;

namespace IR {

class Temp : public IExp {
public:
    enum T_AdditionalInfo{
      AI_Id,
      AI_Name
    };
    const int Id;

    explicit Temp(std::string name);
    explicit Temp(int localId);
    Temp(const Temp& temp);

    const T_AdditionalInfo Info() const { return info; }
    const std::string Name() const { return name; }
    int LocalId() const { return localId; }

private:
    const int localId;
    std::string name;
    T_AdditionalInfo info;

    ACCEPT_IR_VISITOR
};

}
