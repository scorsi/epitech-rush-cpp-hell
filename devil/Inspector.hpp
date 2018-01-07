//
// Created by sylva on 06/01/2018.
//

#ifndef DEVIL_INPECT_HPP
#define DEVIL_INPECT_HPP

#include <iostream>
#include <cstddef>

template<typename Stream, typename Object>
struct is_printable {

    typedef char yes[1];
    typedef char no[2];

    template<typename T>
    static T &nullRef();

    template<size_t S = 0>
    class _IsPrintable {
    };

    template<typename T, size_t U = sizeof(*((Stream *) (NULL)) << *((Object *) (NULL)))>
    static yes &isPrintable(T *, _IsPrintable<U> * = NULL);

    template<typename>
    static no &isPrintable(...);

    static const bool value = sizeof(isPrintable<Object>(NULL)) == sizeof(yes);

};

template<bool Cond, typename T = void *>
struct enable_if {
    typedef T type;
};

template<typename T>
struct enable_if<false, T> {
};

template<typename Stream>
struct Printer {
    template<typename Object, typename enable_if<is_printable<Stream, Object>::value>::type = 0>
    static void print(Stream &stream, Object &object) {
        stream << object;
    }

    template<typename Object, typename enable_if<!(is_printable<Stream, Object>::value)>::type = 0>
    static void print(Stream &stream, Object &object) {
        stream << typeid(object).name();
    }
};

template<typename Stream, typename Object>
void inspect(Stream &stream, const Object &o) {
    Printer<Stream>::print(stream, o);
}

#endif //DEVIL_INPECT_HPP
