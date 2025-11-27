//Header File
#include <stdio.h>

//Functions
int get_height();
void print_spaces(int);
void print_rows(int);

//Main Function
int main()
{
    int height = get_height();

    //Pyramid Building
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - (i + 1));
        print_rows(i + 1);
        print_spaces(2);
        print_rows(i + 1);
        printf("\n");
    }
    
    return 0;
}

int get_height()
{
    int n;
    do
    {
        printf("Enter Height between 1 and 8.\n");
        printf("Height: ");
        scanf("%d", &n);
    }
    while ((n < 0) && (n > 8));
    return n;
}

void print_spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_rows(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}