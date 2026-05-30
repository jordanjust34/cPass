#include "src/CPass.h"

int main(int argc, char* argv[]) {
    if(!CPassConfig()) return 1;
    CPass(argc, argv);
    return 0;
}
