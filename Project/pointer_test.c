#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
}   element;

// Pointer to an element in the linked list
typedef element * elementptr;

void change(elementptr *);

void main()
{
  element kurt;
  kurt.data = 5;
  kurt.next = NULL;

  printf("dat: %d\n",kurt.data);

  elementptr kurtptr;
  kurtptr = (elementptr) malloc(sizeof(element));
  (*kurtptr).data = 10;
  printf("dat: %d\n",(*kurtptr).data);

  change(kurtptr);

  printf("dat: %d\n",(*kurtptr).data);

}

void change(elementptr * k)
{
  k.data = 100;
}
