"""
PROBLEM: READABILITY (COLEMAN–LIAU INDEX)

Write a program that:
1. Prompts the user for text.
2. Counts:
   - Letters
   - Words
   - Sentences
3. Computes Coleman–Liau index.
4. Prints grade level.

Formula:
index = 0.0588L - 0.296S - 15.8

Where:
L = average number of letters per 100 words
S = average number of sentences per 100 words
"""


def letters_count(text):
    """Count alphabetic characters."""
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def word_count(text):
    """Count words based on spaces."""
    spaces = 0
    for char in text:
        if char.isspace():
            spaces += 1
    return spaces + 1


def sentence_count(text):
    """Count sentences based on '.', '!', '?'."""
    sentences = 0
    for char in text:
        if char in ".!?":
            sentences += 1
    return sentences


def coleman_liau_index(letters, words, sentences):
    """Compute readability index."""
    if words == 0:
        return 0

    L = letters / words * 100
    S = sentences / words * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)


def main():
    text = input("Text: ")

    letters = letters_count(text)
    words = word_count(text)
    sentences = sentence_count(text)

    index = coleman_liau_index(letters, words, sentences)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()


"""
---------------- ALGORITHM ----------------

1. Take text input from user.
2. Count letters using isalpha().
3. Count words by counting spaces + 1.
4. Count sentences by checking '.', '!', '?'.
5. Compute:
      L = letters / words * 100
      S = sentences / words * 100
6. Apply Coleman–Liau formula.
7. Round result.
8. Print grade level.

Time Complexity: O(n)
Space Complexity: O(1)
"""