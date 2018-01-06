#include <cstdio>
#include <cassert>
#include "Machine.hpp"

int main() {
    printf("state_machine(\"evil\") = %s\n", state_machine("evil") == Action::HR ? "true" : "false");
    printf("state_machine(\"evi\") = %s\n", state_machine("evi") == Action::HR ? "true" : "false");
    printf("state_machine(\"avil\") = %s\n", state_machine("avil") == Action::HR ? "true" : "false");
    return 0;
}