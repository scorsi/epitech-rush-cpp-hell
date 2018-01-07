//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_STORAGE_HPP
#define BIND_STORAGE_HPP

#include "Generator.hpp"
#include "TypeTraits.hpp"

struct Storage0 {
};

template<typename T1>
struct Storage1 : public Storage0 {
    Storage1(const T1 &t1) : Storage0(), _t1(t1) {}
    T1 _t1;
};

#define Macro_Storage_Generator(N, NM) \
template<Macro_Repeat_1(N, typename T)> \
struct Storage##N : public Storage##NM<Macro_Repeat_1(NM, T)> { \
    Storage##N(Macro_Repeat_2(N, const T, &t)) : Storage##NM<Macro_Repeat_1(NM, T)>(Macro_Repeat_1(NM, t)), _t##N(t##N) {} \
    T##N _t##N; \
};

Macro_Storage_Generator(2, 1)
Macro_Storage_Generator(3, 2)
Macro_Storage_Generator(4, 3)
Macro_Storage_Generator(5, 4)
Macro_Storage_Generator(6, 5)

class TypeList0 : private Storage0 {
public:
    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List&) {
        return callable();
    }
};

template<typename T1>
class TypeList1 : private Storage1<Value<T1> > {
public:
    TypeList1(T1 &a) :
            Storage1<Value<T1> >(Value<T1>(a)) {}

    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List &list) {
        return callable(list[Storage1::_t1]);
    }
};

template<typename T1, typename T2>
class TypeList2 : private Storage2<Value<T1>, Value<T2> > {
public:
    TypeList2(T1 &a, T2 &b) :
            Storage2<Value<T1>, Value<T2> >(Value<T1>(a), Value<T2>(b)) {}

    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List &list) {
        return callable(list[Storage2::_t1], list[Storage2::_t2]);
    }
};

template<typename T1, typename T2, typename T3>
class TypeList3 : private Storage3<Value<T1>, Value<T2>, Value<T3> > {
public:
    TypeList3(T1 &a, T2 &b, T3 &c) :
            Storage3<Value<T1>, Value<T2>, Value<T3> >(Value<T1>(a), Value<T2>(b), Value<T3>(c)) {}


    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List &list) {
        return callable(list[Storage3::_t1], list[Storage3::_t2], list[Storage3::_t3]);
    }
};

template<typename T1, typename T2, typename T3, typename T4>
class TypeList4 : private Storage4<Value<T1>, Value<T2>, Value<T3>, Value<T4> > {
public:
    TypeList4(T1 &a, T2 &b, T3 &c, T4 &d) :
            Storage4<Value<T1>, Value<T2>, Value<T3>, Value<T4> >(Value<T1>(a), Value<T2>(b), Value<T3>(c), Value<T4>(d)) {}


    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List &list) {
        return callable(list[Storage4::_t1], list[Storage4::_t2], list[Storage4::_t3], list[Storage4::_t4]);
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5 : private Storage5<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5> > {
public:
    TypeList5(T1 &a, T2 &b, T3 &c, T4 &d, T5 &e) :
            Storage5<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5> >(Value<T1>(a), Value<T2>(b), Value<T3>(c), Value<T4>(d), Value<T5>(e)) {}


    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List &list) {
        return callable(list[Storage5::_t1], list[Storage5::_t2], list[Storage5::_t3], list[Storage5::_t4], list[Storage5::_t5]);
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class TypeList6 : private Storage6<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5>, Value<T6> > {
public:
    TypeList6(T1 &a, T2 &b, T3 &c, T4 &d, T5 &e, T6 &f) :
            Storage6<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5>, Value<T6> >(Value<T1>(a), Value<T2>(b), Value<T3>(c), Value<T4>(d), Value<T5>(e), Value<T6>(f)) {}

    template<typename T>
    T &operator[](Value<T> &t) {
        return t.get();
    }

    template<typename T>
    const T &operator[](Value<T> &t) const {
        return t.get();
    }

    template<typename ReturnType, typename Callable, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Callable callable, List &list) {
        return callable(list[Storage6::_t1], list[Storage6::_t2], list[Storage6::_t3], list[Storage6::_t4], list[Storage6::_t5], list[Storage6::_t6]);
    }
};

#endif //BIND_STORAGE_HPP
