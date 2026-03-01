/*
    PROBLEM: CASH (CS50 VERSION)

    Write a program that:
    - Prompts the user for the amount of change owed (in cents).
    - Calculates the minimum number of coins needed.
    - Available coins: 25¢, 10¢, 5¢, 1¢.
    - Uses a greedy algorithm.

    Example:
    Input: 41
    Output: 4  (25 + 10 + 5 + 1)
*/

#include <cs50.h>
#include <stdio.h>

// Function prototype
int get_change_owed(void);

int main(void)
{
    int change = get_change_owed();
    int coins = 0;

    // Greedy algorithm: use largest coin first

    // Count quarters
    coins += change / 25;
    change %= 25;

    // Count dimes
    coins += change / 10;
    change %= 10;

    // Count nickels
    coins += change / 5;
    change %= 5;

    // Remaining pennies
    coins += change;

    printf("%i\n", coins);

    return 0;
}

// Prompt user for positive amount
int get_change_owed(void)
{
    int change;

    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    return change;
}

/*
---------------- ALGORITHM ----------------

1. Prompt user for change owed in cents.
2. Initialize coin counter = 0.
3. While change >= 25:
      Add (change / 25) to coins.
      change = change % 25.
4. Repeat for 10¢ coins.
5. Repeat for 5¢ coins.
6. Add remaining pennies.
7. Print total coins.
8. End program.

Time Complexity: O(1)
Space Complexity: O(1)
*/