/*
    PROBLEM: MARIO (LESS COMFORTABLE) - STANDARD C VERSION

    Write a program that:
    - Prompts the user for a height between 1 and 8.
    - Prints a right-aligned pyramid.
    - No CS50 library used.
*/

#include <stdio.h>

// Function prototypes
int get_height(void);
void print_spaces(int space);
void print_rows(int row);

int main(void)
{
    int height = get_height();

    for (int i = 0; i < height; i++)
    {
        print_spaces(height - (i + 1));
        print_rows(i + 1);
    }

    return 0;
}

// Get height using scanf
int get_height(void)
{
    int height;

    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    return height;
}

// Print spaces
void print_spaces(int space)
{
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

// Print hashes and newline
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

1. Prompt user for integer height (1–8).
2. Repeat until valid height is entered.
3. For each row:
    a. Print decreasing spaces.
    b. Print increasing hashes.
    c. Move to next line.
4. End program.

Time Complexity: O(n²)
Space Complexity: O(1)
*/