#pragma once

#include <memory>
#include <utility>
#include <vector>
#include <string>
#include <utility>
#include <variant>
#include <tuple>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include "Tokens/Span.h"

namespace ast {

    extern Span cur_span;

    template<typename T> using sp = std::shared_ptr<T>;
    template<typename T> using spv = std::vector<std::shared_ptr<T>>;

    struct Node;
    struct Block;
    struct Routine;
    struct Statement;
    struct ReturnStatement;
    struct WhileLoop;
    struct IfStatement;
    struct ForLoop;
    struct Declaration;
    struct Assignment;
    struct Expression;
    struct RoutineCall;
    struct Ident;
    struct Type;

    extern std::unordered_map<std::string, std::shared_ptr<Type> > TypeTable ;

    extern int line;

    struct Node {
        std::string name;
        Span span;

        Node() = default;

        explicit Node(std::string s) : name(std::move(s)), span(cur_span) {}

        virtual ~Node() = default;
    };

    struct Type : Node {

        Type() = default;

        explicit Type(const sp<Node> &node) {
            name = node->name;
            span = cur_span;
        }

        explicit Type(const std::string &otherName) : Node(otherName) {}

        ~Type() override = default;

        Type(Type &&) = default;

        Type(Type &) = default;

        Type &operator=(const Type &other) = default;

        Type &operator=(Type &&) = default;
    };

    struct Variable : Type {
        sp<Type> type;
        sp<Ident> ident;
        sp<Expression> value = nullptr;

        Variable() = default;

        Variable(const std::string &Name, sp<Type> type2) :
                Type(Name) {
            type = std::move(type2);
        }

        Variable(const std::string &Name, sp<Expression> exp, sp<Type> type2) : Type(Name), ident(std::make_shared<Ident>(std::move(Name))) {
            value = std::move(exp);
            type = std::move(type2);
        }
    };

    struct Program : Node {
        spv<Variable> variables;
        spv<Statement> statements;
        spv<Routine> routines;

        Program() { span = cur_span; }
    };

    struct Block : Node {
        spv<Variable> variables;
        spv<Statement> statements;

        Block() { span = cur_span; }

        ~Block() override = default;

        void addVariable(const sp<Variable> &v);

        void addStatement(const sp<Statement> &s);
    };

    struct Routine : Node {
        sp<Block> body;
        spv<Variable> parameters;
        sp<Type> returnType;
        spv<ReturnStatement> returnStatements;

        Routine() = default;

        Routine(const std::string &name, spv<Variable> params, const sp<Block> &oBody,
                sp<Type> rtType) : Node(name) {
            parameters = std::move(params);
            body = oBody;
            returnType = std::move(rtType);
            span = cur_span;
        }

        void print() {
            std::cout << "Routine " << name << " with type : ";
            if (returnType != nullptr) {
                std::cout << returnType->name;
            } else {
                std::cout << "void";
            }
            std::cout << std::endl;
            std::cout << "vector size : ";
            std::cout << parameters.size() << std::endl;
            for (const auto &a: parameters)
                std::cout << a->name << " " << a->type->name << std::endl;
        }
    };


    struct Statement : Node {
        ~Statement() override = default;
    };

    struct ReturnStatement : Statement {
        sp<Expression> returned = nullptr;

        ReturnStatement() = default;

        explicit ReturnStatement(sp<Expression> exp) {
            returned = std::move(exp);
            span = cur_span;
        }
    };

    struct WhileLoop : Statement {
        sp<Expression> condition;
        sp<Block> body;

        WhileLoop(sp<Expression> cond, sp<Block> body) {
            span = cur_span;
            condition = std::move(cond);
            body = body;
        }
    };

    struct IfStatement : Statement {
        sp<Expression> condition;
        sp<Block> body;
        sp<Block> elseBody;

        IfStatement(sp<Expression> exp, sp<Block> block, sp<Block> elseBlock) :
                condition(std::move(exp)), body(std::move(block)), elseBody(std::move(elseBlock)) { span = cur_span; }
    };

    struct ForLoop : Statement {
        sp<Block> body;
        sp<Expression> rangeStart;
        sp<Expression> rangeEnd;
        sp<Variable> loopVar;
        bool reversed = false;

        ForLoop() = default;

        ForLoop(const std::string &LoopVar,
                std::tuple<sp<Expression>, sp<Expression>, bool> Range,
                sp<Block> Body) :
                rangeStart(std::get<0>(Range)), rangeEnd(std::get<1>(Range)), reversed(std::get<2>(Range)), body(std::move(Body)) {
            loopVar = std::make_shared<Variable>(LoopVar, nullptr);

            span = cur_span;
        }
    };

    struct Declaration : Statement {
        sp<Type> type;
    };

    struct Assignment : Statement {
        sp<Expression> rValue;
        sp<Ident> lValue;

        Assignment(const std::string &identName, sp<Expression> exp) :
                rValue(std::move(exp)) {

            span = cur_span;
            lValue = std::make_shared<Ident>(identName);
        }
    };

    struct Ident : Node {
        explicit Ident(const std::string &s) : Node(s) {}
    };

    struct Expression : Node {
        using spe = sp<Expression>;
        std::variant<std::string, long long int, double, bool> value;
        spe l = nullptr;
        spe r = nullptr;
        static std::string getType(const std::shared_ptr<Expression> &exp);

        Expression(const std::string &newSymbol, spe first, spe second = nullptr, bool braces = false) : Node(
                "Operation") {
            value = newSymbol;
            l = std::move(first);
            r = std::move(second);
        }

        explicit Expression(long long int val, bool _temp) : Node("integer"), value(val) {}

        explicit Expression(bool val) : Node("boolean"), value(val) {}

        explicit Expression(double val) : Node("real"), value(val) {}

        explicit Expression(const std::string &identName) :
                Node("ident") {
            value = identName;
        }

        ~Expression() override = default;

        void print() {
            switch (value.index()) {
                case 0:
                    std::cout << std::get<0>(value) << std::endl;
                    break;
                case 1:
                    std::cout << std::get<1>(value) << std::endl;
                    break;
                case 2:
                    std::cout << std::get<2>(value) << std::endl;
                    break;
                case 3:
                    std::cout << std::get<3>(value) << std::endl;
                    break;
            }
        }
    };

    struct RoutineCall : Statement {
        spv<Expression> args;

        explicit RoutineCall(const std::string &ident) { name = ident; }
    };

    struct BuiltinType : Type {
        std::variant<long long int, double, bool> iValue, rValue, bValue;

        explicit BuiltinType(const std::string &otherName) : Type(otherName) {
            name = otherName;
        }
    };

    struct Record : Type {
        spv<Variable> fields;

        Record(const std::string &Name, spv<Variable> &Fields) : Type(Name) {
            fields = std::move(Fields);
        }
    };

    struct Alias : Type {
        sp<Type> type;
    };

    struct Array : Type {
        int size = 0;
        sp<Type> type;

        explicit Array(const std::string &name) : Type(name) {}
    };

    void dfs();

    void printVariable(const sp<Variable> &var);
}