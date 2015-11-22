#include <stdio.h>
#include <stdlib.h>
#include "string_extras.h"


int main(int argc, char const *argv[])
{
	// You can replace just a letter with a letter
	printf("> %s\n", replace("Billy!" , "B" , "S") ); // > Silly!
	// A letter with many other letters
	printf("> %s\n", replace("Billy!" , "B" , "Programming-") ); // > Programming-illy!
	// The hole string
	printf("> %s\n", replace("Billy!" , "Billy!" , "Steve!") ); // > Steve!
	// Or just a sub-string
	printf("> %s\n", replace("Billy!" , "!" , "-Steve!") ); // > Billy-Steve!
	// However if the string does not exist in the original string you will get the same string back.
	printf("> %s\n", replace("Billy!" , "Holla!" , "Steve!") ); // > Billy!
	
	return 0;
}
