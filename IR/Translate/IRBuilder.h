#pragma once
#include "common.h"

#include "Visitor.h"
#include "SubtreeWrapper.h"
#include "TypeStackVisitor.h"

namespace IRTranslate {

class IRBuilder : public AST::IVisitor {
public:

    IRBuilder(SymbolTable::Table* table) :
        table(table),
        TypeStackVisitor(table)
    {}

    void Parse(const AST::Program *program);

    IRForest& GetParseResults() { return trees; }

    virtual void Visit(const AST::Program* node) override;
    virtual void Visit(const AST::MainClass* node) override;
    virtual void Visit(const AST::ClassDeclaration* node) override;
    virtual void Visit(const AST::VarDeclaration* node) override {}
    virtual void Visit(const AST::MethodDeclaration* node) override;
    virtual void Visit(const AST::Sequence<const AST::ClassDeclaration>* node) override;
    virtual void Visit(const AST::Sequence<const AST::VarDeclaration>* node) override {}
    virtual void Visit(const AST::Sequence<const AST::MethodDeclaration>* node) override;
    virtual void Visit(const AST::Qualifier* node) override {}
    virtual void Visit(const AST::Type* node) override {}
    virtual void Visit(const AST::ReturnStatement* node) override;
    virtual void Visit(const AST::AssignArrayElementStatement* node) override;
    virtual void Visit(const AST::AssignStatement* node) override;
    virtual void Visit(const AST::PrintLineStatement* node) override;
    virtual void Visit(const AST::WhileStatement* node) override;
    virtual void Visit(const AST::BraceSequenceStatement* node) override;
    virtual void Visit(const AST::IfElseStatement* node) override;
    virtual void Visit(const AST::Sequence<const AST::IStatement>* node) override;
    virtual void Visit(const AST::BinaryExpression* node) override;
    virtual void Visit(const AST::ArrayMemberExpression* node) override;
    virtual void Visit(const AST::ArrayLengthExpression* node) override;
    virtual void Visit(const AST::CallMemberExpression* node) override;
    virtual void Visit(const AST::Sequence<const AST::IExpression>* node) override;
    virtual void Visit(const AST::ValueExpression* node) override;
    virtual void Visit(const AST::IdExpression* node) override;
    virtual void Visit(const AST::ThisExpression* node) override;
    virtual void Visit(const AST::NewIntArrayExpression* node) override;
    virtual void Visit(const AST::NewObjectExpression* node) override;
    virtual void Visit(const AST::NotExpression* node) override;
    virtual void Visit(const AST::ContainerExpression* node) override;
    virtual void Visit(const AST::Id* node) override { assert(false); }

private:
    std::unique_ptr<ISubtreeWrapper> mainSubtree;
    IRForest trees;
    SymbolTable::Table* table;
    SymbolTable::TypeStackVisitor TypeStackVisitor;
    const AR::IFrame* currentFrame;
};

}
