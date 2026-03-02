"""
PROBLEM: CREDIT CARD VALIDATOR

Write a program that:
1. Prompts the user for a positive credit card number.
2. Uses Luhn’s Algorithm to validate the number.
3. Determines the card type:
      - AMEX (15 digits, starts with 34 or 37)
      - MASTERCARD (16 digits, starts with 51–55)
      - VISA (13 or 16 digits, starts with 4)
4. Prints the card type or INVALID.
"""


# Get positive integer from user
def get_number():
    while True:
        try:
            number = int(input("Number: "))
            if number > 0:
                return number
            else:
                print("Give number greater than zero.")
        except ValueError:
            print("Give number greater than zero.")


# Apply Luhn's Algorithm
def luhn_algo(num):
    total = 0
    alternate = False
    temp_number = num

    while temp_number > 0:
        digit = temp_number % 10

        if alternate:
            digit *= 2
            if digit > 9:
                digit -= 9

        total += digit
        alternate = not alternate
        temp_number //= 10

    return total % 10 == 0


# Get length of number
def get_length(num):
    count = 0
    while num > 0:
        num //= 10
        count += 1
    return count


# Get first n digits
def get_start(num, digits):
    length = get_length(num)

    while length > digits:
        num //= 10
        length -= 1

    return num


# Main logic
number = get_number()

# Validate using Luhn
if not luhn_algo(number):
    print("INVALID")
else:
    length = get_length(number)

    start1 = get_start(number, 1)
    start2 = get_start(number, 2)

    if length == 15 and (start2 == 34 or start2 == 37):
        print("AMEX")
    elif length == 16 and 51 <= start2 <= 55:
        print("MASTERCARD")
    elif (length == 13 or length == 16) and start1 == 4:
        print("VISA")
    else:
        print("INVALID")


"""
---------------- ALGORITHM ----------------

1. Prompt user for positive integer.
2. Apply Luhn’s Algorithm:
      a. Starting from last digit, alternate digits.
      b. Double every second digit.
      c. If doubled digit > 9, subtract 9.
      d. Sum all digits.
      e. If total % 10 == 0 → valid.
3. If invalid → print INVALID.
4. If valid:
      a. Get total length.
      b. Get first digit and first two digits.
      c. Check card rules:
            - AMEX → 15 digits & starts with 34 or 37
            - MASTERCARD → 16 digits & starts with 51–55
            - VISA → 13 or 16 digits & starts with 4
5. Print card type or INVALID.

Time Complexity: O(n)
Space Complexity: O(1)
"""