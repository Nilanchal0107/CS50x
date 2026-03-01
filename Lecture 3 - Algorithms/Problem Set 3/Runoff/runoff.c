/*
    PROBLEM: RUNOFF ELECTION (STANDARD C VERSION)

    Implement an instant-runoff voting system.

    Rules:
    - Voters rank candidates in order of preference.
    - If a candidate has more than 50% of votes → wins.
    - Otherwise eliminate candidate(s) with fewest votes.
    - Redistribute votes.
    - Continue until winner or tie.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
#define NAME_LENGTH 100

// Candidate structure
typedef struct
{
    char name[NAME_LENGTH];
    int votes;
    bool eliminated;
} candidate;

// Global variables
int voter_count;
int candidate_count;

candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Function prototypes
bool vote(int voter, int rank, char name[]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }

    // Initialize candidates
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    printf("Number of voters: ");
    scanf("%d", &voter_count);
    getchar();  // Clear newline

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %d\n", MAX_VOTERS);
        return 3;
    }

    // Collect votes
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            char name[NAME_LENGTH];

            printf("Rank %d: ", j + 1);
            fgets(name, sizeof(name), stdin);

            // Remove newline
            name[strcspn(name, "\n")] = '\0';

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Run election rounds
    while (true)
    {
        tabulate();

        if (print_winner())
        {
            break;
        }

        int min = find_min();

        if (is_tie(min))
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        // Reset votes
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Record voter's ranked preference
bool vote(int voter, int rank, char name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Count votes
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int index = preferences[i][j];

            if (!candidates[index].eliminated)
            {
                candidates[index].votes++;
                break;
            }
        }
    }
}

// Check majority winner
bool print_winner(void)
{
    int majority = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Find minimum votes
int find_min(void)
{
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }

    return min;
}

// Check tie
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate lowest candidates
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

/*
---------------- ALGORITHM ----------------

1. Accept candidate names via command-line.
2. Store names, initialize votes = 0, eliminated = false.
3. Prompt for number of voters.
4. For each voter:
    a. Record ranked preferences.
5. Repeat election rounds:
    a. Tabulate votes for highest-ranked non-eliminated candidate.
    b. If someone has >50% → winner.
    c. Find minimum vote count.
    d. If tie → print all remaining candidates.
    e. Eliminate lowest candidates.
    f. Reset votes.
6. End.

Time Complexity:
O(voters × candidates²)

Space Complexity:
O(voters × candidates)
*/