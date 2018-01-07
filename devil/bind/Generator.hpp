//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_GENERATOR_HPP
#define BIND_GENERATOR_HPP

#define Macro_Repeat_1_Array_1(T) T##1
#define Macro_Repeat_1_Array_2(T) Macro_Repeat_1_Array_1(T), T##2
#define Macro_Repeat_1_Array_3(T) Macro_Repeat_1_Array_2(T), T##3
#define Macro_Repeat_1_Array_4(T) Macro_Repeat_1_Array_3(T), T##4
#define Macro_Repeat_1_Array_5(T) Macro_Repeat_1_Array_4(T), T##5
#define Macro_Repeat_1_Array_6(T) Macro_Repeat_1_Array_5(T), T##6
#define Macro_Repeat_1(N, T) Macro_Repeat_1_Array_##N(T)

#define Macro_Repeat_2_Array_1(T1, T2) T1##1 T2##1
#define Macro_Repeat_2_Array_2(T1, T2) Macro_Repeat_2_Array_1(T1, T2), T1##2 T2##2
#define Macro_Repeat_2_Array_3(T1, T2) Macro_Repeat_2_Array_2(T1, T2), T1##3 T2##3
#define Macro_Repeat_2_Array_4(T1, T2) Macro_Repeat_2_Array_3(T1, T2), T1##4 T2##4
#define Macro_Repeat_2_Array_5(T1, T2) Macro_Repeat_2_Array_4(T1, T2), T1##5 T2##5
#define Macro_Repeat_2_Array_6(T1, T2) Macro_Repeat_2_Array_5(T1, T2), T1##6 T2##6
#define Macro_Repeat_2(N, T1, T2) Macro_Repeat_2_Array_##N(T1, T2)

#endif //BIND_GENERATOR_HPP
