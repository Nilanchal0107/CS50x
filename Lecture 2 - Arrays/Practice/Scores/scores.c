#include <cs50.h>
#include <stdio.h>

int count(void);
void get_scores(int length, int array[]);
float average(int length, int array[]);

int main(void)
{
    int N = count();
    int Scores[N];
    get_scores(N, Scores);
    float avg = average(N, Scores);

    printf("Average: %f\n", avg);
}

int count(void)
{
    int N;
    do
    {
        N = get_int("Number of scores: ");
    }
    while (N < 0);
    return N;
}

void get_scores(int length, int array[])
{
    for (int i = 0; i < length; i++)
    {
        array[i] = get_int("Score%i: ", i + 1);
    }
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
