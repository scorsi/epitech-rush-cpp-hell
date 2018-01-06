#include <iostream>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"

int main() {
    FSA fsa;
    fsa.addState(State::factory("S0", 'e'));
    fsa.addState(State::factory("S1", 'v'));
    fsa.addState(State::factory("S2", 'i'));
    fsa.addState(State::factory("S3", 'l', true));

    Matcher m(fsa);
    std::size_t n = 0;

    printf("%s => %s : %d\n", "evilevil", m.find("evilevil", n) ? "true" : "false", n);
    printf("%s => %s : %d\n", "evitoto", m.find("evitoto", n) ? "true" : "false", n);
    printf("%s => %s : %d\n", "evila", m.find("evila", n) ? "true" : "false", n);
    printf("%s => %s : %d\n", "evilevilevilevil", m.find("evilevilevilevil", n) ? "true" : "false", n);

    return 0;
}
