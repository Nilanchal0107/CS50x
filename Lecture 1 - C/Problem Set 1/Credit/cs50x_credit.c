#include <cs50.h>
#include <stdio.h>

long get_number(void);
bool luhn_algo(long);
int get_length(long);
int get_start(long, int);

int main(void)
{
    long number = get_number();

    if (!luhn_algo(number))
    {
        printf("INVALID\n");
        return 0;
    }

    int length = get_length(number);

    int start1 = get_start(number, 1);
    int start2 = get_start(number, 2);

    if ((length == 15) && ((start2 == 34) || (start2 == 37)))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && ((start2 >= 51) && (start2 <= 55)))
    {
        printf("MASTERCARD\n");
    }
    else if (((length == 13) || (length == 16)) && (start1 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    long n;

    do
    {
        n = get_long("Number: ");
    }
    while (n <= 0);

    return n;
}

bool luhn_algo(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (alternate)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10 == 0);
}

int get_length(long number)
{
    int count = 0;

    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int get_start(long number, int start_digit)
{
    while (number >= 10 && start_digit < get_length(number))
    {
        number /= 10;
    }
    return number;
}
