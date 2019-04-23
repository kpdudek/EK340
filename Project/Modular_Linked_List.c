#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX  20 // Max random value

// Structure definition for linked list
typedef struct linked_list
{
    int data;
    struct linked_list *next;
}   element;

// Pointer to an element in the linked list
typedef element * elementptr;

/*
---> Function Prototypes
*/
void init(elementptr *, elementptr *);
void addone(elementptr *);
void trav_and_print(elementptr);

int num_elems(elementptr);
void test_it(elementptr, elementptr);
elementptr get_currentptr(elementptr,int);

/*
---> Main Loop
*/
int main()
{
    // Pointers to linked list elements
    elementptr first = NULL,
               last = NULL,
               current = NULL;

    // Variable declarations
    int num_elem,
        exit = 0;
    char inputchar;

    // Set the random number seed
    srand(time(NULL));

    printf("Welcome Human\n");
    printf("The options are:\n");
    printf("I - Initialize linked list\n");
    printf("T - Traverse and print\n");
    printf("A - Append an element\n");
    printf("E - Exit\n");

    // Print the command line indicator
    printf("\n$ ");

    // Running loop
    while(1)
    {
        // Read the user entered character
        scanf("%c", &inputchar);

        // Switch statement for different menu options
        switch(inputchar)
        {
          case 'I':
            init(&first,&last);
            break;

          case 'T':
            trav_and_print(first);
            break;

          case 'A':
            addone(&last);
            break;

          case 'E':
            exit = 1;
            break;

          default:
            printf("Not a valid option. Please re-enter command.\n");
        }

        // If exit flag is true, exit the running loop
        if(exit){break;}

        // Flush stdin
        while ( getchar() != '\n' && getchar()!=EOF);

        // Print the command line indicator
        printf("$ ");
    }
    printf("Good bye\n\n");

    // init(&first,&last);
    //
    // trav_and_print(first);
    // addone(&last);
    // trav_and_print(first);
    //
    // // Beginning of additions to starter code
    // num_elem = num_elems(first);
    // printf("There are %d elements\n",num_elem);
    //
    // test_it(first,last);
    // current = get_currentptr(first,num_elem);
    // printf("%d\n",current->data);
    return 0;
}

/*
---> Program functions
*/

// Set up linked list with one element
void init(elementptr *f, elementptr *l)
{
    *f = (elementptr) malloc(sizeof(element));
    *l = *f;
    (*l) -> data = rand()%MX+1;
    (*l) -> next = NULL;
    printf("Linked list initialized!\n");
}

// Add element to the end of the linked list
void addone(elementptr *l)
{
    (*l) -> next = (elementptr) malloc(sizeof(element));
    *l = (*l) -> next;
    (*l) -> data = rand()%MX+1;
    (*l) -> next = NULL;

}

// Traverse the linked list and print data member
void trav_and_print(elementptr f)
{
    elementptr current;

    current = f;
    if (current == NULL)
        printf("There is no linked list!\n");
    else
        while (current != NULL)
        {
            printf("The data value is %d\n",current -> data);
            current = current -> next;
        }
}

// Traverse the linked list and count the number of elements
int num_elems(elementptr f)
{
    elementptr current;
    int num = 0;

    current = f;
    if (current == NULL)
        printf("There is no linked list!\n");
    else
        while (current != NULL)
        {
            num++;
            current = current -> next;
        }
        return num;
}

void test_it(elementptr f,elementptr l)
{
  trav_and_print(f);
  printf("The first data value is %d\n",f->data);
  printf("The last data value is %d\n",l->data);
}

elementptr get_currentptr(elementptr f, int length)
{
  int rand_val = rand()%length,
      i=0;
  elementptr current = f;

  while (i < rand_val)
  {
    current = current -> next;
    i++;
  }
  return current;
}
