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
        typedef std::vector<State *>::iterator _It;
        std::vector<State *> closure = this->fsa.closure();
        std::string res;
        for (int idx = 0; str[idx]; idx++) {
            bool found = false;
            for (_It it = closure.begin(); it != closure.end(); it++) {
                printf("Compare %c with %c\n", str[idx], (*it)->transition);
                if (str[idx] == (*it)->transition) {
                    s = *it;
                    res.push_back(str[idx]);
                    found = true;
                    break;
                }
            }
            if (!found && s != this->fsa.initialState) {
                res.clear();
                s = this->fsa.initialState;
                idx--;
            }
            closure = this->fsa.next(s);
            if (closure.empty() || (closure.size() == 1 && closure[0]->finalState)) {
                printf("Found a word: %s\n", res.c_str());
                res.clear();
                n++;
                s = this->fsa.initialState;
                closure = this->fsa.closure();
            }
        }
        return n > 0;
    }
};


#endif //STEP3_MATCHER_HPP
