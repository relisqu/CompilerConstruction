//
// Created by justsomedude on 08.04.23.
//

#include "TypeChecker.h"
#include "AST/AST.h"

namespace ast {
    void TypeChecker::visit(const Node &node) {}

    void TypeChecker::visit(const Block &node) {
        for (auto n : node.nodes) {
            n->accept(this);
        }
    }

    void TypeChecker::visit(const Routine &node) {
        if (node.ident) {
            node.ident->accept(this);
        }
        for (auto n : node.parameters) {
            n->accept(this);
        }
        if (node.body) {
            node.body->accept(this);
        }
        for (auto n : node.returnStatements) {
            n->accept(this);
        }
        if (node.returnType) {
            node.returnType->accept(this);
        }

    }

    void TypeChecker::visit(const Type &node) {}

    void TypeChecker::visit(const Ident &node) {}

    void TypeChecker::visit(const ForLoop &node) {
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

    void TypeChecker::visit(const Statement &node) {}

    void TypeChecker::visit(const WhileLoop &node) {
        if (node.condition) {
            node.condition->accept(this);
        }
        if (node.body) {
            node.body->accept(this);
        }
    }

    void TypeChecker::visit(const Assignment &node) {
        if (node.lValue) {
            node.lValue->accept(this);
        }
        if (node.rValue) {
            node.rValue->accept(this);
        }
    }

    void TypeChecker::visit(const Expression &node) {
        if (node.l) {
            node.l->accept(this);
        }
        if (node.r) {
            node.r->accept(this);
        }
    }

    void TypeChecker::visit(const Declaration &node) {
        // Declaration needs ident of declared item?
        if (node.type) {
            node.type->accept(this);
        }
    }

    void TypeChecker::visit(const IfStatement &node) {
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

    void TypeChecker::visit(const RoutineCall &node) {
        // Routine call needs ident of routine?
        for (auto n : node.args) {
            n->accept(this);
        }
    }

    void TypeChecker::visit(const ReturnStatement &node) {
        if (node.returned) {
            node.returned->accept(this);
        }
    }
}