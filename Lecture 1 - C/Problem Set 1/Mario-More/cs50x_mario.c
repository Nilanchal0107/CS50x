// Header Files
#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_space(int);
void print_rows(int);

// Main Function
int main(void)
{
    int height = get_height();

    for (int i = 0; i < height; i++)
    {
        print_space(height - (i + 1));
        print_rows(i + 1);
    }
}

// Function for user prompt
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

void print_space(int space)
{
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
}

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
