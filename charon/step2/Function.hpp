//
// Created by sylva on 05/01/2018.
//

#ifndef STEP2_FUNCTION_HPP
#define STEP2_FUNCTION_HPP

#include <functional>

template<typename>
class Function;

template<typename RetType>
class Function<RetType()> {
private:

    class Wrapper {
    public:
        virtual ~Wrapper() = default;

        virtual RetType call() = 0;
    };

    class WrapperFun : public Wrapper {
    public:
        RetType (*fun)();

        explicit WrapperFun(RetType (*fun)()) : fun(fun) {}

        virtual ~WrapperFun() = default;

        virtual RetType call() {
            return this->fun();
        }
    };

    template <typename T>
    class WrapperCallable : public Wrapper {
    public:
        T callable;
        explicit WrapperCallable(T callable) : callable(callable) {}

        virtual ~WrapperCallable() = default;

        virtual RetType call() {
            return this->callable();
        }
    };

    Wrapper *wrapper;

public:
    Function(RetType (*fun)()) {
        this->wrapper = new WrapperFun(fun);
    }

    template <typename T>
    Function(T callable) {
        this->wrapper = new WrapperCallable<T>(callable);
    }

    ~Function() {
        delete this->wrapper;
    }

    RetType operator()() {
        return this->wrapper->call();
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

#endif //STEP2_FUNCTION_HPP
