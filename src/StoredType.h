//
// Created by justsomedude on 11.04.23.
//

#ifndef COMPILERCONSTRUCTION_STOREDTYPE_H
#define COMPILERCONSTRUCTION_STOREDTYPE_H


#include <string>
#include <utility>
#include <vector>
#include "Tag.h"


static int globalScope = 0;//global scope is variable which is changed during code generation and is used to determine scope of node

class StoredType;
inline std::string ToString(const std::vector<StoredType>&  t);
/**
 * @brief StoredType is class which stores type information with name of node, type, tag,its scope etc.
 */
class StoredType {
public:
    Tag tag;
    std::string ident;
    int current_scope = globalScope;
    std::string typeName; // For records;

    std::vector<StoredType> inTypes = {};
    std::vector<StoredType> outTypes = {};
    std::vector<StoredType> content = {};

    StoredType() {
        current_scope = globalScope;
        tag = Tag::tagNull;
    }

    explicit StoredType(Tag _tag) {
        current_scope = globalScope;
        tag = _tag;
    }

    StoredType(Tag _tag, std::string _ident) : StoredType(_tag) {
        ident = std::move(_ident);
    }

    StoredType(Tag _tag, std::string _ident,
               std::vector<StoredType> _inTypes,
               std::vector<StoredType> _outTypes,
               std::vector<StoredType> _content) : StoredType(_tag, std::move(_ident)) {
        inTypes = std::move(_inTypes);
        outTypes = std::move(_outTypes);
        content = std::move(_content);
    }

    bool operator== (const StoredType &other) const {
        if (tag != other.tag) {
            return false;
        }
        if (!(inTypes == other.inTypes) ||
            !(outTypes == other.outTypes) ||
            !(content == other.content)) {
            return false;
        }
        return true;
    }

    bool operator!= (const StoredType &other) const {
        return !(*this == other);
    }

    [[nodiscard]] std::string getType() const {
        if (tag == Tag::tagRecord) {
            return "struct " + typeName;
        } else {
            return ToCode(tag);
        }
    }

    void setScope(){
        current_scope = globalScope;
    }

    void setScope(int targetScope) {
        current_scope = targetScope;
    }

    void print() const {
        std::cout << ToString(tag) << '\n';
        std::cout << ident << '\n';
        std::cout << current_scope << '\n';

        std::cout << "InTypes: " << ToString(inTypes) << '\n';
        std::cout << "OutTypes: " << ToString(outTypes) << '\n';
        std::cout << "Content: " << ToString(content) << '\n';
    }

};

/**
 * @brief Function which converts vector of StoredTypes to string for printing, debugging
 */
inline std::string ToString(const std::vector<StoredType>&  t)
{
    std::string types;
    for (const auto& type : t) {
        types+= ToString(type.tag)+ ", ";

    }
    if(types.length()>=2){
        types.pop_back();
        types.pop_back();
    }
    return types;
}
#endif //COMPILERCONSTRUCTION_STOREDTYPE_H
