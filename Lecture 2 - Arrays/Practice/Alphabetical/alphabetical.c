#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please provide a Word.\n");
        return 1;
    }

    string text = argv[1];

    for (int i = 1, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("This is not a word.\n");
            return 2;
        }
    }

    for (int i = 1, n = strlen(text); i < n; i++)
    {
        if (text[i] < text[i - 1])
        {
            printf("No.\n");
            return 0;
        }
    }

    printf("Yes.\n");
}
