// Header Files
#include <cs50.h>
#include <stdio.h>

int get_ChangeOwed(void);

// Main Function
int main(void)
{
    int change = get_ChangeOwed();

    int quarters = change / 25;

    int change2 = change % 25;
    int dimes = change2 / 10;

    int change3 = change2 % 10;
    int nickels = change3 / 5;

    int pennies = change3 % 5;

    printf("%i\n", quarters + dimes + nickels + pennies);
}

int get_ChangeOwed(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change <= 0);
    return change;
}
