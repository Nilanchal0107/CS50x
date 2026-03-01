// Header Files
#include <cs50.h>
#include <stdio.h>

// Functions
int get_positive_int(void);
void meow(int n);

// Main Function
int main(void)
{
    int m = get_positive_int();
    meow(m);
}

int get_positive_int(void)
{
    int m;
    do
    {
        m = get_int("Number: ");
    }
    while (m <= 0);
    return m;
}
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Meow\n");
    }
}
