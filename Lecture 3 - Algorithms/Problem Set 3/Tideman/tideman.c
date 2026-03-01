/*
    PROBLEM: TIDEMAN (RANKED PAIRS) - STANDARD C VERSION

    Implement a ranked-pairs election system.

    Steps:
    1. Voters rank candidates.
    2. Build preference matrix.
    3. Create winning pairs.
    4. Sort pairs by strength.
    5. Lock pairs without creating cycles.
    6. Print source of graph (winner).
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9
#define NAME_LEN 100

// preferences[i][j] = number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] = true if i is locked over j
bool locked[MAX][MAX];

// pair structure
typedef struct
{
    int winner;
    int loser;
} pair;

// Global variables
char candidates[MAX][NAME_LEN];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char name[], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int winner, int loser);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    }

    // Store candidate names
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i], argv[i + 1]);
    }

    // Initialize locked graph
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;

    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);
    getchar();  // Clear newline

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[MAX];

        for (int j = 0; j < candidate_count; j++)
        {
            char name[NAME_LEN];

            printf("Rank %d: ", j + 1);
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

// Record vote
bool vote(int rank, char name[], int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences matrix
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Add winning pairs
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count++] = (pair){i, j};
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count++] = (pair){j, i};
            }
        }
    }
}

// Sort pairs by strength of victory (bubble sort)
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int strength1 = preferences[pairs[j].winner][pairs[j].loser];
            int strength2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            if (strength1 < strength2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

// Lock pairs without forming cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// Recursive cycle detection
bool creates_cycle(int winner, int loser)
{
    if (loser == winner)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (creates_cycle(winner, i))
            {
                return true;
            }
        }
    }

    return false;
}

// Print candidate with no incoming edges
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool has_incoming = false;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                has_incoming = true;
                break;
            }
        }

        if (!has_incoming)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}

/*
---------------- ALGORITHM ----------------

1. Accept candidate names via command-line.
2. Initialize preference matrix and locked graph.
3. For each voter:
    a. Record ranked preferences.
4. Build preference matrix:
    preferences[i][j] counts voters preferring i over j.
5. Create pairs where one candidate beats another.
6. Sort pairs by strength of victory (descending).
7. Lock pairs in order, skipping any that create cycles.
8. Winner = candidate with no incoming edges.

Time Complexity:
O(n^3) due to sorting and cycle detection.

Space Complexity:
O(n^2)
*/