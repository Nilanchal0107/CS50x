/*
    SCRABBLE GAME - CS50 VERSION

    Problem:
    Write a program that calculates the Scrabble score for two players.
    Each letter has a specific point value.
    The program should:
        - Prompt Player 1 and Player 2 for a word.
        - Compute each word’s score.
        - Print who wins, or if it's a tie.
*/

#include <cs50.h>     // For get_string
#include <ctype.h>    // For isupper(), islower()
#include <stdio.h>    // For printf()
#include <string.h>   // For strlen()

// Points array where index 0 = A, 1 = B, ..., 25 = Z
int Points[26] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5,
    1, 3, 1, 1, 3, 10, 1, 1, 1, 1,
    4, 4, 8, 4, 10
};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Prompt both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine winner
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

// Function to compute Scrabble score
int compute_score(string word)
{
    int score = 0;

    // Loop through each character
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // If uppercase letter
        if (isupper(word[i]))
        {
            score += Points[word[i] - 'A'];
        }
        // If lowercase letter
        else if (islower(word[i]))
        {
            score += Points[word[i] - 'a'];
        }
        // Non-alphabetical characters are ignored
    }

    return score;
}

/*
---------------- ALGORITHM ----------------

1. Create an array of 26 integers representing Scrabble points.
2. Prompt Player 1 and Player 2 for words.
3. For each word:
    a. Initialize score = 0
    b. For each character:
        i. If uppercase:
            index = letter - 'A'
            add Points[index]
        ii. If lowercase:
            index = letter - 'a'
            add Points[index]
        iii. Ignore non-letters
4. Compare scores:
    - If score1 > score2 → Player 1 wins
    - If score2 > score1 → Player 2 wins
    - Else → Tie
5. End program.

Time Complexity: O(n)
Space Complexity: O(1)
*/