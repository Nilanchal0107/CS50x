/*
    SCRABBLE GAME - STANDARD C VERSION

    Problem:
    Write a program that calculates the Scrabble score for two players.
    Use standard C functions (no CS50 library).
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Points[26] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5,
    1, 3, 1, 1, 3, 10, 1, 1, 1, 1,
    4, 4, 8, 4, 10
};

int compute_score(const char *word);

int main(void)
{
    char word1[100];
    char word2[100];

    // Prompt players
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);

    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(const char *word)
{
    int score = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isupper(word[i]))
        {
            score += Points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += Points[word[i] - 'a'];
        }
    }

    return score;
}

/*
---------------- ALGORITHM ----------------

1. Create array Points[26] for A–Z values.
2. Read two words using fgets().
3. For each word:
    a. Initialize score = 0
    b. Loop through characters until '\0':
        i. If uppercase:
            index = letter - 'A'
            add Points[index]
        ii. If lowercase:
            index = letter - 'a'
            add Points[index]
        iii. Ignore others
4. Compare scores.
5. Print winner or tie.
6. End program.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
fgets() may include newline '\n',
but since '\n' is not alphabetic,
it does not affect scoring.
*/