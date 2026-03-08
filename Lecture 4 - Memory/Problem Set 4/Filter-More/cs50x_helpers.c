/*
    PROBLEM: IMAGE FILTERS (MORE COMFORTABLE)

    Implement the following filters:

    1. Grayscale
    2. Reflect
    3. Blur (box blur)
    4. Edges (Sobel operator)

    The edges filter must apply the Sobel operator
    to detect edges in the image.
*/

#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round(
                (image[i][j].rgbtRed +
                 image[i][j].rgbtGreen +
                 image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image (box blur)
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Copy original
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalR = 0, totalG = 0, totalB = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height &&
                        nj >= 0 && nj < width)
                    {
                        totalR += copy[ni][nj].rgbtRed;
                        totalG += copy[ni][nj].rgbtGreen;
                        totalB += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float) totalR / count);
            image[i][j].rgbtGreen = round((float) totalG / count);
            image[i][j].rgbtBlue = round((float) totalB / count);
        }
    }
}

// Detect edges using Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Sobel kernels
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] =
    {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    // Copy original image
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRx = 0, sumGx = 0, sumBx = 0;
            int sumRy = 0, sumGy = 0, sumBy = 0;

            // Apply 3x3 Sobel filter
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height &&
                        nj >= 0 && nj < width)
                    {
                        int kernelX = Gx[di + 1][dj + 1];
                        int kernelY = Gy[di + 1][dj + 1];

                        sumRx += copy[ni][nj].rgbtRed * kernelX;
                        sumGx += copy[ni][nj].rgbtGreen * kernelX;
                        sumBx += copy[ni][nj].rgbtBlue * kernelX;

                        sumRy += copy[ni][nj].rgbtRed * kernelY;
                        sumGy += copy[ni][nj].rgbtGreen * kernelY;
                        sumBy += copy[ni][nj].rgbtBlue * kernelY;
                    }
                }
            }

            // Compute magnitude
            int finalR = round(sqrt(sumRx * sumRx + sumRy * sumRy));
            int finalG = round(sqrt(sumGx * sumGx + sumGy * sumGy));
            int finalB = round(sqrt(sumBx * sumBx + sumBy * sumBy));

            // Cap at 255
            if (finalR > 255) finalR = 255;
            if (finalG > 255) finalG = 255;
            if (finalB > 255) finalB = 255;

            image[i][j].rgbtRed = finalR;
            image[i][j].rgbtGreen = finalG;
            image[i][j].rgbtBlue = finalB;
        }
    }
}

/*
---------------- ALGORITHM ----------------

GRAYSCALE:
1. For each pixel:
   average = (R + G + B) / 3
2. Set R, G, B = average.

REFLECT:
1. For each row:
   Swap pixel j with pixel width-1-j.

BLUR:
1. Copy image.
2. For each pixel:
   Average surrounding 3x3 pixels.
3. Assign averaged value.

EDGES (SOBEL):
1. Define Sobel kernels Gx and Gy.
2. Copy original image.
3. For each pixel:
   Apply Gx and Gy kernels.
   Compute gradient magnitude:
       sqrt(Gx² + Gy²)
4. Cap at 255.
5. Assign new pixel values.

Time Complexity:
O(height × width)

This is convolution-based image processing.
*/