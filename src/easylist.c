#include <stdio.h>
#include <stdlib.h>
#include "easylist.h"

typedef struct listcreator {
  TYPE_ num;
  struct listcreator *next;
} NODE;

/*
Generates a new empty list.
*/
int new_list(NODE **Head) {
  *Head = NULL;
  return 1;
}

/*
Deletes the list.
*/
int del_list(NODE **Head) {
  NODE *p = *Head;
  while (p) {
    *Head = p->next;
    free(p);
    p = *Head;
  }
  return 1;
}

/*
Takes the array pointed to by arr and saves its values in a linked list.
It can be used to simulate the Python's syntax : my_list = [1,2,3,4]
WARNING: arr MUST have as a last value the character '\0' !!! .
*/
int set_list(TYPE_ arr[], NODE **Head) {
  if (!del_list(Head))
    return -1;

  if (!arr[0]) {
    *Head = NULL;
    return 1;
  }

  *Head = malloc(sizeof(NODE));
  if (*Head == NULL)
    return -1;

  (*Head)->num = arr[0];
  (*Head)->next = NULL;

  NODE *p = *Head;
  int i;
  for (i = 1; arr[i]; i++) {
    p->next = malloc(sizeof(NODE));
    if (p->next == NULL)
      return -1;
    p = p->next;
    p->num = arr[i];
  }
  p->next = NULL;
  return 1;
}

/*
Creates a list of length 'len' and fills it with value 'value'.
Returns the 'len' if everything went ok , and -1 if
there was a problem allocating memory.
*/

int fill_list(int len, TYPE_ value, NODE **Head) {
  NODE *p;
  int i;

  if (!del_list(Head))
    return -1;
  if (len < 1)
    return -1;

  *Head = malloc(sizeof(NODE));
  if (*Head == NULL)
    return -1;
  (*Head)->num = value;
  (*Head)->next = NULL;

  p = *Head;
  for (i = 0; i < len - 1; i++) {
    p->next = malloc(sizeof(NODE));
    if (p->next == NULL)
      return -1;
    p = p->next;
    p->num = value;
  }
  p->next = NULL;
  return len;
}

/*
Appends the element 'elem' to the end of a list.
Returns 1 if everything went ok , else it returns -1
*/
int append_list(TYPE_ elem, NODE **Head) {
  NODE *p;
  reverse_list(Head);
  insert_list(elem, 0, Head);
  reverse_list(Head);
  return 1;
}

/*
Inserts an element 'elem' in the place index of
the list. Returns 1 if it inserted it ,
0 if it did not insert it and -1 if there was
a problem with the memory allocation.
WARNING: It will not insert an element in the
last place of the list unless the list is empty.
*/

int insert_list(TYPE_ elem, int index, NODE **Head) {
  // If the list is empty and index > 0
  if (*Head == NULL && index > 0) {
    return -1;
  }
  if (*Head == NULL && index == 0) {
    *Head = malloc(sizeof(NODE));
    if (*Head == NULL)
      return -1;
    (*Head)->num = elem;
    (*Head)->next = NULL;
    return 1;
  }
  NODE *p;
  if (index == 0) {
    p = malloc(sizeof(NODE));
    if (p == NULL)
      return -1;
    p->next = *Head;
    p->num = elem;
    (*Head) = p;
    return 1;
  }
  //	Search to find the correct place to insert 'elem'
  if (index == length_list(Head)) {
    append_list(elem, Head);
    return 1;
  }
  NODE *p1;
  p = (*Head)->next;
  int place = 1;
  while (p != NULL) {
    if (place == index - 1) {
      p1 = malloc(sizeof(NODE));
      p1->next = p->next;
      p->next = p1;
      p1->num = elem;
      return 1;
    }
    place++;
    p = p->next;
  }
  return -1;
}

/*
Returns the length of the list.
*/
int length_list(NODE **Head) {
  if (*Head == NULL)
    return 0;
  int len = 1;
  NODE *p = *Head;
  while (p->next) {
    len++;
    p = p->next;
  }
  return len;
}

/*
Returns the sum of all the elements in the list.
*/
double sum_list(NODE **Head) {
  double sum = 0;
  NODE *p = *Head;
  while (p) {
    sum += p->num;
    p = p->next;
  }
  return sum;
}

/*
Get item by index. If the index is out of range
it returns the first item in the list.
*/
int getitem_list(int index, NODE **Head) {
  if (index > length_list(Head) || index == 0)
    return (*Head)->num;
  int current = 0;
  NODE *p = *Head;
  while (p) {
    if (index == current)
      return p->num;
    p = p->next;
    current++;
  }
}

/*
Pops the first element out of the list.
*/
int pop_list(NODE **Head) {
  NODE *p = *Head;
  (*Head) = (*Head)->next;
  free(p);
  return 1;
}

/*
Returns the number of occurrences of 'key'
in the list.
*/
int count_list(TYPE_ key, NODE **Head) {
  int times = 0;
  NODE *p = *Head;
  while (p != NULL) {
    if (p->num == key)
      times++;
    p = p->next;
  }
  return times;
}

/*
Removes the first item that has the value
'key' from the list.
*/
int removeitem_list(TYPE_ key, NODE **Head) {
  NODE *p = *Head;
  // If list is empty
  if (*Head == NULL)
    return -1;
  // If the key is found in the first place of the list
  if ((*Head)->num == key) {
    (*Head) = (*Head)->next;
    free(p);
    return 1;
  }
  while (p->next != NULL) {
    if (p->next->num == key) {
      NODE *temp = p;
      p = p->next;
      temp->next = p->next;
      //(*Head)->last = temp ;
      free(p);
      return 1;
    }
    p = p->next;
  }
  return 0;
}

/*
Returns the first index of 'key'.
Returns -1 if the 'key' was not found.
*/
int indexof_list(TYPE_ key, NODE **Head) {
  NODE *p = *Head;
  int index = 0;
  while (p != NULL) {
    if (p->num == key)
      return index;
    index++;
    p = p->next;
  }
  return -1;
}

/*
  Reverses the list, given the head
  (The head changes)
*/
void reverse_list(NODE **Head) {
  NODE *next;
  NODE *previous = NULL;
  NODE *current = *Head;
  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *Head = previous;
}

/*
  Sorts the linked list, give the head,
  using the well known, merge sort algorithm
*/
void merge_sort_list(NODE **headRef) {
  NODE *head = *headRef;
  NODE *a;
  NODE *b;

  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }

  /* Split head into 'a' and 'b' sublists */
  split_in_half(head, &a, &b);

  /* Recursively sort the sublists */
  merge_sort_list(&a);
  merge_sort_list(&b);

  /* answer = merge the two sorted lists together */
  *headRef = _merge_sort_list(a, b);
}

/*
THIS FUNCTION IS SUPPLEMENTARY TO MERGE SORT
          USE AT YOUR OWN RISK
*/
NODE *_merge_sort_list(NODE *a, NODE *b) {
  NODE *result = NULL;

  /* Base cases */
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;

  /* Pick either a or b, and recurse */
  if (a->num <= b->num) {
    result = a;
    result->next = _merge_sort_list(a->next, b);
  } else {
    result = b;
    result->next = _merge_sort_list(a, b->next);
  }
  return result;
}

/*
  THIS FUNCTION IS SUPPLEMENTARY TO MERGE SORT
            USE AT YOUR OWN RISK
  Splits the list in half by altering the two pointers
*/
void split_in_half(NODE *source, NODE **first, NODE **second) {
  NODE *fast;
  NODE *slow;
  if (source == NULL || source->next == NULL) {
    // if length < 2
    *first = source;
    *second = NULL;
  } else {
    slow = source;
    fast = source->next;

    // Use the fast' and 'slow' pointers to find the mid
    while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }

    //'slow' is now before the midpoint in the list,
    // so we split it there
    *first = source;
    *second = slow->next;
    slow->next = NULL;
  }
}

/*
Prints out the contents of the list.
*/
void print_list(NODE **Start) {
  NODE *p = *Start;
  printf("( ");
  while (p != NULL) {
    printf("%d ", p->num);
    p = p->next;
  }
  printf(") \n");
}
