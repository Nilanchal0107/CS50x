/*
    PROBLEM: HELLO, NAME (CS50 VERSION)

    Write a program that:
    - Prompts the user for their name.
    - Prints a greeting in the format: hello, <name>

    Example:
    Input:  Brian
    Output: hello, Brian
*/

#include <cs50.h>   // Provides get_string()
#include <stdio.h>  // Provides printf()

int main(void)
{
    // Prompt the user for their name and store it in a string variable
    string name = get_string("What's your name? ");

    // Print greeting using formatted string
    // %s is used to print a string
    printf("hello, %s\n", name);

    return 0;
}

/*
---------------- ALGORITHM ----------------

1. Prompt the user to enter their name.
2. Store the input in a string variable.
3. Print "hello, " followed by the user's name.
4. End program.

Time Complexity: O(1)
Space Complexity: O(1)
*/