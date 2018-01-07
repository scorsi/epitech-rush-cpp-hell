#include <iostream>
#include "Bind.hpp"
#include "Storage.hpp"
#include "TypeTraits.hpp"

template<typename A, typename B, typename C>
int f(A a, B b, C c)
{

};

template<typename A, typename B, typename C>
void do_bind() {
  A a;
  B b;
  C c;
  bind(&f, a, b, c);
};

int main()
{
  Storage3<int, char, const char *> s(1, 'c', "ta mere");
  Storage6<int, int, int, int, int, int> a(1, 2, 3, 4, 5, 6);
  std::cout << s._t1 << s._t2 << s._t3 << std::endl;
  std::cout << a._t1 << a._t2 << a._t3 << a._t4 << a._t5 << a._t6 << std::endl;

  do_bind();
  return 0;
}