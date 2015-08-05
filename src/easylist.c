#include <stdio.h>
#include <stdlib.h>
#include "easylist.h" 

typedef struct listcreator {
	int num ;						
	struct listcreator *next ;		
} NODE ;

/*
Generates a new empty list.
*/
int newlist(NODE **Head){
	*Head = NULL ; 
	return 1; 
}

/*
Deletes the list.
*/
int dellist(NODE **Head ){
	NODE *p  = *Head ; 
	while (p) {
        *Head = p->next;
        free(p);
        p = *Head ;
	}
	return 1 ; 
}

/*
Takes the array pointed to by arr and saves its values in a linked list.
It can be used to simulate the Python's syntax : my_list = [1,2,3,4] 
WARNING: arr MUST have as a last value the character '\0' !!! .
*/
int setlist( int arr[] , NODE **Head  ){
	if (!dellist(Head)) return -1 ;

	if (!arr[0]) {
		*Head = NULL ;
		return 1 ;
	}

	*Head = malloc( sizeof(NODE) ) ;
	if ( *Head == NULL )
		return -1 ;

	(*Head)->num = arr[0] ;
	(*Head)->next = NULL ;

	NODE *p = *Head ; 
	int i ; 
	for( i = 1 ; arr[i] ; i++ ){
		p->next = malloc( sizeof(NODE) )  ;
		if ( p->next == NULL )
			return -1 ;
		p = p->next ;
		p->num = arr[i] ;
	}
	p->next = NULL ;
	return 1;

}



/*
Creates a list of length 'len' and fills it with value 'value'.
Returns the 'len' if everything went ok , and -1 if
there was a problem allocating memory.
*/

int filllist(  int len  , int value , NODE **Head ){
	NODE *p ;
	int i ;

	if (!dellist(Head)) return -1 ;
	if (len < 1) return -1 ; 

	*Head = malloc( sizeof(NODE) ) ;
	if ( *Head == NULL )
		return -1 ;
	(*Head)->num = value ;
	(*Head)->next = NULL ;

	p = *Head ; 
	for( i = 0 ; i < len-1 ; i++ ){
		p->next = malloc( sizeof(NODE) )  ;
		if ( p->next == NULL )
			return -1 ;
		p = p->next ;
		p->num = value ;
	}
	p->next = NULL ;
	return len;
}


/*
Appends the element 'elem' to the end of a list.
Returns 1 if everything went ok , else it returns -1
*/
int append( int elem ,  NODE **Head ){
	NODE *p ;
	int i ;
	*Head = reverselist(Head) ;
	insert(0 , elem , Head) ;
	*Head = reverselist(Head) ;
	return 1 ;  
}


/*
Inserts an element 'elem' in the place index of
the list. Returns 1 if it inserted it ,
0 if it did not insert it and -1 if there was 
a problem with the memory allocation.
WARNING: It will not insert an element in the
last place of the list unless the list is empty.
*/

int insert( int index , int elem ,  NODE **Head ){
	NODE *p, *p1 , *p2 ;
	// If the given index is not valid 
	if (index > length(Head) ) return -1 ; 
	// If the list is empty and index > 0 
	if ( *Head == NULL && index > 0 ) {
		return -1 ;
	}
	if (*Head == NULL && index == 0){
		*Head = malloc( sizeof(NODE) ) ;
		if ( *Head == NULL ) return -1 ;
		(*Head)->num = elem ; 
		(*Head)->next = NULL ;
		//(*Head)->last = *Head ; 
		return 1 ;  	
	}
	if ( index == 0 ){
		p = malloc(sizeof(NODE)) ; 
		if ( p == NULL) return -1 ;
		p->next = *Head ; 
		//p->last = (*Head)->last ;
		p->num = elem ;
		(*Head) = p ;  
		return 1 ;
	}
	//	Search to find the correct place to insert 'elem'
	if ( index == length(Head) ){
		append(index , Head) ; 
		return 1 ;
	}
	p = (*Head)->next ;
	int place = 1  ; 
	while ( p != NULL ){
		if ( place == index ){
			p1 = p ;
			p2 = p->next ; 
			p2 = malloc( sizeof(NODE)) ;
			if ( p2 == NULL ) return -1 ;
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

/*
Returns the length of the list.
*/
int length(NODE **Head){
	if (*Head == NULL) return 0 ; 
	int len = 1 ; 
	NODE *p = *Head ;
	while(p->next) {
		len++ ;
		p = p->next	;
	}
	return len ; 
}

/*
Returns the sum of all the elements in the list.
*/
long long int sum(NODE **Head){
	long long int sum = 0 ; 
	NODE *p = *Head;
	while(p){
		sum += p->num ; 
		p = p->next ; 
	}
	return sum ; 
}

/*
Get item by index. If the index is out of range
it returns the first item in the list.
*/
int getitem(int index ,NODE **Head){
	if (index > length(Head) || index == 0) return (*Head)->num ; 
	int current = 0 ;
	NODE *p = *Head;
	while(p){
		if (index == current) return p->num ; 
		p = p->next ; 
		current ++ ;
	}	
}

/*
Pops the first element out of the list.
*/
int pop(NODE **Head){
	NODE *p = *Head; 
	(*Head) = (*Head)->next ; 
	free(p) ;
	return 1 ; 
}

/*
Returns the number of occurrences of 'key'
in the list.
*/
int count(int key , NODE **Head){
	int times = 0 ;
	NODE *p = *Head ;
	while( p != NULL){
		if ( p->num == key) times ++ ;
		p = p->next ; 
	}
	return times ; 
}

/*
Removes the first item that has the value 
'key' from the list.
*/
int removeitem(int key , NODE **Head){
	NODE *p = *Head ; 
	// If list is empty 
	if ( *Head == NULL ) return -1 ;
	// If the key is found in the first place of the list
	if ( (*Head)->num == key ) {
		(*Head) = (*Head)->next ;
		free(p) ;
		return 1 ; 
	}
	while ( p->next != NULL){
		if ( p->next->num == key ){
			NODE *temp = p ; 
			p = p -> next ;  
			temp->next = p -> next ;
			//(*Head)->last = temp ; 
			free(p) ;
			return 1 ;  
		}
		p = p->next ;
	}
	return 0 ;
}

/*
Returns the first index of 'key'.
Returns -1 if the 'key' was not found.
*/
int indexlist(int key , NODE **Head){
  NODE *p = *Head ; 
  int index = 0 ; 
  while( p != NULL ){
    if ( p->num == key) return index ; 
    index ++ ;
    p = p->next ; 
  }
  return -1 ; 
}

NODE * reverselist(NODE **Head){
    NODE *next ;
    NODE *previous =  NULL ;
    NODE *current  = *Head ;
    while (current != NULL ){
        next = current->next ;
        current->next = previous ;
        previous = current ;
        current = next ;
    }
    *Head = previous ;
    return *Head ; 
}


/*
Prints out the contents of the list.
*/
void printlist( NODE **Start ){
	NODE *p = *Start ; 
	printf("( ");
	while ( p != NULL ){
		printf( "%d ", p->num ) ;
		p = p->next ;
	}
	printf(") \n");
}
