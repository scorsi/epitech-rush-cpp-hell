#include <iostream>
#include <string>

#include "Inspector.hpp"

struct foo {
};

struct bar {
};

std::ostream &operator<<(std::ostream &o, bar &b) {
    o << "Hello from bar" << std::endl;
    return o;
}

std::ostream &operator<<(std::ostream &o, const bar &b) {
    o << "Hello from const bar" << std::endl;
    return o;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "is_printable std::ostream int: " << is_printable<std::ostream, int>::value << std::endl;
    std::cout << "is_printable std::ostream foo: " << is_printable<std::ostream, foo>::value << std::endl;
    std::cout << "is_printable std::ostream bar: " << is_printable<std::ostream, bar>::value << std::endl;
    std::cout << "is_printable std::wostream bar: " << is_printable<std::wostream, bar>::value << std::endl;

    int a = 42;
    inspect(std::cout, a);
    std::cout << std::endl;
    foo b;
    inspect(std::cout, b);
    std::cout << std::endl;
    bar c;
    inspect(std::cout, c);
    std::cout << std::endl;
}
