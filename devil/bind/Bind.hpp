//
// Created by sylva on 07/01/2018.
//

#ifndef BIND_BIND_HPP
#define BIND_BIND_HPP

class Storage0 {
};

template<typename T1>
class Storage1 : Storage0 {
protected:
    T1 _t1;
public:
    Storage1(const T1 &t1) : Storage0(), _t1(t1) {}
};

template<typename T1, typename T2>
class Storage2 : Storage1<T1> {
protected:
    T2 _t2;
public:
    Storage2(const T1 &t1, const T2 &t2) : Storage1<T1>(t1), _t2(t2) {}
};

#endif //BIND_BIND_HPP
