#include <iostream>
#include <cstdio>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"

int main()
{
  FSA fsa;
  fsa.addState(State::factory("S0", 'e'));
  fsa.addState(State::factory("S1", 'v'));
  fsa.addState(State::factory("S2", 'i'));
  fsa.addState(State::factory("S3", 'l', true));

  Matcher m(fsa);
  std::size_t n = 0;
  bool ret;
  ret = m.find("evilevil", n);
  printf("%s => %s : %d\n", "evilevil", ret ? "true" : "false", n);
  ret = m.find("evitoto", n);
  printf("%s => %s : %d\n", "evitoto", ret ? "true" : "false", n);
  ret = m.find("evila", n);
  printf("%s => %s : %d\n", "evila", ret ? "true" : "false", n);
  ret = m.find("evilevilevilevil", n);
  printf("%s => %s : %d\n", "evilevilevilevil", ret ? "true" : "false", n);
  ret = m.find("eeeeeeeeevil", n);
  printf("%s => %s : %d\n", "eeeeeeeeevil", ret ? "true" : "false", n);
  ret = m.find("valaevial", n);
  printf("%s => %s : %d\n", "valaevial", ret ? "true" : "false", n);
  return 0;
}
