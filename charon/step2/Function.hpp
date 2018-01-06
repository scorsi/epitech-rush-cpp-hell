//
// Created by sylva on 05/01/2018.
//

#ifndef STEP2_FUNCTION_HPP
#define STEP2_FUNCTION_HPP

template<typename>
class Function;

#define Template_Repeat_WS_Array_0(T)
#define Template_Repeat_WS_Array_1(T) Template_Repeat_WS_Array_0(T), T##1
#define Template_Repeat_WS_Array_2(T) Template_Repeat_WS_Array_1(T), T##2
#define Template_Repeat_WS_Array_3(T) Template_Repeat_WS_Array_2(T), T##3
#define Template_Repeat_WS_Array_4(T) Template_Repeat_WS_Array_3(T), T##4
#define Template_Repeat_WS(N, T) Template_Repeat_WS_Array_##N(T)

#define Template_Repeat_Array_0(T)
#define Template_Repeat_Array_1(T) T##1
#define Template_Repeat_Array_2(T) Template_Repeat_Array_1(T), T##2
#define Template_Repeat_Array_3(T) Template_Repeat_Array_2(T), T##3
#define Template_Repeat_Array_4(T) Template_Repeat_Array_3(T), T##4
#define Template_Repeat(N, T) Template_Repeat_Array_##N(T)

#define Template_Arg_Repeat_Array_0(T, VAR)
#define Template_Arg_Repeat_Array_1(T, VAR) T##1 VAR##1
#define Template_Arg_Repeat_Array_2(T, VAR) Template_Arg_Repeat_Array_1(T, VAR), T##2 VAR##2
#define Template_Arg_Repeat_Array_3(T, VAR) Template_Arg_Repeat_Array_2(T, VAR), T##3 VAR##3
#define Template_Arg_Repeat_Array_4(T, VAR) Template_Arg_Repeat_Array_3(T, VAR), T##4 VAR##4
#define Template_Arg_Repeat(N, T, VAR) Template_Arg_Repeat_Array_##N(T, VAR)

#define Function_Declaration_Template(N_ARG) \
template<typename RetType Template_Repeat_WS(N_ARG, typename ArgType)> \
class Function<RetType(Template_Repeat(N_ARG, ArgType))> { \
private: \
    class Wrapper { \
    public: \
        virtual RetType call(Template_Arg_Repeat(N_ARG, ArgType, arg)) = 0; \
    }; \
    class WrapperFun : public Wrapper { \
    private: \
        RetType (*fun)(Template_Repeat(N_ARG, ArgType)); \
    public: \
        explicit WrapperFun(RetType (*fun)(Template_Repeat(N_ARG, ArgType))) : fun(fun) {} \
        virtual RetType call(Template_Arg_Repeat(N_ARG, ArgType, arg)) { \
            return this->fun(Template_Repeat(N_ARG, arg)); \
        } \
    }; \
    template <typename T> \
    class WrapperCallable : public Wrapper { \
    public: \
        T callable; \
        explicit WrapperCallable(T callable) : callable(callable) {} \
        virtual ~WrapperCallable() {} \
        virtual RetType call(Template_Arg_Repeat(N_ARG, ArgType, arg)) { \
            return this->callable(Template_Repeat(N_ARG, arg)); \
        } \
    }; \
     \
    Wrapper *wrapper; \
     \
public: \
    Function(RetType (*fun)(Template_Repeat(N_ARG, ArgType))) { \
        this->wrapper = new WrapperFun(fun); \
    } \
     \
    template <typename T> \
    Function(T callable) { \
        this->wrapper = new WrapperCallable<T>(callable); \
    } \
     \
    ~Function() { \
        delete this->wrapper; \
    } \
     \
    RetType operator()(Template_Arg_Repeat(N_ARG, ArgType, arg)) { \
        return this->wrapper->call(Template_Repeat(N_ARG, arg)); \
    } \
};

Function_Declaration_Template(0)
Function_Declaration_Template(1)
Function_Declaration_Template(2)
Function_Declaration_Template(3)
Function_Declaration_Template(4)

#endif //STEP2_FUNCTION_HPP
