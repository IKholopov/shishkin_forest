#ifndef METHODDECLARATION_H
#define METHODDECLARATION_H
#include "common.h"

#include <assert.h>

#include "Qualifier.h"
#include "VarDeclaration.h"
#include "Statements/ReturnStatement.h"

struct MethodDeclaration : public ITreeNode
{
    const Qualifier* QualifierType;
    const Type* ReturnType;
    const Id* MethodName;
    const ReturnStatement* StatementToReturn;

    //Nullable
    const Sequence<const VarDeclaration>* Arguments;
    const Sequence<const VarDeclaration>* VarDeclarations;
    const Sequence<const IStatement>* Statements;

    MethodDeclaration(Coordinates coords,
                      const Qualifier* qualifier,
                      const Type* returnType,
                      const Id* methodName,
                      const Sequence<const VarDeclaration>* argumentSequence,
                      const Sequence<const VarDeclaration>* varDeclarations,
                      const Sequence<const IStatement>* statements,
                      const ReturnStatement* returnStatement) :
        coords(coords),
        QualifierType(qualifier),
        ReturnType(returnType),
        MethodName(methodName),
        StatementToReturn(returnStatement),
        Arguments(argumentSequence),
        VarDeclarations(varDeclarations),
        Statements(statements)
    {
        assert(argumentSequence);
    }

    ~MethodDeclaration() {
        delete QualifierType;
        delete ReturnType;
        delete MethodName;
        delete StatementToReturn;
        if(Arguments != nullptr) {
            delete Arguments;
        }
        if(VarDeclarations != nullptr) {
            delete VarDeclarations;
        }
        if(Statements != nullptr) {
            delete Statements;
        }
    }

    ACCEPT_VISITOR
};

#endif