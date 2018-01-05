//
// Created by sylva on 05/01/2018.
//

#include <cstdio>
#include <string>
#include "FunctionSignature.hpp"

int display(const std::string &str) {
    printf("%s\n", str.c_str());
    return 0;
}

void display2(int a) {
    printf("%d\n", a);
}

void p() {
    printf("no argument\n");
}

void pp(char *toto) {
    printf("%c\n", *toto);
}

void pp2(char *toto, int *tata) {
    printf("%c %c\n", *toto, (char) *tata);
}

void pp4(int a, int b, int c, int d) {
    printf("%d %d %d %d\n", a, b, c, d);
}

void pp5(int a, int b, int c, int d, int e) {
    printf("%d %d %d %d %d\n", a, b, c, d, e);
}

int main() {
    FunctionSignature<void()>::type f0 = &p;
    f0();

    FunctionSignature<int(const std::string &)>::type f1 = &display;
    f1("toto");

    FunctionSignature<void(int)>::type f2 = &display2;
    f2(2);

    FunctionSignature<void(char *)>::type f3 = &pp;
    char f3_test = 't';
    f3(&f3_test);

    FunctionSignature<void(char *, int *)>::type f4 = &pp2;
    int f4_test = 'o';
    f4(&f3_test, &f4_test);

    FunctionSignature<void(int, int, int, int)>::type f5 = &pp4;
    f5(1, 2, 3, 4);

    //FunctionSignature<void(int, int, int, int, int)>::type f6 = &pp5;
    //f6(1, 2, 3, 4, 5);
    return 0;
}
