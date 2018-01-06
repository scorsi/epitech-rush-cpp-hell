//
// Created by sylva on 06/01/2018.
//

#ifndef STEP3_MATCHER_HPP
#define STEP3_MATCHER_HPP

#include "FSA.hpp"

class Matcher {
public:
    FSA &fsa;

    explicit Matcher(FSA &fsa) : fsa(fsa) {}

    bool find(const char *str, std::size_t &n) {
        std::string s = str;
        return this->find(s, n);
    }

    bool find(std::string &str, std::size_t &n) {
        n = 0;
        State *s = this->fsa.initialState;
        for (int idx = 0; str[idx]; idx++) {
            if (s->transition == str[idx]) {
                if (s->finalState) {
                    n++;
                    s = this->fsa.initialState;
                } else {
                    State *ns = this->fsa.getNext(s);
                    if (ns == NULL) {
                        n++;
                        s = this->fsa.initialState;
                    } else {
                        s = ns;
                    }
                }
            }
        }
        return n > 0;
    }
};


#endif //STEP3_MATCHER_HPP
