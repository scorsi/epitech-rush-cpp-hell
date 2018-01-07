//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_BIND_HPP
#define BIND_BIND_HPP

#include "Storage.hpp"
#include "TypeTraits.hpp"

template<typename ReturnType>
ReturnType bind() {

}

template<typename ReturnType, typename Callable, typename List>
class Caller {
private:
    Callable _callable;
    List _list;

public:
    Caller(const Callable &callable, const List &list) : _callable(callable), _list(list) {}

    ReturnType operator()() {

    }
};

#endif //BIND_BIND_HPP
