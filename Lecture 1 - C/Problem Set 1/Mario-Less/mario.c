//Header Files
#include <stdio.h>

//Functions
int get_height(void);
void print_spaces(int);
void print_rows(int);

//Main Function
int main ()
{
    int height = get_height();

    //Pyramid Building
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - (i + 1));
        print_rows(i + 1);
    }
}

//Prompt for height for pyramid.
int get_height()
{
    int h;
    do
    {
        printf("Enter height between 1 and 8.\n");
        printf("Height: ");
        scanf("%d", &h);
    }
    while ((h < 1) && (h > 8));
    return h;
}

//Print Spaces
void print_spaces (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

//Print Rows
void print_rows (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}