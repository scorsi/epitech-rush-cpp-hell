//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_STORAGE_HPP
#define BIND_STORAGE_HPP

struct Storage0 {
};

template<typename T1>
struct Storage1 : public Storage0 {
    Storage1(const T1 &t1) : Storage0(), _t1(t1) {}
    T1 _t1;
};

#define Macro_Storage_Repeat_Type_Array_1(T) T##1
#define Macro_Storage_Repeat_Type_Array_2(T) Macro_Storage_Repeat_Type_Array_1(T), T##2
#define Macro_Storage_Repeat_Type_Array_3(T) Macro_Storage_Repeat_Type_Array_2(T), T##3
#define Macro_Storage_Repeat_Type_Array_4(T) Macro_Storage_Repeat_Type_Array_3(T), T##4
#define Macro_Storage_Repeat_Type_Array_5(T) Macro_Storage_Repeat_Type_Array_4(T), T##5
#define Macro_Storage_Repeat_Type_Array_6(T) Macro_Storage_Repeat_Type_Array_5(T), T##6
#define Macro_Storage_Repeat_Type(N, T) Macro_Storage_Repeat_Type_Array_##N(T)

#define Macro_Storage_Repeat_Arg_Array_1(T1, T2) T1##1 T2##1
#define Macro_Storage_Repeat_Arg_Array_2(T1, T2) Macro_Storage_Repeat_Arg_Array_1(T1, T2), T1##2 T2##2
#define Macro_Storage_Repeat_Arg_Array_3(T1, T2) Macro_Storage_Repeat_Arg_Array_2(T1, T2), T1##3 T2##3
#define Macro_Storage_Repeat_Arg_Array_4(T1, T2) Macro_Storage_Repeat_Arg_Array_3(T1, T2), T1##4 T2##4
#define Macro_Storage_Repeat_Arg_Array_5(T1, T2) Macro_Storage_Repeat_Arg_Array_4(T1, T2), T1##5 T2##5
#define Macro_Storage_Repeat_Arg_Array_6(T1, T2) Macro_Storage_Repeat_Arg_Array_5(T1, T2), T1##6 T2##6
#define Macro_Storage_Repeat_Arg(N, T1, T2) Macro_Storage_Repeat_Arg_Array_##N(T1, T2)

#define Macro_Storage_Generator(N, NM) \
template<Macro_Storage_Repeat_Type(N, typename T)> \
struct Storage##N : public Storage##NM<Macro_Storage_Repeat_Type(NM, T)> { \
    Storage##N(Macro_Storage_Repeat_Arg(N, const T, &t)) : Storage##NM<Macro_Storage_Repeat_Type(NM, T)>(Macro_Storage_Repeat_Type(NM, t)), _t##N(t##N) {} \
    T##N _t##N; \
};

Macro_Storage_Generator(2, 1)
Macro_Storage_Generator(3, 2)
Macro_Storage_Generator(4, 3)
Macro_Storage_Generator(5, 4)
Macro_Storage_Generator(6, 5)

#endif //BIND_STORAGE_HPP
