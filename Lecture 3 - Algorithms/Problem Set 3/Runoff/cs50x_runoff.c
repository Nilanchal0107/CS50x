/*
    PROBLEM: RUNOFF ELECTION (CS50 VERSION)

    Implement an instant-runoff voting system.

    Rules:
    - Voters rank candidates in order of preference.
    - If a candidate has >50% of votes → wins.
    - If not, eliminate the candidate with the fewest votes.
    - Redistribute votes based on next preference.
    - Repeat until a winner exists or tie occurs.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

int voter_count;
int candidate_count;

candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 2;
            }
        }
        printf("\n");
    }

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

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Record voter's ranked preference
bool vote(int voter, int rank, string name)
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

// Count votes for highest-ranked non-eliminated candidate
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];

            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

// Print winner if majority exists
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

// Find minimum votes among remaining candidates
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

// Check if tie exists
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

// Eliminate candidates with minimum votes
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

1. Accept candidate names from command-line.
2. Record voter ranked preferences.
3. Repeat:
    a. Count votes for highest non-eliminated candidate.
    b. If someone has >50% → print winner.
    c. Find minimum vote count.
    d. If all remaining candidates tied → print all.
    e. Eliminate candidate(s) with minimum votes.
    f. Reset vote counts.
4. End.

Time Complexity: O(voters × candidates²)
Space Complexity: O(voters × candidates)
*/