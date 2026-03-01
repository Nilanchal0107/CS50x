/*
    CAESAR CIPHER (STANDARD C VERSION)

    Problem:
    Encrypt plaintext using Caesar cipher without CS50 library.

    Requirements:
    - Accept one command-line argument (numeric key).
    - Preserve case.
    - Leave non-alphabetical characters unchanged.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int only_digits(const char *key);
void encrypt(const char *text, int key);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    char plaintext[1000];

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt(plaintext, key);

    return 0;
}

// Check if key contains only digits
int only_digits(const char *key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isdigit(key[i]))
        {
            return 0;
        }
    }
    return 1;
}

// Perform encryption
void encrypt(const char *text, int key)
{
    int n = strlen(text);
    char ciphertext[n + 1];

    for (int i = 0; i < n; i++)
    {
        if (isupper(text[i]))
        {
            int pos = text[i] - 'A';
            int new_pos = (pos + key) % 26;
            ciphertext[i] = new_pos + 'A';
        }
        else if (islower(text[i]))
        {
            int pos = text[i] - 'a';
            int new_pos = (pos + key) % 26;
            ciphertext[i] = new_pos + 'a';
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }

    ciphertext[n] = '\0';

    printf("ciphertext: %s\n", ciphertext);
}

/*
---------------- ALGORITHM ----------------

1. Check if exactly one argument is provided.
2. Validate key contains only digits.
3. Convert key string to integer.
4. Read plaintext using fgets().
5. For each character:
    a. If uppercase:
        new_char = ((char - 'A' + key) % 26) + 'A'
    b. If lowercase:
        new_char = ((char - 'a' + key) % 26) + 'a'
    c. Else:
        copy unchanged
6. Add null terminator.
7. Print ciphertext.
8. Exit.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
fgets() includes newline '\n',
but newline remains unchanged and prints normally.
*/