/*
    READABILITY PROGRAM (CS50 VERSION)

    Problem:
    Write a program that calculates the readability grade level of a text
    using the Coleman-Liau Index.

    Formula:
        index = 0.0588 * L - 0.296 * S - 15.8

    Where:
        L = average number of letters per 100 words
        S = average number of sentences per 100 words

    The program should:
        - Prompt user for text
        - Count letters, words, sentences
        - Compute the index
        - Print grade level
*/

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int letters_count(string text);
int word_count(string text);
int sentence_count(string text);
int Coleman_Liau_index(int letters, int words, int sentences);

int main(void)
{
    // Prompt user
    string text = get_string("Text: ");

    // Compute components
    int letters = letters_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);

    // Compute readability index
    int index = Coleman_Liau_index(letters, words, sentences);

    // Print grade level
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
        printf("Grade %i\n", index);
    }

    return 0;
}

// Count alphabetic characters
int letters_count(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// Count words (words = spaces + 1)
int word_count(string text)
{
    int spaces = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            spaces++;
        }
    }

    return spaces + 1;
}

// Count sentences (. ! ?)
int sentence_count(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

// Compute Coleman-Liau index
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

1. Prompt user for input text.
2. Count letters:
    - For each character:
        If alphabetic → increment counter.
3. Count words:
    - Count number of spaces.
    - Words = spaces + 1.
4. Count sentences:
    - Count occurrences of '.', '!', '?'.
5. Compute:
    L = (letters / words) * 100
    S = (sentences / words) * 100
6. Apply formula:
    index = 0.0588L - 0.296S - 15.8
7. Round index.
8. Print:
    - Before Grade 1 (if index < 1)
    - Grade 16+ (if index > 16)
    - Otherwise Grade X
9. End.

Time Complexity: O(n)
Space Complexity: O(1)
*/