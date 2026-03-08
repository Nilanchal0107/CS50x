#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *t = malloc(3 * sizeof(int));

    t[0] = 23;
    t[1] = 43;
    t[2] = 33;

    free(t);
}
