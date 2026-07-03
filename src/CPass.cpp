#include "CPass.h"


void CPass(int argc, char* argv[]) {
    try {
        parseFlag(argc, argv);

        /* Start of new verifying feature */
        // if(verify()) {
        //     parseFlag(argc, argv);
        // } else {
        //     std::cout << "Error with given password..." << std::endl;
        //     return;
        // }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
}

bool CPassConfig() {
    try {
        std::string configPATH = createDir();
        if(configPATH == "") return false;
    
        std::filesystem::path filePATH = std::filesystem::path(configPATH) / "config.json";
        if(std::filesystem::exists(filePATH)) return true;
        std::ofstream newFile(filePATH);
    
        std::string masterPassword;
        std::cout << "Create Master Password: ";
        std::cin >> masterPassword;
        if(masterPassword == "") {
            std::cout << "Password is required..." << std::endl;
            return false;
        }
    
        std::string key = encrypt(masterPassword, masterPassword);
        nlohmann::json data;
        data["user"] = key;
        newFile << data.dump(4);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

std::string getKey() {
    try {
        std::string configPATH = createDir();
        if(configPATH == "") return "";
    
        std::filesystem::path filePATH = std::filesystem::path(configPATH) / "config.json";
        if(!std::filesystem::exists(filePATH)) CPassConfig();
    
        nlohmann::json data;
        std::ifstream f(filePATH);
        data = nlohmann::json::parse(f);
    
        return data["user"];
    } catch (std::exception& e) {
        std::cout << "getKey()" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return "";
}

std::string stripKey(std::string content) {
    content.erase(std::remove(content.begin(), content.end(), '\"'), content.end());
    return content;
}