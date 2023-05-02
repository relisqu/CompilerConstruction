//
// Created by justsomedude on 02.05.23.
//

#include "CodeGenerator.h"
#include "AST/AST.h"
#include "Error/ErrorHandler.h"

namespace ast {

    CodeGenerator::CodeGenerator() {}

    void CodeGenerator::visit(const Node &node) {
        std::cout << "WARNING UNRESOLVED NODE: Visiting generic node " << node.name << " at " << std::string(node.span) << '\n';
    }

    void CodeGenerator::visit(const Block &node) {
        std::string resultCode = "{\n";

        increaseScope();
        std::cout << "Visiting block at " << std::string(node.span) << '\n';
        for (const auto& n : node.nodes) {
            n->accept(this);
            resultCode += (returnStack.back() + ";\n");
            returnStack.pop_back();
        }
        resultCode += "}\n";

        decreaseScope();

        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Routine &node) {
        std::string resultCode;
        std::string identCode;
        std::string parametersCode;
        std::string returnTypeCode;
        std::string bodyCode;

        increaseScope();
        std::cout << "Visiting Routine " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType expected = ST_PLACEHOLDER;
        StoredType ident = ST_NULL;
        ident.setScope();
        expected.setScope();
        if (node.ident) {
            node.ident->accept(this);
            ident = contextStack.back();

            identCode = returnStack.back();
            returnStack.pop_back();
        }
        std::vector <StoredType> inTypes = {};
        std::vector<StoredType> outTypes = {};

        for (const auto& n : node.parameters) {
            n->accept(this);
            contextStack.back().setScope();
            inTypes.push_back(contextStack.back());

            if (!parametersCode.empty()) {
                parametersCode += ", ";
            }
            parametersCode += returnStack.back();
            returnStack.pop_back();
        }

        if (node.returnType) {
            node.returnType->accept(this);
            expected = contextStack.back();
            expected.setScope();
            outTypes.push_back(expected);

            returnTypeCode += returnStack.back();
            returnStack.pop_back();
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

            bodyCode += returnStack.back();
            returnStack.pop_back();
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
        result.setScope(globalScope - 1);
        identMap[result.ident][index] = result;

        decreaseScope();

        resultCode = result.outTypes[0].getType() + " " +
                     result.ident +
                     "(" + parametersCode + ")" +
                     bodyCode;
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Type &node) {

        std::cout << "Visiting Type " << node.name << " at " << std::string(node.span) << '\n';
        contextStack.push_back(identMap[node.name].back());

        returnStack.push_back("struct " + node.name);
    }

    void CodeGenerator::visit(const Ident &node) {
        std::cout << "Visiting Ident " << node.name << " at " << std::string(node.span) << '\n';

        StoredType result = ST_IDENT;
        result.setScope();
        result.ident = node.name;
        contextStack.push_back(result);

        returnStack.push_back(node.name);
    }
    void CodeGenerator::visit(const ForLoop &node) {
        std::string resultCode;
        std::string rangeStartCode;
        std::string rangeEndCode;
        std::string loopVarCode;
        std::string bodyCode;
        
        increaseScope();
        
        std::cout << "Visiting ForLoop " << node.name << " at " << std::string(node.span) << '\n';
        StoredType start = ST_NULL;
        start.setScope();
        StoredType end = ST_NULL;
        end.setScope();
        StoredType var = ST_NULL;
        var.setScope();
        int startSize = contextStack.size();
        if (node.rangeStart) {
            node.rangeStart->accept(this);
            start = contextStack.back();
            if (start.tag == Tag::tagIdent) {
                start = resolveIdent(start);
            }

            rangeStartCode = returnStack.back();
            returnStack.pop_back();
        }
        if (node.rangeEnd) {
            node.rangeEnd->accept(this);
            end = contextStack.back();
            if (end.tag == Tag::tagIdent) {
                end = resolveIdent(end);
            }

            rangeEndCode = returnStack.back();
            returnStack.pop_back();
        }
        if (node.loopVar) {
            node.loopVar->accept(this);
            var = contextStack.back();

            loopVarCode = returnStack.back();
            returnStack.pop_back();
        }
        cutContextStack(startSize);
        identMap[var.ident].push_back(ST_INTEGER);

        if (node.body) {
            node.body->accept(this);

            bodyCode = returnStack.back();
            returnStack.pop_back();
        }

        decreaseScope();

        if (!node.reversed)
            resultCode = "for (int " + loopVarCode + " = " + rangeStartCode + ";" +
                          loopVarCode + " < " + rangeEndCode + ";" +
                          loopVarCode + "++)" +
                          bodyCode;
        else
            resultCode = "for (int " + loopVarCode + " = " + rangeEndCode + ";" +
                         loopVarCode + " > " + rangeStartCode + ";" +
                         loopVarCode + "--)" +
                         bodyCode;

        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Statement &node) {
        std::cout << "Visiting Statement " << node.name << " at " << std::string(node.span) << '\n';
    }

    void CodeGenerator::visit(const WhileLoop &node) {
        std::string resultCode;
        std::string conditionCode;
        std::string bodyCode;
        
        increaseScope();
        
        std::cout << "Visiting WhileLoop " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType cond = ST_NULL;
        cond.setScope();
        if (node.condition) {
            node.condition->accept(this);
            cond = contextStack.back();

            conditionCode = returnStack.back();
            returnStack.pop_back();
        }
        if (cond.tag == Tag::tagIdent) {
            cond = resolveIdent(cond);
        }
        if (node.body) {
            node.body->accept(this);

            bodyCode = returnStack.back();
            returnStack.pop_back();
        }
        
        decreaseScope();

        resultCode = "while(" + conditionCode + ")" + bodyCode;
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Assignment &node) {
        std::string resultCode;
        std::string lvalCode;
        std::string rvalCode;
        
        std::cout << "Visiting Assignment " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType lval = ST_NULL;
        lval.setScope();
        StoredType rval = ST_NULL;
        rval.setScope();
        if (node.lValue) {
            node.lValue->accept(this);
            lval = contextStack.back();

            lvalCode = returnStack.back();
            returnStack.pop_back();
        }
        if (node.rValue) {
            node.rValue->accept(this);
            rval = contextStack.back();

            rvalCode = returnStack.back();
            returnStack.pop_back();
        }

        if (lval.tag == Tag::tagIdent) {
            lval = resolveIdent(lval);
        }
        if (rval.tag == Tag::tagIdent) {
            rval = resolveIdent(rval);
        }

        cutContextStack(startSize);

        resultCode = lvalCode + " = " + rvalCode;
        returnStack.push_back(resultCode);
    }

    // TO-DO
    // This is a clusterfuck. Redo the tree structure to make it more bearable
    void CodeGenerator::visit(const Expression &node) {
        std::string resultCode;
        std::string operationCode;
        std::string leftCode;
        std::string rightCode;
        std::string valueCode;
        bool isSizeOp = false;

        std::cout << "Visiting Expression " << node.name << " ";
        StoredType result = ST_NULL;
        result.setScope();
        std::string operation = "";
        switch (node.value.index()) {
            case 0:
                operation = std::get<0>(node.value);
                std::cout << operation;
                valueCode = operation;
                break;
            case 1:
                std::cout << std::get<1>(node.value);
                result = ST_INTEGER;
                valueCode = std::to_string(std::get<1>(node.value));
                break;
            case 2:
                std::cout << std::get<2>(node.value);
                result = ST_REAL;
                valueCode = std::to_string(std::get<2>(node.value));
                break;
            case 3:
                std::cout << std::get<3>(node.value);
                result = ST_BOOLEAN;
                valueCode = std::to_string(std::get<3>(node.value));
                break;
        }
        std::cout << " at " << std::string(node.span) << '\n';
        StoredType leftType = ST_NULL;
        leftType.setScope();
        StoredType rightType = ST_NULL;
        rightType.setScope();
        int startSize = contextStack.size();
        if (node.l) {
            node.l->accept(this);
            leftCode = returnStack.back();
            returnStack.pop_back();
        }
        if (!contextStack.empty()) {
            leftType = contextStack.back();
        }
        if (node.r) {
            node.r->accept(this);
            rightCode = returnStack.back();
            returnStack.pop_back();
        }
        if (!contextStack.empty()) {
            rightType = contextStack.back();
        }
        cutContextStack(startSize);

        if (!operation.empty()) {
            if (operation == "[]") {
                leftType = resolveIdent(leftType);
                if (rightType.tag == Tag::tagIdent) {
                    rightType = resolveIdent(rightType);
                }

                StoredType _result = leftType.content.back();
                contextStack.push_back(_result);
            } else if (operation == ".") {
                if (leftType.tag == Tag::tagIdent) {
                    leftType = resolveIdent(leftType);
                }
                if (rightType.tag == Tag::tagIdent && rightType.ident == "size") {
                    contextStack.push_back(ST_INTEGER);

                    isSizeOp = true;
                }
                else {
                    for (auto &i: leftType.content) {
                        if (i.ident == rightType.ident) {
                            contextStack.push_back(i);
                            break;
                        }
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
                contextStack.push_back(leftType);
            } else if (node.name == "ident") {
                StoredType ret = ST_IDENT;
                ret.setScope();
                ret.ident = operation;
                contextStack.push_back(ret);
            }
        } else {
            contextStack.push_back(result);
        }

        // Converting comparison to C-style
        if (operation == "=") {
            operation = "==";
        }
        operationCode = operation;
        resultCode = leftCode + " " + operationCode + " " + rightCode;
        // Accessing array field
        if (operationCode == "[]") {
            resultCode = leftCode + "[" + rightCode + "]";
        }
        // Accessing record field
        if (operationCode == ".") {
            resultCode = leftCode + "." + rightCode;
        }
        // Case of ident
        if (resultCode == "  ") {
            resultCode = valueCode;
        }
        // Case of calling .size.
        if (isSizeOp) {
            resultCode = "(sizeof(" + leftCode + ") / sizeof(" + leftType.content[0].getType() + "))";
        }
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Declaration &node) {
        std::string resultCode;

        std::cout << "Visiting Declaration " << node.name << " at " << std::string(node.span) << '\n';
        if (node.type) {
            node.type->accept(this);
            resultCode = returnStack.back();
            returnStack.pop_back();
        }

        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const IfStatement &node) {
        std::string resultCode;
        std::string conditionCode;
        std::string bodyCode;
        std::string elseBodyCode;

        increaseScope();

        std::cout << "Visiting IfStatement " << node.name << " at " << std::string(node.span) << '\n';
        StoredType cond = ST_NULL;
        cond.setScope();
        int startSize = contextStack.size();
        if (node.condition) {
            node.condition->accept(this);
            cond = contextStack.back();

            conditionCode = returnStack.back();
            returnStack.pop_back();
        }
        if (cond.tag == Tag::tagIdent) {
            cond = resolveIdent(cond);
        }
        if (node.body) {
            node.body->accept(this);

            bodyCode = returnStack.back();
            returnStack.pop_back();
        }
        if (node.elseBody) {
            node.elseBody->accept(this);

            elseBodyCode = returnStack.back();
            returnStack.pop_back();
        }
        cutContextStack(startSize);

        decreaseScope();

        resultCode = "if (" + conditionCode + ")" + bodyCode;
        if (!elseBodyCode.empty()) {
            resultCode += " else " + elseBodyCode;
        }

        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const RoutineCall &node) {
        std::string resultCode;
        std::string argsCode;

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

            if (!argsCode.empty()) {
                argsCode += ", ";
            }
            argsCode += returnStack.back();
            returnStack.pop_back();
        }
        StoredType expectedRoutine = resolveIdent(node.name);
        cutContextStack(startSize);

        contextStack.push_back(expectedRoutine.outTypes.back());

        resultCode = node.name + "(" + argsCode + ")";
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const ReturnStatement &node) {
        std::string resultCode;
        std::string returnedCode;

        std::cout << "Visiting ReturnStatement " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType result = ST_NULL;
        result.setScope();
        if (node.returned) {
            node.returned->accept(this);
            result = contextStack.back();
            if (result.tag == Tag::tagIdent) {
                result = resolveIdent(result);
            }

            returnedCode = returnStack.back();
            returnStack.pop_back();
        }
        if (expectedReturnTypes.back() == ST_PLACEHOLDER) {
            expectedReturnTypes.back() = result;
        }
        cutContextStack(startSize);

        resultCode = "return " + returnedCode;
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Program &program) {
        std::string resultCode;
        resultCode += "#define and &\n";
        resultCode += "#define or |\n";
        resultCode += "#define xor ^\n";
        resultCode += "int main() {\n";


        increaseScope();
        
        std::cout << "Visiting program.\n";
        for (const auto& n : program.nodes) {
            n->accept(this);
            resultCode += returnStack.back() + ";\n";
            returnStack.pop_back();
        }
        resultCode += "}\n";
        
        decreaseScope();

        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Variable &node) {
        std::string resultCode;
        std::string typeCode;
        std::string valueCode;
        std::string identCode;
        std::string sizeCode;

        std::cout << "Visiting Variable " << node.name << " at " << std::string(node.span) << '\n';

        int startSize = contextStack.size();
        int lastSize = startSize;

        StoredType expected = ST_NULL;
        StoredType val = ST_NULL;

        if (node.type) {
            node.type->accept(this);
            expected = contextStack.back();

            typeCode = returnStack.back();
            returnStack.pop_back();
        }
        if (node.value) {
            node.value->accept(this);
            val = contextStack.back();

            valueCode = returnStack.back();
            returnStack.pop_back();
        }
        if (node.ident) {
            node.ident->accept(this);

            identCode = returnStack.back();
            returnStack.pop_back();
        }
        cutContextStack(startSize);

        StoredType oldVal = val;

        if (expected.tag != Tag::tagNull) {
            val = expected;
        }
        if (val.tag == Tag::tagIdent) {
            val = resolveIdent(val.ident);
        }

        val.setScope();
        expected.setScope();

        identMap[node.name].push_back(val);
        val.ident = node.name;
        contextStack.push_back(val);
        if (typeCode.empty() && !valueCode.empty()) {
            if (oldVal.tag == Tag::tagIdent) {
                oldVal = resolveIdent(oldVal.ident);
            }
            typeCode = oldVal.getType();
        }
        //Handling declaration of arrays
        if (val.tag == Tag::tagArray) {
            int splitPointer = typeCode.size() - 1;
            while (splitPointer > 0) {
                if (typeCode[splitPointer] == '[') {
                    sizeCode = std::string(typeCode.begin() + splitPointer, typeCode.end());
                    typeCode = std::string (typeCode.begin(), typeCode.begin() + splitPointer);
                    break;
                }
                splitPointer--;
            }
        }
        if (identCode.empty()) {
            identCode = node.name;
        }
        resultCode = typeCode + " " + identCode + sizeCode;
        if (!valueCode.empty()) {
            resultCode += " = " + valueCode;
        }
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const BuiltinType &node) {
        
        
        std::cout << "Visiting BuiltinType " << node.name << " at " << std::string(node.span) << '\n';
        if (node.name == "integer") {
            contextStack.push_back(ST_INTEGER);
            returnStack.push_back("int");
        }
        else if (node.name == "real") {
            contextStack.push_back(ST_REAL);
            returnStack.push_back("double");
        }
        else if (node.name == "boolean") {
            contextStack.push_back(ST_BOOLEAN);
            returnStack.push_back("int");
        }
    }

    void CodeGenerator::visit(const Record &node) {
        std::string resultCode;
        std::string fieldsCode;
        
        increaseScope();
        
        std::cout << "Visiting Record " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        for (auto const &n : node.fields) {
            n->accept(this);
            fieldsCode += returnStack.back();
            fieldsCode += ";\n";
            returnStack.pop_back();
        }
        StoredType result = ST_RECORD;
        std::vector <StoredType> content(contextStack.begin() + startSize, contextStack.end());
        cutContextStack(startSize);
        result.content = content;
        result.setScope(globalScope - 1);
        result.typeName = node.name;
        identMap[node.name].push_back(result);

        decreaseScope();

        fieldsCode = "{\n" + fieldsCode + "}";
        resultCode = "struct " + result.typeName + fieldsCode;
        returnStack.push_back(resultCode);
    }

    void CodeGenerator::visit(const Array &node) {
        std::string resultCode;
        std::string sizeCode;
        std::string typeCode;
        
        std::cout << "Visiting Array " << node.name << " at " << std::string(node.span) << '\n';
        int startSize = contextStack.size();
        StoredType result = ST_ARRAY;
        StoredType size = ST_NULL;
        size.setScope();
        result.setScope();
        if (node.size) {
            node.size->accept(this);
            size = contextStack.back();
            if (size.tag == Tag::tagIdent) {
                size = resolveIdent(size);
            }

            sizeCode = returnStack.back();
            returnStack.pop_back();
        }
        StoredType type = ST_NULL;
        type.setScope();
        if (node.type) {
            node.type->accept(this);
            type = contextStack.back();

            typeCode = returnStack.back();
            returnStack.pop_back();
        }
        result.content.push_back(type);

        cutContextStack(startSize);

        contextStack.push_back(result);

        resultCode = typeCode + "[" + sizeCode + "]"; // Proper size representation at higher level (Variable)
        returnStack.push_back(resultCode);
    }
}