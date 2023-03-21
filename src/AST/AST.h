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

struct Routine;
struct Statement;
struct ReturnStatement;
struct Expression;
struct Ident;

template<typename T> using sp = std::shared_ptr<T>;
template<typename T> using vsp = std::vector<std::shared_ptr<T>>;

extern int line;

struct Node {
    std::string name;
    int start{}, end{};

    Node() = default;

    explicit Node(std::string s) : name(std::move(s)), start(line) {}

    virtual ~Node() = default;

};

struct Type : Node {
    explicit Type(const sp<Node> &node) {
        name = node->name;
        start = node->start;
        end = node->end;
    }

    explicit Type(const std::string &otherName) : Node(otherName) {}

    Type() = default;

    Type(Type &&) = default;

    Type(Type &) = default;

    Type &operator=(const Type &other) = default;

    Type &operator=(Type &&) = default;

    ~Type() override = default;

    static std::unordered_map<std::string, sp<Type> > TypeTable;
};

struct Variable : Type {
    sp<Type> type;
    sp<Ident> ident;
    sp<Expression> value = nullptr;

    Variable() = default;

    Variable(const std::string &Name, sp<Type> type2) :
            Type(Name) {
        this->type = std::move(type2);
    }

    Variable(const std::string &Name, sp<Expression> exp, sp<Type> type2) : Type(Name) {
        value = std::move(exp);
        type = std::move(type2);
    }
};

struct Program : Node {
    vsp<Variable> variables;
    vsp<Statement> statemets;
    vsp<Routine> routines;

    Program() { start = line; }
};

struct Block : Node {
    vsp<Variable> variables;
    vsp<Statement> statemets;

    Block() { start = end = line; }

    ~Block() override = default;
};

struct Routine : Node {
    sp<Block> body;
    vsp<Variable> parameters;
    sp<Type> returnType;
    vsp<ReturnStatement> returnStatements;

    Routine() = default;

    Routine(const std::string &name, vsp<Variable> params, const sp<Block> &oBody, sp<Type> rtType) : Node(name) {
        parameters = std::move(params);
        body = oBody;
        returnType = std::move(rtType);
        end = oBody->end;
    }

    void print() {
        std::cout << "Routine " << name << " with type : ";
        if (returnType != nullptr) {
            std::cout << returnType->name;
        }
        else {
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

    explicit ReturnStatement(sp<Expression> exp) {
        returned = std::move(exp);
        start = end = line;
    }

    ReturnStatement() = default;
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

    Expression(const std::string &newSymbol, spe first, spe second = nullptr, bool braces = false) : Node("Operation") {
        value = newSymbol;
        l = std::move(first);
        r = std::move(second);
    }

    Expression(long long int val, bool temp) : Node("INTEGER"), value(val) {}

    explicit Expression(bool val) : Node("BOOLEAN"), value(val) {}

    explicit Expression(double val) : Node("REAL"), value(val) {}

    explicit Expression(const std::string &identName) :
            Node("IDENT") {
        value = identName;
    }

    ~Expression() override = default;

    void print() {
        switch (value.index()) {
            case 0:
                std::cout << get<0>(value) << std::endl;
                break;
            case 1:
                std::cout << get<1>(value) << std::endl;
                break;
            case 2:
                std::cout << get<2>(value) << std::endl;
                break;
            case 3:
                std::cout << get<3>(value) << std::endl;
                break;
        }
    }
};