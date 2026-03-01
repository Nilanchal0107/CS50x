//Header File
#include <cs50.h>
#include <stdio.h>

//Main Functions
int main(void)
{
    //Prompt for a user
    char c = get_char("Do you Agree? \n");

    //Check response
    if ((c == 'y') || (c == 'Y'))
    {
        printf("Agreed\n");
    }
    else if ((c == 'n') || (c == 'N'))
    {
        printf("Disagreed\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

