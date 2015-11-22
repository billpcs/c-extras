/* A file to demonstrate the possible usage of the function 'totitle' . */

#include <stdio.h>
#include <stdlib.h>
#include "string_extras.h"


int main(int argc, char const *argv[])
{
	printf(">%s\n>%s\n" ,"tHiS iS a rEALy mEsSy sTRING" , totitle("tHiS iS a rEALy mEsSy sTRING"));
	char str[] = "tHiS iS aNoTeR rEALy mEsSy sTRING" ; 
	printf(">%s\n>%s\n", str , totitle(str) );
	return 0;
}


/*
> OUT:

>tHiS iS a rEALy mEsSy sTRING
>This Is A Realy Messy String
>tHiS iS aNoTeR rEALy mEsSy sTRING
>This Is Anoter Realy Messy String

*/
