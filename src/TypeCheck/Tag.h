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

#endif //COMPILERCONSTRUCTION_TAG_H
