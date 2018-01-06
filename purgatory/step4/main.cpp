#include <iostream>
#include <cstdio>
#include "State.hpp"
#include "FSA.hpp"
#include "Matcher.hpp"

int main()
{
  FSA fsa;
  fsa.addState(State::factory("root", -1));
  fsa.setInitialState(fsa["root"]);
  fsa.addClosure(fsa["root"], fsa["root"]);

  fsa.addState(State::factory("end", -1, true));

  fsa.addState(State::factory("A1", 'e'));
  fsa.addClosure(fsa["root"], fsa["A1"]);
  fsa.addState(State::factory("A2", 'v'));
  fsa.addClosure(fsa["A1"], fsa["A2"]);
  fsa.addState(State::factory("A3", 'i'));
  fsa.addClosure(fsa["A2"], fsa["A3"]);
  fsa.addState(State::factory("A4", 'l'));
  fsa.addClosure(fsa["A3"], fsa["A4"]);

  fsa.addClosure(fsa["A4"], fsa["end"]);

  fsa.addState(State::factory("B1", 'a'));
  fsa.addClosure(fsa["root"], fsa["B1"]);
  fsa.addState(State::factory("B2", 't'));
  fsa.addClosure(fsa["B1"], fsa["B2"]);

  fsa.addClosure(fsa["B2"], fsa["end"]);

  fsa.addState(State::factory("C1", 't'));
  fsa.addClosure(fsa["root"], fsa["C1"]);
  fsa.addState(State::factory("C2", 'o'));
  fsa.addClosure(fsa["C1"], fsa["C2"]);

  fsa.addClosure(fsa["C2"], fsa["end"]);

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
  ret = m.find("evilatevil", n);
  printf("%s => %s : %d\n", "evilatevil", ret ? "true" : "false", n);
  ret = m.find("evitol", n);
  printf("%s => %s : %d\n", "evitol", ret ? "true" : "false", n);

  return 0;
}
