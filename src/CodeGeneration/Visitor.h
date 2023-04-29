//
// Created by Relisqu on 29.04.2023.
//
#pragma once

#include "AST/AST.h"
#include "ICodeGeneratable.h"

using namespace ast;


class Visitor : public ast::Visitor{
public:
    ICodeGeneratable codeGeneratable;
    void visit(const Program &node) override {

        for (const auto& n : node.nodes) {
            n->accept(this);
        }
    }

    void visit(const Node &node) override {

    }

    void visit(const Block &node) override {
        for (const auto& n : node.nodes) {
            n->accept(this);
        }
    }

    void visit(const Routine &node) override {

        if (node.ident) {
            node.ident->accept(this);
        }

        for (const auto& n : node.parameters) {
            n->accept(this);
        }
        if (node.returnType) {
            node.returnType->accept(this);
        }

        if (node.body) {
            node.body->accept(this);
        }
        for (const auto& n : node.returnStatements) {
            n->accept(this);
        }
    }

    void visit(const Statement &node) override {

    }

    void visit(const ReturnStatement &node) override {

        if (node.returned) {
            node.returned->accept(this);
        }
    }

    void visit(const WhileLoop &node) override {

        if (node.condition) {
            node.condition->accept(this);
        }

        if (node.body) {
            node.body->accept(this);
        }
    }

    void visit(const IfStatement &node) override {

        if (node.condition) {
            node.condition->accept(this);
        }
        if (node.body) {
            node.body->accept(this);
        }
        if (node.elseBody) {
            node.elseBody->accept(this);
        }
    }

    void visit(const ForLoop &node) override {

        if (node.rangeStart) {
            node.rangeStart->accept(this);
        }
        if (node.rangeEnd) {
            node.rangeEnd->accept(this);
        }
        if (node.loopVar) {
            node.loopVar->accept(this);
        }

        if (node.body) {
            node.body->accept(this);
        }
    }

    void visit(const Declaration &node) override {
        if (node.type) {
            node.type->accept(this);
        }
    }

    void visit(const Assignment &node) override {

        if (node.lValue) {
            node.lValue->accept(this);
        }
        if (node.rValue) {
            node.rValue->accept(this);
        }
    }

    void visit(const Expression &node) override {
        if (node.l) {
            node.l->accept(this);
        }
        if (node.r) {
            node.r->accept(this);
        }
    }

    void visit(const RoutineCall &node) override {

        for (const auto& n : node.args) {
            n->accept(this);
        }
    }

    void visit(const Ident &node) override {

    }

    void visit(const Type &node) override {

    }

    void visit(const Variable &node) override {

        if (node.type) {
            node.type->accept(this);
        }
        if (node.value) {
            node.value->accept(this);
        }
        if (node.ident) {
            node.ident->accept(this);
        }
    }

    void visit(const BuiltinType &node) override {

    }

    void visit(const Record &node) override {
        for (auto const &n : node.fields) {
            n->accept(this);
        }
    }

    void visit(const Array &node) override {
        if (node.size) {
            node.size->accept(this);
        }
        if (node.type) {
            node.type->accept(this);
        }
    }


};