#include <iostream>
#include "Bind.hpp"

int printtest() {
    std::cout << "Hello, World !" << std::endl;
    return 0;
}

int addtest(int a, int b) {
    return a + b;
}

class foobar;

std::ostream &operator<<(std::ostream &stream, foobar &foobar) {
    stream << "foobar" << std::endl;
    return stream;
}

class foobar {
public:
    void operator()() {
        std::cout << *this;
    }

    void operator()(int a) {
        std::cout << a << *this;
    }
};

void toto(int a, int b, int c, int d, int e, int f) {}

int main() {
    Storage3<int, char, const char *> s(1, 'c', "ta mere");
    Storage6<int, int, int, int, int, int> a(1, 2, 3, 4, 5, 6);
    std::cout << s._t1 << s._t2 << s._t3 << std::endl;
    std::cout << a._t1 << a._t2 << a._t3 << a._t4 << a._t5 << a._t6 << std::endl;

    Caller<int, int (*)(), TypeList0> f0 = bind(&printtest);
    f0();

    Caller<int, int (*)(int, int), TypeList2<int, int> > f1 = bind(&addtest, 1, 2);
    f1();

    Caller<void, void (*)(int, int, int, int, int, int), TypeList6<int, int, int, int, int, int> > f2 = bind(&toto, 1, 2, 3, 4, 5, 6);
    f2();

    foobar foobar1;

    Caller<void, foobar, TypeList0> f3 = bind<void>(foobar1);
    f3();

    Caller<void, foobar, TypeList1<int> > f4 = bind<void>(foobar1, 42);
    f4();
    f4(32);

    const foobar const_foobar1 = foobar();
    Caller<void, const foobar, TypeList0> f5 = bind<void>(const_foobar1);
    f5();
    return 0;
}