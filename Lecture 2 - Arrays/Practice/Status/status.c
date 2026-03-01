#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if(argc == 1)
    {
        printf("Missing Command-Line Argument\n");
        return 1;
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            printf("Hello. %s", argv[i]);
        }
        printf("\n");
        return 0;
    }
}
