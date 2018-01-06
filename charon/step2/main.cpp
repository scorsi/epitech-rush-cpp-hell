#include <cstdio>
#include <string>
#include <functional>
#include <type_traits>
#include "Function.hpp"

int test() {
    printf("hello\n");
    return 42;
}

void toto(int a) {
    printf("%d\n", a);
}

class Test {
public:
    void operator()() {
        std::printf("hey");
    }
};

int main() {
    Function<int()> f0 = &test;
    f0();

    Function<int()> f1 = std::bind(&test);
    f1();

    Function<void()> f2 = Test();
    f2();

    return 0;
}
