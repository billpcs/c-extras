#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num ;						
	struct node *next ;			
} LIST ;



/*
Generates a new empty list.
*/
int newlist(LIST **Head){
	*Head = NULL ; 
	return 1; 
}


/*
Creates a list of length 'len' and fills it with zeros.
Returns the 'len' if everything went ok , and -1 if
there was a problem allocating memory.
*/

int filllist( int len , LIST **Head )
{
	LIST *p ;
	int i ;

	if (len < 1) return -1 ; 
	*Head = malloc( sizeof(LIST) ) ;
	if ( *Head == NULL )
		return -1 ;
	(*Head)->num = 0 ;
	(*Head)->next = NULL ;

	p = *Head ; 

	for( i = 0 ; i < len-1 ; i++ ){
		p->next = malloc( sizeof(LIST) )  ;
		if ( p->next == NULL )
			return -1 ;
		p = p->next ;
		p->num = 0 ;	
	}
	p->next = NULL ;
	return len;
}


/*
Appends the element 'elem' to the end of a list.
Returns 1 if everything went ok , else it returns -1
*/
int append( int elem ,  LIST **Head )
{
	LIST *p ;
	int i ;

	if ( *Head == NULL ){
		*Head = malloc( sizeof(LIST) ) ;
		if ( *Head == NULL )
			return -1 ;
		(*Head)->num = elem;
		(*Head)->next = NULL ;
		return 1 ; 
	}


	p = *Head ;

	while ( p->next != NULL ) p = p->next ;
	p->next = malloc( sizeof(LIST) )  ;
	if ( p->next == NULL )
		return -1 ;
	p = p->next ;
	p->num = elem ;
	p->next = NULL ;
	return 1 ;
}


/*
Prints out the contents of the list.
*/
void printlist( LIST *Start )
{
	printf("[");
	while ( Start->next != NULL )
	{
		printf( "%d,", Start->num ) ;
		Start = (Start)->next ;
	}
	printf( "%d", (Start)->num ) ; 
	printf("] \n");
}



/*
Inserts an element 'elem' in the place index of
the list. Returns 1 if it inserted it ,
0 if it did not insert it and -1 if there was 
a problem with the memory allocation.
*/

int insert( int index , int elem ,  LIST **Head )
{
	LIST *p, *p1 , *p2 ;
	

	// If the given index is not valid 
	if (index < 0) return -1 ; 

	//	If the list is empty and index > 0 
	if ( *Head == NULL && index > 0 ) return -1 ;
	else if (*Head == NULL && index == 0){
		*Head = malloc( sizeof(LIST) ) ;
		if ( *Head == NULL )
			return -1 ;
		(*Head)->num = elem ; 
		(*Head)->next = NULL ; 	
	}
		

	//	Search to find the correct place to insert 'elem'
	p = *Head ;
	int place = 0 ; 
	while ( p != NULL ){
		printf("%d\n", place );
		if ( place == index ){
			p1 = p ;
			p2 = p->next ; 
			p->next = malloc( sizeof(LIST)) ;
			if ( p->next == NULL )
				return -1 ;
			p = p->next ;
			p->num = p1->num;
			p1->num = elem ; 
			p->next = p2 ;
			return 1; 
		}	
		place ++ ; 
		p = p->next ;
	}
	return 0 ;
}


int main(void)
{

	LIST *test ;
	newlist(&test) ;  
 	int i ;
 	for (i = 0 ;  i < 20 ; i++){
 		append(i*i , &test) ; 
 	}
 	printlist(test) ; // [0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361]
	
	return 0;
}
