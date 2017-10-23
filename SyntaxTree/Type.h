#ifndef TYPE_H
#define TYPE_H
#include "common.h"

#include "TreeNode.h"

enum T_Type {
    T_Int,
    T_Boolean,
    T_IntArray,
    T_UserType
};

struct Type : public ITreeNode
{
    const T_Type TypeEnum;
    const Id* TypeName;

    Type(Coordinates coords,
         const T_Type typeEnum,
         const Id* name = nullptr) :
        coords(coords),
        TypeEnum(typeEnum),
        TypeName(name)
    {}

    ~Type() {
        if(TypeName != nullptr) {
            delete TypeName;
        }
    }

    ACCEPT_VISITOR
};

#endif
