#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 5, 10, 20, 50, 100, 200};

    int n = get_int("Number: ");

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not Found.\n");
    return 1;
}
