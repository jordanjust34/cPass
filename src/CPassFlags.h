#ifndef CPASSFLAGS_H
#define CPASSFLAGS_H

#include "CPass.h"
#include "CPassNew.h"
#include "CPassList.h"
#include "CPassRemove.h"
#include "CPassEncrypt.h"

#include <iostream>
#include <cctype>
#include <string>

enum Flag { // FLAGS
    NEW,
    LIST,
    REMOVE,
    PURGE,
    NOFLAG,
    ERROR
};

// PARSING
void parseFlag(int, char*[]);
enum Flag getFlag(std::string);
std::string toUpper(std::string);
std::string stripFlag(std::string);


#endif