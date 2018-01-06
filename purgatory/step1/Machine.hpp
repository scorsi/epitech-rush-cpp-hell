//
// Created by sylva on 06/01/2018.
//

#ifndef TEST_FSA_MACHINE_HPP
#define TEST_FSA_MACHINE_HPP

#include <vector>
#include <map>

enum class State {
    S0 = 0,
    S1,
    S2,
    S3,
    STATE_ERROR
};

enum class Action {
    MA = 0,
    HR,
    ACTION_ERROR
};

Action state_machine(const char *str);

extern std::map<State, std::vector<State>> stateTable;
extern std::map<State, std::vector<Action>> actionTable;
extern const char *state_machine_match;

#endif //TEST_FSA_MACHINE_HPP
