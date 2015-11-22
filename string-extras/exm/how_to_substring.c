/* A file to demonstrate the possible usage of the function 'substring' . */

#include <stdio.h>
#include <stdlib.h>
#include "string_extras.h"

int main(int argc, char const *argv[]){
	char name[] = "Hello World" ; 
	printf("'%s'\n", name );
	printf("'%s'\n", substring(name,6));
	//To save it to a new string:
	char *new  = substring(name,6) ; 
	printf("'%s'\n ", new) ; 
	return 0 ;
}


/*

> OUT:
'Hello World'
'World'
'World'

*/
