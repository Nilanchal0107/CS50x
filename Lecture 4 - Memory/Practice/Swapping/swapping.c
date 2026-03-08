#include <stdio.h>

void swap(int *a, int*b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("The value of x is %i\nThe value of y is %i\n", x, y);

    swap(&x, &y);
    printf("The value of x is %i\nThe value of y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}
