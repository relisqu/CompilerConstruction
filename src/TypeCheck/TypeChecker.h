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

namespace ast {
    class TypeChecker : public Visitor {
    public:
        std::map<std::string, std::vector<StoredType> > identMap;

        std::vector<StoredType> contextStack = {};
        std::vector<StoredType> expectedReturnTypes = {ST_INTEGER};

        void cutContextStack(int targetSize) {
            while (contextStack.size() > targetSize) {
                contextStack.pop_back();
            }
        }

        StoredType resolveIdent(const StoredType& ident) {
            if (ident.tag != Tag::tagIdent) {
                return ST_NULL;
            }
            if (!identMap[ident.ident].empty()) {
                return identMap[ident.ident].back();
            }
            return ST_NULL;
        }

        StoredType resolveIdent(const std::string &ident) {
            if (!identMap[ident].empty()) {
                return identMap[ident].back();
            }
            return ST_NULL;
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

        TypeChecker();
    };
}



#endif //COMPILERCONSTRUCTION_TYPECHECKER_H
