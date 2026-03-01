/*
    PROBLEM: PLURALITY ELECTION (CS50 VERSION)

    Write a program that:
    - Accepts candidate names as command-line arguments.
    - Prompts user for number of voters.
    - Prompts each voter to vote for a candidate.
    - Counts votes using plurality rule.
    - Prints the winner(s) of the election.
    
    Plurality Rule:
    The candidate with the highest number of votes wins.
    If there is a tie, print all candidates with highest votes.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

// Define candidate structure
typedef struct
{
    string name;
    int votes;
} candidate;

// Global variables
candidate candidates[MAX];
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for at least one candidate
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Initialize candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Process votes
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
    return 0;
}

// Increment vote count for matching candidate
bool vote(string name)
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

// Print winner(s)
void print_winner(void)
{
    int highest = 0;

    // Find highest vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest)
        {
            highest = candidates[i].votes;
        }
    }

    // Print all candidates with highest votes
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

1. Ensure at least one candidate is provided.
2. Store candidate names and initialize vote counts to 0.
3. Prompt user for number of voters.
4. For each voter:
    a. Prompt for vote.
    b. Compare vote with candidate names using strcmp().
    c. If match found → increment votes.
    d. If no match → print "Invalid vote."
5. Find highest vote count.
6. Print all candidates with highest votes.
7. End program.

Time Complexity: O(n * m)
(n = voters, m = candidates)
Space Complexity: O(m)
*/