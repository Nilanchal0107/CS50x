#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 1;

    while (true)
    {
        char c = get_char("Do you want $%i or I double it and give it to the next person? ", n);

        if ((c == 'y') || (c == 'Y'))
        {
            n *= 2;
        }
        else
        {
            break;
        }
        printf("Here is yours $%i.\n", n);
    }
}
