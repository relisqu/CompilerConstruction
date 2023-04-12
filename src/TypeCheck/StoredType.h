//
// Created by justsomedude on 11.04.23.
//

#ifndef COMPILERCONSTRUCTION_STOREDTYPE_H
#define COMPILERCONSTRUCTION_STOREDTYPE_H


#include <string>
#include <utility>
#include <vector>
#include "Tag.h"

class StoredType {
public:
    Tag tag;
    std::string ident;
    int current_scope = 0;

    std::vector<StoredType> inTypes = {};
    std::vector<StoredType> outTypes = {};
    std::vector<StoredType> content = {};

    StoredType() {
        tag = Tag::tagNull;
    }

    explicit StoredType(Tag _tag) {
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

};


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