//
// Created by Relisqu on 29.04.2023.
//
#pragma once

#include "AST/AST.h"

using namespace ast;


class ICodeGeneratable{

    std::vector <std::string> MainVoidCommands;
    std::vector <std::string> GlobalScopeCommands;


    static std::string generate(const Node &node) {};

    static std::string generate(const Block &node)  {
        std::string commands;
        for (auto &innerNode: node.nodes) {
            commands+= generate(*innerNode)+"\n";
        }
        return commands;
    };

    static std::string generate(const Routine &node)  {

        std::string type="void";
        std::string name;
        std::string params;
        std::string body;
        std::string returnStr="return ";

        if (node.returnType) {
            type= generate(*node.returnType);
        }
        name= generate(*node.ident);

        for (const auto& n : node.parameters) {
            params+= generate(*n)+" ";
        }

        body= generate(*node.body);

        for (const auto& n : node.returnStatements) {
            returnStr+=generate(*n);
        }
        return type+" "+name+"("+params+"){\n"+body+returnStr+";}\n";
    };

    static std::string generate(const Statement &node)  {};

    static std::string generate(const ReturnStatement &node) {};

    static std::string generate(const WhileLoop &node) {
        std::string condition= generate(*node.condition);
        std::string body;
        if(node.body){
            body= generate(*node.body);
        }
        return "while( "+condition+" ){\n"+body+"}\n";
    };

    static std::string generate(const IfStatement &node) {
        std::string condition;
        std::string ifBranch;
        std::string elseBranch;

        if (node.condition) {
            condition= generate(*node.condition);
        }

        if (node.body) {
            ifBranch= generate(*node.body);
        }

        std::string ifStr= "if ("+condition+"){ "+ifBranch+" }";
        if(node.elseBody){
            ifStr+= "else { "+ generate(*node.elseBody)+" }";
        }
        return ifStr;
    };

    static std::string generate(const ForLoop &node) {
        std::string start;
        std::string end;
        std::string loop;
        std::string body;
        if (node.rangeStart) {
            start= generate(*node.rangeStart);
        }

        if (node.rangeEnd) {
            end= generate(*node.rangeEnd);
        }
        if (node.loopVar) {
            loop= generate(*node.loopVar);
        }

        if(node.reversed){
            std::swap(end,start);
        }
        if (node.body) {
            body= generate(*node.body);
        }
        return "for ("+start+end+loop+") {\n"+body+"}\n";
    };

    static std::string generate(const Declaration &node) {
        return generate(*node.type);
    };

    static std::string generate(const Assignment &node) {
        return generate(*node.lValue) +" = "+ generate(*node.rValue)+";";
    };

    static std::string generate(const Expression &node){
        std::string operation;
        switch (node.value.index()) {
            case 0:
                operation = std::get<0>(node.value);
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
        return generate(*node.l)+ operation+ generate(*node.r)+";\n";
    };

    static std::string generate(const RoutineCall &node){

        std::string name=node.name;
        std::string params;

        for (const auto& n : node.args) {
           params+= generate(*n)+" ";
        }
        return name+"("+params+");\n";
    };

    static std::string generate(const Ident &node) {
        return " "+node.name+" ";
    };

    static std::string generate(const Type &node) {
        return " "+node.name+" ";
    };

    static  std::string generate(const Variable &node) {
        return generate(*node.type)+" "+generate(*node.ident)+" = "+ generate(*node.value);
    };

    static std::string generate(const BuiltinType &node){
        if (node.name == "integer") {
            return std::to_string(std::get<0>(node.Value));
        }
        else if (node.name == "real") {
            return std::to_string(std::get<1>(node.Value));
        }
        else if (node.name == "boolean") {
            return std::to_string(std::get<2>(node.Value));
        }
        return "";
    };

    static std::string generate(const Record &node) {
        std::string params;
        for (auto const &n : node.fields) {
            params+= generate(*n)+" ";
        }
        return "struct "+node.name+" {\n"+params+"};\n";
    };

    static std::string generate(const Array &node) {
        "int myNumbers[] = {25, 50, 75, 100};" ;
        std::string size;
        if(node.size){
            size=generate(*node.size);
        }
        return generate(*node.type)+" "+node.name+"["+size+"];\n";
    };
public:
    static std::string generate(const Program &program) {
        std::string innerCommands;

        for (auto &node: program.nodes) {
            std::string nodeStr=generate(*node);
            innerCommands+= nodeStr;
        }
        return "int main() { \n"+innerCommands+"\n return 0; \n}";
    }
};