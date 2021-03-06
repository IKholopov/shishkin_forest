#pragma once

#include "common.h"

#include <stack>
#include "TreeTypes.h"
#include "Table.h"

namespace SymbolTable {

class TypeScopeSwitcher {
public:
    TypeScopeSwitcher(const TypeInfo& type, Table* table,
                      const Position& position);
    TypeScopeSwitcher(const std::string& className, Table* table,
                      const Position& position);
    ~TypeScopeSwitcher();

private:
    Table* table;
    const TypeInfo& type;
};

class MethodScopeSwitcher {
public:
    MethodScopeSwitcher(const MethodInfo* method, Table* table,
                              const Position& position);
    MethodScopeSwitcher(const std::string& name , Table* table,
                              const Position& position);
    ~MethodScopeSwitcher();

private:
    Table* table;
} ;


class TypeStackVisitor: public AST::IVisitor {
public:
    TypeStackVisitor(Table* table);

    const SymbolTable::TypeInfo* PopTypeFromStack();
    const SymbolTable::TypeInfo* GetTypeFromStack() const;

    virtual void Visit(const AST::Program* node) override {}
    virtual void Visit(const AST::MainClass* node) override {}
    virtual void Visit(const AST::ClassDeclaration* node) override {}
    virtual void Visit(const AST::VarDeclaration *node) override {}
    virtual void Visit(const AST::MethodDeclaration *node) override {}
    virtual void Visit(const AST::Sequence<const AST::ClassDeclaration>* node) override {}
    virtual void Visit(const AST::Sequence<const AST::VarDeclaration>* node) override {}
    virtual void Visit(const AST::Sequence<const AST::MethodDeclaration>* node) override {}
    virtual void Visit(const AST::Qualifier* node) override {}
    virtual void Visit(const AST::Type* node) override {}
    virtual void Visit(const AST::ReturnStatement* node) override {}
    virtual void Visit(const AST::AssignArrayElementStatement* node) override {}
    virtual void Visit(const AST::AssignStatement* node) override {}
    virtual void Visit(const AST::PrintLineStatement* node) override {}
    virtual void Visit(const AST::WhileStatement* node) override {}
    virtual void Visit(const AST::BraceSequenceStatement* node) override {}
    virtual void Visit(const AST::IfElseStatement* node) override {}
    virtual void Visit(const AST::Sequence<const AST::IStatement>* node) override {}
    virtual void Visit(const AST::BinaryExpression* node) override;
    virtual void Visit(const AST::ArrayMemberExpression* node) override;
    virtual void Visit(const AST::ArrayLengthExpression* node) override;
    virtual void Visit(const AST::CallMemberExpression* node) override;
    virtual void Visit(const AST::Sequence<const AST::IExpression>* node) override {}
    virtual void Visit(const AST::ValueExpression* node) override;
    virtual void Visit(const AST::IdExpression* node) override;
    virtual void Visit(const AST::ThisExpression* node) override;
    virtual void Visit(const AST::NewIntArrayExpression* node) override;
    virtual void Visit(const AST::NewObjectExpression* node) override;
    virtual void Visit(const AST::NotExpression* node) override;
    virtual void Visit(const AST::ContainerExpression* node) override {}
    virtual void Visit(const AST::Id* node) override {}

private:
    SymbolTable::Table* table;
    std::stack<const SymbolTable::TypeInfo*> typesStack;

    const SymbolTable::TypeInfo* popTypeStack();
};

inline const SymbolTable::TypeInfo* TypeStackVisitor::popTypeStack() {
    auto type = typesStack.top();
    typesStack.pop();
    return type;
}

}
