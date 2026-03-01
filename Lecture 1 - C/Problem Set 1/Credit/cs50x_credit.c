/*
    PROBLEM: CREDIT CARD VALIDATOR (CS50 VERSION)

    Write a program that:
    - Prompts the user for a credit card number.
    - Validates the number using Luhn's Algorithm.
    - Determines card type (AMEX, MASTERCARD, VISA).
    - Prints the card type or INVALID.

    Card Rules:
    AMEX: 15 digits, starts with 34 or 37
    MASTERCARD: 16 digits, starts with 51–55
    VISA: 13 or 16 digits, starts with 4
*/

#include <cs50.h>
#include <stdio.h>

// Function prototypes
long get_number(void);
bool luhn_algo(long number);
int get_length(long number);
int get_start(long number, int digits);

int main(void)
{
    long number = get_number();

    // Validate using Luhn's Algorithm
    if (!luhn_algo(number))
    {
        printf("INVALID\n");
        return 0;
    }

    int length = get_length(number);
    int start1 = get_start(number, 1);
    int start2 = get_start(number, 2);

    // Determine card type
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

// Prompt for positive card number
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

// Implement Luhn's Algorithm
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

// Count number of digits
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

// Get first 1 or 2 starting digits
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

1. Prompt user for positive credit card number.
2. Apply Luhn’s Algorithm:
    a. Starting from last digit:
        - Multiply every second digit by 2.
        - If result > 9, subtract 9.
    b. Add all digits together.
    c. If total % 10 != 0 → INVALID.
3. Count number of digits.
4. Extract first 1 and first 2 digits.
5. Determine card type:
    - AMEX → length 15, starts with 34 or 37
    - MASTERCARD → length 16, starts with 51–55
    - VISA → length 13 or 16, starts with 4
6. Print result.
7. End.

Time Complexity: O(n)
Space Complexity: O(1)
*/