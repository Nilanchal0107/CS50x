/*
    PROBLEM: MARIO (LESS COMFORTABLE) - CS50 VERSION

    Write a program that:
    - Prompts the user for a height between 1 and 8.
    - Prints a right-aligned pyramid of that height.

    Example (height = 4):

       #
      ##
     ###
    ####
*/

#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_height(void);
void print_spaces(int space);
void print_rows(int row);

int main(void)
{
    // Get height from user
    int height = get_height();

    // Print pyramid row by row
    for (int i = 0; i < height; i++)
    {
        // Print leading spaces
        print_spaces(height - (i + 1));

        // Print hashes
        print_rows(i + 1);
    }

    return 0;
}

// Prompt user until height is valid (1–8)
int get_height(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

// Print given number of spaces
void print_spaces(int space)
{
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

// Print given number of hashes and move to next line
void print_rows(int row)
{
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    printf("\n");
}

/*
---------------- ALGORITHM ----------------

1. Prompt user for height between 1 and 8.
2. Repeat until valid input is given.
3. For each row from 0 to height - 1:
    a. Print (height - row - 1) spaces.
    b. Print (row + 1) hashes (#).
    c. Move to next line.
4. End program.

Time Complexity: O(n²)
Space Complexity: O(1)
*/