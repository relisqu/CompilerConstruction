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

        StoredType result = ST_IDENT;
        result.ident = node.name;
        contextStack.push_back(result);

        decreaseDepth();
    }

    void TypeChecker::visit(const ForLoop &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting ForLoop " << node.name << " at " << std::string(node.span) << '\n';
        StoredType start = ST_NULL;
        StoredType end = ST_NULL;
        StoredType var = ST_NULL;
        int startSize = contextStack.size();
        if (node.rangeStart) {
            node.rangeStart->accept(this);
            start = contextStack.back();
            if (start.tag == Tag::tagIdent) {
                start = resolveIdent(start);
            }
        }
        if (node.rangeEnd) {
            node.rangeEnd->accept(this);
            end = contextStack.back();
            if (end.tag == Tag::tagIdent) {
                end = resolveIdent(end);
            }
        }
        if (node.loopVar) {
            node.loopVar->accept(this);
            var = contextStack.back();
        }
        if (start.tag != Tag::tagInteger ||
            end.tag != Tag::tagInteger) {
            std::cout << "Loop range types must be integers";
            exit(1);
        }
        cutContextStack(startSize);
        identMap[var.ident].push_back(ST_INTEGER);

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
        int startSize = contextStack.size();
        StoredType cond = ST_NULL;
        if (node.condition) {
            node.condition->accept(this);
            cond = contextStack.back();
        }
        if (cond.tag == Tag::tagIdent) {
            cond = resolveIdent(cond);
        }
        if (cond.tag != tagBool) {
            printOffset();
            std::cout << "While condition is non-bool";
            exit(1);
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

    // TO-DO
    // This is a clusterfuck. Redo the tree structure to make it more bearable
    void TypeChecker::visit(const Expression &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Expression " << node.name << " ";
        StoredType result = ST_NULL;
        std::string operation = "";
        switch (node.value.index()) {
            case 0:
                operation = std::get<0>(node.value);
                std::cout << operation;
                break;
            case 1:
                std::cout << std::get<1>(node.value);
                result = ST_INTEGER;
                break;
            case 2:
                std::cout << std::get<2>(node.value);
                result = ST_REAL;
                break;
            case 3:
                std::cout << std::get<3>(node.value);
                result = ST_BOOLEAN;
                break;
        }
        std::cout << " at " << std::string(node.span) << '\n';
        StoredType leftType = ST_NULL;
        StoredType rightType = ST_NULL;
        int startSize = contextStack.size();
        if (node.l) {
            node.l->accept(this);
        }
        if (!contextStack.empty()) {
            leftType = contextStack.back();
        }
        if (node.r) {
            node.r->accept(this);
        }
        if (!contextStack.empty()) {
            rightType = contextStack.back();
        }
        cutContextStack(startSize);

        if (!operation.empty()) {
            if (operation == "[]") {
                leftType = resolveIdent(leftType);
                if (leftType.tag != Tag::tagArray) {
                    printOffset();
                    std::cout << "Type mismatch: square bracket access of non-array";
                    exit(1);
                }
                if (rightType.tag == Tag::tagIdent) {
                    rightType = resolveIdent(rightType);
                }
                if (rightType.tag != Tag::tagInteger) {
                    printOffset();
                    std::cout << "Type mismatch: non-int at square bracket access";
                    exit(1);
                }
                contextStack.push_back(leftType.content.back());
            } else if (operation == ".") {
                leftType = resolveIdent(leftType);
                if (leftType.tag != Tag::tagRecord) {
                    printOffset();
                    std::cout << "Type mismatch: dot access of non-record";
                    exit(1);
                }
                if (rightType.tag != Tag::tagIdent) {
                    printOffset();
                    std::cout << "Type mismatch: malformed dot access of record";
                    exit(1);
                }
                bool found = false;
                for (auto & i : leftType.content) {
                    if (i.ident == rightType.ident) {
                        contextStack.push_back(i);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    printOffset();
                    std::cout << "Type mismatch: no such component of record";
                    exit(1);
                }
            } else if (operation == "and" ||
                       operation == "or" ||
                       operation == "xor") {
                if (leftType.tag == Tag::tagIdent) {
                    leftType = resolveIdent(leftType);
                }
                if (rightType.tag == Tag::tagIdent) {
                    rightType = resolveIdent(rightType);
                }
                if (leftType.tag != Tag::tagBool || rightType.tag != Tag::tagBool) {
                    printOffset();
                    std::cout << "Type mismatch: boolean operation on non-bool";
                    exit(1);
                }
                contextStack.push_back(ST_BOOLEAN);
            } else if (operation == "<" ||
                       operation == "<=" ||
                       operation == ">" ||
                       operation == ">=" ||
                       operation == "=" ||
                       operation == "\\=") {
                if (leftType.tag == Tag::tagIdent) {
                    leftType = resolveIdent(leftType);
                }
                if (rightType.tag == Tag::tagIdent) {
                    rightType = resolveIdent(rightType);
                }
                if (leftType.tag == Tag::tagBool ||
                    rightType.tag == Tag::tagBool ||
                    leftType.tag != rightType.tag) {
                    printOffset();
                    std::cout << "Type mismatch: comparison operation on non-real or non-integer, or mismatching types";
                    exit(1);
                }
                contextStack.push_back(ST_BOOLEAN);
            } else if (operation == "*" ||
                       operation == "/" ||
                       operation == "%" ||
                       operation == "+" ||
                       operation == "-") {
                if (leftType.tag == Tag::tagIdent) {
                    leftType = resolveIdent(leftType);
                }
                if (rightType.tag == Tag::tagIdent) {
                    rightType = resolveIdent(rightType);
                }
                if (leftType.tag == Tag::tagBool ||
                    rightType.tag == Tag::tagBool ||
                    leftType.tag != rightType.tag) {
                    printOffset();
                    std::cout << "Type mismatch: arithmetic operation on non-real or non-integer, or mismatching types";
                    exit(1);
                }
                contextStack.push_back(leftType);
            } else if (node.name == "ident") {
                StoredType ret = ST_IDENT;
                ret.ident = operation;
                contextStack.push_back(ret);
            }
        } else {
            contextStack.push_back(result);
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
        StoredType cond = ST_NULL;
        int startSize = contextStack.size();
        if (node.condition) {
            node.condition->accept(this);
            cond = contextStack.back();
        }
        if (cond.tag == Tag::tagIdent) {
            cond = resolveIdent(cond);
        }
        if (cond.tag != tagBool) {
            printOffset();
            std::cout << "If condition is non-bool";
            exit(1);
        }
        if (node.body) {
            node.body->accept(this);
        }
        if (node.elseBody) {
            node.elseBody->accept(this);
        }
        cutContextStack(startSize);
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
        std::cout << "Visiting Variable " << node.name << " at " << std::string(node.span) << '\n';

        int startSize = contextStack.size();
        int lastSize = startSize;
        if (node.type) {
            node.type->accept(this);
        }
        StoredType expected = ST_NULL;
        if (contextStack.size() == startSize + 1) {
            expected = contextStack.back();
            lastSize = startSize + 1;
        }
        if (node.value) {
            node.value->accept(this);
        }
        StoredType val = ST_NULL;
        if (contextStack.size() == lastSize + 1) {
            val = contextStack.back();
        }
        if (node.ident) {
            node.ident->accept(this);
        }

        if (expected.tag != Tag::tagNull) {
            if (expected != val) {
                printOffset();
                std::cout << "Variable declaration type mismatch";
                exit(1);
            }
        }

        cutContextStack(startSize);
        identMap[node.name].push_back(val);
        val.ident = node.name;
        contextStack.push_back(val);

        decreaseDepth();
    }

    void TypeChecker::visit(const BuiltinType &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting BuiltinType " << node.name << " at " << std::string(node.span) << '\n';
        if (node.name == "integer") {
            contextStack.push_back(ST_INTEGER);
        }
        else if (node.name == "real") {
            contextStack.push_back(ST_REAL);
        }
        else if (node.name == "boolean") {
            contextStack.push_back(ST_BOOLEAN);
        }
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

    void TypeChecker::visit(const Array &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Array " << node.name << " at " << std::string(node.span) << '\n';
        if (node.size) {
            node.size->accept(this);
        }
        if (node.type) {
            node.type->accept(this);
        }
        decreaseDepth();
    }
}