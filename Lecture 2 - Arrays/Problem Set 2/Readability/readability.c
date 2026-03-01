/*
    READABILITY PROGRAM (STANDARD C VERSION)

    Problem:
    Calculate the readability grade level of text using
    the Coleman-Liau Index formula.

    No CS50 library used.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int letters_count(const char *text);
int word_count(const char *text);
int sentence_count(const char *text);
int Coleman_Liau_index(int letters, int words, int sentences);

int main(void)
{
    char text[1000];

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = letters_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);

    int index = Coleman_Liau_index(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

int letters_count(const char *text)
{
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int word_count(const char *text)
{
    int spaces = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isblank(text[i]))
        {
            spaces++;
        }
    }

    return spaces + 1;
}

int sentence_count(const char *text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int Coleman_Liau_index(int letters, int words, int sentences)
{
    if (words == 0)
    {
        return 0;
    }

    float L = ((float) letters / words) * 100.0;
    float S = ((float) sentences / words) * 100.0;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    return (int) round(index);
}

/*
---------------- ALGORITHM ----------------

1. Read input text using fgets().
2. Count letters using isalpha().
3. Count words by counting spaces and adding 1.
4. Count sentences by checking '.', '!', '?'.
5. Compute averages:
       L = letters per 100 words
       S = sentences per 100 words
6. Apply Coleman-Liau formula.
7. Round result.
8. Print grade level accordingly.
9. End.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
fgets() includes newline character '\n',
but it does not affect counting logic.
*/