//
// Created by justsomedude on 08.04.23.
//

#include "TypeChecker.h"
#include "AST/AST.h"

namespace ast {
    void TypeChecker::visit(const Node &node) {}

    void TypeChecker::visit(const Block &node) {}

    void TypeChecker::visit(const Routine &node) {}

    void TypeChecker::visit(const Type &node) {}

    void TypeChecker::visit(const Ident &node) {}

    void TypeChecker::visit(const ForLoop &node) {}

    void TypeChecker::visit(const Statement &node) {}

    void TypeChecker::visit(const WhileLoop &node) {}

    void TypeChecker::visit(const Assignment &node) {}

    void TypeChecker::visit(const Expression &node) {}

    void TypeChecker::visit(const Declaration &node) {}

    void TypeChecker::visit(const IfStatement &node) {}

    void TypeChecker::visit(const RoutineCall &node) {}

    void TypeChecker::visit(const ReturnStatement &node) {}
}