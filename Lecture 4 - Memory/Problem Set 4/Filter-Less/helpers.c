/*
    IMAGE FILTERS - STANDARD C VERSION
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

/* Same filter functions implemented using Pixel struct */

void grayscale(int h, int w, Pixel img[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int avg = round((img[i][j].red +
                             img[i][j].green +
                             img[i][j].blue) / 3.0);

            img[i][j].red = avg;
            img[i][j].green = avg;
            img[i][j].blue = avg;
        }
    }
}