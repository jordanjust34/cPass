#include "CPassFlags.h"

void parseFlag(int argc, char* argv[]) {    // do I need 'argc'?
    enum Flag flag = getFlag(argv[1]);
    std::vector<std::string> opts(argv + 1, argv + argc);
    std::string rm;
    switch (flag) {
        case (NEW):
            newPassword(opts);
            break;
        case (LIST):
            list();
            break;
        case (REMOVE):
            rm = argv[2];
            removePassword(rm);
            break;
        case (PURGE):
            purge();
            break;
        case (NOFLAG):
        default:
            cpyPassword(argv[1]);   // new function to copy password to user clipboard on MAC & LIMUX
            break;
    }
}

enum Flag getFlag(std::string flag) {
    flag = toUpper(flag);
    if(flag == "N" || flag == "NEW") {
        return NEW;
    } else if(flag == "L" || flag == "LIST") {
        return LIST;
    } else if(flag == "R" || flag == "RM" || flag == "REMOVE") {
        return REMOVE;
    } else if(flag == "PURGE") {
        return PURGE;
    } else {
        return NOFLAG;
    }
}

std::string toUpper(std::string flag) {
    flag = stripFlag(flag);
    for(char& c : flag) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return flag;
}

std::string stripFlag(std::string flag) {
    size_t first = flag.find_first_not_of('-');
    if(first != std::string::npos) {
        return flag.substr(first);
    }
    return flag;
}