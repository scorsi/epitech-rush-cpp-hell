//
// Created by sylva on 05/01/2018.
//

#ifndef STEP1_FUNCTIONSIGNATURE_HPP
#define STEP1_FUNCTIONSIGNATURE_HPP

#include <functional>

template<typename>
class Function;

template<typename RetType>
class Function<RetType()> {
private:

    RetType (*fun)();

public:
    Function(RetType (*fun)()) {
        this->fun = fun;
    }

    virtual Function<RetType()> &operator=(RetType (*fun)()) {
        this->fun = fun;
        return *this;
    }

    virtual RetType operator()() {
        return this->fun();
    }
};

template<typename RetType, typename ArgType1>
class Function<RetType(ArgType1)> {
private:

    RetType (*fun)(ArgType1);

public:
    Function(RetType (*fun)(ArgType1)) {
        this->fun = fun;
    }

    virtual Function<RetType(ArgType1)> &operator=(RetType (*fun)(ArgType1)) {
        this->fun = fun;
        return *this;
    }

    virtual RetType operator()(ArgType1 arg1) {
        return this->fun(arg1);
    }
};

template<typename RetType, typename ArgType1, typename ArgType2>
class Function<RetType(ArgType1, ArgType2)> {
private:

    RetType (*fun)(ArgType1, ArgType2);

public:
    Function(RetType (*fun)(ArgType1, ArgType2)) {
        this->fun = fun;
    }

    virtual Function<RetType(ArgType1, ArgType2)> &operator=(RetType (*fun)(ArgType1, ArgType2)) {
        this->fun = fun;
        return *this;
    }

    virtual RetType operator()(ArgType1 arg1, ArgType2 arg2) {
        return this->fun(arg1, arg2);
    }
};

template<typename RetType, typename ArgType1, typename ArgType2, typename ArgType3>
class Function<RetType(ArgType1, ArgType2, ArgType3)> {
private:

    RetType (*fun)(ArgType1, ArgType2, ArgType3);

public:
    Function(RetType (*fun)(ArgType1, ArgType2, ArgType3)) {
        this->fun = fun;
    }

    virtual Function<RetType(ArgType1, ArgType2, ArgType3)> &operator=(RetType (*fun)(ArgType1, ArgType2, ArgType3)) {
        this->fun = fun;
        return *this;
    }

    virtual RetType operator()(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3) {
        return this->fun(arg1, arg2, arg3);
    }
};

template<typename RetType, typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
class Function<RetType(ArgType1, ArgType2, ArgType3, ArgType4)> {
private:

    RetType (*fun)(ArgType1, ArgType2, ArgType3, ArgType4);

public:
    Function(RetType (*fun)(ArgType1, ArgType2, ArgType3, ArgType4)) {
        this->fun = fun;
    }

    virtual Function<RetType(ArgType1, ArgType2, ArgType3, ArgType4)> &
    operator=(RetType (*fun)(ArgType1, ArgType2, ArgType3, ArgType4)) {
        this->fun = fun;
        return *this;
    }

    virtual RetType operator()(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4) {
        return this->fun(arg1, arg2, arg3, arg4);
    }
};

/*
template<typename RetType, typename ArgType1>
struct FunctionSignature<RetType(ArgType1)> {
    typedef RetType (*type)(ArgType1);
};

template<typename RetType, typename ArgType1, typename ArgType2>
struct FunctionSignature<RetType(ArgType1, ArgType2)> {
    typedef RetType (*type)(ArgType1, ArgType2);
};

template<typename RetType, typename ArgType1, typename ArgType2, typename ArgType3>
struct FunctionSignature<RetType(ArgType1, ArgType2, ArgType3)> {
    typedef RetType (*type)(ArgType1, ArgType2, ArgType3);
};

template<typename RetType, typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
struct FunctionSignature<RetType(ArgType1, ArgType2, ArgType3, ArgType4)> {
    typedef RetType (*type)(ArgType1, ArgType2, ArgType3, ArgType4);
};
*/
#endif //STEP1_FUNCTIONSIGNATURE_HPP
