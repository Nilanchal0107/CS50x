#include <cs50.h>
#include <stdio.h>

int numer(string name);

int main(void)
{
    string s = get_string("Name: ");

    int length = numer(s);

    printf("%i\n", length);
}

int numer(string name)
{
    int n = 0;
    while (name[n] != 0)
    {
        n++;
    }
    return n;
}
