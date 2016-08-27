/* A file to demonstrate the possible usage of the function 'uppercase' and
 * 'lowercase' . */

#include <stdio.h>
#include <stdlib.h>
#include "string_extras.h"

int main(int argc, char const *argv[]) {
  char name[] = "Seed or Die";
  printf("> '%s'\n", name);            //> 'Seed or Die'
  printf("> '%s'\n", uppercase(name)); //> 'SEED OR DIE'
  printf("> '%s'\n", lowercase(name)); //> 'seed or die'
  // To save it to a new string:
  char *new = uppercase(name);
  char *new2 = lowercase(name);
  printf("> '%s'\n", new);  //> 'SEED OR DIE'
  printf("> '%s'\n", new2); //> 'seed or die'
  // Or to change the existing string:
  strcpy(name, uppercase(name));
  printf("> '%s'\n", name); //> 'SEED OR DIE'
  strcpy(name, lowercase(name));
  printf("> '%s'\n", name);                                  //> 'seed or die'
  printf("> '%s'\n", lowercase(uppercase(lowercase(name)))); //> 'seed or die'
  return 0;
}
