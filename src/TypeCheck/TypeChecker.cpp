//
// Created by justsomedude on 08.04.23.
//

#include "TypeChecker.h"
#include "AST/AST.h"
#include "Error/ErrorHandler.h"

namespace ast {
    TypeChecker::TypeChecker() {}

    int currentDepth = 0;

    void TypeChecker::increaseScope() {
        globalScope++;
    }

    void TypeChecker::decreaseScope() {
        globalScope--;
        for (auto it = identMap.begin(); it != identMap.end(); it++) {
            while (!it->second.empty() && it->second.back().current_scope > globalScope) {
                it->second.pop_back();
            }
        }

    }

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
        increaseScope();
        increaseDepth();
        printOffset();
        std::cout << "Visiting block at " << std::string(node.span) << '\n';
        for (const auto& n : node.nodes) {
            n->accept(this);
        }
        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const Routine &node) {
        increaseScope();
        increaseDepth();
        printOffset();
        std::cout << "Visiting Routine " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();

        StoredType expected = ST_PLACEHOLDER;
        StoredType ident = ST_NULL;
        if (node.ident) {
            node.ident->accept(this);
            ident = contextStack.back();
        }
        std::vector <StoredType> inTypes = {};
        std::vector<StoredType> outTypes = {};

        for (const auto& n : node.parameters) {
            n->accept(this);
            inTypes.push_back(contextStack.back());
        }

        if (node.returnType) {
            node.returnType->accept(this);
            expected = contextStack.back();
            outTypes.push_back(expected);
        }

        expectedReturnTypes.push_back(expected);

        StoredType result = ST_ROUTINE;

        result.inTypes = inTypes;
        result.outTypes = outTypes;
        result.ident = ident.ident;

        int index = identMap[result.ident].size();
        identMap[result.ident].push_back(result);
        if (node.body) {
            node.body->accept(this);
        }
        for (const auto& n : node.returnStatements) {
            n->accept(this);
        }
        if (expectedReturnTypes.back() == ST_PLACEHOLDER) {
            // if no return statements happened, then we can assume routine is void.
            expectedReturnTypes.back() = ST_NULL;
        }

        if (outTypes.empty())
            outTypes.push_back(expectedReturnTypes.back());
        else
            outTypes.back() = expectedReturnTypes.back();
        expectedReturnTypes.pop_back();
        cutContextStack(startSize);

        result.inTypes = inTypes;
        result.outTypes = outTypes;
        result.ident = ident.ident;

        identMap[result.ident][index] = result;

        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const Type &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Type " << node.name << " at " << std::string(node.span) << '\n';
        if (identMap[node.name].empty()) {
            printOffset();
            ErrorHandler::ThrowError("Undeclared record type: "+ node.name,node.span);
            exit(1);
        } else {
            if (identMap[node.name].back().tag != Tag::tagRecord) {
                ErrorHandler::ThrowError("Got non-record " + node.name + " as type",node.span);
                exit(1);
            } else {
                contextStack.push_back(identMap[node.name].back());
            }
        }
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
        increaseScope();
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
            ErrorHandler::ThrowError("Loop range types expected to be integer, got "+ ToString(start.tag)+" and "+ ToString(end.tag),node.span);
            exit(1);
        }
        cutContextStack(startSize);
        identMap[var.ident].push_back(ST_INTEGER);

        if (node.body) {
            node.body->accept(this);
        }


        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const Statement &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Statement " << node.name << " at " << std::string(node.span) << '\n';
        decreaseDepth();
    }

    void TypeChecker::visit(const WhileLoop &node) {
        increaseDepth();
        increaseScope();
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
            ErrorHandler::ThrowError("While condition expected to be bool , got "+ ToString(cond.tag),node.span);
        }
        if (node.body) {
            node.body->accept(this);
        }
        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const Assignment &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Assignment " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType lval = ST_NULL;
        StoredType rval = ST_NULL;
        if (node.lValue) {
            node.lValue->accept(this);
            lval = contextStack.back();
        }
        if (node.rValue) {
            node.rValue->accept(this);
            rval = contextStack.back();
        }

        if (lval.tag == Tag::tagIdent) {
            lval = resolveIdent(lval);
        }
        if (rval.tag == Tag::tagIdent) {
            rval = resolveIdent(rval);
        }

        if (lval != rval) {
            printOffset();
            ErrorHandler::ThrowError("Assignment type mismatch: expected types to be equal, got: "+
                    ToString(lval.tag)+" and "+ ToString(rval.tag), node.span);
            exit(1);
        }

        cutContextStack(startSize);
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
                    ErrorHandler::ThrowError("Type mismatch: square bracket access expected to be for array, got "+
                                             ToString(leftType.tag),node.span);
                    exit(1);
                }
                if (rightType.tag == Tag::tagIdent) {
                    rightType = resolveIdent(rightType);
                }
                if (rightType.tag != Tag::tagInteger) {
                    printOffset();
                    //if(leftTy)
                    ErrorHandler::ThrowError("Type mismatch: square bracket access expected to be int, got "+
                                             ToString(rightType.tag),node.span);
                    exit(1);
                }

                StoredType _result = leftType.content.back();
                contextStack.push_back(_result);
            } else if (operation == ".") {
                if (leftType.tag == Tag::tagIdent) {
                    leftType = resolveIdent(leftType);
                }
                if (rightType.tag == Tag::tagIdent && rightType.ident == "size") {
                    if (leftType.tag != Tag::tagArray) {
                        printOffset();
                        ErrorHandler::ThrowError("Type mismatch: expected to obtain size from array, got from: "+
                                                 ToString(leftType.tag),node.span);
                        exit(1);
                    } else {
                        contextStack.push_back(ST_INTEGER);
                    }
                }
                else {
                    if (leftType.tag != Tag::tagRecord) {
                        printOffset();
                        ErrorHandler::ThrowError("Type mismatch: expected dot access of record, got of: "+
                                                 ToString(leftType.tag),node.span);
                        exit(1);
                    }
                    if (rightType.tag != Tag::tagIdent) {
                        printOffset();
                        ErrorHandler::ThrowError("Type mismatch: expected identifier, got: "+
                                                 ToString(rightType.tag),node.span);
                        exit(1);
                    }
                    bool found = false;
                    for (auto &i: leftType.content) {
                        if (i.ident == rightType.ident) {
                            contextStack.push_back(i);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        printOffset();
                        ErrorHandler::ThrowError("Type mismatch: no such component of record ",node.span);
                        exit(1);
                    }
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
                    ErrorHandler::ThrowError("Type mismatch: expected: "+ ToString(Tag::tagBool)+ ", got: "
                                             + ToString(leftType.tag)+" and"+ ToString(rightType.tag),node.span);
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
                    ErrorHandler::ThrowError("Type mismatch: comparison operation on non-real or non-integer, or mismatching types",node.span);
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
                    ErrorHandler::ThrowError("Type mismatch: arithmetic operation on non-real or non-integer, or mismatching types",node.span);
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
        increaseScope();
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
            ErrorHandler::ThrowError("If condition mismatch: expected: "+ ToString(Tag::tagBool)+", got: "+
                                     ToString(cond.tag),node.span);
        }
        if (node.body) {
            node.body->accept(this);
        }
        if (node.elseBody) {
            node.elseBody->accept(this);
        }
        cutContextStack(startSize);
        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const RoutineCall &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting RoutineCall " << node.name << " at " << std::string(node.span) << '\n';

        int startSize = contextStack.size();
        std::vector<StoredType> inTypes;
        for (const auto& n : node.args) {
            n->accept(this);
            StoredType cur = contextStack.back();
            if (cur.tag == Tag::tagIdent) {
                cur = resolveIdent(cur);

            }
            inTypes.push_back(cur);
        }
        StoredType expectedRoutine = resolveIdent(node.name);
        if (expectedRoutine.inTypes != inTypes) {
            printOffset();
            ErrorHandler::ThrowError("RoutineCall argument mismatch: expected: "+ ToString(expectedRoutine.inTypes)+", got: "+
                                     ToString(inTypes),node.span);
        }
        cutContextStack(startSize);

        contextStack.push_back(expectedRoutine.outTypes.back());
        decreaseDepth();
    }

    void TypeChecker::visit(const ReturnStatement &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting ReturnStatement " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType result = ST_NULL;
        if (node.returned) {
            node.returned->accept(this);
            result = contextStack.back();
            if (result.tag == Tag::tagIdent) {
                result = resolveIdent(result);
            }
        }
        if (expectedReturnTypes.back() == ST_PLACEHOLDER) {
            expectedReturnTypes.back() = result;
        } else {
            if (expectedReturnTypes.back() != result) {
                printOffset();
                ErrorHandler::ThrowError("Expected return type mismatch: expected: "+ ToString(expectedReturnTypes.back().tag)+", got: "+
                                         ToString(result.tag),node.span);
            }
        }
        cutContextStack(startSize);
        decreaseDepth();
    }

    void TypeChecker::visit(const Program &program) {
        increaseScope();
        increaseDepth();
        printOffset();
        std::cout << "Visiting program.\n";
        for (const auto& n : program.nodes) {
            n->accept(this);
        }
        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const Variable &node) {
        increaseDepth();

        printOffset();
        std::cout << "Visiting Variable " << node.name << " at " << std::string(node.span) << '\n';

        int startSize = contextStack.size();
        int lastSize = startSize;

        StoredType expected = ST_NULL;
        StoredType val = ST_NULL;

        if (node.type) {
            node.type->accept(this);
            expected = contextStack.back();
        }
        if (node.value) {
            node.value->accept(this);
            val = contextStack.back();
        }
        if (node.ident) {
            node.ident->accept(this);
        }
        cutContextStack(startSize);

        if (expected.tag != Tag::tagNull) {
            if (val.tag != Tag::tagNull) {
                if (expected != val) {
                    printOffset();
                    ErrorHandler::ThrowError("Variable declaration type mismatch: expected: "+ ToString(expected.tag)+", got: "+
                                                                                                                      ToString(val.tag),node.span);
                }
            } else {
                val = expected;
            }
        }

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
        increaseScope();
        printOffset();
        std::cout << "Visiting Record " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        for (auto const &n : node.fields) {
            n->accept(this);
        }
        std::vector <StoredType> content(contextStack.begin() + startSize, contextStack.end());
        cutContextStack(startSize);

        StoredType result = ST_RECORD;
        result.content = content;
        identMap[node.name].push_back(result);

        decreaseDepth();
        decreaseScope();
    }

    void TypeChecker::visit(const Array &node) {
        increaseDepth();
        printOffset();
        std::cout << "Visiting Array " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType result = ST_ARRAY;
        StoredType size = ST_NULL;
        if (node.size) {
            node.size->accept(this);
            size = contextStack.back();
            if (size.tag == Tag::tagIdent) {
                size = resolveIdent(size);
            }
            if (size.tag != Tag::tagInteger) {
                printOffset();
                ErrorHandler::ThrowError("Expected array size to be int, got " + ToString(size.tag),node.span);
            }
        }
        StoredType type = ST_NULL;
        if (node.type) {
            node.type->accept(this);
            type = contextStack.back();
            if (type.tag == Tag::tagIdent) {
                printOffset();
                ErrorHandler::ThrowError( "Array type is " + type.ident + ", this is not supported", node.span);
            }

        }
        if (type == ST_NULL) {
            printOffset();
            ErrorHandler::ThrowError("No array type specified.", node.span);
            exit(1);
        }
        result.content.push_back(type);

        cutContextStack(startSize);

        contextStack.push_back(result);
        decreaseDepth();
    }

}