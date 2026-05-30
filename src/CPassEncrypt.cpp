#include "CPassEncrypt.h"

std::string encrypt(std::string content, std::string key) {
    std::string tmp(key);
    while(key.size() < content.size()) key += tmp;
    for(std::string::size_type i = 0; i < content.size(); i++) content[i] ^= key[i];
    return content;
}

std::string decrypt(std::string content, std::string key) {
    return encrypt(content, key);
}