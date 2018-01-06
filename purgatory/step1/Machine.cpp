//
// Created by sylva on 06/01/2018.
//

#include "Machine.hpp"

/**
 * STATE    e       v       i       l       *
 *  S0      S1      ERROR   ERROR   ERROR   ERROR
 *  S1      ERROR   S2      ERROR   ERROR   ERROR
 *  S2      ERROR   ERROR   S3      ERROR   ERROR
 *  S3      ERROR   ERROR   ERROR   S4      ERROR
 *  S4      ERROR   ERROR   ERROR   ERROR   ERROR
 */

/**
 * STATE    e       v       i       l       *
 *  S0      MA      ERROR   ERROR   ERROR   ERROR
 *  S1      ERROR   MA      ERROR   ERROR   ERROR
 *  S2      ERROR   ERROR   MA      ERROR   ERROR
 *  S3      ERROR   ERROR   ERROR   MA      ERROR
 *  S4      ERROR   ERROR   ERROR   ERROR   HR
 */

std::map<State, std::vector<State>> stateTable = {
        {State::S0, {State::S1,          State::STATE_ERROR, State::STATE_ERROR, State::STATE_ERROR, State::STATE_ERROR}},
        {State::S1, {State::STATE_ERROR, State::S2,          State::STATE_ERROR, State::STATE_ERROR, State::STATE_ERROR}},
        {State::S2, {State::STATE_ERROR, State::STATE_ERROR, State::S3,          State::STATE_ERROR, State::STATE_ERROR}},
        {State::S3, {State::STATE_ERROR, State::STATE_ERROR, State::STATE_ERROR, State::STATE_ERROR, State::STATE_ERROR}}
};
std::map<State, std::vector<Action >> actionTable = {
        {State::S0, {Action::MA,           Action::ACTION_ERROR, Action::ACTION_ERROR, Action::ACTION_ERROR, Action::ACTION_ERROR}},
        {State::S1, {Action::ACTION_ERROR, Action::MA,           Action::ACTION_ERROR, Action::ACTION_ERROR, Action::ACTION_ERROR}},
        {State::S2, {Action::ACTION_ERROR, Action::ACTION_ERROR, Action::MA,           Action::ACTION_ERROR, Action::ACTION_ERROR}},
        {State::S3, {Action::ACTION_ERROR, Action::ACTION_ERROR, Action::ACTION_ERROR, Action::HR,           Action::ACTION_ERROR}}
};
const char *state_machine_str = "evil";

Action state_machine(const char *str) {
    State state = State::S0;
    for (int idx = 0; str[idx]; ++idx) {
        int o_idx;
        for (o_idx = 0; state_machine_str[o_idx] && state_machine_str[o_idx] != str[idx]; ++o_idx);
        Action action = actionTable[state][o_idx];
        switch (action) {
            case Action::MA:
                printf("%c = MA\n", str[idx]);
                state = stateTable[state][o_idx];
                break;
            case Action::HR:
                printf("%c = HR\n", str[idx]);
                return Action::HR;
            default:
                printf("%c = ERROR\n", str[idx]);
                return Action::ACTION_ERROR;
        }
    }
    printf("%c = ERROR\n", '\0');
    return Action::ACTION_ERROR;
}
