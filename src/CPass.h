#ifndef CPASS_H
#define CPASS_H

#include <iostream>
#include <filesystem>

#include "CPassFlags.h"
#include "CPassCred.h"

void CPass(int, char*[]);
bool CPassConfig();
std::string getKey();
std::string stripKey(std::string);

#endif