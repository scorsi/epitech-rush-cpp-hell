//
// Created by sylva on 05/01/2018.
//

#ifndef STEP1_FUNCTIONSIGNATURE_HPP
#define STEP1_FUNCTIONSIGNATURE_HPP

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

template<typename T>
struct FunctionSignature;

#define FunctionSignature_Declaration_Template(N_ARG) \
template<typename RetType Template_Repeat_WS(N_ARG, typename ArgType)> \
struct FunctionSignature<RetType(Template_Repeat(N_ARG, ArgType))> { \
    typedef RetType (*type)(Template_Repeat(N_ARG, ArgType)); \
};

FunctionSignature_Declaration_Template(0)
FunctionSignature_Declaration_Template(1)
FunctionSignature_Declaration_Template(2)
FunctionSignature_Declaration_Template(3)
FunctionSignature_Declaration_Template(4)

#endif //STEP1_FUNCTIONSIGNATURE_HPP
