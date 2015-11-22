// Below lie some examples. Remember that it is always a good practice to use
// **dellist** when you
// do not need the list any more, so as not to create memory leaks.

// ###Example 1: Creating an empty list.

int main(void) {
  // Create a list named test
  NODE *test;
  // Make your list pointing to NULL (optional)`
  new_list(&test);
  // Print your list
  print_list(&test); // ( )
  del_list(&lst);
  return 0;
}

// ###Example 2:Initializing your list.
// There are many ways to do it: First it's the standard way
// Create an empty list and append to it 3 zeros using a **for loop** like so:

int main(void) {
  NODE *test;
  new_list(&test);
  int i;
  for (i = 0; i < 3; i++)
    append(0, &test);
  print_list(&test); // ( 0 0 0 )
  del_list(&test);
  return 0;
}

// The second (faster for big numbers way ) is to use the function **filllist**
// :

int main(void) {
  NODE *test;
  new_list(&test);
  fill_list(0, 3, &test);
  print_list(&test); // ( 0 0 0 )
  del_list(&test);
  return 0;
}
// The **fill_list** function creates a list with the number you specify as the
// first parameter, with length that you specify as the second parameter. If you
// call fill_list on a non-empty list it will erase it and create a new one.

// Finally if you want to give certain values to your list you can use
// **set_list** function.

int main(void) {
  // Create the list
  NODE *lst;
  // Make it point to NULL (optional)
  new_list(&lst);
  // Create an int array to transform into a list
  int arr[] = {1, 2, 3, 4, '\0'};
  // Takes the array and makes it into a list
  set_list(arr, &lst);
  // Print out the list in a nice format.
  print_list(&lst); // ( 1 2 3 4 )
  dellist(&lst);
  return 0;
}

// **CAREFUL** You must always initialize the array so that its last value is
// '\0' character in order for the function to work correctly.

// ###Example 3:Inserting to the list.
// The **insert** function inserts to the place specified by the fist parameter
// , the number specified in the second. Note that **insert** _can not_ insert
// to the end of a list unless it is empty. You will have to use append to do
// it. Here is an example:

int main(void) {
  NODE *test;
  new_list(&test);
  int i;
  for (i = 0; i < 5; i++) {
    insert(i, 0, &test);
    print_list(&test);
  }
  del_list(&test);
  return 0;
}

// The _OUTPUT_ is:

// * [ 0 ]
// * [ 1 0 ]
// * [ 2 1 0 ]
// * [ 3 2 1 0 ]
// * [ 4 3 2 1 0 ]

// ###Example 4 : Getting the length.
int main(void) {
  NODE *lst;
  new_list(&lst);
  int i;
  for (i = 0; i < 5; i++) {
    append(i, &lst);
  }
  print_list(lst);                            // ( 0 1 2 3 4 )
  printf("> Length: %d\n", length_list(lst)); // > Length: 5
  del_list(&lst);
  return 0;
}

// ###Example 5: Getting items.

int main(void) {
  NODE *lst;
  new_list(&lst);
  int i;
  for (i = 0; i < 10; i++) {
    append_list(i, &lst);
  }
  for (i = 0; i < length_list(lst); i++) {
    printf("%d ", getitem_list(i, lst));
  }
  del_list(&lst);
  return 0;
}

// OUT: 0 1 2 3 4 5 6 7 8 9

// ###Example 6: Summing your list.

int main(void) {
  NODE *lst;
  new_list(&lst);
  int i;
  for (i = 0; i < 10000; i++) {
    append_list(i, &lst);
  }
  printf("> %lld\n", sum(&lst)); //> 4999950000
  del_list(&lst);
}

// To demonstrate the speed of sum() function against the classic iteration way:

int main(void) {
  NODE *lst;
  new_list(&lst);
  int i;
  long long sumoflist = 0;
  for (i = 0; i < 10000; i++) {
    append(i, &lst);
  }
  int len = length_list(&lst);
  for (i = 0; i < len; i++) {
    sumoflist += getitem_list(i, &lst);
  }
  printf("> %lld\n", sumoflist); //> 4999950000
  del_list(&lst);
}

// The times using **time** command:

// 1) **sum() function** :

//                         real	0m0.609s
//                         user	0m0.609s

// 2) **Classic iteration** :

//                          real	0m1.075s
//                          user	0m1.075s

// ###Example 7: Removing items from your list.

int main(void) {
  NODE *lst;
  new_list(&lst);
  int i;
  for (i = 0; i < 10; i++) {
    append_list(i, &lst);
  }
  print_list(&lst); // ( 0 1 2 3 4 5 6 7 8 9 )
  removeitem_list(7, &lst);
  print_list(&lst); // ( 0 1 2 3 4 5 6 8 9 )
  del_list(&lst);
  return 0;
}

// ### Example 8 : Reversing your list.

int main(void) {
  NODE *test = NULL; // Alternative way
  // This -> new_list(&test) ; is not needed now
  int i;
  for (i = 0; i < 10; i++) {
    insert(0, i, &test);
  }
  print_list(&test); // > ( 9 8 7 6 5 4 3 2 1 0 )
  reverse_list(&test);
  print_list(&test); // > ( 0 1 2 3 4 5 6 7 8 9 )
  return 0;
}
