//
// Created by justsomedude on 11.04.23.
//

#ifndef COMPILERCONSTRUCTION_TAG_H
#define COMPILERCONSTRUCTION_TAG_H

enum Tag {
    tagPlaceholder, // Tag intended to be replaced during typecheck.
    tagNull, // Bad tag for specifying something went wrong
    tagIdent,
    tagInteger,
    tagReal,
    tagBool,
    tagRecord,
    tagArray,
    tagRoutine
};

inline std::string ToString(Tag tag)
{
    switch (tag)
    {
        case tagPlaceholder:
            break;
        case tagNull:
            return "errorType";
            break;
        case tagIdent:
            return "identifier";
            break;
        case tagInteger:
            return "integer";
            break;
        case tagReal:
            return "real";
            break;
        case tagBool:
            return "bool";
            break;
        case tagRecord:
            return "record";
            break;
        case tagArray:
            return "array";
            break;
        case tagRoutine:
            return "routine";
            break;
    }
}
#endif //COMPILERCONSTRUCTION_TAG_H
