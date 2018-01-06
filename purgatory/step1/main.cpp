#include <cstdio>
#include <cassert>
#include "Machine.hpp"

int main()
{
  printf("state_machine(\"evil\") = %s\n",
	 !state_machine("evil") ? "true" : "false");
  printf("state_machine(\"evi\") = %s\n",
	 !state_machine("evi") ? "true" : "false");
  printf("state_machine(\"avil\") = %s\n",
	 !state_machine("avil") ? "true" : "false");
  printf("state_machine(\"avilevil\") = %s\n",
	 !state_machine("avilevil") ? "true" : "false");
  printf("state_machine(\"avileviafevi\") = %s\n",
	 !state_machine("avileviafevi") ? "true" : "false");
  printf("state_machine(\"evilevilevil\") = %s\n",
	 !state_machine("evilevilevil") ? "true" : "false");
  return 0;
}