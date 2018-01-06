#include <cstdio>
#include <string>
#include <functional>
#include "Function.hpp"

int test() {
    printf("Test without argument to Function\n");
    return 42;
}

void toto(int a) {
    printf("Testing passing an integer to Function, it's value is: %d\n", a);
}

void pp4(int a, int b, int c, int d) {
    printf("Testing with 4 argument to Function, their value are: %d %d %d %d\n", a, b, c, d);
}

class Test {
public:
    void operator()() {
        printf("Testing with a callable object as parameter to Function\n");
    }
};

int main() {
    Function<int()> f0 = &test;
    f0();

    //Function<int()> f1 = std::bind(&test);
    //f1();

    Function<void()> f2 = Test();
    f2();

    Function<void(int)> f3 = &toto;
    f3(42);

    Function<void(int, int, int, int)> f4 = &pp4;
    f4(1, 2, 3, 4);

    return 0;
}
