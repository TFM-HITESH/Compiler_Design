// Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
int z = 0, i = 0, j = 0, c = 0;

// Modify array size to increase
// length of string to be parsed
char a[16], ac[20], stk[15], act[10];

// This Function will check whether
// the stack contains a production rule
// which is to be reduced.
// Rules can be S->CC , C->cC , C->d
void check()
{
    // Copying string to be printed as action
    strcpy(ac, "REDUCE TO ");

    // c = length of input string
    for (z = 0; z < c; z++)
    {
        // checking for production rule C -> d
        if (stk[z] == 'd')
        {
            printf("%sC -> d", ac);
            stk[z] = 'C';
            stk[z + 1] = '\0';

            // printing action
            printf("\n$%s\t%s$\t", stk, a);
        }
    }

    for (z = 0; z < c - 1; z++)
    {
        // checking for production rule C -> cC
        if (stk[z] == 'c' && stk[z + 1] == 'C')
        {
            printf("%sC -> cC", ac);
            stk[z] = 'C';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 1;
        }
    }

    for (z = 0; z < c - 1; z++)
    {
        // checking for production rule S -> CC
        if (stk[z] == 'C' && stk[z + 1] == 'C')
        {
            printf("%sS -> CC", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 1;
        }
    }
    return; // return to main
}

// Driver Function
int main()
{
    printf("GRAMMAR is -\nS -> CC \nC -> cC \nC -> d\n");

    // a is the input string
    strcpy(a, "cdcd");

    // strlen(a) will return the length of a to c
    c = strlen(a);

    // "SHIFT" is copied to act to be printed
    strcpy(act, "SHIFT");

    // This will print Labels (column name)
    printf("\nstack \t input \t action");

    // This will print the initial
    // values of stack and input
    printf("\n$\t%s$\t", a);

    // This will run up to the length of the input string
    for (i = 0; j < c; i++, j++)
    {
        // Printing action
        printf("%s", act);

        // Pushing into stack
        stk[i] = a[j];
        stk[i + 1] = '\0';

        // Moving the pointer
        a[j] = ' ';

        // Printing action
        printf("\n$%s\t%s$\t", stk, a);

        // Call check function to check the stack
        // for any production rules
        check();
    }

    // Rechecking one last time if the stack
    // contains any valid production
    check();

    // If the top of the stack is S (starting symbol)
    // then the input is accepted
    if (stk[0] == 'S' && stk[1] == '\0')
        printf("Accept\n");
    else // otherwise, reject
        printf("Reject\n");

    return 0;
}
