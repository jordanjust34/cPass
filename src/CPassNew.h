#ifndef CPASSNEW_H
#define CPASSNEW_H

#include "CPass.h"
#include "CPassOS.h"
#include "CPassEncrypt.h"
#include "vendor/json.hpp"

#include <iostream>
#include <vector>
#include <fstream>

void newPassword(std::vector<std::string>);
std::string returnPassword(std::string);    // decided to put this here because I can

#endif