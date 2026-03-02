"""
PROBLEM: MARIO (MORE COMFORTABLE)

Write a program that:
1. Prompts the user for a height (integer between 1 and 8).
2. Prints a double half-pyramid of that height.
3. The two pyramids are separated by two spaces.
"""

# Keep asking until valid input is given
while True:
    try:
        # Take input from user and convert to integer
        height = int(input("Height: "))

        # Check if height is between 1 and 8
        if 1 <= height <= 8:
            break
        else:
            print("Give me integer between 1 to 8")

    # If user enters non-integer value
    except ValueError:
        print("Give me a integer between 1 to 8")


# Print the pyramid
for i in range(height):

    # Print leading spaces
    for j in range(height - (i + 1)):
        print(" ", end="")

    # Print left hashes
    for j in range(i + 1):
        print("#", end="")

    # Print gap between pyramids
    print("  ", end="")

    # Print right hashes
    for j in range(i + 1):
        print("#", end="")

    # Move to next line after each row
    print()


"""
---------------- ALGORITHM ----------------

1. Repeat forever:
    a. Try to take integer input from user.
    b. If input is between 1 and 8:
         break loop.
    c. Otherwise:
         print error message.
    d. If input is not an integer:
         catch ValueError and print error message.

2. For each row i from 0 to height - 1:
    a. Print (height - i - 1) spaces.
    b. Print (i + 1) hashes.
    c. Print two spaces.
    d. Print (i + 1) hashes.
    e. Move to next line.

Time Complexity: O(n²)
Space Complexity: O(1)
"""