//
// Created by sylva on 05/01/2018.
//

#include <cstdio>
#include <string>
#include "FunctionSignature.hpp"

int display(const std::string &str) {
    printf(str.c_str());
    return 0;
}

int main() {
    FunctionSignature<int (const std::string &)>::type f = &display;
    f("toto");
    return 0;
}
