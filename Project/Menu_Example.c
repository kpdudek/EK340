#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int command;

    while ((command = getchar()) != EOF)
    {
        switch(command)
        {
        case 'c':
            printf("Create a new hash table\n");
            break;

        case 'l':
            printf("Look up a word\n");
            break;

        case 'f':
            printf("Read a file\n");
            break;

        case 'p':
            printf("Print the table\n");
            break;

        case 'r':
            printf("Remove a word\n");
            break;

        case 'q':
            printf("Quit\n");
            exit(0);
            break;

        default:
            printf("Unexpected input %d (0x%.2X) ('%c')\n",
                   command, command, isgraph(command) ? command : '.');
            break;
        }
    }
    return 0;
}
