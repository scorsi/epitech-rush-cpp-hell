#include <cstdio>
#include <cassert>
#include "Machine.hpp"

int main() {
    printf("state_machine(\"evil\") = %s\n", state_machine("evil") == HR ? "true" : "false");
    printf("state_machine(\"evi\") = %s\n", state_machine("evi") == HR ? "true" : "false");
    printf("state_machine(\"avil\") = %s\n", state_machine("avil") == HR ? "true" : "false");
    printf("state_machine(\"eeeeeeeevil\") = %s\n", state_machine("eeeeeeeevil") == HR ? "true" : "false");
    return 0;
}