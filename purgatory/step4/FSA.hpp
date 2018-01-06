//
// Created by sylva on 06/01/2018.
//

#ifndef STEP3_FSA_HPP
#define STEP3_FSA_HPP

#include <vector>
#include "State.hpp"

class FSA {
private:
    std::vector<State *> states;
    std::map<State *, std::vector<State *> > closures;

public:
    State *initialState;

    void addState(State *s) {
        if (s != NULL)
            states.push_back(s);
    }

    void addClosure(State *orig, State *source) {
        closures[orig].push_back(source);
    }

    void setInitialState(State *s) {
        if (s != NULL)
            initialState = s;
    }

    std::vector<State *> next(State *s) {
        return this->closures[s];
    }

    std::vector<State *> closure() {
        return this->closures[this->initialState];
    }

    State *operator[](const char *name) {
        std::string s = name;
        return this->operator[](s);
    }

    State *operator[](const std::string &name) {
        for (std::vector<State *>::iterator it = states.begin(); it != states.end(); it++) {
            if ((*it)->name == name) return *it;
        }
        return NULL;
    }
};


#endif //STEP3_FSA_HPP
