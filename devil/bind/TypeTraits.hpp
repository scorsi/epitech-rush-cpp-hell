//
// Created by god on 1/7/18.
//

#ifndef BIND_TYPETRAITS_HPP
#define BIND_TYPETRAITS_HPP

template<typename T>
class Value {
private:
  T t;

public:
  typedef T type;

  Value(T &t) : t(t) {}

  T &get() { return this->t; }

  T const &get() const { return  this->t; }
};

/*
template<class T>
class GetType
{
public:
  typedef Value<T> Type;
};
 */

template<class T>
struct TypeTraits {};

#endif //BIND_TYPETRAITS_HPP
