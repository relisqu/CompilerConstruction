//
// Created by justsomedude on 08.04.23.
//

#include "TypeChecker.h"
#include "AST/AST.h"

namespace ast {
    TypeChecker::TypeChecker() {}

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

    void TypeChecker::visit(const Node &node) {
        increaseDepth();
        printOffset();
        std::cout << "WARNING UNRESOLVED NODE: Visiting generic node " << node.name << " at " << std::string(node.span) << '\n';
        decreaseDepth();
    }

    void TypeChecker::visit(const Block &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting block at " << std::string(node.span) << '\n';
        for (const auto& n : node.nodes) {
            n->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Routine &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Routine " << node.name << " at " << std::string(node.span) << '\n';
        if (node.ident) {
            node.ident->accept(this);
        }
        for (const auto& n : node.parameters) {
            n->accept(this);
        }
        if (node.body) {
            node.body->accept(this);
        }
        for (const auto& n : node.returnStatements) {
            n->accept(this);
        }
        if (node.returnType) {
            node.returnType->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Type &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Type " << node.name << " at " << std::string(node.span) << '\n';
        decreaseDepth();
    }

    void TypeChecker::visit(const Ident &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Ident " << node.name << " at " << std::string(node.span) << '\n';
        decreaseDepth();
    }

    void TypeChecker::visit(const ForLoop &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting ForLoop " << node.name << " at " << std::string(node.span) << '\n';
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
        decreaseDepth();
    }

    void TypeChecker::visit(const Statement &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Statement " << node.name << " at " << std::string(node.span) << '\n';
        decreaseDepth();
    }

    void TypeChecker::visit(const WhileLoop &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting WhileLoop " << node.name << " at " << std::string(node.span) << '\n';
        if (node.condition) {
            node.condition->accept(this);
        }
        if (node.body) {
            node.body->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Assignment &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Assignment " << node.name << " at " << std::string(node.span) << '\n';
        if (node.lValue) {
            node.lValue->accept(this);
        }
        if (node.rValue) {
            node.rValue->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Expression &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Expression " << node.name << " ";
        switch (node.value.index()) {
            case 0:
                std::cout << std::get<0>(node.value);
                break;
            case 1:
                std::cout << std::get<1>(node.value);
                break;
            case 2:
                std::cout << std::get<2>(node.value);
                break;
            case 3:
                std::cout << std::get<3>(node.value);
                break;
        }
        std::cout << " at " << std::string(node.span) << '\n';
        if (node.l) {
            node.l->accept(this);
        }
        if (node.r) {
            node.r->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Declaration &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Declaration " << node.name << " at " << std::string(node.span) << '\n';
        if (node.type) {
            node.type->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const IfStatement &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting IfStatement " << node.name << " at " << std::string(node.span) << '\n';
        if (node.condition) {
            node.condition->accept(this);
        }
        if (node.body) {
            node.body->accept(this);
        }
        if (node.elseBody) {
            node.elseBody->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const RoutineCall &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting RoutineCall " << node.name << " at " << std::string(node.span) << '\n';

        for (const auto& n : node.args) {
            n->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const ReturnStatement &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting ReturnStatement " << node.name << " at " << std::string(node.span) << '\n';
        if (node.returned) {
            node.returned->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Program &program) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting program.\n";
        for (const auto& n : program.nodes) {
            n->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const Variable &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Variable at " << std::string(node.span) << '\n';

        if (node.type) {
            node.type->accept(this);
        }
        if (node.ident) {
            node.ident->accept(this);
        }
        if (node.value) {
            node.value->accept(this);
        }
        decreaseDepth();
    }

    void TypeChecker::visit(const BuiltinType &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting BuiltinType " << node.name << " at " << std::string(node.span) << '\n';
        decreaseDepth();
    }

    void TypeChecker::visit(const Record &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Record " << node.name << " at " << std::string(node.span) << '\n';
        for (auto const &n : node.fields) {
            n->accept(this);
        }
        decreaseDepth();
    }
}