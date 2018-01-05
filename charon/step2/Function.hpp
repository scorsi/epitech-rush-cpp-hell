//
// Created by sylva on 05/01/2018.
//

#ifndef STEP1_FUNCTIONSIGNATURE_HPP
#define STEP1_FUNCTIONSIGNATURE_HPP

#include <functional>

template<typename>
class Function {
};

template<typename RetType, typename... Args>
class Function<RetType(Args...)> {
private:

    RetType (*fun)(Args...);

public:
    Function(RetType (*fun)(Args...)) {
        this->fun = fun;
    }

    virtual Function<RetType(Args...)> &operator=(RetType (*fun)(Args...)) {
        this->fun = fun;
        return *this;
    }

    virtual RetType operator()(Args... args) {
        return this->fun(args...);
    }
};

template<typename RetType, typename... Args>
class Function<RetType(Args...)> {
private:


public:
    Function(const std::bind<RetType, Args...> &func) {

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
