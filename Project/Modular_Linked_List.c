/*

  EK340 Final Project
  Kurt Dudek
  2019/04/29

*/

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
void init(elementptr *, elementptr *); // initialize the linked linked_list
void addone(elementptr *); // Append an element to the end of the list
void trav_and_print(elementptr); // Traverse and print

int num_elems(elementptr); // Count and print the number of elements
void test_it(elementptr, elementptr); // traverse and print, then print first and last
elementptr get_currentptr(elementptr,int); // set current pointer to a random element in list
void append_to_current(elementptr *,elementptr *,elementptr *); // append an element to current pointer
void add_before_current(elementptr *,elementptr *,elementptr *); // add an element before current pointer
void delete_current(elementptr *,elementptr *,elementptr *,int); // deletes current pointer
void append_many(elementptr *); // calls add one a specified number of times
void print_menu(); // Print the menu options

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
        exit = 0;

    // Set the random number seed
    srand(time(NULL));

    // Print menu options
    printf("\n-- Welcome Human --\n");
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
    printf("10 - Append multiple elements\n");
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
            break;

          // Traverse and print the linked list
          case 2:
            trav_and_print(first);
            break;

          // Test the integrity of the linked list
          case 3:
            test_it(first,last);
            break;

          // Set a random current pointer
          case 4:
            current = get_currentptr(first,num_elems(first));
            break;

          // Count the number of elements
          case 5:
            num_elem = num_elems(first);

            // Conditions for propper conjugation
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
            addone(&last);
            break;

          // Append an element after the current pointer
          case 7:
            // Check if there is a current pointer, make one if there isnt
            if (first != NULL && last != NULL && current == NULL)
            {
              printf("Current pointer did not exist! One was created for you.\n");
              current = get_currentptr(first,num_elems(first));
            }
            append_to_current(&first,&current,&last);
            break;

          // Add an element before the current pointer
          case 8:
            // Check if there is a current pointer, make one if there isnt
            if (first != NULL && last != NULL && current == NULL)
            {
              printf("Current pointer did not exist! One was created for you.\n");
              current = get_currentptr(first,num_elems(first));
            }
            add_before_current(&first,&current,&last);
            break;

          // Delete the element that the current pointer points to
          case 9:
            // Check if there is a current pointer, make one if there isnt
            if (first != NULL && last != NULL && current == NULL)
            {
              printf("Current pointer did not exist! One was created for you.\n");
              current = get_currentptr(first,num_elems(first));
            }
            delete_current(&first,&current,&last,num_elems(first));
            break;

          case 10:
            append_many(&last);
            break;

          // Exit the program
          case 0:
            // Set exit flag to true
            exit = 1;
            break;

          // Handle any cases not offered in menu
          default:
            printf("Not a valid option. Please re-enter command.\n\n");
            print_menu();
        }

        // If exit flag is true, exit the running loop
        if(exit){break;}

        // Flush stdin
        while (getchar() != '\n' && getchar()!= EOF);

        // Print the command line indicator
        printf("$ ");
    }
    printf("\n\nGood bye :(\n\n");
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
  printf("10 - Append multiple elements\n");
  printf("0 - Exit\n");

}

// Set up linked list with one element
void init(elementptr *f, elementptr *l)
{
    // Allocate memory for a new element
    *f = (elementptr) malloc(sizeof(element));
    // Assign the last pointer to the first element since length == 1
    *l = *f;
    // Assign a random data value
    (*l) -> data = rand()%MX+1;
    // Set the next element as NULL
    (*l) -> next = NULL;

    printf("Linked list initialized!\n");
}

// Add element to the end of the linked list
void addone(elementptr *l)
{
    // Check that there is a linked list
    if (*l == NULL)
    {
      printf("There is no linked list!\n");
    }
    else
    {
      // Allocate memory for a new element
      (*l) -> next = (elementptr) malloc(sizeof(element));
      // Reassign the last pointer
      *l = (*l) -> next;
      // Set a random data value
      (*l) -> data = rand()%MX+1;
      // Set the next element as NULL
      (*l) -> next = NULL;
  }
}

// Traverse the linked list and print data member
void trav_and_print(elementptr f)
{
    // Temporary pointer used to traverse the list
    elementptr current;
    int i = 0;
    // Start from the first element in the list
    current = f;
    // Check if there is a linked list
    if (current == NULL)
        printf("There is no linked list!\n");
    else
        // While there is another element after the current one
        printf("Element:  Value\n");
        while (current != NULL)
        {
            // Print the element index and its value
            printf("%-9d %-5d\n",i,current -> data);
            // Set the current pointer to the next element
            current = current -> next;
            // iterate the counter for the element number
            i++;
        }
}

// Traverse the linked list and count the number of elements
int num_elems(elementptr f)
{
    // Create a temporary pointer to traverse the list
    elementptr current;
    // Num is a counter
    int num = 0;

    // Start from the beginning of the list
    current = f;
    // Check that there is a linked list
    if (current == NULL)
    {
        printf("There is no linked list!\n");
        return 0;
    }
    else
    {
        // While there is another element in the list
        while (current != NULL)
        {
            // Iterate the counter
            num++;
            // Direct the pointer to the next element
            current = current -> next;
        }
        return num;
    }
}

// Call traverse and print. Then print the data value in the first and last
// Element to check the integrity of the linked list
void test_it(elementptr f,elementptr l)
{
  // Call trav_and_print to display the list
  trav_and_print(f);
  // If there is a linked list, print the first and last elements data values to
  // check the integrity
  if (f != NULL)
  {
    printf("\n");
    printf("The first data value is %d\n",f->data);
    printf("The last data value is %d\n",l->data);
  }
}

// Generates a random number in the range of the length of the linked list and
// and then assigns a pointer to that index in the linked list
elementptr get_currentptr(elementptr f, int length)
{
  // Check if there is a linked list.
  // There is no need to print that there is no linked list since the
  // num_elems() function call will print it
  if (f != NULL)
  {
    // Get a random value in the range of the length of the linked list
    int rand_val = rand()%length,
        i=0; // i is a counter
    // Use a temporary pointer to traverse the list and set it to the first element
    elementptr current = f;

    // When the counter is one less than the random value, stop
    while (i < rand_val)
    {
      // Set the current pointer equal to the next value. Since the while loop stopped
      // at rand_val -1, this will make the current pointer point to rand_val
      current = current -> next;
      // Iterate i
      i++;
    }
    printf("The current pointer points to element #%d\n",i+1);
    return current;
  }
}

// This function adds an element to the linked list after the current pointer
void append_to_current(elementptr *f, elementptr *c, elementptr *l)
{
  // Check if there is a linked list
  if (*f == NULL)
  {
    printf("There is no linked list\n");
  }
  else
  {
    // Create a temporary pointer
    elementptr temp;
    // Allocate enough memory for a new element
    temp = (elementptr)malloc(sizeof(element));
    // Set the new elements data value to a random value
    temp->data = rand()%MX+1;

    // Edge case: if the current pointer points to the last element in the list,
    // move the last pointer to the new element
    if ((*c)->next == NULL)
    {
      *l = temp;
    }

    // Set the new elements next pointer to the next pointer of the current pointer
    temp->next = (*c)->next;
    // Set the current pointers next pointer to the new element
    (*c)->next = temp;
  }
}

// This function adds an element before the current pointer
void add_before_current(elementptr *f, elementptr *c, elementptr *l)
{
  // Check if there is a linked list
  if (*f == NULL)
  {
    printf("There is no linked list\n");
  }
  else
  {
    // Create a temporary pointer and a running pointer
    // The running pointer is used to find the element before the current pointer
    elementptr temp, running = *f;
    // Allocate enough memory for a new element
    temp = (elementptr)malloc(sizeof(element));
    // Set the new elements data value to be a random number
    temp->data = rand()%MX+1;

    // Edge case: if the current pointer points to the first element in the list,
    // move the first pointer to point to the new element.
    if ((*f) == (*c))
    {
      // Make the first pointer point to the new element
      (*f) = temp;
      // Make the new elemenets next pointer the current pointers value (the first
      // element in the list)
      temp->next = (*c);

    } else {

    // While the running pointer's next pointer is not the current pointer
    while(running->next !=  (*c))
    {
      // Make running the next element in the list
      running = running -> next;
    }

    // Make the running elements next pointer point to the new element
    running->next = temp;
    // Make the new elements next pointer point to the current pointer
    temp->next = (*c);
  }
  }
}

// This function deletes the element that the current pointer points to
void delete_current(elementptr *f, elementptr *c, elementptr *l, int num_elem)
{
  // There is no need to print that there is no linked list since the
  // num_elems() function call will print it
  if (*f != NULL)
  {
    // Create a running pointer
    // The running pointer is used to find the element before the current pointer
    elementptr running = *f;
    // Edge case: if the current pointer points to the first element...
    if ((*f) == (*c))
    {
      // ... and if there is only one element in the list ...
      if (num_elem ==1)
      {
        // free up the memory
        free(*f);
        // Assign the pointer to NULL since there is no longer a linked list
        (*f) = NULL;
        (*l) = NULL;
        (*c) = NULL;
      }
      // The first pointer must be moved to the next element in the list to
      // maintain the integrity of the list
      else
      {
        // Move the first pointer
        (*f) = (*c)->next;
        // Free up the memory
        free(*c);
        // Make the current pointer NULL since it no longer points to anything
        (*c) = NULL;
        return;
      }
    }

    // While the running pointer's next value is not the current value
    while(running->next !=  (*c))
    {
      // Make running the next element in the list
      running = running -> next;
    }

    // Edge case: if the current pointer points to the last element in the list
    // the last pointer must be moved to point to the previous
    if ((*l) == (*c))
    {
      // Set the last pointer to the running value which is adjacent to the
      // last value in the list
      (*l) = running;
      // Free up the memory
      free(*c);
      // Set the current pointer to NULL since it no longer exists
      (*c) = NULL;
      return;
    }

    // Set the running elements next pointer to the value after the current value
    running -> next = (*c) -> next;
    // Free up the memory
    free(*c);
    // Set the current pointer to NULL since it no longer exists
    (*c) = NULL;
  }
}

void append_many(elementptr *l)
{
  // Check if there is a linked list
  if (*l == NULL)
  {
      printf("There is no linked list!\n");
  }
  else
  {
    // Integer number of new elements to add
    int val;
    // Prompt the user and store the response
    printf("Enter the number of elements you wish to add: \n");
    scanf("%d",&val);
    // Call the addone function to create n number of new elements at the end of
    // the linked list
    for (int i = 0; i<val; i++)
    {
      addone(l);
    }
  }
}
