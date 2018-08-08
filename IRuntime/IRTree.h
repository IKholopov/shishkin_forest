#pragma once

#include <utility>
#include <unordered_map>
#include <IRTypes.h>

namespace IRuntime {
	
enum IROp {
    UN_OP,
    BIN_OP,
    MOV_OP,
    REG_OP,
    CALL_OP,
    EXPLIST_OP,
    EXPSEQ_OP,
    STMLIST_OP,
    MEM_OP,
    NAME_OP,
    CONST_OP,
    JUMP_OP,
    JUNPC_OP,
    LABEL_OP,
    
    NONE_OP
};

struct IRNodeData {
	std::vector<int> Child;
	int Parent;
	IROp Type;
	uint64_t Data;
	
	IRNodeData(): Parent(0), Type(NONE_OP), Data(0) 
	{}
};

class IRTree {
public:
    static const int NoParent = -1;

    IRTree(const IRTree&) = delete;
    IRTree(IRTree&&) = default;

    IRNodeData& AddNodeAt(IROp op, int parent = NoParent);
    const IRNodeData& operator[](int index) { return nodes[index]; }
	
private:
    std::vector<IRNodeData> nodes;
};

}

