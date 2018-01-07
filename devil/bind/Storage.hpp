//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_STORAGE_HPP
#define BIND_STORAGE_HPP

#include "TypeTraits.hpp"

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


class TypeList0 : private Storage0 {

};

template<typename T1>
class TypeList1 : private Storage1<Value<T1>> {
public:
  TypeList1(T1 &a) : Storage1(Value(a)) {}
};

template<typename T1, typename T2>
class TypeList2 : private Storage2<Value<T1>, Value<T2>> {
public:
  TypeList2(T1 &a, T2 &b) : Storage2(Value(a), Value(b)) {}
};

template<typename T1, typename T2, typename T3>
class TypeList3 : private Storage3<Value<T1>, Value<T2>, Value<T3>> {
public:
  TypeList3(T1 &a, T2 &b, T3 &c) : Storage3(Value(a), Value(b), Value(c)) {}
};

template<typename T1, typename T2, typename T3, typename T4>
class TypeList4 : private Storage4<Value<T1>, Value<T2>, Value<T3>, Value<T4>> {
public:
  TypeList4(T1 &a, T2 &b, T3 &c, T4 &d) : Storage4(Value(a), Value(b), Value(c), Value(d)) {}
};

template<typename T1, typename T2, typename T3, typename T4, typename T5>
class TypeList5 : private Storage5<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5>> {
public:
  TypeList5(T1 &a, T2 &b, T3 &c, T4 &d, T5 &e) : Storage5(Value(a), Value(b), Value(c), Value(d), Value(e)) {}
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class TypeList6 : private Storage6<Value<T1>, Value<T2>, Value<T3>, Value<T4>, Value<T5>, Value<T6>> {
public:
  TypeList6(T1 &a, T2 &b, T3 &c, T4 &d, T5 &e, T6 &f) : Storage6(Value(a), Value(b), Value(c), Value(d), Value(e), Value(f)) {}
};

#endif //BIND_STORAGE_HPP
