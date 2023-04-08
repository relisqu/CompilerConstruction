//
// Created by justsomedude on 08.04.23.
//

#ifndef COMPILERCONSTRUCTION_VISITOR_H
#define COMPILERCONSTRUCTION_VISITOR_H


#include "AST.h"

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

class Visitor {
public:
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
};

#endif //COMPILERCONSTRUCTION_VISITOR_H
