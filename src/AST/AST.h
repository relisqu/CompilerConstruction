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
#include <map>
#include "Tokens/Span.h"
#include "StoredType.h"
#include "Consts.h"
#include "Error/ErrorHandler.h"

namespace ast {

    extern Span cur_span;

    template<typename T> using sp = std::shared_ptr<T>;
    template<typename T> using spv = std::vector<std::shared_ptr<T>>;

    struct Program;
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
    struct Variable;
    struct BuiltinType;
    struct Record;
    struct Array;

    extern std::unordered_map<std::string, std::shared_ptr<Type> > TypeTable;

    extern int line;

    class Visitor {
    public:

        std::map<std::string, std::vector<StoredType> > identMap;

        void increaseScope() {
            globalScope++;
        }

        void decreaseScope() {
            globalScope--;
            for (auto it = identMap.begin(); it != identMap.end(); it++) {
               while (!it->second.empty() && it->second.back().current_scope > globalScope) {
                    it->second.pop_back();
                }
            }

        }

        StoredType resolveIdent(const StoredType& ident) {
            StoredType result = ST_NULL;
            result.ident = ident.ident;
            if (ident.tag != Tag::tagIdent) {
                return result;
            }
            if (!identMap[ident.ident].empty()) {
                return identMap[ident.ident].back();
            }
            if (result == ST_NULL) {
                //printOffset();
                ErrorHandler::ThrowError("Ident type mismatch: no such ident defined \"" + result.ident+"\"");
            }
            return result;
        }

        StoredType resolveIdent(const std::string &ident) {
            if (!identMap[ident].empty()) {
                return identMap[ident].back();
            }
            return ST_NULL;
        }

        std::vector<StoredType> contextStack = {};
        std::vector<StoredType> expectedReturnTypes = {ST_INTEGER};

        void cutContextStack(int targetSize) {
            while (contextStack.size() > targetSize) {
                contextStack.pop_back();
            }
        }

        virtual void visit(const Program &node) = 0;

        virtual void visit(const Node &node) = 0;

        virtual void visit(const Block &node) = 0;

        virtual void visit(const Routine &node) = 0;

        virtual void visit(const Statement &node) = 0;

        virtual void visit(const ReturnStatement &node) = 0;

        virtual void visit(const WhileLoop &node) = 0;

        virtual void visit(const IfStatement &node) = 0;

        virtual void visit(const ForLoop &node) = 0;

        virtual void visit(const Declaration &node) = 0;

        virtual void visit(const Assignment &node) = 0;

        virtual void visit(const Expression &node) = 0;

        virtual void visit(const RoutineCall &node) = 0;

        virtual void visit(const Ident &node) = 0;

        virtual void visit(const Type &node) = 0;

        virtual void visit(const Variable &node) = 0;

        virtual void visit(const BuiltinType &node) = 0;

        virtual void visit(const Record &node) = 0;

        virtual void visit(const Array &node) = 0;
    };

    struct Node {
        std::string name;
        Span span;

        Node() = default;

        explicit Node(std::string s) : name(std::move(s)), span(cur_span) {}

        virtual ~Node() = default;

        virtual void accept(Visitor *v) const {
            v->visit(*this);
        }
        virtual std::string generateCode() {
            return {};
        }
    };
    struct Ident : Node {
        explicit Ident(const std::string &s) : Node(s) {}

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            return " "+ name+" ";
        };
    };

    struct Expression : Node {
        using spe = sp<Expression>;
        std::variant<std::string, long long int, double, bool> value;
        spe l = nullptr;
        spe r = nullptr;

        static std::string getType(const std::shared_ptr<Expression> &exp);

        Expression(const std::string &newSymbol, spe first, spe second = nullptr) : Node(
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

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            std::string operation;
            std::string strValue = "NOTCONSTVAL";
            switch (value.index()) {
                case 0:
                    operation = std::get<0>(value);
                    break;
                case 1:
                    std::cout << std::get<1>(value);
                    strValue = std::to_string(std::get<1>(value));
                    break;
                case 2:
                    std::cout << std::get<2>(value);
                    strValue = std::to_string(std::get<2>(value));
                    break;
                case 3:
                    std::cout << std::get<3>(value);
                    strValue = std::to_string(std::get<3>(value));
                    break;
            }
            std::string left;
            std::string right;
            if(l){
                left=l->generateCode();
            }
            if(r){
                right=r->generateCode();
            }
            // return left+ operation+right +";\n";
            if (left + operation + right == "") {
                return strValue;
            }
            std::cout<<"\n-- l:" +left<<" ,n:"<<name<<" ,r:"<<right<<" ,o:"<<operation<<"----\n";
            return left + operation + right;
        };
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

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        virtual std::string generateCode() override{
            return " "+name+" ";
        };
    };

    struct Variable : Type {
        sp<Type> type;
        sp<Ident> ident;
        sp<Expression> value = nullptr;

        Variable() = default;

        explicit Variable(const std::string &Name) : Type(Name) {}

        Variable(const std::string &Name, sp<Type> type2) :
                Type(Name) {
            type = std::move(type2);
        }

        Variable(const std::string &Name, sp<Expression> exp) : Type(Name) {
            value = std::move(exp);
        }

        Variable(const std::string &Name, sp<Expression> exp, sp<Type> type2) : Type(Name),
                                                                                ident(std::make_shared<Ident>(
                                                                                        Name)) {
            value = std::move(exp);
            type = std::move(type2);
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            std::string typeStr;
            std::string valueStr;
            std::string result;

            if(type){
                typeStr=type->generateCode();
                result += typeStr + " ";
            }
            result += name;
            if(value){
                result += " = ";
                valueStr=value->generateCode();
                result += valueStr;
                if (!type) {
                    result = "auto " + result;
                }
            }
            result += ";\n";
            return result;
        };
    };

    struct Program : Node {
        std::vector<sp<Node>> nodes;

        Program() { span = cur_span; }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
        std::string generateCode() override{
            std::string innerCommands;

            for (auto &node: nodes) {
                std::string nodeStr=node->generateCode();
                innerCommands+= nodeStr;
            }
            return "int main() { \n"+innerCommands+"\n return 0; \n}";
        }
    };

    struct Block : Node {
        std::vector<sp<Node>> nodes;

        Block() { span = cur_span; }

        ~Block() override = default;

        void addVariable(const sp<Node> &v);

        void addStatement(const sp<Node> &s);

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
        std::string generateCode() override{
            std::string commands;
            for (auto &innerNode: nodes) {
                commands+= innerNode->generateCode()+"\n";
            }
            return commands;
        };
    };

    struct Statement : Expression {
        explicit Statement(const std::string& name) : Expression(name) {}

        ~Statement() override = default;
        std::string generateCode() override{
            return "STATEMENT";
        };
    };

    struct ReturnStatement : Statement {
        sp<Expression> returned = nullptr;

        explicit ReturnStatement(sp<Expression> exp) : Statement("return") {
            returned = std::move(exp);
            span = cur_span;
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
    };

    struct WhileLoop : Statement {
        sp<Expression> condition;
        sp<Block> body;

        WhileLoop(sp<Expression> cond, sp<Block> obody) : Statement("while") {
            span = cur_span;
            condition = std::move(cond);
            body = std::move(obody);
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            std::string conditionStr= condition->generateCode();
            std::string bodyStr;
            if(body){
                bodyStr= body->generateCode();
            }
            return "while( "+conditionStr+" ){\n"+bodyStr+"}\n";
        };
    };

    struct IfStatement : Statement {
        sp<Expression> condition;
        sp<Block> body;
        sp<Block> elseBody;

        IfStatement(sp<Expression> exp, sp<Block> block, sp<Block> elseBlock) :
                Statement("if"), condition(std::move(exp)), body(std::move(block)),
                elseBody(std::move(elseBlock)) { span = cur_span; }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

         std::string generateCode() override{
            std::string conditionStr;
            std::string ifBranch;
            std::string elseBranch;

            if (condition) {
                conditionStr= condition->generateCode();
            }

            if (body) {
                ifBranch=body->generateCode();
            }

            std::string ifStr= "if ("+conditionStr+"){\n "+ifBranch+" }";
            if(elseBody){
                ifStr+= "\nelse {\n "+elseBody->generateCode()+" }";
            }
            return ifStr;
        };

    };

    struct ForLoop : Statement {
        sp<Block> body;
        sp<Expression> rangeStart;
        sp<Expression> rangeEnd;
        sp<Variable> loopVar;
        bool reversed = false;

        ForLoop(const std::string &LoopVar,
                std::tuple<sp<Expression>, sp<Expression>, bool> Range,
                sp<Block> Body) :
                Statement("for"),
                rangeStart(std::get<0>(Range)), rangeEnd(std::get<1>(Range)), reversed(std::get<2>(Range)),
                body(std::move(Body)) {
            loopVar = std::make_shared<Variable>(LoopVar);

            span = cur_span;
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
        std::string generateCode() override{
            std::string start;
            std::string end;
            std::string loop;
            std::string bodyStr;
            if (rangeStart) {
                start= rangeStart->generateCode();
            }

            if (rangeEnd) {
                end= rangeEnd->generateCode();
            }
            if (loopVar) {
                loop= loopVar->generateCode();
            }

            if(reversed){
                std::swap(end,start);
            }
            if (body) {
                bodyStr= body->generateCode();
            }
            loop.pop_back(); // remove \n
            loop.pop_back(); // remove ;
            if (!reversed)
                return "for (int "+loop+"="+start+";"+loop+"<"+end + ";"+loop+"++"+") {\n"+bodyStr+"}\n";
            else
                return "for (int "+loop+"="+start+";"+loop+">"+end + ";"+loop+"--"+") {\n"+bodyStr+"}\n";
        };
    };

    struct Declaration : Statement {
        sp<Type> type;

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            return type->generateCode();
        };
    };

    struct Assignment : Statement {
        sp<Expression> lValue;
        sp<Expression> rValue;

        Assignment(const std::string &identName, sp<Expression> exp) :
                Statement("assign"),
                rValue(std::move(exp)) {
            span = cur_span;
            lValue = std::make_shared<Expression>(identName);
        }

        Assignment(sp<Expression> _lValue, sp<Expression> _rValue) :
                Statement("assign"),
                lValue(std::move(_lValue)),
                rValue(std::move(_rValue)){
            span = cur_span;
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
        std::string generateCode() override{
            return lValue->generateCode() +" = "+ rValue->generateCode() +";";
        };
    };


    struct RoutineCall : Statement {
        spv<Expression> args;

        explicit RoutineCall(const std::string &ident) : Statement("Routine call") { name = ident; }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
        std::string generateCode() override{

            std::string nameStr=name;
            std::string params;

            for (const auto& n : args) {
                params+= n->generateCode()+" ";
            }
            return nameStr+"("+params+");\n";
        };
    };

    struct BuiltinType : Type {
        std::variant<long long int, double, bool> Value;

        explicit BuiltinType(const std::string &otherName) : Type(otherName) {
            name = otherName;
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            return " "+name+" ";
        };
    };

    struct Record : Type {
        spv<Variable> fields;

        Record(const std::string &Name, spv<Variable> &Fields) : Type(Name) {
            fields = std::move(Fields);
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            std::string params;
            for (auto const &n : fields) {
                params+= n->generateCode()+" ";
            }
            return "struct "+name+" {\n"+params+"};\n";
        };

    };

    struct Alias : Type {
        sp<Type> type;

        void accept(Visitor *v) const override {
            v->visit(*this);
        }
    };


    struct Routine : Node {
        sp<Block> body;
        sp<Ident> ident;
        spv<Variable> parameters;
        sp<Type> returnType;
        spv<ReturnStatement> returnStatements;

        Routine() = default;

        Routine(const std::string &name, spv<Variable> params, const sp<Block> &oBody,
                sp<Type> rtType) : Node("routine"), ident(std::make_shared<Ident>(name)) {
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

        void accept(Visitor *v) const override {
            v->visit(*this);
        }


        std::string generateCode() override{

            std::string type="void";
            std::string name;
            std::string params;
            std::string bodyStr;
            std::string returnStr="return ";

            if (returnType) {
                type= returnType->generateCode();
            }
            name= ident->generateCode();

            for (const auto& n : parameters) {
                params+= n->generateCode()+" ";
            }

            bodyStr= body->generateCode();

            for (const auto& n : returnStatements) {
                returnStr+=n->generateCode();
            }
            return type+" "+name+"("+params+"){\n"+bodyStr+returnStr+";}\n";
        };
    };

    struct Array : Type {
        sp <Expression> size;
        bool hasSize = false;
        sp<Type> type;

        explicit Array(const std::string &name) : Type(name) {}

        Array(const std::string& _name, const sp<Type>& _type) : Type(_name) {
            type = _type;
        }

        Array(const std::string& _name, const sp<Type>& _type, const sp<Expression>& _size) : Array(_name, _type) {
            size = _size;
            hasSize = true;
        }

        void accept(Visitor *v) const override {
            v->visit(*this);
        }

        std::string generateCode() override{
            "int myNumbers[] = {25, 50, 75, 100};" ;
            std::string sizeStr;
            if(size){
                sizeStr=size->generateCode();
            }
            return type->generateCode()+" "+name+"["+sizeStr+"];\n";
        };
    };

    sp<Program> getProgram();

    void dfs();

    void show_dfs();

    void sort_program();

    void printStatement(const sp<Statement> &statement);

    void printVariable(const sp<Variable> &var);
}