//
// Created by justsomedude on 02.05.23.
//

#ifndef COMPILERCONSTRUCTION_CODEGENERATOR_H
#define COMPILERCONSTRUCTION_CODEGENERATOR_H
#include "AST/AST.h"
#include <map>
#include <vector>
#include "StoredType.h"
#include "Consts.h"
#include "Error/ErrorHandler.h"

namespace ast {

    class CodeGenerator : public Visitor {
    public:
        std::vector<std::string> declarationStack;
        std::vector<std::string> returnStack;

        void cutReturnStack(int targetSize) {
            while (returnStack.size() > targetSize) {
                returnStack.pop_back();
            }
        }

        bool is_number(const std::string& s) {
            try {
                std::stoi(s);
            } catch (std::exception& e) {
                return false;
            }
            return true;
        }

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

        CodeGenerator();
    };

} // ast

#endif //COMPILERCONSTRUCTION_CODEGENERATOR_H
