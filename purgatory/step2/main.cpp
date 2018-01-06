#include <cstdio>
#include <cassert>
#include "Machine.hpp"

int main()
{
  printf("state_machine(\"evil\") = %s\n",
	 state_machine("evil") ? "true" : "false");
  printf("state_machine(\"evi\") = %s\n",
	 state_machine("evi") ? "true" : "false");
  printf("state_machine(\"avil\") = %s\n",
	 state_machine("avil") ? "true" : "false");
  printf("state_machine(\"eeeeeeeevil\") = %s\n",
	 state_machine("eeeeeeeevil") ? "true" : "false");
  printf("state_machine(\"evilevilevil\") = %s\n",
	 state_machine("evilevilevil") ? "true" : "false");
  printf("state_machine(\"eeeeeeeevileeeeeeeevil\") = %s\n",
	 state_machine("eeeeeeeevileeeeeeeevil") ? "true" : "false");
  return 0;
}