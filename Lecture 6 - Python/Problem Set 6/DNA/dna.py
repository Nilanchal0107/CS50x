"""
PROBLEM: DNA PROFILING

Write a program that:
1. Takes two command-line arguments:
   - A CSV database file containing STR counts.
   - A text file containing a DNA sequence.
2. Computes the longest run of each STR in the DNA sequence.
3. Compares the STR counts with the database.
4. Prints the matching person's name.
5. If no match is found, print "No match".
"""

import csv
import sys


def main():

    # Check for correct number of command-line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # Read database file into memory
    with open(sys.argv[1], newline="") as database_file:
        reader = csv.DictReader(database_file)
        database = list(reader)

        # Extract STR names (column headers except 'name')
        str_list = reader.fieldnames[1:]

    # Read DNA sequence file into memory
    with open(sys.argv[2], "r") as sequence_file:
        dna_sequence = sequence_file.read()

    # Compute longest match of each STR in DNA sequence
    str_counts = {}
    for str_sequence in str_list:
        str_counts[str_sequence] = longest_match(dna_sequence, str_sequence)

    # Compare STR counts against each person in database
    for person in database:
        match = True

        for str_sequence in str_list:
            if int(person[str_sequence]) != str_counts[str_sequence]:
                match = False
                break

        # If all STR counts match exactly
        if match:
            print(person["name"])
            return

    # If no match found
    print("No match")


def longest_match(sequence, subsequence):
    """
    Returns length of longest run of subsequence in sequence.
    """

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each position in the DNA sequence
    for i in range(sequence_length):

        count = 0

        # Check consecutive repeats
        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()


"""
---------------- ALGORITHM ----------------

1. Check command-line arguments:
      If not exactly 2 arguments → print error and exit.

2. Read CSV database file:
      a. Store each row as dictionary.
      b. Extract STR names from header (excluding 'name').

3. Read DNA sequence file into string.

4. For each STR:
      a. Compute longest consecutive run using longest_match().
      b. Store result in dictionary.

5. For each person in database:
      a. Compare each STR count.
      b. If all STR counts match → print person's name and exit.

6. If no matches found → print "No match".

Time Complexity:
O(n × m)
Where:
n = length of DNA sequence
m = number of STRs

Space Complexity:
O(d)
Where:
d = number of people in database
"""
