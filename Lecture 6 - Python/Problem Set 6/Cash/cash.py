"""
PROBLEM: CASH (GREEDY ALGORITHM)

Write a program that:
1. Prompts the user for the amount of change owed (in dollars).
2. Converts that amount into cents.
3. Calculates the minimum number of coins required.
4. Uses U.S. coin denominations:
      - 25 cents (quarters)
      - 10 cents (dimes)
      - 5 cents (nickels)
      - 1 cent (pennies)
5. Prints the total number of coins used.
"""


# Keep asking user until valid positive number is entered
while True:
    try:
        change = float(input("Change Owed: "))

        # Ensure change is greater than 0
        if change > 0:
            break
        else:
            print("Give me number above 0")

    # Handle invalid (non-numeric) input
    except ValueError:
        print("Give me number above 0")


# Convert dollars to cents to avoid floating point errors
cents = round(change * 100)


# Calculate number of quarters (25 cents)
quarters = cents // 25
cents %= 25


# Calculate number of dimes (10 cents)
dimes = cents // 10
cents %= 10


# Calculate number of nickels (5 cents)
nickels = cents // 5
cents %= 5


# Remaining cents are pennies
pennies = cents


# Total number of coins
total = quarters + dimes + nickels + pennies

print(total)


"""
---------------- ALGORITHM ----------------

1. Repeat until valid input:
      a. Prompt user for change owed.
      b. Convert input to float.
      c. If input > 0 → continue.
      d. Otherwise → print error message.

2. Convert dollars to cents:
      cents = round(change * 100)

3. Use greedy approach:
      a. quarters = cents // 25
      b. cents = cents % 25
      c. dimes = cents // 10
      d. cents = cents % 10
      e. nickels = cents // 5
      f. cents = cents % 5
      g. pennies = remaining cents

4. Add total coins.
5. Print result.

Time Complexity: O(1)
Space Complexity: O(1)
"""