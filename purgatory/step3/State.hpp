//
// Created by sylva on 06/01/2018.
//

#ifndef STEP3_STATE_HPP
#define STEP3_STATE_HPP

#include <map>
#include <vector>
#include <algorithm>
#include <string>

class State {
private:
    static std::vector<std::string> names;

public:
    const std::string name;
    const int idx;
    const bool finalState;
    char transition;

private:
    explicit State(std::string &name, const int idx, const char transition, bool finalState)
            : name(name), idx(idx), transition(transition), finalState(finalState) {}

public:
    static State *factory(const char *name, const char transition = 0, bool finalState = false) {
        std::string s = name;
        return State::factory(s, transition, finalState);
    }

    static State *factory(std::string &name, const char transition = 0, bool finalState = false) {
        if (std::find(names.begin(), names.end(), name) != names.end()) return NULL;
        names.push_back(name);

        static int idx = 0;
        State *state = new State(name, idx, transition, finalState);
        ++idx;
        return state;
    }

    void setTransition(const char c) {
        this->transition = c;
    }

    bool operator==(const State &other) {
        return this->name == other.name;
    }

    bool operator!=(const State &other) {
        return this->name != other.name;
    }
};

std::vector<std::string> State::names;

#endif //STEP3_STATE_HPP
