//
// Created by justsomedude on 12.04.23.
//

#ifndef COMPILERCONSTRUCTION_CONSTS_H
#define COMPILERCONSTRUCTION_CONSTS_H

#include "StoredType.h"
#include "Tag.h"

const StoredType ST_PLACEHOLDER = StoredType(Tag::tagPlaceholder);

const StoredType ST_NULL = StoredType(Tag::tagNull);
const StoredType ST_INTEGER = StoredType(Tag::tagInteger);
const StoredType ST_REAL = StoredType(Tag::tagReal);
const StoredType ST_BOOLEAN = StoredType(Tag::tagBool);

const StoredType ST_IDENT = StoredType(Tag::tagIdent);
const StoredType ST_RECORD = StoredType(Tag::tagRecord);
const StoredType ST_ROUTINE = StoredType(Tag::tagRoutine);

const StoredType ST_ARRAY = StoredType(Tag::tagArray);

#endif //COMPILERCONSTRUCTION_CONSTS_H
