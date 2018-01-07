#include <iostream>
#include "Bind.hpp"
#include "Storage.hpp"
#include "TypeTraits.hpp"

int main() {
    Storage3<int, char, const char *> s(1, 'c', "ta mere");
    std::cout << s._t1 << s._t2 << s._t3 << std::endl;


    return 0;
}