#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string words[] = {"tanjiro", "deku", "goku", "saitama", "luffy", "ichigo", "naruto"};

    string s = get_string("Name: ");

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(words[i], s) == 0)
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not Found.\n");
    return 1;
}
