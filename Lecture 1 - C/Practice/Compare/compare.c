// Header File
#include <cs50.h>
#include <stdio.h>

// Main Function
int main(void)
{
    //Prompt for user
    int x = get_int("Number x: ");
    int y = get_int("Number y: ");

    //Conditionals
    if (x > y)
    {
        printf("x is greater than y.\n");
    }
    else if (x < y)
    {
        printf("x is smaller than y.\n");
    }
    else
    {
        printf("x is equals to y.\n");
    }
}
