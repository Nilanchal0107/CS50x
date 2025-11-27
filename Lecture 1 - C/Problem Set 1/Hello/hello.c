#include <stdio.h>

int main ()
{
    char name[100];
    printf("What's your name? ");
    fgets(name , 100, stdin);
    printf("Hello, ");
    puts(name);

    return 0;
}