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

template<typename T> using shared_pointer = std::shared_ptr<T>;
template<typename T> using shared_pointer_vector = std::vector<std::shared_ptr<T>>;

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

extern int line;

struct Node {
    std::string name;
    int start{}, end{};

    Node() = default;

    explicit Node(std::string s) : name(std::move(s)), start(line) {}

    virtual ~Node() = default;
};

struct Type : Node {
    static std::unordered_map<std::string, shared_pointer<Type> > TypeTable;

    Type() = default;

    explicit Type(const shared_pointer<Node> &node) {
        name = node->name;
        start = node->start;
        end = node->end;
    }

    explicit Type(const std::string &otherName) : Node(otherName) {}

    ~Type() override = default;

    Type(Type &&) = default;

    Type(Type &) = default;

    Type &operator=(const Type &other) = default;

    Type &operator=(Type &&) = default;
};

struct Variable : Type {
    shared_pointer<Type> type;
    shared_pointer<Ident> ident;
    shared_pointer<Expression> value = nullptr;

    Variable() = default;

    Variable(const std::string &Name, shared_pointer<Type> type2) :
            Type(Name) {
        type = std::move(type2);
    }

    Variable(const std::string &Name, shared_pointer<Expression> exp, shared_pointer<Type> type2) : Type(Name) {
        value = std::move(exp);
        type = std::move(type2);
    }
};

struct Program : Node {
    shared_pointer_vector<Variable> variables;
    shared_pointer_vector<Statement> statements;
    shared_pointer_vector<Routine> routines;

    Program() { start = line; }
};

struct Block : Node {
    shared_pointer_vector<Variable> variables;
    shared_pointer_vector<Statement> statements;

    Block() { start = end = line; }

    ~Block() override = default;

    void addVariable(const shared_pointer<Variable> &v);

    void addStatement(const shared_pointer<Statement> &s);
};

struct Routine : Node {
    shared_pointer<Block> body;
    shared_pointer_vector<Variable> parameters;
    shared_pointer<Type> returnType;
    shared_pointer_vector<ReturnStatement> returnStatements;

    Routine() = default;

    Routine(const std::string &name, shared_pointer_vector<Variable> params, const shared_pointer<Block> &oBody,
            shared_pointer<Type> rtType) : Node(name) {
        parameters = std::move(params);
        body = oBody;
        returnType = std::move(rtType);
        end = oBody->end;
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
    shared_pointer<Expression> returned = nullptr;

    ReturnStatement() = default;

    explicit ReturnStatement(shared_pointer<Expression> exp) {
        returned = std::move(exp);
        start = end = line;
    }
};

struct WhileLoop : Statement {
    shared_pointer<Expression> condition;
    shared_pointer<Block> body;

    WhileLoop(shared_pointer<Expression> cond, shared_pointer<Block> body) {
        start = line;
        condition = std::move(cond);
        body = body;
    }
};

struct IfStatement : Statement {
    shared_pointer<Expression> condition;
    shared_pointer<Block> body;
    shared_pointer<Block> elseBody;

    IfStatement(shared_pointer<Expression> exp, shared_pointer<Block> block, shared_pointer<Block> elseBlock) :
            condition(std::move(exp)), body(std::move(block)), elseBody(std::move(elseBlock)) { start = line; }
};

struct ForLoop : Statement {
    shared_pointer<Block> body;
    shared_pointer<Expression> rangeStart;
    shared_pointer<Expression> rangeEnd;
    shared_pointer<Variable> loopVar;
    bool reversed = false;

    ForLoop() = default;

    ForLoop(const std::string &LoopVar, std::tuple<shared_pointer<Expression>, shared_pointer<Expression>, bool> Range,
            shared_pointer<Block> Body) :
            rangeStart(get<0>(Range)), rangeEnd(get<1>(Range)), reversed(get<2>(Range)), body(std::move(Body)) {
        loopVar = std::make_shared<Variable>(LoopVar, nullptr);
        start = line;
    }
};

struct Declaration : Statement {
    shared_pointer<Type> type;
};

struct Assignment : Statement {
    shared_pointer<Expression> rValue;
    shared_pointer<Ident> lValue;

    Assignment(const std::string &identName, shared_pointer<Expression> exp) :
            rValue(std::move(exp)) {
        start = line;
        lValue = std::make_shared<Ident>(identName);
    }
};

struct Ident : Node {
    explicit Ident(const std::string &s) : Node(s) {}
};

struct Expression : Node {
    using spe = shared_pointer<Expression>;
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
    shared_pointer_vector<Expression> args;

    explicit RoutineCall(const std::string &ident) { name = ident; }
};

struct BuiltinType : Type {
    std::variant<long long int, double, bool> iValue, rValue, bValue;

    explicit BuiltinType(const std::string &otherName) : Type(otherName) {
        name = otherName;
    }
};

struct Record : Type {
    shared_pointer_vector<Variable> fields;

    Record(const std::string &Name, shared_pointer_vector<Variable> &Fields) : Type(Name) {
        fields = std::move(Fields);
    }
};

struct Alias : Type {
    shared_pointer<Type> type;
};

struct Array : Type {
    int size = 0;
    shared_pointer<Type> type;

    explicit Array(const std::string &name) : Type(name) {}
};

void dfs();

void printVariable(shared_pointer<Variable> var);