/*
    PROBLEM: PLURALITY ELECTION (STANDARD C VERSION)

    Same functionality as CS50 version,
    but without using CS50 library.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char name[100];
    int votes;
} candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(char name[]);
void print_winner(void);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    }

    // Initialize candidates
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }

    int voter_count;

    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Clear input buffer
    getchar();

    for (int i = 0; i < voter_count; i++)
    {
        char name[100];

        printf("Vote: ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0';

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
    return 0;
}

bool vote(char name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int highest = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest)
        {
            highest = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

/*
---------------- ALGORITHM ----------------

1. Accept candidate names from command-line arguments.
2. Initialize vote count for each candidate to 0.
3. Prompt for number of voters.
4. For each voter:
    a. Read vote input.
    b. Compare vote to candidate list.
    c. If match → increment votes.
    d. If no match → print "Invalid vote."
5. Find maximum vote count.
6. Print all candidates with maximum votes.
7. End.

Time Complexity: O(n * m)
Space Complexity: O(m)
*/