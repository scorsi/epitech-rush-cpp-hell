#include <cstdio>
#include <string>
#include <functional>
#include "Function.hpp"

int test() {
    printf("hello\n");
    return 42;
}

void toto(int a) {
    printf("%d\n", a);
}

int main() {
    Function<int()> f0 = &test;
    f0();

    Function<void(int)> f1 = &toto;
    f1(42);

    return 0;
}
