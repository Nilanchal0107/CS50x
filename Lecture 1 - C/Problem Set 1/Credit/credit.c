/*
    PROBLEM: CREDIT CARD VALIDATOR (STANDARD C VERSION)

    Validate a credit card number using Luhn’s Algorithm
    and determine card type.

    No CS50 library used.
*/

#include <stdio.h>
#include <stdbool.h>

// Function prototypes
long get_number(void);
bool luhn_algo(long number);
int get_length(long number);
int get_start(long number, int digits);

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

    if ((length == 15) && (start2 == 34 || start2 == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (start2 >= 51 && start2 <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && start1 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

long get_number(void)
{
    long n;

    do
    {
        printf("Number: ");
        scanf("%ld", &n);
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

int get_start(long number, int digits)
{
    while (number >= 10 && get_length(number) > digits)
    {
        number /= 10;
    }

    return number;
}

/*
---------------- ALGORITHM ----------------

1. Prompt user for card number.
2. Validate using Luhn’s Algorithm:
    - Double every second digit from right.
    - Subtract 9 if result > 9.
    - Sum all digits.
    - Check if sum % 10 == 0.
3. If invalid → print INVALID.
4. Count total digits.
5. Extract starting digits.
6. Determine card type using rules.
7. Print card name.
8. End program.

Time Complexity: O(n)
Space Complexity: O(1)
*/