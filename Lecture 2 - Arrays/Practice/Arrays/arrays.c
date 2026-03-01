#include <cs50.h>
#include <stdio.h>

int count(void);

int main(void)
{
    int size = count();

    int numbers[size];

    numbers[0] = 1;

    printf("%i\n", numbers[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i + 1] = numbers[i] * 2);
    }
}

int count(void)
{
    int N;
    do
    {
        N = get_int("Till how much times do you need to double the number start from 1: ");
    }
    while (N < 0);
    return N;
}
