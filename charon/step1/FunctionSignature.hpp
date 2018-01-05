//
// Created by sylva on 05/01/2018.
//

#ifndef STEP1_FUNCTIONSIGNATURE_HPP
#define STEP1_FUNCTIONSIGNATURE_HPP

template<typename T>
struct FunctionSignature {
};

template<typename RetType>
struct FunctionSignature<RetType()> {
    typedef RetType (*type)();
};

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

#endif //STEP1_FUNCTIONSIGNATURE_HPP
