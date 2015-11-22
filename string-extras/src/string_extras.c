#include "string_extras.h"

/*##################################################
Removes space characters from the beginning and 
the end of a string given.
*///################################################
char* trim( char string[] ){
 	int len = strlen(string);
 	int index = len - 1 ;
 	char *newstring = malloc(sizeof(char)*len);
 	if (!newstring) return string ;
 	int pfb = 0 ;
 	while ( string[pfb] == ' ' || string[pfb] == '\t' || string[pfb] == '\n' ) pfb ++ ;
 	int pfe = 0 ;
 	while ( string[index] == ' ' || string[index] == '\t' || string[index] == '\n' ){
 		pfe++ ;
 		index -- ;
 	}
 	strncpy(newstring , string+pfb , len-pfb-pfe ) ;
 	strcat(newstring , "\0") ;
	return newstring ;
}


/*##################################################
Gets all the characters except for the first
'index' characters of the string given.
*///################################################
char* substring(char string[]  , int index){
	int len = strlen(string) ;
	if (index > len) return string; 
	char *newstring = malloc(sizeof(char)*len);
	if (!newstring) return  string ; 
	// Get the substring.
	strncpy(newstring , string+index , len-index ) ; 
	strcat(newstring , "\0") ;
	return newstring ; 
}


/*##################################################
Returns a sub-array that is determined by 
the two indexes in the parameters.
*///################################################
char* subsequence(char string[] , int lower , int upper){
	int len = strlen(string) ; 
	if (upper > len || lower < 0 || lower>upper) return string ;
	char *newstring = malloc(sizeof(char)*len-(upper-lower)+1) ; 
	int i , j = 0 ; 
	for (i=lower ; i<upper ; i++){
		newstring[j++] = string[i] ; 
	}
	newstring[j] = '\0' ; 
	return newstring ; 
}

/*##################################################
Returns the index of the first time the 
character is found in the string. If the 
character could not be found it returns -1. 
*///################################################
int indexof(char string[] , char character){
	int len = strlen(string) ;
	int i ; 
	for (i=0 ; i < len ; i++){
		if (string[i] == character) return  i ;
	}
	return -1  ; 
}



/*##################################################
Returns the index the substring was found if the 
string contains the substring and -1 if the string 
does not contain it.
*///################################################
int contains(char string[] , char substring[]){
	int master_len = strlen(string) ;
	int slave_len = strlen(substring) ; 
	int index = 0 ;
	char *sub ;  
	while(index + slave_len <= master_len){
		sub = subsequence(string , index , index+slave_len) ; 
		if (!strcmp(sub , substring)) return index ;
		index ++ ; 
	}
	return -1 ; 
}


/*##################################################
Return 1 if the string ends with the substring given
else it returns 0.
*///################################################
int endswith(char string[] , char substring[]){
	int len = strlen(string) ;
	int lsub = strlen(substring) ;
	//If the sub-string is longer than the actual string.
	if (len < lsub) return -1 ;
	char *correct_end = subsequence(string , len-lsub ,len) ; 
	if (!strcmp(correct_end , substring)) return 1 ;
	return 0 ; 
}

/*##################################################
Return 1 if the string starts with the substring given
else it returns 0.
*///################################################
int startswith( char string[] , char substring[]){
	int len = strlen(string) ;
 	int lsub = strlen(substring) ;
 	// If sub-string is longer than the actual string.
 	if (len < lsub) return -1 ;
 	char *correct_start = subsequence(string , 0 , lsub ) ;
 	if (!strcmp(correct_start , substring)) return 1 ;
 	return 0 ;
}


/*##################################################
Return the lower case of the string given.
*///################################################
char* lowercase( char string[] ){
	int len = strlen(string), letter = 0;
	char *newstring =  malloc(sizeof(char)*len+1);
	strcpy(newstring, string);
	do{
		if( string[letter] > 64 && string[letter] < 91 )   newstring[letter] = string[letter] + 32;
	}while( letter++ < len );
	return newstring;
}


/*##################################################
Return the upper case of the string given.
*///################################################
char* uppercase( char string[] ){
	int len = strlen(string), letter = 0;
	char *newstring =  malloc(sizeof(char)*len+1);
	strcpy(newstring, string);
	do{  
		if( string[letter] > 96 && string[letter] < 123 )   newstring[letter] = string[letter] - 32;
	}while( letter++ < len );
	return newstring;
}

char* swapcase(char string[]){
	int len = strlen(string) , i ;
	char *newstring =  malloc(sizeof(char)*len+1);
	strcpy(newstring, string);
	for (i = 0 ; i < len ; i++){
		if( isalpha(string[i])){
			if ( isupper(string[i]) ) newstring[i] += 32 ;
			else newstring[i] -= 32 ;
		}
	}
	return newstring ; 
}


/*##################################################
If the given string is a integer return 1 and in any 
other case return 0.
This function DOES NOT take into account empty space 
in the beginning and the end of a given string.
e.g. isint( "52" ) --> 1
e.g. isint( "\t 52  " ) --> 1
e.g. isint( " \n52 \t " ) --> 1
e.g. isint( "fifty two" ) --> 0
e.g. isint( " 5 2  " ) --> 0
*///################################################
int isint( char string[] ){
	char *newstring = trim(string) ;
	int i = 0, len = strlen(newstring) -1 ;
	do{
		if( newstring[i] < 48 || newstring[i] > 57 ) return 0 ;
	}while( i++ < len ) ;
	return 1 ;
}


/*##################################################
If a string with only numerics is given then return 
it as an unsigned int. 
This function DOES NOT check whether the given string 
represents an integer.
This function DOES NOT take into account empty space 
in the beginning and the end of a given string.
e.g. strtoint("blue") --> 56743
e.g. strtoint("fifty two") --> 1856735695
e.g. strtoint("52") --> 52. 
e.g. strtoint("  52 \n") --> 52.s
*///################################################
unsigned int strtoint( char string[] ){
	unsigned int N = 0, tens = 1 ;
	char *newstring = trim(string) ;
	int i = 0, len = strlen( newstring ) ; 
	while( i < len ){
		N += ( newstring[len - i - 1] - 48 ) * tens ;
		tens *= 10 ;
		i++;
	}
	return N;
}

char* replace(char string[] , char toreplace[] , char replacer[] ){

	int index , i ;
	int final_length = strlen(string)+strlen(replacer)-strlen(toreplace) ; 

	// If the string does not exist.
	if ( (index = contains(string , toreplace)) == -1 ) return string;

	char *newstring = 
		malloc(sizeof(char)*final_length) ; 

	for (i=0 ; i < index ; i++)
		newstring[i] = string[i] ; 
	
  	for (i=index ; i < strlen(replacer) + index ; i++) 
  		newstring[i] = replacer[i-index] ;
  	
  	for (i=strlen(replacer) + index ; i < final_length ; i++)
  		newstring[i] = string[ i - (final_length - strlen(string) )] ;
  	return  newstring ; 

}

char * totitle(char string[]){
	int len = strlen(string) , i , j ; 
	char *newstring = malloc(sizeof(char)*len+1) ;
	strcpy(newstring, string); 
	if (len == 0) return string;
	// First letter you find , make it uppercase.
	for (i = 0 ; i < len ; i++){
		if ( isalpha(string[i]) && islower(string[i]) ){
			newstring[i] -= 32 ;
			break ; 
		} 
	}
	// From then on . . .
	for (j = i+1 ; j < len ; j++){
		if( isalpha(string[j]) ){
			if (islower(string[j]) && string[j-1] == ' ' )
				newstring[j] -= 32;
			else if ( ! (islower(string[j])) ) newstring[j] += 32 ; 
		}
	}
	return newstring ;
}


