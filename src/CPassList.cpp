#include "CPassList.h"

void list() {
    std::string PATH = resolvePath(getPATH(getOS()));   // path cleaning
    if(!std::filesystem::exists(PATH)) return;
    std::vector<std::string> fileVec;

    int cnt = 0;
    try {
        for(const auto& fp : std::filesystem::directory_iterator(PATH)) {
            if(fp.is_regular_file()) {
                std::string fileName = fp.path().filename().string();
                if((fileName.size() > 5) && (fileName.substr(fileName.size() - 5) == ".json")) {
                    fileName = fileName.substr(0, fileName.size() - 5);\
                    fileVec.push_back(fileName);
                }
                cnt ++;
            }
        }
        if(cnt == 0) std::cout << "No passwords stored" << std::endl;
        show(fileVec);
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void show(std::vector<std::string> fileVec) {
    int cnt = 1;
    const int columnWidth = 22;
    for(std::string fileName : fileVec) {
        std::cout << std::left << std::setw(columnWidth) << fileName;
        cnt++;
        if((cnt & 2) == 0) std::cout << std::endl;
    }
}