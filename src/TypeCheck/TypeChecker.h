//
// Created by justsomedude on 08.04.23.
//

#ifndef COMPILERCONSTRUCTION_TYPECHECKER_H
#define COMPILERCONSTRUCTION_TYPECHECKER_H
#include "AST/Visitor.h"
#include "AST/AST.h"

namespace ast {
    class TypeChecker : Visitor {
        void visit(const Node &node) override;

        void visit(const Block &node) override;

        void visit(const Routine &node) override;
    };
}



#endif //COMPILERCONSTRUCTION_TYPECHECKER_H
