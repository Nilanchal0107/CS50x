#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string);
void encrypt(string, int);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool digit = only_digits(argv[1]);

    if (!digit)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    encrypt(plaintext, key);

    return 0;
}

bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

void encrypt(string text, int key)
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
