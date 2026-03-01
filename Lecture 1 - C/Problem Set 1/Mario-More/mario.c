/*
    PROBLEM: MARIO (MORE COMFORTABLE) - STANDARD C VERSION

    Write a program that:
    - Prompts the user for a height (1–8).
    - Prints a double half-pyramid.
    - No CS50 library used.
*/

#include <stdio.h>

// Function prototypes
int get_height(void);
void print_space(int space);
void print_rows(int row);

int main(void)
{
    int height = get_height();

    for (int i = 0; i < height; i++)
    {
        print_space(height - (i + 1));
        print_rows(i + 1);
    }

    return 0;
}

// Get height using standard input
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
void print_space(int space)
{
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

// Print pyramid rows
void print_rows(int row)
{
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    printf("  ");

    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    printf("\n");
}

/*
---------------- ALGORITHM ----------------

1. Prompt user for integer between 1 and 8.
2. Repeat until valid input.
3. For each row:
    a. Print decreasing spaces.
    b. Print increasing hashes.
    c. Print two-space gap.
    d. Print increasing hashes again.
4. Move to next line.
5. End.

Time Complexity: O(n²)
Space Complexity: O(1)
*/