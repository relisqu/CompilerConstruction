#include "AST.h"

int ast::line = 0;
extern ast::sp<ast::Program> ourProgram;
Span ast::cur_span = Span();

std::unordered_map<std::string, std::shared_ptr<ast::Type> > ast::TypeTable = {};

namespace ast {

    sp<Program> getProgram() {
        return ourProgram;
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
        auto *sign = std::get_if<std::string>(&exp->value);

        if (!(*sign == ">" || *sign == ">=" || *sign == "<" ||
              *sign == "<=" || *sign == "=" || *sign == "/=" ||
              *sign == "and" || *sign == "or" || *sign == "xor")) {
            if (left == "real" || right == "real") {
                return "real";
            } else if (left == "integer" || right == "integer") {
                return "integer";
            }
        } else {
            return "boolean";
        }
        return "";
    }

}