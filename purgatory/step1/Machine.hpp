//
// Created by sylva on 06/01/2018.
//

#ifndef TEST_FSA_MACHINE_HPP
#define TEST_FSA_MACHINE_HPP

#include <vector>
#include <map>

enum State {
    S0 = 0,
    S1,
    S2,
    S3,
    STATE_ERROR
};

enum Action {
    MA = 0,
    HR,
    ACTION_ERROR
};

template<typename T, std::size_t N>
std::vector<T> my_make_vector(const T (&data)[N]) {
  return std::vector<T>(data, data + N);
};

template<typename T1, typename T2>
std::pair<T1, T2> my_make_pair(T1 a, T2 b) {
  return std::pair<T1, T2>(a, b);
};

template<typename T1, typename T2, std::size_t N>
std::map<T1, T2> my_make_map(const std::pair<T1, T2> (&data)[N]) {
  return std::map<T1, T2>(data, data + sizeof(data) / sizeof(data[0]));
};

bool state_machine(const char *str);

extern std::map<State, std::vector<State> > stateTable;
extern std::map<State, std::vector<Action> > actionTable;
extern const char *state_machine_match;

#endif //TEST_FSA_MACHINE_HPP
