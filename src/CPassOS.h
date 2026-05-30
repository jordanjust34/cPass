#ifndef CPASSOS_H
#define CPASSOS_H

#include <iostream>
#include <filesystem>

enum SysOS {
    WIN,
    MAC,
    LIN,
    UNIX
};

enum SysOS getOS();

std::string getPATH(enum SysOS);
std::string resolvePath(std::string);
std::string createDir();

#endif