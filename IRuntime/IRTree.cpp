#include "IRTree.h"

namespace IRuntime {
	
IRNodeData& AddNodeAt(IROp op, int parent) {
	nodes.push_back(IRNodeData{});
	IRNodeData& data = *nodes.rbegin();
	data.Parent = parent;
	data.Type = op;
	if(parent != NoParent) {
		nodes[parent].Child.push_back(nodes.size());
	}
}
	
}