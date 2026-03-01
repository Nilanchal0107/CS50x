#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string names[] = {"Nilanchal Jena", "Nirakar Jena", "Sunilkumar Jena"};
    string numbers[] = {"+91-9324565609", "+91-7400285472", "+91-9920297419"};

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("%s.\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found.\n");
    return 1;
}
