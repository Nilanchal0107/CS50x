/*
    PROBLEM: MARIO (MORE COMFORTABLE) - CS50 VERSION

    Write a program that:
    - Prompts the user for a height (1–8).
    - Prints a double half-pyramid of that height.
    - Each row has:
        - Leading spaces
        - Left hashes (#)
        - Two spaces gap
        - Right hashes (#)

    Example (height = 4):

       #  #
      ##  ##
     ###  ###
    ####  ####
*/

#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_height(void);
void print_space(int space);
void print_rows(int row);

int main(void)
{
    // Get valid height from user
    int height = get_height();

    // Print each row
    for (int i = 0; i < height; i++)
    {
        // Print leading spaces
        print_space(height - (i + 1));

        // Print left and right pyramid
        print_rows(i + 1);
    }

    return 0;
}

// Prompt user until height is between 1 and 8
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

// Print required number of spaces
void print_space(int space)
{
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

// Print hashes and middle gap
void print_rows(int row)
{
    // Left pyramid
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    // Middle gap
    printf("  ");

    // Right pyramid
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    printf("\n");
}

/*
---------------- ALGORITHM ----------------

1. Prompt the user for height between 1 and 8.
2. For each row from 0 to height - 1:
    a. Print (height - row - 1) spaces.
    b. Print (row + 1) hashes (#).
    c. Print two spaces.
    d. Print (row + 1) hashes (#).
    e. Move to next line.
3. End program.

Time Complexity: O(n²)
Space Complexity: O(1)
*/