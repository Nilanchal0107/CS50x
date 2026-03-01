/*
    PROBLEM: CASH (STANDARD C VERSION)

    Write a program that:
    - Prompts user for change owed in cents.
    - Calculates minimum number of coins needed.
    - No CS50 library used.
*/

#include <stdio.h>

// Function prototype
int get_change_owed(void);

int main(void)
{
    int change = get_change_owed();
    int coins = 0;

    coins += change / 25;
    change %= 25;

    coins += change / 10;
    change %= 10;

    coins += change / 5;
    change %= 5;

    coins += change;

    printf("%d\n", coins);

    return 0;
}

// Get input using scanf
int get_change_owed(void)
{
    int change;

    do
    {
        printf("Change owed: ");
        scanf("%d", &change);
    }
    while (change < 0);

    return change;
}

/*
---------------- ALGORITHM ----------------

1. Ask user for change owed in cents.
2. Ensure value is non-negative.
3. Use greedy strategy:
      - Take as many 25¢ coins as possible.
      - Then 10¢ coins.
      - Then 5¢ coins.
      - Remaining are 1¢ coins.
4. Count total coins used.
5. Print total.
6. End.

Time Complexity: O(1)
Space Complexity: O(1)
*/