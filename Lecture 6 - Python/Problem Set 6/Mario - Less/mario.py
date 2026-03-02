"""
PROBLEM: MARIO (LESS COMFORTABLE)

Write a program that:
1. Prompts the user for a height (integer between 1 and 8).
2. Prints a right-aligned half-pyramid of that height.
"""


# Keep asking user until valid input is entered
while True:
    try:
        # Take input and convert to integer
        height = int(input("Height: "))

        # Check if height is within valid range
        if height > 0 and height < 9:
            break
        else:
            print("Enter a number between 1 to 8")

    # If input cannot be converted to integer
    except ValueError:
        print("Enter a number between 1 to 8")


# Print the pyramid
for i in range(0, height, 1):

    # Print leading spaces
    for j in range(0, height - (i + 1), 1):
        print(" ", end="")

    # Print hashes
    for j in range(0, i + 1, 1):
        print("#", end="")

    # Move to next line after each row
    print("")


"""
---------------- ALGORITHM ----------------

1. Repeat forever:
    a. Try to take integer input from user.
    b. If height is between 1 and 8:
         break loop.
    c. Otherwise:
         print error message.
    d. If input is not an integer:
         catch ValueError and print error message.

2. For each row i from 0 to height - 1:
    a. Print (height - i - 1) spaces.
    b. Print (i + 1) hashes.
    c. Move to next line.

Time Complexity: O(n²)
Space Complexity: O(1)
"""