//
// Created by justsomedude on 11.04.23.
//

#ifndef COMPILERCONSTRUCTION_STOREDTYPE_H
#define COMPILERCONSTRUCTION_STOREDTYPE_H


#include <string>
#include <vector>
#include "Tag.h"

class StoredType {
public:
    Tag tag;
    std::string ident;

    std::vector<StoredType> inTypes;
    std::vector<StoredType> outTypes;
    std::vector<StoredType> content;


};


#endif //COMPILERCONSTRUCTION_STOREDTYPE_H
