#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "Nilanchal Jena";
    people[0].number = "+91-9324565609";

    people[1].name = "Nirakar Jena";
    people[1].number = "+91-7400285472";

    people[2].name = "Sunilkumar Jena";
    people[2].number = "+91-9920297419";

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("%s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found.\n");
    return 1;
}
