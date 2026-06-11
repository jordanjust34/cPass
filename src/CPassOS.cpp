#include "CPassOS.h"

enum SysOS getOS() {
    enum SysOS OS;
    #if defined(_WIN32) || defined(_WIN64)
        OS = WIN;
    #elif defined(__APPLE__)
        OS = MAC;
    #elif defined(__linux__)
        OS = LIN;
    #else
        OS = UNIX;
    #endif
    return OS;
}

std::string getPATH(enum SysOS OS) {
    if(OS == WIN) return "C:\\Users\\<Username>\\AppData\\cpass\\";
    return "~/.cpass/";
}

std::string resolvePath(std::string PATH) {
    if(!PATH.empty() && PATH[0] == '~') {   // check that PATH != empty, and starts with '~'
        const char* homeDir = std::getenv("HOME");  // tells computer to get home directory
        if(homeDir) {
            PATH.replace(0, 1, homeDir);
        }
    }
    return PATH;
}

std::string createDir() {
    std::string PATH = resolvePath(getPATH(getOS()));   // path cleaning
    try {
        if(!std::filesystem::exists(PATH)) {    // if path doesn't already exist
            std::filesystem::create_directories(PATH);
        }
        return PATH;
    } catch (const std::exception& e) {
        std::cerr << "Filesystem Error: " << e.what() << std::endl;
        return "";
    }
}