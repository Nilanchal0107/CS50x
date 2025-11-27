// Header Files
#include <cs50.h>
#include <stdio.h>

// Functions
int get_height(void);
void print_spaces(int space);
void print_rows(int row);

// Main Functions
int main(void)
{
    int height = get_height();

    // Print pyramid
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - (i + 1));
        print_rows(i + 1);
    }
}

// Prompt for user for Height of Pyramid
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while ((height <= 0) || (height > 8));
    return height;
}

// Function for printing spaces
void print_spaces(int space)
{
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

// Function for printing rows
void print_rows(int row)
{
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }
    printf("\n");
}
