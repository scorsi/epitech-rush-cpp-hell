//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_BIND_HPP
#define BIND_BIND_HPP

#include "Storage.hpp"

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

class TypeList0 : private Storage0 {

};

template<typename T1>
class TypeList1 : private Storage1<T1> {

};

template<typename T1, typename T2>
class TypeList2 : private Storage2<T1, T2> {

};

template<typename T1, typename T2, typename T3>
class TypeList3 : private Storage3<T1, T2, T3> {

};

template<typename T1, typename T2, typename T3, typename T4>
class TypeList4 : private Storage4<T1, T2, T3, T4> {

};

template<typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5 : private Storage5<T1, T2, T3, T4, T5> {

};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class TypeList6 : private Storage6<T1, T2, T3, T4, T5, T6> {

};

#endif //BIND_BIND_HPP
