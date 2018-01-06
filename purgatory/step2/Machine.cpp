//
// Created by sylva on 06/01/2018.
//

#include <cstdio>
#include "Machine.hpp"

/**
 * STATE    e       v       i       l       *
 *  S0      S1      ERROR   ERROR   ERROR   ERROR
 *  S1      ERROR   S2      ERROR   ERROR   ERROR
 *  S2      ERROR   ERROR   S3      ERROR   ERROR
 *  S3      ERROR   ERROR   ERROR   S4      ERROR
 *  S4      ERROR   ERROR   ERROR   ERROR   ERROR
 */

/**
 * STATE    e       v       i       l       *
 *  S0      MA      ERROR   ERROR   ERROR   ERROR
 *  S1      ERROR   MA      ERROR   ERROR   ERROR
 *  S2      ERROR   ERROR   MA      ERROR   ERROR
 *  S3      ERROR   ERROR   ERROR   MA      ERROR
 *  S4      ERROR   ERROR   ERROR   ERROR   HR
 */

const State ls0[] = {S1, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR};
const State ls1[] = {S1, S2, STATE_ERROR, STATE_ERROR, STATE_ERROR};
const State ls2[] = {STATE_ERROR, STATE_ERROR, S3, STATE_ERROR, STATE_ERROR};
const State ls3[] = {STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR};

const std::pair<State, std::vector<State> > statep[] = {
  my_make_pair<State, std::vector<State> >(S0, my_make_vector<State>(ls0)),
  my_make_pair<State, std::vector<State> >(S1, my_make_vector<State>(ls1)),
  my_make_pair<State, std::vector<State> >(S2, my_make_vector<State>(ls2)),
  my_make_pair<State, std::vector<State> >(S3, my_make_vector<State>(ls3))
};

const Action la0[] = {MA, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR};
const Action la1[] = {MA, MA, ACTION_ERROR, ACTION_ERROR, ACTION_ERROR};
const Action la2[] = {ACTION_ERROR, ACTION_ERROR, MA, ACTION_ERROR, ACTION_ERROR};
const Action la3[] = {ACTION_ERROR, ACTION_ERROR, ACTION_ERROR, HR, ACTION_ERROR};

const std::pair<State, std::vector<Action> > actionp[] = {
  my_make_pair<State, std::vector<Action> >(S0, my_make_vector<Action>(la0)),
  my_make_pair<State, std::vector<Action> >(S1, my_make_vector<Action>(la1)),
  my_make_pair<State, std::vector<Action> >(S2, my_make_vector<Action>(la2)),
  my_make_pair<State, std::vector<Action> >(S3, my_make_vector<Action>(la3))
};

std::map<State, std::vector<State> > stateTable = my_make_map<State, std::vector<State> >(statep);

std::map<State, std::vector<Action> > actionTable = my_make_map<State, std::vector<Action> >(actionp);
const char *state_machine_str = "evil";

bool state_machine(const char *str)
{
  State state = S0;
  bool isError = true;
  for (int idx = 0; str[idx]; ++idx)
  {
    int o_idx;
    for (o_idx = 0; state_machine_str[o_idx] &&
		    state_machine_str[o_idx] != str[idx]; ++o_idx);
    Action action = actionTable[state][o_idx];
    switch (action)
    {
      case MA:
	printf("%c = MOVE APPEND FROM %d TO %d\n", str[idx], state, stateTable[state][o_idx]);
	state = stateTable[state][o_idx];
	break;
      case HR:
	printf("%c = SUCCESS, RESET TO 0\n", str[idx]);
	state = S0;
	isError = false;
	break;
      default:
	printf("%c = FAILED, return to 0\n", str[idx]);
	state = S0;
	break;
    }
  }
  printf("%c = END\n", '\0');
  return !isError;
}
