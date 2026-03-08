/*
    PROBLEM: MODIFY VOLUME OF A WAV FILE

    Write a program that:
    - Takes an input WAV file
    - Creates an output WAV file
    - Multiplies each audio sample by a given factor
    - Writes modified audio to output file

    Usage:
        ./volume input.wav output.wav factor

    Example:
        ./volume input.wav louder.wav 2.0
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// WAV header is always 44 bytes
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check correct number of arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input);
        return 1;
    }

    // Convert scaling factor from string to float
    float factor = atof(argv[3]);

    // Copy header (first 44 bytes)
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Read audio samples (16-bit signed integers)
    int16_t sample;

    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        // Scale sample
        sample = sample * factor;

        // Write modified sample
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}

/*
---------------- ALGORITHM ----------------

1. Validate command-line arguments.
2. Open input WAV file in binary read mode.
3. Open output WAV file in binary write mode.
4. Convert scaling factor from string to float.
5. Copy first 44 bytes (WAV header).
6. Loop:
    a. Read one 16-bit sample.
    b. Multiply sample by factor.
    c. Write modified sample.
7. Close files.

Time Complexity:
O(n) where n = number of samples.

Space Complexity:
O(1)
*/