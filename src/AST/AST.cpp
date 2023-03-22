#include "AST.h"

int ast::line = 0;
extern ast::sp<ast::Program> ourProgram;
Span ast::cur_span = Span();

std::unordered_map<std::string, std::shared_ptr<ast::Type> > ast::TypeTable = {};

namespace ast {

    void Block::addVariable(const sp<Variable> &variable) {
        variables.push_back(variable);
        variable->span = cur_span;
    }

    void Block::addStatement(const sp<Statement> &statement) {
        statements.push_back(statement);
        statement->span = cur_span;
    }


    std::string Expression::getType(const std::shared_ptr<Expression> &exp) {
        if (exp == nullptr) {
            return "";
        }
        if (exp->l == nullptr && exp->r == nullptr) // this means it is a number or an identifer
        {
            std::string temp;
            switch (exp->value.index()) {
                case 0:
                    temp = "ident";
                    break;
                case 1:
                    temp = "integer";
                    break;
                case 2:
                    temp = "real";
                    break;
                case 3:
                    temp = "boolean";
                    break;
            }
            if (temp == "ident") {
                return TypeTable[std::get<0>(exp->value)]->name;
            } else {
                return temp;
            }
        } else if (exp->l == nullptr) {
            return getType(exp->l);
        } else if (exp->r == nullptr) {
            return getType(exp->r);
        }
        std::string left = getType(exp->l);
        std::string right = getType(exp->r);
        auto* sign  = std::get_if<std::string>(&exp->value);
        // TODO : fix this peace of ...
        if (!(sign->compare(">") == 0 || sign->compare(">=") == 0 || sign->compare("<") == 0 || sign->compare("<=") == 0 || sign->compare("=") == 0 || sign->compare("/=") == 0|| sign->compare("and") == 0 || sign->compare("or") == 0 || sign->compare("xor") == 0)){
            if (left == "real" || right == "real") {
                return "real";
            } else if (left == "integer" || right == "integer") {
                return "integer";
            }
        } else {
            return "boolean";
        }
    }

    void dfs() {
        std::sort(ourProgram->variables.begin(), ourProgram->variables.end(),
                  [](const std::shared_ptr<Variable> &a, const std::shared_ptr<Variable> &b) -> bool {
                      return a->span < b->span;
                  });
        std::cout << "\nourProgram contains:";
        std::cout << "\n=====VARIABLES=====\n";
        for (const auto &v: ourProgram->variables) {
            printVariable(v);
        }
        std::cout << "\n=====ROUTINES=====\n";
        for (const auto &r: ourProgram->routines) {
            std::cout << '\n';
            std::cout << r->name;
            std::cout << " at line " << r->span.lineNum;
            std::cout << " with parameters: \n";
            for (const auto &p: r->parameters)
                std::cout << p->name << " of type " << p->type->name << "\n";
            std::cout << "with variables :\n";
            for (const auto &v: r->body->variables)
                printVariable(v);
            std::cout << "with statements :\n";
            for (const auto &statement: r->body->statements) {
                printStatement(statement);
            }
        }
        std::cout << "\n=====GLOBAL STATEMENTS=====\n";
        for (const auto &statement : ourProgram->statements) {
            printStatement(statement);
        }
    }

    void printStatement(const sp<Statement> &s) {
        std::cout << "Statement " << s->name << " at line " << s->span.lineNum << '\n';
    }

    void printVariable(const sp<Variable> &v) {
        std::string x = v->name + "has value";
        std::cout << v->name << " ";
        if (v->value == nullptr) {
            std::cout << "(no value yet)";
        } else {
            std::cout << "of type " << Expression::getType(v->value);
        }
        std::cout << " at line " << v->span.lineNum << std::endl;
    }
}