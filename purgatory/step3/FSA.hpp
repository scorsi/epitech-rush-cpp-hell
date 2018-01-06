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

public:
    State *initialState;

    void addState(State *s) {
        if (s == NULL) return;

        if (states.empty()) this->setInitialState(s);
        states.push_back(s);
    }

    void setInitialState(State *s) {
        if (s != NULL)
            initialState = s;
    }

    void setInitialState(const char *name) {
        State *s = this->operator[](name);
        if (s != NULL)
            initialState = s;
    }

    void setInitialState(const std::string &name) {
        State *s = this->operator[](name);
        if (s != NULL)
            initialState = s;
    }

    State *getNext(State *s) {
        std::vector<State *>::iterator it = std::find(this->states.begin(), this->states.end(), s);
        if (it == this->states.end()) return NULL;
        it++;
        if (it == this->states.end()) return NULL;
        return *it;
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
