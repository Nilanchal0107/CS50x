/*
    CS50 Substitution Cipher

    Problem:
    Implement a substitution cipher program that encrypts plaintext
    using a 26-character key provided as a command-line argument.

    Requirements:
    - Accept exactly one command-line argument (the key).
    - Key must:
        * Contain exactly 26 characters
        * Contain only alphabetic characters
        * Contain each letter exactly once (no duplicates)
    - Preserve case during encryption.
    - Non-alphabetic characters remain unchanged.
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool valid_key(string key);

int main(int argc, string argv[])
{
    // Ensure exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate key
    if (!valid_key(key))
    {
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt each character
    for (int i = 0; i < strlen(plaintext); i++)
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

// Function to validate key
bool valid_key(string key)
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