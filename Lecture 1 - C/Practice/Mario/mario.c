#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void box(int n);

int main (void)
{
    int m = get_positive_int();
    box(m);
}

int get_positive_int(void)
{
    int m;
    do
    {
        m = get_int("Number: ");
    }
    while( m <= 0 );
    return m;
}

void box(int n)
{
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
        printf("#");
        }
        printf("\n");
    }
}

