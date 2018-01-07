//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_BIND_HPP
#define BIND_BIND_HPP

#include "Generator.hpp"
#include "Storage.hpp"
#include "TypeTraits.hpp"

template<typename ReturnType, typename Callable, typename List>
class Caller {
private:
    Callable _callable;
    List _list;

public:
    Caller(const Callable &callable, const List &list) : _callable(callable), _list(list) {}

    ReturnType operator()() {
        return this->_list(TypeTraits<ReturnType>(), this->_callable, TypeList0());
    }

    template<typename T1>
    ReturnType operator()(T1 t1) {
        TypeList1<T1> list(t1);
        return this->_list(TypeTraits<ReturnType>(), this->_callable, list);
    }

    template<typename T1, typename T2>
    ReturnType operator()(T1 t1, T2 t2) {
        TypeList2<T1, T2> list(t1, t2);
        return this->_list(TypeTraits<ReturnType>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3>
    ReturnType operator()(T1 t1, T2 t2, T3 t3) {
        TypeList3<T1, T2, T3> list(t1, t2, t3);
        return this->_list(TypeTraits<ReturnType>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3, typename T4>
    ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4) {
        TypeList4<T1, T2, T3, T4> list(t1, t2, t3, t4);
        return this->_list(TypeTraits<ReturnType>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) {
        TypeList5<T1, T2, T3, T4, T5> list(t1, t2, t3, t4, t5);
        return this->_list(TypeTraits<ReturnType>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) {
        TypeList6<T1, T2, T3, T4, T5, T6> list(t1, t2, t3, t4, t5, t6);
        return this->_list(TypeTraits<ReturnType>(), this->_callable, list);
    }
};

template<typename Callable, typename List>
class Caller<void> {
private:
    Callable _callable;
    List _list;

public:
    Caller(const Callable &callable, const List &list) : _callable(callable), _list(list) {}

    void operator()() {
        this->_list(TypeTraits<void>(), this->_callable, TypeList0());
    }

    template<typename T1>
    void operator()(T1 t1) {
        TypeList1<T1> list(t1);
        this->_list(TypeTraits<void>(), this->_callable, list);
    }

    template<typename T1, typename T2>
    void operator()(T1 t1, T2 t2) {
        TypeList2<T1, T2> list(t1, t2);
        this->_list(TypeTraits<void>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3>
    void operator()(T1 t1, T2 t2, T3 t3) {
        TypeList3<T1, T2, T3> list(t1, t2, t3);
        this->_list(TypeTraits<void>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3, typename T4>
    void operator()(T1 t1, T2 t2, T3 t3, T4 t4) {
        TypeList4<T1, T2, T3, T4> list(t1, t2, t3, t4);
        this->_list(TypeTraits<void>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) {
        TypeList5<T1, T2, T3, T4, T5> list(t1, t2, t3, t4, t5);
        this->_list(TypeTraits<void>(), this->_callable, list);
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) {
        TypeList6<T1, T2, T3, T4, T5, T6> list(t1, t2, t3, t4, t5, t6);
        this->_list(TypeTraits<void>(), this->_callable, list);
    }
};

template<typename ReturnType>
Caller<ReturnType, ReturnType (*)(), TypeList0> bind(ReturnType (*callable)()) {
    return Caller<ReturnType, ReturnType (*)(), TypeList0>(callable, TypeList0());
}

#define Macro_Bind_Function_Generator(N) \
template<typename ReturnType, Macro_Repeat_1(N, typename ArgType)> \
Caller<ReturnType, ReturnType (*)(Macro_Repeat_1(N, ArgType)), TypeList##N<Macro_Repeat_1(N, ArgType)> > bind(ReturnType (*callable)(Macro_Repeat_1(N, ArgType)), Macro_Repeat_2(N, ArgType, arg)) { \
    return Caller<ReturnType, ReturnType (*)(Macro_Repeat_1(N, ArgType)), TypeList##N<Macro_Repeat_1(N, ArgType)> >(callable, TypeList##N<Macro_Repeat_1(N, ArgType)>(Macro_Repeat_1(N, arg))); \
}

Macro_Bind_Function_Generator(1)
Macro_Bind_Function_Generator(2)
Macro_Bind_Function_Generator(3)
Macro_Bind_Function_Generator(4)
Macro_Bind_Function_Generator(5)
Macro_Bind_Function_Generator(6)

#undef Macro_Bind_Function_Generator

#define Macro_Bind_Callable_Generator(N) \
template<typename ReturnType, typename Callable, Macro_Repeat_1(N, typename ArgType)> \
Caller<ReturnType, Callable, TypeList##N<Macro_Repeat_1(N, ArgType)> > bind(Callable &callable, Macro_Repeat_2(N, ArgType, arg)) { \
    return Caller<ReturnType, Callable, TypeList##N<Macro_Repeat_1(N, ArgType)> >(callable, TypeList##N<Macro_Repeat_1(N, ArgType)>(Macro_Repeat_1(N, arg))); \
}

template<typename ReturnType, typename Callable>
Caller<ReturnType, Callable, TypeList0> bind(Callable &callable) {
    return Caller<ReturnType, Callable, TypeList0>(callable, TypeList0());
}

Macro_Bind_Callable_Generator(1)
Macro_Bind_Callable_Generator(2)
Macro_Bind_Callable_Generator(3)
Macro_Bind_Callable_Generator(4)
Macro_Bind_Callable_Generator(5)
Macro_Bind_Callable_Generator(6)

#undef Macro_Bind_Callable_Generator

#endif //BIND_BIND_HPP
