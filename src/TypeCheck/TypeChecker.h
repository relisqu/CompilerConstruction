//
// Created by justsomedude on 08.04.23.
//

#ifndef COMPILERCONSTRUCTION_TYPECHECKER_H
#define COMPILERCONSTRUCTION_TYPECHECKER_H
#include "AST/AST.h"
#include <map>
#include <vector>
#include "StoredType.h"
#include "Consts.h"
#include "Error/ErrorHandler.h"

namespace ast {
    class TypeChecker : public Visitor {
    public:


        int currentDepth = 0;

        void increaseDepth() {
            currentDepth++;
        }

        void decreaseDepth() {
            currentDepth--;
        }

        void printOffset() {
            for (int i = 0; i < currentDepth; i++) {
                std::cout << "  ";
            }
        }

        //void printOffset();


        void visit(const Program &program) override;

        void visit(const Node &node) override;

        void visit(const Block &node) override;

        void visit(const Routine &node) override;

        void visit(const Statement &node) override;

        void visit(const ReturnStatement &node) override;

        void visit(const WhileLoop &node) override;

        void visit(const IfStatement &node) override;

        void visit(const ForLoop &node) override;

        void visit(const Declaration &node) override;

        void visit(const Assignment &node) override;

        void visit(const Expression &node) override;

        void visit(const RoutineCall &node) override;

        void visit(const Ident &node) override;

        void visit(const Type &node) override;

        void visit(const Variable &node) override;

        void visit(const BuiltinType &node) override;

        void visit(const Record &node) override;

        void visit(const Array &node) override;

        TypeChecker();
    };
}



#endif //COMPILERCONSTRUCTION_TYPECHECKER_H
