#include "CPassCred.h"

bool verify() {
    std::string userPassword;
    std::cout << "Password: ";
    std::cin >> userPassword;

    if(decrypt(getKey(), userPassword) == userPassword) return true;
    return false;
}