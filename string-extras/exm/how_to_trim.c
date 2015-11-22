/* A file to demonstrate the possible usage of the function 'trim' . */

#include <stdio.h>
#include <stdlib.h>
#include "string_extras.h"

int main(int argc, char const *argv[]) {
  char name[] = "   -2000   \t\t\n\n";
  printf("'%s'\n", name);
  printf("'%s'\n", trim(name));
  // To save it to a new string:
  char *new = trim(name);
  printf("'%s'\n ", new);
  return 0;
}

/*
> OUT:

'   -2000

'
'-2000'
'-2000'

*/
