#include "CPassNew.h"

void newPassword(std::vector<std::string> opts) {
    if(opts.size() != 4) {  // makes sure all are reqs are filled out
        std::cout << "Not all reqs are filled out. (website, username/email, password)" << std::endl;
        return;
    }
    try {
        std::string dirPATH = createDir();
        if(dirPATH == "") return;
        std::filesystem::path filePATH = std::filesystem::path(dirPATH) / (opts[1] + ".json");
        if(std::filesystem::exists(filePATH)) return;
        std::ofstream newFile(filePATH);
        // opts[1] website
        // opts[2] username/email
        // opts[3] password
        std::string key = getKey();

        if(opts[1] == "" || opts[2] == "" || opts[3] == "") {
            std::cout << "Error writing data..." << std::endl;
            return;
        }

        nlohmann::json data;    // data encapsulation, json format
        data["website"] = encrypt(opts[1], key);
        data["username/email"] = encrypt(opts[2], key);
        data["password"] = encrypt(opts[3], key);


        newFile << data.dump(4);    // write json to file with tabs of size 4
    } catch (const std::exception& e) {
        std::cout << "newPassword()" << std::endl;
        std::cerr << e.what() << std::endl;
        if(std::filesystem::exists(std::filesystem::path(createDir()) / (opts[1] + ".json"))) std::filesystem::remove(std::filesystem::path(createDir()) / (opts[1] + ".json"));
    }
    return;
}

std::string returnPassword(std::string site) {
    std::string PATH = resolvePath(getPATH(getOS()));   // path cleaning
    std::filesystem::path filePATH = std::filesystem::path(PATH) / (site + ".json");
    if(!std::filesystem::exists(filePATH)) {
        std::cout << "No password found for " << site << std::endl;
        return "";
    }
    try {
        std::ifstream inFile(filePATH);
        nlohmann::json data;
        inFile >> data;
        return encrypt(data["password"].get<std::string>(), getKey());
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return "";
    }
}