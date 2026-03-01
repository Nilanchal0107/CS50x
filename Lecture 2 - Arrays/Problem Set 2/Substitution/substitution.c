/*
    Substitution Cipher (Standard C Version)

    Problem:
    Encrypt plaintext using a 26-character substitution key
    provided as a command-line argument.

    No CS50 library used.
    Uses standard C input (fgets).
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool valid_key(const char *key);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    const char *key = argv[1];

    if (!valid_key(key))
    {
        return 1;
    }

    char plaintext[1000];

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            int index = c - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(c))
        {
            int index = c - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

// Validate key
bool valid_key(const char *key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return false;
        }

        int index = toupper(key[i]) - 'A';

        if (seen[index])
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }

        seen[index] = true;
    }

    return true;
}

// 1. If argc != 2 → error → exit.
// 2. Validate key:
//     a. Length must be 26.
//     b. All alphabetic.
//     c. No duplicates.
// 3. Get plaintext.
// 4. For each character:
//     a. If uppercase:
//         index = c - 'A'
//         print toupper(key[index])
//     b. Else if lowercase:
//         index = c - 'a'
//         print tolower(key[index])
//     c. Else:
//         print unchanged
// 5. Print newline.
// 6. Return 0.