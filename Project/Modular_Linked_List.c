#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX  20 // Max random value

// Defining ASCII escape codes for terminal emulator colored ouput
// Since escape codes are handled by an emulator, this will not effect windows
// operation
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
void init(elementptr *, elementptr *); // initialize the linked linked_list
void addone(elementptr *); // Append an element to the end of the list
void trav_and_print(elementptr); // Traverse and print

int num_elems(elementptr); // Count and print the number of elements
void test_it(elementptr, elementptr); // traverse and print, then print first and last
elementptr get_currentptr(elementptr,int); // set current pointer to a random element in list
void append_to_current(elementptr *,elementptr *,elementptr *); // append an element to current pointer
void add_before_current(elementptr *,elementptr *,elementptr *); // add an element before current pointer
void delete_current(elementptr *,elementptr *,elementptr *,int); // deletes current pointer
void print_menu();

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
    int inputint,
        num_elem = 0,
        exit = 0,
        isLinkedList = 0;

    // Set the random number seed
    srand(time(NULL));

    // Print menu options
    printf(ANSI_COLOR_RESET "\n-- Welcome Human --\n");
    printf("The options are:\n");
    printf("1 - Initialize linked list\n");
    printf("2 - Traverse and print\n");
    printf("3 - Test the linked list\n");
    printf("4 - Randomize current pointer\n");
    printf("5 - Count and print number of elements\n");
    printf("6 - Append an element to end of list\n");
    printf("7 - Append to current pointer\n");
    printf("8 - Add an element before the current pointer\n");
    printf("9 - Deletes the current pointer's element\n");
    printf("0 - Exit\n");

    // Print the command line indicator
    printf("\n$ ");

    // Running loop - runs until program is killed or 'E' is entered
    while(1)
    {
        // Read the user entered character
        scanf("%d", &inputint);
        //printf("You entered %d\n",inputint); // Debugging the user input

        // Switch statement for different menu options as specified in print statements
        switch(inputint)
        {
          // Initialize the linked list
          case 1:
            init(&first,&last);
            isLinkedList = 1;
            break;

          // Traverse and print the linked list
          case 2:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            trav_and_print(first);
            break;

          // Test the integrity of the linked list
          case 3:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            test_it(first,last);
            break;

          // Set a random current pointer
          case 4:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            current = get_currentptr(first,num_elems(first));
            if (current != NULL)
            {
              printf("Current pointer set.\n");
            }
            break;

          // Count the number of elements
          case 5:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            num_elem = num_elems(first);
            if(num_elem==1)
            {
              printf("There is 1 element\n");
            }
            else if (num_elem > 1)
            {
              printf("There are %d elements\n",num_elem);
            }
            break;

          // Append an element to the end of the linked list
          case 6:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            addone(&last);
            break;

          // Append an element after the current pointer
          case 7:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            if (current == NULL)
            {
              current = get_currentptr(first,num_elems(first));
              printf(ANSI_COLOR_CYAN"Current pointer did not exist! One was created for you.\n");
            }
            append_to_current(&first,&current,&last);
            break;

          // Add an element before the current pointer
          case 8:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            if (current == NULL)
            {
              current = get_currentptr(first,num_elems(first));
              printf(ANSI_COLOR_CYAN"Current pointer did not exist! One was created for you.\n");
            }
            add_before_current(&first,&current,&last);
            break;

          // Delete the element that the current pointer points to
          case 9:
            //if (!isLinkedList){printf(ANSI_COLOR_RED"Initialize the linked list!\n");break;}
            if (current == NULL)
            {
              current = get_currentptr(first,num_elems(first));
              printf(ANSI_COLOR_CYAN"Current pointer did not exist! One was created for you.\n");
            }
            delete_current(&first,&current,&last,num_elems(first));
            break;

          // Exit the program
          case 0:
            exit = 1; // set exit flag to true
            break;

          // Handle any cases not offered in menu
          default:
            printf(ANSI_COLOR_RED"Not a valid option. Please re-enter command.\n\n"ANSI_COLOR_RESET);
            print_menu();
        }

        // If exit flag is true, exit the running loop
        if(exit){break;}

        // Flush stdin
        while (getchar() != '\n' && getchar()!= EOF);

        // Print the command line indicator
        printf(ANSI_COLOR_RESET "$ ");
    }
    printf(ANSI_COLOR_YELLOW "\n\nGood bye :(\n\n" ANSI_COLOR_RESET);
    return 0;
}

/*
---> Program functions
*/

// Print the menu options
void print_menu()
{
  printf("The options are:\n");
  printf("1 - Initialize linked list\n");
  printf("2 - Traverse and print\n");
  printf("3 - Test the linked list\n");
  printf("4 - Randomize current pointer\n");
  printf("5 - Count and print number of elements\n");
  printf("6 - Append an element to end of list\n");
  printf("7 - Append to current pointer\n");
  printf("8 - Add an element before the current pointer\n");
  printf("9 - Deletes the current pointer's element\n");
  printf("0 - Exit\n");
}

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
    if (*l == NULL)
    {
      printf("There is no linked list!\n");
    }
    else
    {
      (*l) -> next = (elementptr) malloc(sizeof(element));
      *l = (*l) -> next;
      (*l) -> data = rand()%MX+1;
      (*l) -> next = NULL;
  }
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
    {
        printf("There is no linked list!\n");
        return 0;
    }
    else
    {
        while (current != NULL)
        {
            num++;
            current = current -> next;
        }
        return num;
    }
}

// Call traverse and print. Then print the data value in the first and last
// Element to check the integrity of the linked list
void test_it(elementptr f,elementptr l)
{
  trav_and_print(f);
  printf("\n");
  if (f != NULL)
  {
    printf("The first data value is %d\n",f->data);
    printf("The last data value is %d\n",l->data);
  }
}

// Generates a random number in the range of the length of the linked list and
// and then assigns a pointer to that index in the linked list
elementptr get_currentptr(elementptr f, int length)
{
  if (f == NULL)
  {
    printf("There is no linked list!\n");
    return NULL;
  }
  else
  {
    int rand_val = rand()%length,
        i=0;
    elementptr current = f;

    while (i < rand_val)
    {
      current = current -> next;
      i++;
    }
    printf("The current pointer points to element #%d\n",i+1);
    return current;
  }
}

// This function adds an element to the linked list after the current pointer
void append_to_current(elementptr *f, elementptr *c, elementptr *l)
{
  if (*f == NULL)
  {
    printf("There is no linked list\n");
  }
  else
  {
    elementptr temp;
    temp = (elementptr)malloc(sizeof(element));
    temp->data = rand()%MX+1;

    if ((*c)->next == NULL)
    {
      *l = temp;
    }

    temp->next = (*c)->next;
    (*c)->next = temp;
  }
}

// This function adds an element before the current pointer
void add_before_current(elementptr *f, elementptr *c, elementptr *l)
{
  if (*f == NULL)
  {
    printf("There is no linked list\n");
  }
  else
  {
    elementptr temp, running = *f;
    temp = (elementptr)malloc(sizeof(element));
    temp->data = rand()%MX+1;

    if ((*f) == (*c))
    {
      (*f) = temp;
      temp->next = (*c);
      return;
    }

    while(running->next !=  (*c))
    {
      running = running -> next;
    }

    running->next = temp;
    temp->next = (*c);
  }
}

// This function deletes the element that the current pointer points to
void delete_current(elementptr *f, elementptr *c, elementptr *l, int num_elem)
{
  if (*f == NULL)
  {
    printf("There is no linked list\n");
  }
  else
  {
    elementptr running = *f;
    if ((*f) == (*c))
    {
      if (num_elem ==1)
      {
        free(*f);
        (*f) = NULL;
        (*l) = NULL;
        (*c) = NULL;
      }
      else
      {
        (*f) = (*c)->next;
        free(*c);
        (*c) = NULL;
        return;
      }
    }

    while(running->next !=  (*c))
    {
      running = running -> next;
    }

    if ((*l) == (*c))
    {
      (*l) = running;
      free(*c);
      (*c) = NULL;
      return;
    }

    running -> next = (*c) -> next;
    free(*c);
    (*c) = NULL;
  }
}
