#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX  20 // Max random value
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
void append_to_current(elementptr *,elementptr *,elementptr *);

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
    int num_elem = 0,
        exit = 0,
        isLinkedList = 0;
    char inputchar;

    // Set the random number seed
    srand(time(NULL));

    // Print menu options
    printf("\n-- Welcome Human --\n");
    printf("The options are:\n");
    printf("I - Initialize linked list\n");
    printf("P - Traverse and print\n");
    printf("A - Append an element\n");
    printf("T - Test the linked list\n");
    printf("C - Randomize current pointer\n");
    printf("N - Count and print number of elements\n");
    printf("L - Append to current pointer\n");
    printf("E - Exit\n");

    // Print the command line indicator
    printf("\n$ ");

    // Running loop - runs until program is killed or 'E' is entered
    while(1)
    {
        // Read the user entered character
        scanf("%c", &inputchar);

        // Switch statement for different menu options as specified in print statements
        switch(inputchar)
        {
          case 'I':
            init(&first,&last);
            isLinkedList = 1;
            break;

          case 'P':
            if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            trav_and_print(first);
            break;

          case 'A':
            if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            addone(&last);
            break;

          case 'E':
            exit = 1;
            break;

          case 'T':
            if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            test_it(first,last);
            break;

          case 'C':
            if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            current = get_currentptr(first,num_elems(first));
            break;

          case 'N':
            if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            num_elem = num_elems(first);
            if(num_elem==1)
            {
              printf("There is 1 element\n");
            }
            else
            {
              printf("There are %d elements\n",num_elem);
            }
            break;

          case 'L':
            if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            if (current == NULL)
            {
              current = get_currentptr(first,num_elems(first));
              printf(ANSI_COLOR_CYAN"Current pointer did not exist! One was created for you.\n");
            }
            append_to_current(&first,&current,&last);
            break;

          default: // Handle any characters not offered in menu
            printf(ANSI_COLOR_RED"Not a valid option. Please re-enter command.\n");
        }

        // If exit flag is true, exit the running loop
        if(exit){break;}

        // Flush stdin
        while (getchar() != '\n' && getchar()!= EOF);

        // Print the command line indicator
        printf(ANSI_COLOR_RESET "$ ");
    }
    printf("\n\nGood bye :(\n\n");
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

// Call traverse and print. Then print the data value in the first and last
// Element to check the integrity of the linked list
void test_it(elementptr f,elementptr l)
{
  trav_and_print(f);
  printf("\n");
  printf("The first data value is %d\n",f->data);
  printf("The last data value is %d\n",l->data);
}

// Generates a random number in the range of the length of the linked list and
// and then assigns a pointer to that index in the linked list
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

// This function adds an element to the linked list after the current Pointer
void append_to_current(elementptr *f, elementptr *c, elementptr *l)
{
  elementptr temp;
  temp = (elementptr)malloc(sizeof(element));
  temp->data = rand()%MX+1;
  temp->next = (*c)->next;
  (*c)->next = temp;
  if ((*l) == (*c))
  {
    *l = *c;
  }
}
