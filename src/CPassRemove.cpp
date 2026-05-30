#include "CPassRemove.h"

void removePassword(std::string password) {
    std::string PATH = resolvePath(getPATH(getOS()));

    if(!std::filesystem::exists(PATH)) return;
    try {
        std::string filePATH = PATH + password + ".json";
        if(std::filesystem::exists(filePATH)) {
            std::filesystem::remove(filePATH);
        }
        return;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void purge() {
    std::string PATH = resolvePath(getPATH(getOS()));
    if(!std::filesystem::exists(PATH)) return;
    std::filesystem::remove_all(PATH);
}