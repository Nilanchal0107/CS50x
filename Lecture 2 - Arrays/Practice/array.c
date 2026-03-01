#include <cs50.h>
#include <stdio.h>

int get_positive(void);
void get_num(int array[], int length);
int get_largest(int array[], int length);

int main(void)
{
    int amount = get_positive();

    int Numbers[amount];

    get_num(Numbers, amount);

    int ans = get_largest(Numbers, amount);

    printf("The largest number is %i.", ans);
}

int get_positive(void)
{
    int numbers;

    do
    {
        numbers = get_int("How many numbers do you need to compare? ");
    }
    while (numbers < 0);
    return numbers;
}

void get_num(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = get_int("Number %i: ", i + 1);
    }
}

int get_largest(int array[], int length)
{
    int largest = array[0];

    for (int i = 0; i < length; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}

