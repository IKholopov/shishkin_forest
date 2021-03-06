#include <LifecycleNode.h>

namespace RegLifecycle {

LifecycleNode::LifecycleNode(const CodeGeneration::IInstruction* instruction,
                             const std::vector<IR::Temp>& used, const std::vector<IR::Temp>& defined):
    instruction(instruction),
    isMove(false)
{
    for(auto& u: used) {
        this->used.insert(u);
    }
    for(auto& d: defined) {
        this->defined.insert(d);
    }
    const CG::MoveInstruction* move = dynamic_cast<const CG::MoveInstruction*>(instruction);
    if(move != nullptr && instruction->DefinedVars().size() > 0)
    {
        isMove = move->PureMove();
    }
}

bool LifecycleNode::Update()
{
    bool inserted = false;
    for(auto t: used) {
        inserted |= in.insert(t).second;
    }
    for(auto outNode: next) {
        for(auto inNode: outNode->in) {
            inserted |= out.insert(inNode).second;
        }
    }

    for(auto outNode: out) {
        if(defined.find(outNode) == defined.end()) {
            inserted |= in.insert(outNode).second;
        }
    }
    return inserted;
}

std::string LifecycleNode::Format() const
{
    std::string name = isMove ? "move |" : " |";
    /*
    for(auto& t: in) {
        name += " " + t.Name() + "[" + std::to_string(t.Id) + " ]";
    }
    name += " |";
    for(auto& t: out) {
        name += " " + t.Name() + "[" + std::to_string(t.Id) + " ]";
    }
    name += " |";
    */
    name += instruction->Format();
    return name;
}

}
