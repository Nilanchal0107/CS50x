#include <cs50.h>
#include <stdio.h>

int f(int);

int main(void)
{
    int number;

    do
    {
        number = get_int("Number: ");
    }
    while (number < 0);

int result = f(number);

printf("The factorial of %i is %i.\n", number, result);

}

int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * (n - 1);
    }
}
